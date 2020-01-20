#include <vector>
#include <iostream> 
#include "Main_Piece.h"
#include "Functions.h"

using namespace std;

void Piece::Slide_Right()
{
	main = { main[0], main[1] + 1 };
	rel_1 = { rel_1[0], rel_1[1] + 1 }; 
	rel_2 = { rel_2[0], rel_2[1] + 1 };
	rel_3 = { rel_3[0], rel_3[1] + 1 }; 
}

void Piece::Slide_Left()
{
	main = { main[0], main[1] - 1 };
	rel_1 = { rel_1[0], rel_1[1] - 1 };
	rel_2 = { rel_2[0], rel_2[1] - 1 };
	rel_3 = { rel_3[0], rel_3[1] - 1 };
}

void Piece::Drop()
{
	main = { main[0] + 1, main[1] };
	rel_1 = { rel_1[0] + 1, rel_1[1] };
	rel_2 = { rel_2[0] + 1, rel_2[1] };
	rel_3 = { rel_3[0] + 1, rel_3[1] };
}

bool Piece::Movement(vector<vector<char>> Board, char cmd){
	if (Movement_Check(Board, cmd)){
		if (cmd=='d')
		{
			Drop();
		}
		if (cmd=='l')
		{
			Slide_Left();
			
		}
		if (cmd=='r')
		{
			Slide_Right();
		}
		return 1;
	}
	return 0;
}

bool Piece::Movement_Check(vector<vector<char>> Board, char cmd)
{
	vector<int> newmain;
	vector<int> new_rel_1;
	vector<int> new_rel_2;
	vector<int> new_rel_3;

	if (cmd == 'd')
	{
		newmain = { main[0] + 1, main[1] };
		new_rel_1 = { rel_1[0] + 1, rel_1[1] };
		new_rel_2 = { rel_2[0] + 1, rel_2[1] };
		new_rel_3 = { rel_3[0] + 1, rel_3[1] };
	}
	else if (cmd == 'l')
	{
		newmain = { main[0], main[1] - 1 };
		new_rel_1 = { rel_1[0], rel_1[1] - 1 };
		new_rel_2 = { rel_2[0], rel_2[1] - 1 };
		new_rel_3 = { rel_3[0], rel_3[1] - 1 };
	}
	else if (cmd == 'r')
	{
		newmain = { main[0], main[1] + 1 };
		new_rel_1 = { rel_1[0], rel_1[1] + 1 };
		new_rel_2 = { rel_2[0], rel_2[1] + 1 };
		new_rel_3 = { rel_3[0], rel_3[1] + 1 };
	}

	// Temporarily change the values @ the original main, rel_1, rel_2, and rel_3 to make it easier to check 
	// Changes won't stick since the board was not malloc'd; 

	Board[main[0]][main[1]] = ' ';
	Board[rel_1[0]][rel_1[1]] = ' ';
	Board[rel_2[0]][rel_2[1]] = ' ';
	Board[rel_3[0]][rel_3[1]] = ' ';

	return Movement_Check_Helper(newmain, new_rel_1, new_rel_2, new_rel_3, Board);
}

bool Piece::Movement_Check_Helper(vector<int> newmain, vector<int> new_rel_1, vector<int> new_rel_2, vector<int> new_rel_3, vector<vector<char>> Board)
{
	char main_val = Get_Char(newmain, Board);
	char new_rel_1_val = Get_Char(new_rel_1, Board);
	char new_rel_2_val = Get_Char(new_rel_2, Board);
	char new_rel_3_val = Get_Char(new_rel_3, Board);

	if ((main_val == ' ') && (new_rel_1_val == ' ') && (new_rel_2_val == ' ') && (new_rel_3_val == ' '))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Piece::Hard_Drop(vector<vector<char>> Board)
{
	while (Movement_Check(Board, 'd') == true)
	{
		Drop(); 
	}
}

void Piece::Rotate()
{
	cerr << "Error" << endl;
}

bool Piece::Rotate_Test(vector<vector<char>> Board)
{
	cerr << "Error" << endl; 
	return NULL; 
}