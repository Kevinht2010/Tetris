#include <vector>
#include <iostream>
#include "Game_Logic.h"
#include "Main_Piece.h"
#include "I_Block.h"
#include "J_Block.h"
#include "L_Block.h"
#include "O_Block.h"
#include "S_Block.h"
#include "T_Block.h"
#include "Z_Block.h"

vector<vector<char>> Board; 
vector<int> Row_Fullness;

int main(void)
{
	Board.resize = 29;

	for (int i = 0; i < 29; i++)
	{
		Board[i] = { 'o', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'o' };
	}

	
}