#include <vector>
#include <iostream>
#include "Main_Piece.h"

class L_Block : public Piece
{
public: 

	L_Block(vector<int> Position);

	void Rotate();

	bool Rotate_Test(vector<vector<char>> Board);
};