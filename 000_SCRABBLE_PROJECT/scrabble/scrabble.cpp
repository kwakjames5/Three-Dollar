#include "scrabble.h"
#include "formatting.h"
#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

// C++ exception with description "vector::_M_range_check: __n (which is 15) >= this->size() (which is 15)" thrown in the test body.

// Given to you. this does not need to be changed
Scrabble::Scrabble(const ScrabbleConfig& config)
    : hand_size(config.hand_size)
    , minimum_word_length(config.minimum_word_length)
    , tile_bag(TileBag::read(config.tile_bag_file_path, config.seed))
    , board(Board::read(config.board_file_path))
    , dictionary(Dictionary::read(config.dictionary_file_path)) {}

void Scrabble::add_players()
{
    // 1-8 PLAYER CHECK file exception
    cout << "Please enter number of players: ";
    size_t player_count = 0;
    cin >> player_count;
    cout << player_count << " players confirmed." << endl;

    if(player_count < 1 || player_count > 8)
    {
        throw FileException("Invalid player count.");
    }

    for(size_t i = 0; i < player_count; i++)
    {
        // Take inputs and instantiate the actual HumanPlayer
        string new_player;
        cout << "Please enter name for player " << i + 1 << ": ";
        cin >> new_player;
        char computer_human_input;
        cout << "Is " << new_player << " a computer? (y/n)" << endl;
        cin >> computer_human_input;

        if(computer_human_input == 'y')
        {
            shared_ptr<Player> new_player_ptr = make_shared<ComputerPlayer>(new_player, this->hand_size);
            this->players.push_back(new_player_ptr);

            // give this new ComputerPlayer a hand
            vector<TileKind> new_hand = this->tile_bag.remove_random_tiles(this->hand_size); // draws tiles for size of hand
            this->players[i]->add_tiles(new_hand); // adds tiles to hand
            cout << "Player " << i + 1 << " named \"" << new_player << "\", has been added." << endl;
        }
        else if(computer_human_input == 'n')
        {
            shared_ptr<Player> new_player_ptr = make_shared<HumanPlayer>(new_player, this->hand_size);
            this->players.push_back(new_player_ptr);

            // give this new HumanPlayer a hand
            vector<TileKind> new_hand = this->tile_bag.remove_random_tiles(this->hand_size); // draws tiles for size of hand
            this->players[i]->add_tiles(new_hand); // adds tiles to hand
            cout << "Player " << i + 1 << " named \"" << new_player << "\", has been added." << endl;

            num_human_players++;
        }
        else
        {
            cout << "Invalid response, defaulting to human player." << endl;
            shared_ptr<Player> new_player_ptr = make_shared<HumanPlayer>(new_player, this->hand_size);
            this->players.push_back(new_player_ptr);

            // give this new HumanPlayer a hand
            vector<TileKind> new_hand = this->tile_bag.remove_random_tiles(this->hand_size); // draws tiles for size of hand
            this->players[i]->add_tiles(new_hand); // adds tiles to hand
            cout << "Player " << i + 1 << " named \"" << new_player << "\", has been added." << endl;

            num_human_players++;
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
}

// Game Loop should cycle through players and get and execute that players move
// until the game is over.
void Scrabble::game_loop() {
    // this is called after instantiating and creating all of the players to  be made
    // this should constantly loop these players until a finish conditional is met
    // for each player iteration, we should do player::get_move()
    // this creates a Move object, which we've already checked if it is legit in get_move() im assuming bc of board and dictioary being parameteres for get_move()
    // afterwards, since we now know this move is legal, we should alter the board object that scrabble has and as we alter this board,
    // we should be applying any of the board bonuses here
    // update scores, keep iterating etc
    size_t consecutive_pass_track = 0;
    bool empty_hand_check = false;

    while(consecutive_pass_track != num_human_players || empty_hand_check == false)
    {
        for(size_t i = 0; i < this->players.size(); i++)
        {
            Move curr_move;
            try
            {
                curr_move = this->players[i]->get_move(this->board, this->dictionary);
            }
            catch (CommandException& error)
            {
                cerr << error.what() << endl;
                i--;
                break;
            }
            
            // cerr << "get_move was successful, back in scrabble game_loop" << endl;            

            if(curr_move.kind == MoveKind::PASS)
            {
                // cerr << "User successfully made a move with PASS" << endl;
                if(this->players[i]->is_human() == true)
                {
                    consecutive_pass_track++;
                }
                if(consecutive_pass_track == num_human_players)
                {
                    break; // will exit while loop as well
                }
            }
            else // when the move is NOT a pass and breaks the chain
            {
                consecutive_pass_track = 0; // reset the tracker
            }

            if(curr_move.kind == MoveKind::PLACE)
            {
                PlaceResult move_result_validity_check = board.test_place(curr_move);
                if(move_result_validity_check.valid == false)
                {
                    cerr << move_result_validity_check.error << endl;
                    i--;
                    continue;
                }

                // cerr << "User successfully made a move with PLACE" << endl;
                size_t original_score = players[i]->get_points();

                // cerr << "Move is being placed into board. " << endl << endl;
                PlaceResult place_move_result = board.place(curr_move);

                this->players[i]->remove_tiles(curr_move.tiles);

                if(players[i]->count_tiles() == 0)
                {
                    place_move_result.points += 50;
                    empty_hand_check = true;
                }
                this->players[i]->add_points(place_move_result.points);
                
                size_t draw_size = curr_move.tiles.size(); // want to draw from TileBag same number of tiles that we placed down
                
                // CHECK IF THERE ARE ENOUGH TILES IN THE TILE_BAG

                vector<TileKind> draw_vector = this->tile_bag.remove_random_tiles(draw_size);
                this->players[i]->add_tiles(draw_vector); // adds the drawn tiels to the player's hand

                cout << "You gained " << SCORE_COLOR << (players[i]->get_points() - original_score) << rang::style::reset << " points!" << endl;
            }
            else if(curr_move.kind == MoveKind::EXCHANGE)
            {
                // cerr << "User successfully made a move with EXCHANGE" << endl;
                size_t exchange_count = curr_move.tiles.size();
                for(size_t i = 0; i < exchange_count; i++)
                {
                    this->tile_bag.add_tile(curr_move.tiles[i]);
                }
                this->players[i]->remove_tiles(curr_move.tiles);
                vector<TileKind> draw_tiles = this->tile_bag.remove_random_tiles(exchange_count);
                this->players[i]->add_tiles(draw_tiles);
            }
            cout << "Your current score: " << SCORE_COLOR << this->players[i]->get_points() << rang::style::reset << endl;
            cout << endl << "Press [enter] to continue.";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
    }
}

// Performs final score subtraction. Players lose points for each tile in their
// hand. The player who cleared their hand receives all the points lost by the
// other players.
void Scrabble::final_subtraction(vector<shared_ptr<Player>> & plrs) {
    // TODO: implement this method.
    // Do not change the method signature.
    // Needs to check if and which player had the cleared hand
    // If the player has not cleared hand, subtract points worth whatever is left in their hand
    // add up all these points, give it to the player with the cleared hand
    size_t cleared_player_index = 0;
    bool cleared_check = false;
    size_t sum = 0;

    for(size_t i = 0; i < plrs.size(); i++)
    {
        if(plrs[i]->get_hand_value() == 0) // CLEARED HAND
        {
            cleared_check = true;
            cleared_player_index = i;
        }
        else // everyone else
        {
            sum += plrs[i]->get_hand_value(); // add the player's hand value to the total sum to be given to the cleared player
            if(plrs[i]->get_points() > plrs[i]->get_hand_value()) // we have enough points to subtract the entire hand
            {
                plrs[i]->subtract_points(plrs[i]->get_hand_value());
            }
            else // do not enough points to subtract the entire hand; make the points 0
            {
                plrs[i]->subtract_points(plrs[i]->get_points());
            }
        }
    }

    if(cleared_check == true)
    {
        plrs[cleared_player_index]->add_points(sum);
    }
}

// You should not need to change this function.
void Scrabble::print_result() {
	// Determine highest score
    size_t max_points = 0;
	for (auto player : this->players) {
		if (player->get_points() > max_points) {
			max_points = player->get_points();
        }
	}

	// Determine the winner(s) indexes
	vector<shared_ptr<Player>> winners;
	for (auto player : this->players) {
		if (player->get_points() >= max_points) {
			winners.push_back(player);
        }
	}

    cout << (winners.size() == 1 ? "Winner:" : "Winners: ");
	for (auto player : winners) {
		cout << SPACE << PLAYER_NAME_COLOR << player->get_name();
	}
	cout << rang::style::reset << endl;

	// now print score table
    cout << "Scores: " << endl;
    cout << "---------------------------------" << endl;

	// Justify all integers printed to have the same amount of character as the high score, left-padding with spaces
    cout << setw(static_cast<uint32_t>(floor(log10(max_points) + 1)));

	for (auto player : this->players) {
		cout << SCORE_COLOR << player->get_points() << rang::style::reset << " | " << PLAYER_NAME_COLOR << player->get_name() << rang::style::reset << endl;
	}
}

// You should not need to change this.
void Scrabble::main() {
    add_players();
    game_loop();
    final_subtraction(this->players);
    print_result();
}
