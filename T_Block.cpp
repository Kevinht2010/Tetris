#include<vector>
#include<iostream>
#include "T_Block.h"

T_Block::T_Block(vector<int> Position)
{
	color = 'p'; 

	main = { Position[0] - 1, Position[1] };
	rel_1 = { main[0] + 1, main[1] };
	rel_2 = { main[0], main[1] + 1 };
	rel_3 = { main[0] - 1, main[1] };

	orientation = 0; 
}

void T_Block::Rotate()
{
	if (orientation == 0)
	{
		rel_1 = { main[0], main[1] + 1 };
		rel_2 = { main[0] - 1, main[1] };
		rel_3 = { main[0], main[1] - 1};

		orientation = 1; 
	}
	else if (orientation == 1)
	{
		rel_1 = { main[0] - 1, main[1] };
		rel_2 = { main[0], main[1] - 1 };
		rel_3 = { main[0] + 1, main[1] };

		orientation = 2;
	}
	else if (orientation == 2)
	{
		rel_1 = { main[0], main[1] - 1 };
		rel_2 = { main[0] + 1, main[1] };
		rel_3 = { main[0], main[1] + 1 }; 

		orientation = 3;
	}
	else
	{
		rel_1 = { main[0] + 1, main[1] };
		rel_2 = { main[0], main[1] + 1 };
		rel_3 = { main[0] - 1, main[1] };

		orientation = 0;
	}
}

bool T_Block::Rotate_Test(vector<vector<char>> Board)
{
	vector<int> new_rel_1;
	vector<int> new_rel_2;
	vector<int> new_rel_3;

	if (orientation == 0)
	{
		new_rel_1 = { main[0], main[1] + 1 };
		new_rel_2 = { main[0] - 1, main[1] };
		new_rel_3 = { main[0], main[1] - 1 };
	}
	else if (orientation == 1)
	{
		new_rel_1 = { main[0] - 1, main[1] };
		new_rel_2 = { main[0], main[1] - 1 };
		new_rel_3 = { main[0] + 1, main[1] };
	}
	else if (orientation == 2)
	{
		new_rel_1 = { main[0], main[1] - 1 };
		new_rel_2 = { main[0] + 1, main[1] };
		new_rel_3 = { main[0], main[1] + 1 };
	}
	else
	{
		new_rel_1 = { main[0] + 1, main[1] };
		new_rel_2 = { main[0], main[1] + 1 };
		new_rel_3 = { main[0] - 1, main[1] };
	}

	Board[main[0]][main[1]] = ' ';
	Board[rel_1[0]][rel_2[1]] = ' ';
	Board[rel_2[0]][rel_2[1]] = ' ';
	Board[rel_3[0]][rel_3[1]] = ' ';

	return Movement_Check_Helper(main, new_rel_1, new_rel_2, new_rel_3, Board);
}
