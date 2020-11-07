#include "board.h"
#include "board_square.h"
#include "exceptions.h"
#include "formatting.h"
#include <iomanip>
#include <fstream>

using namespace std;


bool Board::Position::operator==(const Board::Position& other) const {
    return this->row == other.row && this->column == other.column;
}

bool Board::Position::operator!=(const Board::Position& other) const {
    return this->row != other.row || this->column != other.column;
}

Board::Position Board::Position::translate(Direction direction) const {
    return this->translate(direction, 1);
}

Board::Position Board::Position::translate(Direction direction, ssize_t distance) const {
    if (direction == Direction::DOWN) {
        return Board::Position(this->row + distance, this->column);
    } else {
        return Board::Position(this->row, this->column + distance);
    }
}

Board Board::read(const string& file_path) {
    ifstream file(file_path);
    if (!file) {
        throw FileException("cannot open board file!");
    }
    size_t rows;
    size_t columns;
    size_t starting_row;
    size_t starting_column;
    file >> rows >> columns >> starting_row >> starting_column;
    Board board(rows, columns, starting_row, starting_column);
    // read function is called in scrabble.cpp constructor for scrabble object
    // within scrabble.h, there is a default Board board object with no parameters
    // when scrabble's initialization list is called, it does this:
    // board(Board::read(config.board_file_path))
    // this, i am assuming, means that we want a object in the right to be a copy constructor
    // we want to instantiate and edit the board object we made above and return that to re-construct the default board we have
    for(size_t i = 0; i < rows; i++)
    {
    	vector<BoardSquare> new_row; // vector to push into squares

    	// string row_string;
    	// file >> row_string; // row_string is now ..........

    	for(size_t j = 0; j < columns; j++)
    	{
    		char curr;
    		file >> curr; // curr will be ., 2, 3, d or t
    		if(curr == '.')
    		{
    			BoardSquare new_square(1, 1);
    			new_row.push_back(new_square);
    		}
    		else if(curr == '2')
    		{
    			// letter double multiplier
    			BoardSquare new_square(2, 1);
    			new_row.push_back(new_square);
    		}
    		else if(curr == '3')
    		{
    			// letter triple multiplier
    			BoardSquare new_square(3, 1);
    			new_row.push_back(new_square);
    		}
    		else if(curr == 'd')
    		{
    			// word double multiplier
    			BoardSquare new_square(1, 2);
    			new_row.push_back(new_square);
    		}
    		else if(curr == 't')
    		{
    			// word triple multiplier
    			BoardSquare new_square(1, 3);
    			new_row.push_back(new_square);
    		}
    		else
    		{
    			throw FileException("File error. Try again.");
    		}
    	}
    	board.squares.push_back(new_row);
    }

    return board;
}

size_t Board::get_move_index() const {
    return this->move_index;
}

PlaceResult Board::test_place(const Move& move) const {
    size_t move_length = move.tiles.size();
    // starts on the initial row and col
    size_t start_row = move.row;
    size_t start_col = move.column;
    Board::Position curr_letter_position(start_row, start_col);
    size_t final_points = 0;
    size_t final_word_multiplier = 1;

    // In bounds Checker
    for(size_t i = 0; i < move_length; i++)
    {
        // cerr << "Checking bounds in test_place: " << curr_letter_position.row << ", " << curr_letter_position.column << endl;
    	if(is_in_bounds(curr_letter_position))
    	{
    		curr_letter_position = curr_letter_position.translate(move.direction);
    	}
    	else
    	{
    		PlaceResult out_of_bounds_error("Word goes out of bounds. Try again.");
            return out_of_bounds_error;
    	}
    }
    // cerr << "Bound loop just ran" << endl;
    // Vectors and string to store data for Move
    vector<Board::Position> position_vector;
    vector<TileKind> tilekind_vector;
    string complete_word;
    bool adjacent_check = false; // this must become true at the end of this function

    // Prefix Checker
    curr_letter_position.row = start_row; // reset row
	curr_letter_position.column = start_col; // reset col
	// cerr << "Resetted position after bound loop: (" << curr_letter_position.row + 1 << ", " << curr_letter_position.column + 1<< ")" << endl;

    size_t prefix_size = 0;
    curr_letter_position = curr_letter_position.translate(move.direction, -1); // this translate will move the position to the tile directly above or left of the move
    // cerr << "Translated position: (" << curr_letter_position.row + 1 << ", " << curr_letter_position.column + 1 << ")" << endl;

    // while loop will keep checking for prefixes as long as it exists and is in bound
    while(is_in_bounds(curr_letter_position) && at(curr_letter_position).has_tile())
    {
    	// cerr << "Entering prefix while loop" << endl;
    	// cerr << "(" << curr_letter_position.row << ", " << curr_letter_position.column << ")" << endl;
    	prefix_size++;
    	curr_letter_position = curr_letter_position.translate(move.direction, -1);
    	adjacent_check = true;
    }
    // curr_letter_position is going to be on the tile before the first letter of the prefix, or the word if no prefix
    curr_letter_position = curr_letter_position.translate(move.direction); // translate curr_letter_position onto the first letter of the word
    for(size_t i = 0; i < prefix_size; i++)
    {
    	// cerr << "Entering prefix for loop" << endl;
    	position_vector.push_back(curr_letter_position); // add the position of the prefixes to vector
    	tilekind_vector.push_back(at(curr_letter_position).get_tile_kind()); // add tile_kind of prefixes to vector
    	if(at(curr_letter_position).get_tile_kind().letter == '?')
        {
            complete_word += at(curr_letter_position).get_tile_kind().assigned;
        }
        else
        {
            complete_word += at(curr_letter_position).get_tile_kind().letter; // add prefix to complete_word
        }        
        final_points += at(curr_letter_position).get_tile_kind().points; // updates points without regards to multiplier
    	curr_letter_position = curr_letter_position.translate(move.direction); // moves position
    }

    // cerr << "Prefix accounted for. complete_word: " << complete_word << endl;

    // Actual Move
	curr_letter_position.row = start_row; // reset row
	curr_letter_position.column = start_col; // reset col
    // cerr << "Position after prefix checker: (" << curr_letter_position.row + 1 << ", " << curr_letter_position.column + 1 << ")" << endl;
	size_t curr_letter_vector_index = 0;

	bool placed_start_on_empty = false;

	for(size_t i = 0; i < move_length && curr_letter_vector_index < move.tiles.size(); i++)
	{
		if(at(curr_letter_position).has_tile()) // handles when there is something in the middle of the word
		{
			if(i == 0)
			{
				PlaceResult error_move("Cannot overwrite another tile with first tile. Try again.");
				return error_move;
			}
			position_vector.push_back(curr_letter_position); // add position of the existing letter
			tilekind_vector.push_back(at(curr_letter_position).get_tile_kind()); // add tile_kind of existing letter to vector
			if(at(curr_letter_position).get_tile_kind().letter == '?')
            {
                complete_word += at(curr_letter_position).get_tile_kind().assigned;
            }
            else
            {
                complete_word += at(curr_letter_position).get_tile_kind().letter; // add prefix to complete_word
            }    
            final_points += at(curr_letter_position).get_tile_kind().points; // updates points without regards to multiplier
			adjacent_check = true;
			move_length++; // since we just checked an existing tile, need to make sure the for loop runs one extra iteration
		}
		else // when at a empty spot on board
		{
			if(curr_letter_position == start)
			{
				placed_start_on_empty = true; // becomes true when placing first tile of move onto an empty spot
			}
			position_vector.push_back(curr_letter_position); // add positions of the actual Move's word's char
			tilekind_vector.push_back(move.tiles[curr_letter_vector_index]); // add tile_kind of actual Move's word's char to vector
            final_points += (move.tiles[curr_letter_vector_index].points * at(curr_letter_position).letter_multiplier); // updates points w regards to multiplier
            final_word_multiplier *= at(curr_letter_position).word_multiplier; // updates word multiplier for later

			if(move.tiles[curr_letter_vector_index].letter == TileKind::BLANK_LETTER) 
			{
  				complete_word += move.tiles[curr_letter_vector_index].assigned;
			}
			else 
			{
				complete_word += move.tiles[curr_letter_vector_index].letter;
			}

			// complete_word += move.tiles[curr_letter_vector_index].letter; // add the actual Move's word's char to complete_word
			curr_letter_vector_index++;
		}
		curr_letter_position = curr_letter_position.translate(move.direction); // moves position
	}

	// cerr << "Actual move accounted for. complete_word: " << complete_word << endl;

	if(placed_start_on_empty == false && this->move_index == 0) // if we are on the first move of the game but did not place on the starting position
	{
		// cerr << "DID NOT PLACE ON START" << endl;
		PlaceResult error_move("Must place a tile on the Start tile for the first move. Try again.");
		return error_move;
	}
    // cerr << "Position before suffix checker: (" << curr_letter_position.row + 1 << ", " << curr_letter_position.column + 1 << ")" << endl;
	// Suffix Checker
	// curr_letter_position is currently on the tile right after the end of the move's word
    /*if(is_in_bounds(curr_letter_position))
    {
        while(at(curr_letter_position).has_tile() && is_in_bounds(curr_letter_position))
        {
            // cerr << "flag 2" << endl;
            position_vector.push_back(curr_letter_position);
            // cerr << "flag 3" << endl;
            tilekind_vector.push_back(at(curr_letter_position).get_tile_kind());
            // cerr << "flag 4" << endl;
            complete_word += at(curr_letter_position).get_tile_kind().letter;
            final_points += at(curr_letter_position).get_tile_kind().points;
            adjacent_check = true;
            curr_letter_position = curr_letter_position.translate(move.direction);
        }
    }*/

    // IT WILL CHECK IN FLAM*in*ES FLAMES
    // it WILL cross check FLAM but not ES

    while(is_in_bounds(curr_letter_position) && at(curr_letter_position).has_tile())
    {
        // cerr << "flag 2" << endl;
        position_vector.push_back(curr_letter_position);
        // cerr << "flag 3" << endl;
        tilekind_vector.push_back(at(curr_letter_position).get_tile_kind());
        // cerr << "flag 4" << endl;
        if(at(curr_letter_position).get_tile_kind().letter == '?')
        {
            complete_word += at(curr_letter_position).get_tile_kind().assigned;
        }
        else
        {
            complete_word += at(curr_letter_position).get_tile_kind().letter; // add prefix to complete_word
        }    
        final_points += at(curr_letter_position).get_tile_kind().points;
        adjacent_check = true;
        curr_letter_position = curr_letter_position.translate(move.direction);
    }
	
	// cerr << "Suffix accounted for. complete_word: " << complete_word << endl;

	// Opposite Checker
	PlaceResult opposite_words_result = opposite_direction_checker(move);
	// cerr << "Opposite checker completed" << endl;

	// Adjacent Check (Only if MOVE_INDEX is not 0)
	if(this->move_index > 0 && adjacent_check == false && opposite_words_result.words.size() == 0)
	{
		// cerr << "Move was not adjacent to any tiles ERROR" << endl;
		PlaceResult error_move("Your move must be made adjacent to an existing tile. Try again.");
		return error_move;
	}

    /*
	// updates points based on the tiles placed for the actual Move
	for(size_t i = 0; i < position_vector.size(); i++)
	{
		final_points += tilekind_vector[i].points * at(position_vector[i]).letter_multiplier; // add the current Tile's point multiplied by letter multiplier
		final_word_multiplier *= at(position_vector[i]).word_multiplier; // update the final word multiplier of this Move
	}
    */

	final_points *= final_word_multiplier;
	vector<string> all_words_vector;
	all_words_vector = opposite_words_result.words; // THIS IS FOR THE OPPOSITE WORDS
	if(complete_word.size() > 1 || (complete_word.size() == 1 && this->move_index == 0))
	{
        // cerr << "Entering complete word of Move if it is a word" << endl;
		all_words_vector.push_back(complete_word); // THIS IS FOR THE WORD FOUND FROM MOVE
	}
	final_points += opposite_words_result.points;

	/* cerr << "At the end. complete_word: " << complete_word << " final_points: " << final_points << endl;
    cerr << "All words made from this move: ";
	for(size_t i = 0; i < all_words_vector.size(); i++)
	{
		cerr << all_words_vector[i] << " ";
	}
	cerr << endl;*/

	PlaceResult final_result(all_words_vector, final_points);

	return final_result;

    // check if it is the first placed word, must be on the letter on the board
    // check @ move's initial col & row if there is smth there + continue moving length of move to check if it runs into another letter that exists
    // check out of bound of squares/board
}

PlaceResult Board::opposite_direction_checker(const Move& move) const {
	// cerr << "opposite_direction_checker entered" << endl;
	Direction opposite_dir;
	if(move.direction == Direction::ACROSS) { opposite_dir = Direction::DOWN; } 
	else { opposite_dir = Direction::ACROSS; }

	size_t move_length = move.tiles.size();
    // starts on the initial row and col
    size_t start_row = move.row;
    size_t start_col = move.column;
    Board::Position curr_letter_position(start_row, start_col);

    vector<string> opp_words_vector;
    size_t final_points = 0;
	size_t update_points = 0;
	size_t update_word_multiplier = 1;

    // cerr << "move_length: " << move_length << endl;

    for(size_t i = 0; i < move_length; i++) // check opposite direction for each letter in move
    {
    	// cerr << "Checking opposite of " << move.tiles[i].letter << " ITERATION " << i + 1 <<  endl;
    	if(in_bounds_and_has_tile(curr_letter_position)) // in the case that we run into any tiles that were placed before the Move was made
    	{
    		// cerr << "This spot has a tile and " << move.tiles[i].letter << " must be placed on a empty BoardSquare" << endl;
    		curr_letter_position = curr_letter_position.translate(move.direction); 
            i--;
    		// cerr << "curr_letter_position: (" << curr_letter_position.row + 1 << ", " << curr_letter_position.column + 1 << ")" << endl;
            // we want to skip over this tile because any words formed before the Move or any words that were used
    		// to complete the Move's actual word should not be included as a opposite word
    		// an opposite word only counts if it became a new word due to a tile that Move put down
    	}
        else
        {
            // need to check opposite prefix and suffix of the Move letter
            string complete_word;
            Board::Position original_position(curr_letter_position.row, curr_letter_position.column);
            // cerr << "original_position: (" << original_position.row + 1 << ", " << original_position.column + 1 << ")" << endl;
            // cerr << "curr_letter_position: (" << curr_letter_position.row + 1 << ", " << curr_letter_position.column + 1 << ")" << endl;

            // Prefix Checker
            size_t prefix_size = 0;
            curr_letter_position = curr_letter_position.translate(opposite_dir, -1);
            while(at(curr_letter_position).has_tile())
            {
                prefix_size++;
                curr_letter_position = curr_letter_position.translate(opposite_dir, -1);
            }
            // cerr << "Prefix accounted for. " << endl;
            curr_letter_position = curr_letter_position.translate(opposite_dir); // move the position back to the first letter of the word
            // cerr << "curr_letter_position should be at the start of the prefix of move (" << curr_letter_position.row + 1 << ", " << curr_letter_position.column + 1 << ")" << endl;
            size_t index_counter = 0; // used to keep track of index of opposite word found
            // cerr << "Entering check for opposite word" << endl;
            while(is_in_bounds(curr_letter_position))
            {
                if(at(curr_letter_position).has_tile() == false && index_counter == prefix_size) // when at the actual move's letter NEED TO CHECK MULTIPLIERS HERE
                {
                    if(move.tiles[i].letter == '?')
                    {
                        complete_word += move.tiles[i].assigned;
                    }
                    else
                    {
                        complete_word += move.tiles[i].letter;
                    }
                    
                    update_points += move.tiles[i].points * at(curr_letter_position).letter_multiplier;
                    update_word_multiplier *= at(curr_letter_position).word_multiplier;
                }
                else if(at(curr_letter_position).has_tile())// when checking prefix or suffix NO MULTIPLIERS
                {   
                    complete_word += at(curr_letter_position).get_tile_kind().letter;
                    update_points += at(curr_letter_position).get_tile_kind().points;
                }
                else if(at(curr_letter_position).has_tile() == false && index_counter != prefix_size)
                {   
                    break;
                }
                index_counter++;
                curr_letter_position = curr_letter_position.translate(opposite_dir);
                // cerr << "complete_word so far: " << complete_word << endl;
            }

            // cerr << "Opposite word found on " << move.tiles[i].letter << " was: " << complete_word << endl;
            if(complete_word.size() > 1)
            {
                opp_words_vector.push_back(complete_word);
                final_points += update_points * update_word_multiplier;
            }
            /*cerr << "opp_words_vector right now: ";
            for(size_t i = 0; i < opp_words_vector.size(); i++)
            {
                cerr << opp_words_vector[i] << " ";
            }
            cerr << endl;*/

            // reset position to the letter we were checking on Move
            // move to the next letter to check
            // reset the update points and multipliers
            curr_letter_position = original_position;
         
            // IMPORTANT LINE THIS MIGHT BE WRONG
            if(is_in_bounds(curr_letter_position.translate(move.direction)))
            {
                curr_letter_position = curr_letter_position.translate(move.direction);
            }
            else
            {
                break;
            }

            // TESTING
            // curr_letter_position = curr_letter_position.translate(move.direction);


            // cerr << "curr_letter_position should be at the next move (" << curr_letter_position.row + 1 << ", " << curr_letter_position.column + 1 << ")" << endl;
            update_points = 0;
            update_word_multiplier = 1;
            // cerr << "Exitting loop iteration " << i + 1 << endl << endl;
        }
    }

    PlaceResult return_placeresult(opp_words_vector, final_points);
    return return_placeresult;
}

PlaceResult Board::place(const Move& move) {
    // TODO: Complete implementation here
    // cerr << "Board place entered. " << endl;
    PlaceResult test_result = test_place(move);
    if(test_result.valid == false)
    {
        return test_result;
    }
    Board::Position curr_letter_position(move.row, move.column);
    size_t move_length = move.tiles.size();
    size_t index_counter = 0;

    // cerr << "Placing for loop entered" << endl;
    for(size_t i = 0; i < move_length && index_counter < move.tiles.size(); i++)
    {
    	if(at(curr_letter_position).has_tile()) // when the position we are checking has something, skip over it. no need to place anything
    	{
    		move_length++; // need to increment to make sure for loop runs properly
    	}
    	else // PLACE SOMETHING
    	{
    		this->squares[curr_letter_position.row][curr_letter_position.column].set_tile_kind(move.tiles[index_counter]);
    		// this->squares[curr_letter_position.row][curr_letter_position.column].word_multiplier = 1; DO NOT RESET THE MULTIPLIERS
    		// this->squares[curr_letter_position.row][curr_letter_position.column].letter_multiplier = 1; DO NOT RESET THE MULTIPLIERS
    		index_counter++;
    		// cerr << this->squares[curr_letter_position.row][curr_letter_position.column].get_tile_kind().letter << " placed on (" << curr_letter_position.row + 1 << ", " << curr_letter_position.column + 1 << ")" << endl;
    	}
    	// cerr << "About to translate over" << endl;
    	curr_letter_position = curr_letter_position.translate(move.direction);
    	// cerr << "curr_letter_position: (" << curr_letter_position.row + 1 << ", " << curr_letter_position.column + 1 << ")" << endl;
    }
    // cerr << "Move placed on board SUCCESSFULLY" << endl;

    this->move_index++; // MOVE WAS SUCCESSFULLY DONE

    return test_result;
}

// The rest of this file is provided for you. No need to make changes.

BoardSquare& Board::at(const Board::Position& position) {
    return this->squares.at(position.row).at(position.column);
}

const BoardSquare& Board::at(const Board::Position& position) const {
    return this->squares.at(position.row).at(position.column);
}

bool Board::is_in_bounds(const Board::Position& position) const {
    return position.row < this->rows && position.column < this->columns;
}

bool Board::in_bounds_and_has_tile(const Position& position) const{
    return is_in_bounds(position) && at(position).has_tile();
}

void Board::print(ostream& out) const {
	// Draw horizontal number labels
	for (size_t i = 0; i < BOARD_TOP_MARGIN - 2; ++i) {
		out << std::endl;
	}
	out << FG_COLOR_LABEL << repeat(SPACE, BOARD_LEFT_MARGIN);
	const size_t right_number_space = (SQUARE_OUTER_WIDTH - 3) / 2;
	const size_t left_number_space = (SQUARE_OUTER_WIDTH - 3) - right_number_space;
	for (size_t column = 0; column < this->columns; ++column) {
		out << repeat(SPACE, left_number_space) << std::setw(2) << column + 1 << repeat(SPACE, right_number_space);
	}
	out << std::endl;

	// Draw top line
	out << repeat(SPACE, BOARD_LEFT_MARGIN);
    print_horizontal(this->columns, L_TOP_LEFT, T_DOWN, L_TOP_RIGHT, out);
    out << endl;

	// Draw inner board
	for (size_t row = 0; row < this->rows; ++row) {
        if (row > 0) {
            out << repeat(SPACE, BOARD_LEFT_MARGIN);
			print_horizontal(this->columns, T_RIGHT, PLUS, T_LEFT, out);
			out << endl;
		}

		// Draw insides of squares
		for (size_t line = 0; line < SQUARE_INNER_HEIGHT; ++line) {
			out << FG_COLOR_LABEL << BG_COLOR_OUTSIDE_BOARD;

			// Output column number of left padding
			if (line == 1) {
				out << repeat(SPACE, BOARD_LEFT_MARGIN - 3);
				out << std::setw(2) << row + 1;
				out << SPACE;
			} else {
				out << repeat(SPACE, BOARD_LEFT_MARGIN);
			}

            // Iterate columns
			for (size_t column = 0; column < this->columns; ++column) {
				out << FG_COLOR_LINE << BG_COLOR_NORMAL_SQUARE << I_VERTICAL;
				const BoardSquare& square = this->squares.at(row).at(column);
				bool is_start = this->start.row == row && this->start.column == column;

				// Figure out background color
				if (square.word_multiplier == 2) {
					out << BG_COLOR_WORD_MULTIPLIER_2X;
				} else if (square.word_multiplier == 3) {
					out << BG_COLOR_WORD_MULTIPLIER_3X;
				} else if (square.letter_multiplier == 2) {
					out << BG_COLOR_LETTER_MULTIPLIER_2X;
				} else if (square.letter_multiplier == 3) {
					out << BG_COLOR_LETTER_MULTIPLIER_3X;
				} else if (is_start) {
					out << BG_COLOR_START_SQUARE;
                }

				// Text
                if (line == 0 && is_start) {
                    out << "  \u2605  ";
                } else if (line == 0 && square.word_multiplier > 1) {
                    out << FG_COLOR_MULTIPLIER << repeat(SPACE, SQUARE_INNER_WIDTH - 2) << 'W' << std::setw(1) << square.word_multiplier;
                } else if (line == 0 && square.letter_multiplier > 1) {
                    out << FG_COLOR_MULTIPLIER << repeat(SPACE, SQUARE_INNER_WIDTH - 2) << 'L' << std::setw(1) << square.letter_multiplier;
				} else if (line == 1 && square.has_tile()) {
                    char l = square.get_tile_kind().letter == TileKind::BLANK_LETTER ? square.get_tile_kind().assigned : ' ';
                    out << repeat(SPACE, 2) << FG_COLOR_LETTER << square.get_tile_kind().letter << l << repeat(SPACE, 1);
				} else if (line == SQUARE_INNER_HEIGHT - 1 && square.has_tile()) {
					out << repeat(SPACE, SQUARE_INNER_WIDTH - 1) << FG_COLOR_SCORE << square.get_points();
				} else {
					out << repeat(SPACE, SQUARE_INNER_WIDTH);
				}
			}

			// Add vertical line
			out << FG_COLOR_LINE << BG_COLOR_NORMAL_SQUARE << I_VERTICAL << BG_COLOR_OUTSIDE_BOARD << std::endl;
		}
	}

	// Draw bottom line
	out << repeat(SPACE, BOARD_LEFT_MARGIN);
	print_horizontal(this->columns, L_BOTTOM_LEFT, T_UP, L_BOTTOM_RIGHT, out);
	out << endl << rang::style::reset << std::endl;
}

char Board::letter_at(Position p) const {
    if(at(p).get_tile_kind().letter == '?')
    {
        return at(p).get_tile_kind().assigned;
    }
    else
    {
        return at(p).get_tile_kind().letter;
    }
}

bool Board::is_anchor_spot(Position p) const {
    if(is_in_bounds(p)) // 1) In bounds
    {
        if(in_bounds_and_has_tile(p) == false) // 2) Unoccupied
        {
            if(p == start) // 3) is the start square
            {
                return true;
            }
            else // 2) adjacent to a placed tile
            {   
                Position temp = p;
                bool anchor_flag = false;

                // Check adjacency top, right, down, left in that order
                temp = temp.translate(Direction::DOWN, -1); // 1 ABOVE Position P
                if(in_bounds_and_has_tile(temp) == true)
                {
                    anchor_flag = true;
                }

                temp = p; // reset temp
                temp = temp.translate(Direction::ACROSS, 1); // 1 RIGHT Position P
                if(in_bounds_and_has_tile(temp) == true)
                {
                    anchor_flag = true;
                }

                temp = p; // reset temp
                temp = temp.translate(Direction::DOWN, 1); // 1 BELOW Position P
                if(in_bounds_and_has_tile(temp) == true)
                {
                    anchor_flag = true;
                }

                temp = p; // reset temp
                temp = temp.translate(Direction::ACROSS, -1); // 1 LEFT Position P
                if(in_bounds_and_has_tile(temp) == true)
                {
                    anchor_flag = true;
                }

                if(anchor_flag == true)
                {
                    return true;
                }
            }
        }
    }

    return false;
} 

std::vector<Board::Anchor> Board::get_anchors() const { // Used for testing
    Position tracker(0, 0);
    vector<Anchor> all_anchors;
    for(size_t i = 0; i < rows; i++) // Going down the board
    {
        for(size_t j = 0; j < columns; j++) // Going across the board
        {
            if(is_anchor_spot(tracker))
            {
                Position anchor_tracker = tracker;
                anchor_tracker = anchor_tracker.translate(Direction::ACROSS, -1); // PREFIX TO LEFT
                int across_limit = 0;

                while(is_in_bounds(anchor_tracker) && in_bounds_and_has_tile(anchor_tracker) == false && is_anchor_spot(anchor_tracker) == false)
                {
                    across_limit++;
                    anchor_tracker = anchor_tracker.translate(Direction::ACROSS, -1);
                }

                Anchor across_anchor(tracker, Direction::ACROSS, across_limit);
                all_anchors.push_back(across_anchor);

                anchor_tracker = tracker;
                anchor_tracker = anchor_tracker.translate(Direction::DOWN, -1); // PREFIX TO ABOVE
                int down_limit = 0;

                while(is_in_bounds(anchor_tracker) && in_bounds_and_has_tile(anchor_tracker) == false && is_anchor_spot(anchor_tracker) == false)
                {
                    down_limit++;
                    anchor_tracker = anchor_tracker.translate(Direction::DOWN, -1);
                }

                Anchor down_anchor(tracker, Direction::DOWN, down_limit);
                all_anchors.push_back(down_anchor);
            }
            tracker = tracker.translate(Direction::ACROSS);
        }
        tracker.column = 0;
        tracker = tracker.translate(Direction::DOWN);
    }
    return all_anchors;
}