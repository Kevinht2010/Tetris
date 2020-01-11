#include<vector>
#include<iostream>

using namespace std; 

char Get_Char(vector<int> Position, vector<vector<char>> Board)
{
	return (Board[Position[0]][Position[1]]);
}


