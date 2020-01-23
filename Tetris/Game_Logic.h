#include<vector>
#include "Main_Piece.h"
#include <iostream>
#pragma once
//Updates A Piece Onto a Board
void Update_Piece(vector<vector<char>>* Board, Piece Block);

//Deletes A Piece From a Board
void Delete_Piece(vector<vector<char>>* Board, Piece Block);

//Updates Row Fullness After (Use after block lands)
void Update_Row_Fullness(vector<int>* Row_Fullness, Piece Block);

//Deletes row @ row_number and shifts everything before it down; 
void Shift_Down_Board(vector<vector<char>>* Board, int row_number);

//Deletes row @ row_number and shifts everything before it down;
void Shift_Down_RowFullness(vector<int>* Row_Fullness, int row_number);

//Updates the Score (Use after block lands)
void Update_Score(vector<int> Row_Fullness, unsigned int* score,unsigned int width);

//Uses Shift_Down_Bard and Shift_Down_Row_Fullness to update board (Use after Update_Score
// and Update_Row_Fullness)
void Update_Board(vector<vector<char>>* Board, vector<int>* Row_Fullness,unsigned int size);

//Checks if Lost (Pieces are above the board)
bool Lost(vector<int> Row_Fullness);