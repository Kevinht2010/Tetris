#include <vector>
#include <iostream>
#include "Main_Piece.h"

using namespace std; 

void Update_Piece(vector<vector<char>>* Board, Piece Block)
{
	(*Board)[Block.main[0]][Block.main[1]] = Block.color;
	(*Board)[Block.rel_1[0]][Block.rel_1[1]] = Block.color;
	(*Board)[Block.rel_2[0]][Block.rel_2[1]] = Block.color;
	(*Board)[Block.rel_3[0]][Block.rel_3[1]] = Block.color;
}

void Delete_Piece(vector<vector<char>>* Board, Piece Block)
{
	(*Board)[Block.main[0]][Block.main[1]] = ' ';
	(*Board)[Block.rel_1[0]][Block.rel_1[1]] = ' ';
	(*Board)[Block.rel_2[0]][Block.rel_2[1]] = ' ';
	(*Board)[Block.rel_3[0]][Block.rel_3[1]] = ' ';
}

void Update_Row_Fullness(vector<int>* Row_Fullness, Piece Block)
{
	++(*Row_Fullness)[Block.main[0]]; 
	++(*Row_Fullness)[Block.rel_1[0]];
	++(*Row_Fullness)[Block.rel_2[0]];
	++(*Row_Fullness)[Block.rel_3[0]];
}

void Shift_Down_Board(vector<vector<char>>* Board, int row_number)
{
	for (int i = row_number; i > 0; i--)
	{
		(*Board)[i] = (*Board)[i - 1];
	}

	(*Board)[0] = { 'o', ' ', ' ', ' ', ' ', ' ', ' ' , ' ' , ' ' , ' ', ' ', 'o' };
}

void Shift_Down_RowFullness(vector<int>* Row_Fullness, int row_number)
{
	for (int i = row_number; i > 0; i--)
	{
		(*Row_Fullness)[i] = (*Row_Fullness)[i - 1];
	}

	(*Row_Fullness)[0] = 0; 
}

void Update_Board(vector<vector<char>>* Board, vector<int>* Row_Fullness)
{
	for (int i = 0; i < Row_Fullness->size(); i++)
	{
		if ((*Row_Fullness)[i] = 10)
		{
			Shift_Down_Board(Board, i);

			Shift_Down_RowFullness(Row_Fullness, i);
		}
	}
}

void Update_Score(vector<vector<char>>* Board, vector<int>* Row_Fullness, int* score)
{

}

bool Lost(vector<vector<char>> Board)
{

}