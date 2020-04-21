#include <iostream>

int main()
{
	int original_bit = 223; // 11011111;
	int mask = 227; // 11100011;

	int masked_bit = original_bit & mask; // 11000011

	std::cout << "masked bit: " << masked_bit << std::endl;

	int updated_mask = masked_bit | (5 << 2); // (5 << 2) = 10100

	std::cout << "updated mask: " << updated_mask << std::endl; // 11010111

	return 0;
}