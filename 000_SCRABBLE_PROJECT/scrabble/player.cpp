#include "player.h"

using namespace std;

void Player::add_points(size_t points)
{
	this->points += points;
}

// Subtracts points from player's score
void Player::subtract_points(size_t points)
{
	this->points -= points;
}

size_t Player::get_points() const
{
	return this->points;
}

const std::string& Player::get_name() const
{
	return this->name;
}

// Returns the number of tiles in a player's hand.
size_t Player::count_tiles() const
{
	return this->tiles.count_tiles();
}

// Removes tiles from player's hand.
void Player::remove_tiles(const std::vector<TileKind>& tiles)
{
	for(size_t i = 0; i < tiles.size(); i++)
	{
		this->tiles.remove_tile(tiles[i]);
	}
}

// Adds tiles to player's hand.
void Player::add_tiles(const std::vector<TileKind>& tiles)
{
	for(size_t i = 0; i < tiles.size(); i++)
	{
		this->tiles.add_tile(tiles[i]);
	}
}

// Checks if player has a matching tile.
bool Player::has_tile(TileKind tile)
{
	try
	{
		this->tiles.lookup_tile(tile.letter);
	} 
	catch (out_of_range)
	{
		return false;
	}

	return true;
}

// Returns the total points of all tiles in the players hand.
unsigned int Player::get_hand_value() const
{
	return this->tiles.total_points();
}

size_t Player::get_hand_size() const
{
	return this->hand_size;
}

// gets called in get_move to check if player has right number of tiles we need for the new parse_move
bool Player::tiles_quan_checker(const vector<TileKind>& tiles) const 
{
	// this->tiles and tiles are different
	// this->tiles is the actual player's hand and tiles is the parse_move's tiles
	TileCollection::const_iterator it(this->tiles.cbegin());
	
	// iterate through the player's hand
	// for each tile in the hand, check quantity and decrement it for each matching tile in the parse_move
	// when a quantity hits 0, this means player does not have enough tiles to complete the move
	for(it = this->tiles.cbegin(); it != this->tiles.cend(); it++)
	{
		size_t curr_letter_count = this->tiles.count_tiles(*it);
		for(size_t i = 0; i < tiles.size(); i++)
		{
			if(*it == tiles[i]) // if the current tile we are on has a match in parse_move
			{
				if(curr_letter_count > 0)
				{
					curr_letter_count--; // decrement the letter count
				}
				else
				{
					return false; // when the count is 0, this function will return false
				}
			}
		}
	}

	return true;
}