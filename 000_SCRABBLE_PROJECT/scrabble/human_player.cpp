#include <sstream>
#include <stdexcept>
#include <vector>
#include <map>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "place_result.h"
#include "move.h"
#include "exceptions.h"
#include "human_player.h"
#include "tile_kind.h"
#include "formatting.h"
#include "rang.h"

using namespace std;


// This method is fully implemented.
inline string& to_upper(string& str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

Move HumanPlayer::get_move(const Board& board, const Dictionary& dictionary) const {
	board.print(cout); // prints board
    this->print_hand(cout); // prints hand
    cout << MOVE_PROMPT_COLOR << "Your move, " << PLAYER_NAME_COLOR << this->get_name() << MOVE_PROMPT_COLOR << ": " << rang::style::reset;
    string move_string;
    getline(cin, move_string); // user input for move
    Move parse_user_move = this->parse_move(move_string); // parses user input string
    
    if(this->tiles_quan_checker(parse_user_move.tiles) == false) // BOTH EXCHANGE AND PLACE NEED TO CHECK IF THERE ARE ENOUGH TILES
    {
        cerr << "You don't have enough tiles for this move. Try again." << endl;
        return this->get_move(board, dictionary);
    }

    if(parse_user_move.kind == MoveKind::PLACE) // place needs to check dictionary, exchange can just return
    {
        PlaceResult test_place_result = board.test_place(parse_user_move);

        for(size_t i = 0; i < test_place_result.words.size(); i++)
        {
            if(dictionary.is_word(test_place_result.words[i]) == false)
            {
                cerr << "Invalid word created from move. Try again." << endl;
                return this->get_move(board, dictionary);
            }
        }
    }
    return parse_user_move;
}

vector<TileKind> HumanPlayer::parse_tiles(string& letters) const{
    // checks non-quantitative availability of necessary tiles in hand and does NOT check validity
    vector<TileKind> tile_vector;
    for(size_t i = 0; i < letters.size(); i++)
    {
        try
        {
            TileKind temp_tile = this->tiles.lookup_tile(letters[i]);
            if(temp_tile.letter == TileKind::BLANK_LETTER)
            {
                temp_tile.points = 0;
                // temp_tile.letter = (letters[i + 1]);
                temp_tile.assigned = tolower(letters[i + 1]);
                i++;
            }
            tile_vector.push_back(temp_tile);
        }
        catch (out_of_range& error)
        {
            throw CommandException("A tile could not be found. Try again."); // Where do i catch it? How can i insure repetition
        }
    }

    // returns successfully compiled vector
    return tile_vector;
}

vector<TileKind> HumanPlayer::parse_tiles_EXCHANGE(string& letters) const{
    // checks non-quantitative availability of necessary tiles in hand and does NOT check validity
    vector<TileKind> tile_vector;
    for(size_t i = 0; i < letters.size(); i++)
    {
        try
        {
            TileKind temp_tile = this->tiles.lookup_tile(letters[i]);
            tile_vector.push_back(temp_tile);
        }
        catch (out_of_range& error)
        {
            throw CommandException("A tile could not be found. Try again."); // Where do i catch it? How can i insure repetition
        }
    }

    // returns successfully compiled vector
    return tile_vector;
}

Move HumanPlayer::parse_move(string& move_string) const {
    // cerr << "Entering parse_move" << endl;
    stringstream ss(move_string);
    string temp;
    ss >> temp;
    // might need to use toopper on temp b/c what if temp is smth like "pAsS"
    to_upper(temp);
    if(temp == "EXCHANGE")
    { 
        // EXCHANGE ABCXYZ
        string exchange_string;
        ss >> exchange_string;
        vector<TileKind> exchange_vector = parse_tiles_EXCHANGE(exchange_string);
        // overloaded constructor with only vector will make exchange
        Move parse_move(exchange_vector);
        return parse_move;
    }
    else if(temp == "PLACE")
    {
        string direction_string, tile_string;
        size_t row, col;
        ss >> direction_string >> row >> col >> tile_string;
        if(direction_string == "|")
        {
            vector<TileKind> tile_string_vector = parse_tiles(tile_string);
            Move parse_move(tile_string_vector, row - 1, col - 1, Direction::DOWN);
            return parse_move;
        }
        else if(direction_string == "-")
        {
            vector<TileKind> tile_string_vector = parse_tiles(tile_string);
            Move parse_move(tile_string_vector, row - 1, col - 1, Direction::ACROSS);
            return parse_move;
        }
        else if(direction_string != "-" || direction_string != "|")
        {
            throw CommandException("Invalid direction inputted. Try again.");
        }
    }
    else if(temp == "PASS")
    {
        // PASS CASE
        Move parse_move;
        return parse_move;
    }
    else if(temp == "")
    {
    }
    else
    {
        throw CommandException("Invalid command. Try again.");
    }

    // PASS CASE
    Move parse_move;
    return parse_move;
}
// This function is fully implemented.
void HumanPlayer::print_hand(ostream& out) const {
	const size_t tile_count = tiles.count_tiles();
	const size_t empty_tile_count = this->get_hand_size() - tile_count;
	const size_t empty_tile_width = empty_tile_count * (SQUARE_OUTER_WIDTH - 1);

	for(size_t i = 0; i < HAND_TOP_MARGIN - 2; ++i) {
		out << endl;
	}

	out << repeat(SPACE, HAND_LEFT_MARGIN) << FG_COLOR_HEADING << "Your Hand: " << endl << endl;

    // Draw top line
    out << repeat(SPACE, HAND_LEFT_MARGIN) << FG_COLOR_LINE << BG_COLOR_NORMAL_SQUARE;
    print_horizontal(tile_count, L_TOP_LEFT, T_DOWN, L_TOP_RIGHT, out);
    out << repeat(SPACE, empty_tile_width) << BG_COLOR_OUTSIDE_BOARD << endl;

    // Draw middle 3 lines
    for (size_t line = 0; line < SQUARE_INNER_HEIGHT; ++line) {
        out << FG_COLOR_LABEL << BG_COLOR_OUTSIDE_BOARD << repeat(SPACE, HAND_LEFT_MARGIN);
        for (auto it = tiles.cbegin(); it != tiles.cend(); ++it) {
            out << FG_COLOR_LINE << BG_COLOR_NORMAL_SQUARE << I_VERTICAL << BG_COLOR_PLAYER_HAND;

            // Print letter
            if (line == 1) {
                out << repeat(SPACE, 2) << FG_COLOR_LETTER << (char)toupper(it->letter) << repeat(SPACE, 2);

            // Print score in bottom right
            } else if (line == SQUARE_INNER_HEIGHT - 1) {
                out << FG_COLOR_SCORE << repeat(SPACE, SQUARE_INNER_WIDTH - 2) << setw(2) << it->points;

            } else {
                out << repeat(SPACE, SQUARE_INNER_WIDTH);
            }
        }
        if (tiles.count_tiles() > 0) {
            out << FG_COLOR_LINE << BG_COLOR_NORMAL_SQUARE << I_VERTICAL;
            out << repeat(SPACE, empty_tile_width) << BG_COLOR_OUTSIDE_BOARD << endl;
        }
    }

    // Draw bottom line
    out << repeat(SPACE, HAND_LEFT_MARGIN) << FG_COLOR_LINE << BG_COLOR_NORMAL_SQUARE;
    print_horizontal(tile_count, L_BOTTOM_LEFT, T_UP, L_BOTTOM_RIGHT, out);
    out << repeat(SPACE, empty_tile_width) << rang::style::reset << endl;
}
