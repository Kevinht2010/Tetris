#include <vector>
#include <iostream> 
#include "Functions.h"
#pragma once
using namespace std;

class Piece
{
public:

	char color; 

	vector<int> main;
	vector<int> rel_1;
	vector<int> rel_2;
	vector<int> rel_3;

	int orientation;
	void Slide_Right();
	void Slide_Left();
	void Drop();
	void Hard_Drop(vector<vector<char>> Board);

	bool Movement_Check(vector<vector<char>> Board, char cmd);

	bool Movement_Check_Helper(vector<int> newmain, vector<int> new_rel_1, vector<int> new_rel_2, vector<int> new_rel_3, vector<vector<char>> Board);

	bool Movement(vector<vector<char>> Board, char cmd);

	virtual void Rotate();

	virtual bool Rotate_Test(vector<vector<char>> Board);
};