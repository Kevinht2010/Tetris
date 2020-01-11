#include <vector>
#include <iostream>
#include "Main_Piece.h"

class S_Block : public Piece
{
public:

	S_Block(vector<int> Position);

	void Rotate();

	bool Rotate_Test(vector<vector<char>> Board);
};