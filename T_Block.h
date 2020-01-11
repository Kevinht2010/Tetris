#include <vector>
#include <iostream>
#include "Main_Piece.h"

class T_Block : public Piece
{
public: 

	T_Block(vector<int> Position);

	void Rotate();

	bool Rotate_Test(vector<vector<char>> Board);
};