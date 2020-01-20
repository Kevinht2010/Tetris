#include <vector>
#include <iostream>
#include "Main_Piece.h"

class Z_Block : public Piece
{
public: 

	Z_Block(vector<int> Position);

	void Rotate();

	bool Rotate_Test(vector<vector<char>> Board);
};