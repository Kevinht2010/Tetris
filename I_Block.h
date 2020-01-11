#include <vector>
#include <iostream>
#include "Main_Piece.h"

class I_Block : public Piece
{
	I_Block(vector<int> Position);

	void Rotate();

	bool Rotate_Test(vector<vector<char>> Board);
};