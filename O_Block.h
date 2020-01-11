#include <vector>
#include <iostream>
#include "Main_Piece.h"

class O_Block : public Piece
{
public:

	O_Block(vector<int> Position);

	void Rotate();

	bool Rotate_Test(vector<vector<char>> Board);
};