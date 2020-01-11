#include <vector>
#include <iostream>
#include "O_Block.h"

O_Block::O_Block(vector<int> Position)
{
	main = { Position[0], Position[1] };
	rel_1 = { main[0], main[1] + 1 };
	rel_2 = { main[0] - 1, main[1] };
	rel_3 = { main[0] - 1, main[1] - 1 };

	orientation = 0; 
}

void O_Block::Rotate()
{
}

bool O_Block::Rotate_Test(vector<vector<char>> Board)
{
	return true; 
}