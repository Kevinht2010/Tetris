#include <vector>
#include <iostream>
#include "Main_Piece.h"

class J_Block : public Piece
{
	J_Block(vector<int> Position);

	void Rotate();

	bool Rotate_Test(vector<vector<char>> Board);
};
