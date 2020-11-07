#include <memory>
#include "computer_player.h"
#include <string>
#include <map>
#include <iostream>
#include <stdexcept>

void ComputerPlayer::left_part(Board::Position anchor_pos, 
                               std::string partial_word,
                               Move partial_move, 
                               std::shared_ptr<Dictionary::TrieNode> node, 
                               size_t limit,
                               TileCollection& remaining_tiles,
                               std::vector<Move>& legal_moves,
                               const Board& board) const {
  extend_right(anchor_pos, partial_word, partial_move, node, remaining_tiles, legal_moves, board);
  if(limit > 0)
  {
    std::map<char, std::shared_ptr<Dictionary::TrieNode>>::iterator map_it;
    for(map_it = node->nexts.begin(); map_it != node->nexts.end(); map_it++) // iterate through nexts
    {
      try
      {
        TileKind curr_tile = remaining_tiles.lookup_tile(map_it->first);
        remaining_tiles.remove_tile(curr_tile);
        partial_word = partial_word + curr_tile.letter;

        std::vector<TileKind> partial_tiles_2 = partial_move.tiles;
        partial_tiles_2.push_back(curr_tile);

        int row_2 = partial_move.row;
        int column_2 = partial_move.column;
        if(partial_move.direction == Direction::ACROSS)
        {
          column_2--;
        }
        else if(partial_move.direction == Direction::DOWN)
        {
          row_2--;
        }

        Move partial_move_2(partial_tiles_2, row_2, column_2, partial_move.direction);

        left_part(anchor_pos, partial_word, partial_move_2, map_it->second, limit - 1, remaining_tiles, legal_moves, board);
        remaining_tiles.add_tile(curr_tile);
      } 
      catch (std::out_of_range& e) // from lookup_tile(map_it->first) AKA when remaining_tiles does NOT have map_it->first
      {
        // blank check and do similar to try block
        try
        {
          TileKind blank_tile = remaining_tiles.lookup_tile('?');
          blank_tile.assigned = map_it->first;

          remaining_tiles.remove_tile(blank_tile);
          partial_word = partial_word + map_it->first;

          std::vector<TileKind> partial_tiles_2 = partial_move.tiles;
          partial_tiles_2.push_back(blank_tile);

          int row_2 = partial_move.row;
          int column_2 = partial_move.column;
          if(partial_move.direction == Direction::ACROSS)
          {
            column_2--;
          }
          else if(partial_move.direction == Direction::DOWN)
          {
            row_2--;
          }

          Move partial_move_2(partial_tiles_2, row_2, column_2, partial_move.direction);

          left_part(anchor_pos, partial_word, partial_move_2, map_it->second, limit - 1, remaining_tiles, legal_moves, board);
          remaining_tiles.add_tile(blank_tile);
        }
        catch (std::out_of_range& f)
        {
        }
      }
    }
  }
}

void ComputerPlayer::extend_right(Board::Position square,
                                  std::string partial_word,
                                  Move partial_move, 
                                  std::shared_ptr<Dictionary::TrieNode> node,
                                  TileCollection& remaining_tiles,
                                  std::vector<Move>& legal_moves,
                                  const Board& board) const {
  try
  {
    if(board.in_bounds_and_has_tile(square) == false) // VACANT
    {
      if(node->is_final == true) // If N is a terminal node then
      {
        legal_moves.push_back(partial_move);
      }

      std::map<char, std::shared_ptr<Dictionary::TrieNode>>::iterator map_it;
      for(map_it = node->nexts.begin(); map_it != node->nexts.end(); map_it++)
      {
        try
        {
          TileKind curr_tile = remaining_tiles.lookup_tile(map_it->first);
          remaining_tiles.remove_tile(curr_tile);
          partial_word += curr_tile.letter;

          std::vector<TileKind> partial_tiles_2 = partial_move.tiles;
          partial_tiles_2.push_back(curr_tile);

          Move partial_move_2(partial_tiles_2, partial_move.row, partial_move.column, partial_move.direction);

          extend_right(square.translate(partial_move.direction), partial_word, partial_move_2, map_it->second, remaining_tiles, legal_moves, board);
          remaining_tiles.add_tile(curr_tile);
        } 
        catch (std::out_of_range& e) // from lookup_tile(map_it->first) AKA when remaining_tiles does NOT have map_it->first
        {
          try
          {
            TileKind blank_tile = remaining_tiles.lookup_tile('?');
            blank_tile.assigned = map_it->first;

            remaining_tiles.remove_tile(blank_tile);

            partial_word += map_it->first;

            std::vector<TileKind> partial_tiles_2 = partial_move.tiles;
            partial_tiles_2.push_back(blank_tile);

            Move partial_move_2(partial_tiles_2, partial_move.row, partial_move.column, partial_move.direction);

            extend_right(square.translate(partial_move.direction), partial_word, partial_move_2, map_it->second, remaining_tiles, legal_moves, board);
            remaining_tiles.add_tile(blank_tile);
          }
          catch (std::out_of_range& f)
          {
          }
        }
      }
    }
    else // NO VACANT
    {
      char curr_char = board.letter_at(square);
      std::map<char, std::shared_ptr<Dictionary::TrieNode>>::iterator map_it = node->nexts.find(curr_char);
      if(map_it != node->nexts.end())
      {
        partial_word += curr_char;

        extend_right(square.translate(partial_move.direction), partial_word, partial_move, map_it->second, remaining_tiles, legal_moves, board);
      }
    }
  }
  catch (std::out_of_range& e)
  {
  }
}

Move ComputerPlayer::get_move(const Board& board, const Dictionary& dictionary) const {
	board.print(std::cout); // prints board
  std::vector<Move> legal_moves;
  std::vector<Board::Anchor> anchors = board.get_anchors();
  
  for(size_t i = 0; i < anchors.size(); i++)
  {
    Board::Anchor curr_anchor = anchors[i];
    if(curr_anchor.limit > 0)
    {
      std::vector<TileKind> tiles;
      Direction anchor_direction = curr_anchor.direction;
      Move partial_move(tiles, curr_anchor.position.row, curr_anchor.position.column, anchor_direction);

      TileCollection copy_remaining = this->tiles;

      left_part(curr_anchor.position, "", partial_move, dictionary.get_root(), curr_anchor.limit, copy_remaining, legal_moves, board);
    } 
    else if(curr_anchor.limit == 0)
    {
      std::string partial_word = "";
      std::vector<TileKind> partial_move_tiles_vector;
      Board::Position prefix_tracker = curr_anchor.position;
      Direction anchor_direction = curr_anchor.direction;

      prefix_tracker = prefix_tracker.translate(anchor_direction, -1); // moves either up or left from anchor by 1

      while(board.in_bounds_and_has_tile(prefix_tracker))
      {
        partial_word = board.letter_at(prefix_tracker) + partial_word;
        prefix_tracker = prefix_tracker.translate(curr_anchor.direction, -1); // moves either up or left from anchor by 1
      }

      Move partial_move(partial_move_tiles_vector, curr_anchor.position.row, curr_anchor.position.column, anchor_direction);
      std::shared_ptr<Dictionary::TrieNode> prefix_node = dictionary.find_prefix(partial_word);

      TileCollection copy_remaining = this->tiles;

      extend_right(curr_anchor.position, partial_word, partial_move, prefix_node, copy_remaining, legal_moves, board);
    }
  }
	return get_best_move(legal_moves, board, dictionary);
}

Move ComputerPlayer::get_best_move(std::vector<Move> legal_moves, const Board& board, const Dictionary& dictionary) const {
  Move best_move = Move(); // Pass if no move found	
  int highest_score = 0;

  for(size_t i = 0; i < legal_moves.size(); i++)
  {
    try
    {
      Move curr_move = legal_moves[i];
      PlaceResult result = board.test_place(curr_move);
      int curr_score = result.points;

      for(size_t j = 0; j < result.words.size(); j++)
      {
        if(dictionary.is_word(result.words[j]) == false)
        {
          throw std::out_of_range("Invalid result");
        }
      }

      if(curr_move.tiles.size() == this->get_hand_size())
      {
        curr_score += 50;
      }

      if(result.valid && curr_score > highest_score)
      {
        best_move = curr_move;
        highest_score = curr_score;
      }
    }
    catch (std::out_of_range& e)
    {
    }
  }
	
  return best_move;	
}
