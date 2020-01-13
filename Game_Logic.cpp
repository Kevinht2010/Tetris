#include <vector>
#include <iostream>
#include "Main_Piece.h"

using namespace std; 

//Updates the piece onto the board;
void Update_Piece(vector<vector<char>>* Board, Piece Block)
{
	(*Board)[Block.main[0]][Block.main[1]] = Block.color;
	(*Board)[Block.rel_1[0]][Block.rel_1[1]] = Block.color;
	(*Board)[Block.rel_2[0]][Block.rel_2[1]] = Block.color;
	(*Board)[Block.rel_3[0]][Block.rel_3[1]] = Block.color;
}

//Deletes the piece from the board; 
void Delete_Piece(vector<vector<char>>* Board, Piece Block)
{
	(*Board)[Block.main[0]][Block.main[1]] = ' ';
	(*Board)[Block.rel_1[0]][Block.rel_1[1]] = ' ';
	(*Board)[Block.rel_2[0]][Block.rel_2[1]] = ' ';
	(*Board)[Block.rel_3[0]][Block.rel_3[1]] = ' ';
}

//Updates Row Fullness Vector (Use upon piece landing)
void Update_Row_Fullness(vector<int>* Row_Fullness, Piece Block)
{
	++(*Row_Fullness)[Block.main[0]]; 
	++(*Row_Fullness)[Block.rel_1[0]];
	++(*Row_Fullness)[Block.rel_2[0]];
	++(*Row_Fullness)[Block.rel_3[0]];
}

//Deletes a row from the board while shifting the rows above down;
void Shift_Down_Board(vector<vector<char>>* Board, int row_number)
{
	for (int i = row_number; i > 0; i--)
	{
		(*Board)[i] = (*Board)[i - 1];
	}

	(*Board)[0] = { 'o', ' ', ' ', ' ', ' ', ' ', ' ' , ' ' , ' ' , ' ', ' ', 'o' };
}

//Updates Row Fullness Vector (Deletes row_number's row and shifts everything before down
void Shift_Down_RowFullness(vector<int>* Row_Fullness, int row_number)
{
	for (int i = row_number; i > 0; i--)
	{
		(*Row_Fullness)[i] = (*Row_Fullness)[i - 1];
	}

	(*Row_Fullness)[0] = 0; 
}

//Updates the entire board (All full rows are deleted and everything is shifted down; 
void Update_Board(vector<vector<char>>* Board, vector<int>* Row_Fullness)
{
	for (int i = 0; i < Row_Fullness->size(); i++)
	{
		if ((*Row_Fullness)[i] == 10)
		{
			Shift_Down_Board(Board, i);

			Shift_Down_RowFullness(Row_Fullness, i);
		}
	}
}

//Updates Score 
void Update_Score(vector<int> Row_Fullness, int* score)
{
	int rows_cleared = 0; 

	for (int i = 3; i < 28; i++)
	{
		if (Row_Fullness[i] = 10)
		{
			++rows_cleared;
		}
	}

	if (rows_cleared == 0)
	{
	}
	else if (rows_cleared == 1)
	{
		(*score) = (*score) + 40;
	}
	else if (rows_cleared == 2)
	{
		(*score) = (*score) + 100;
	}
	else if (rows_cleared == 3)
	{
		(*score) = (*score) + 400;
	}
	else if (rows_cleared == 4)
	{
		(*score) = (*score) + 1200; 
	}
}

//Checks if Lost; 
bool Lost(vector<int> Row_Fullness)
{
	if (Row_Fullness[0] > 0 || Row_Fullness[1] > 0 || Row_Fullness[2] > 0)
	{
		return false;
	}
	else
	{
		return true; 
	}
}