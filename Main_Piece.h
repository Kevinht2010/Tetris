#include <vector>
#include <iostream> 
#include "Functions.h"

using namespace std;

class Piece
{
protected:

	vector<int> main;
	vector<int> rel_1;
	vector<int> rel_2;
	vector<int> rel_3;

	int orientation;

public:

	void Slide_Right();
	void Slide_Left();
	void Drop();

	bool Movement_Check(vector<vector<char>> Board, char cmd);

	bool Movement_Check_Helper(vector<int> newmain, vector<int> new_rel_1, vector<int> new_rel_2, vector<int> new_rel_3, vector<vector<char>> Board);

	virtual void Rotate(vector<vector<char>> Board);

	virtual bool Rotate_Test(vector<vector<char>> Board);

};