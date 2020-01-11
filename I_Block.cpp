#include <vector>
#include <iostream>
#include "I_Block.h"

I_Block::I_Block(vector<int> Position)
{
	orientation = 0; 

	main[0] = Position[0];
	main[1] = Position[1];

	rel_1[0] = main[0] - 1;
	rel_1[1] = main[1];

	rel_2[0] = main[0] - 2;
	rel_2[1] = main[1];

	rel_3[0] = main[0] - 3;
	rel_3[1] = main[1]; 
}

void I_Block::Rotate()
{
	if (orientation == 0)
	{
		main = { main[0] - 1, main[1] + 2 };
		rel_1 = { main[0], main[1] - 1 };
		rel_2 = { main[0], main[1] - 2 };
		rel_3 = { main[0], main[1] - 3 };

		orientation = 1; 
	}
	else if (orientation == 1)
	{
		main = { main[0] - 2, main[1] - 1 };
		rel_1 = { main[0] + 1, main[1] };
		rel_2 = { main[0] + 2, main[1] };
		rel_3 = { main[0] + 3, main[1] }; 

		orientation = 2; 
	}
	else if (orientation == 2)
	{
		main = { main[0] + 1, main[1] - 2 };
		rel_1 = { main[0], main[1] + 1 };
		rel_1 = { main[0], main[1] + 2 };
		rel_2 = { main[0], main[1] + 3 };

		orientation = 3; 

	}
	else if (orientation == 3)
	{
		main = { main[0] + 2, main[1] + 1 };
		rel_1 = { main[0] - 1, main[1] };
		rel_2 = { main[0] - 2, main[1] };
		rel_3 = { main[0] - 3, main[1] };

		orientation = 0; 
	}
}

bool I_Block::Rotate_Test(vector<vector<char>> Board)
{
	vector<int> newmain;
	vector<int> new_rel_1;
	vector<int> new_rel_2;
	vector<int> new_rel_3;

	if (orientation == 0)
	{
		newmain = { main[0] - 1, main[1] + 2 };
		new_rel_1 = { main[0], main[1] - 1 };
		new_rel_2 = { main[0], main[1] - 2 };
		new_rel_3 = { main[0], main[1] - 3 };
	}
	else if (orientation == 1)
	{
		newmain = { main[0] - 2, main[1] - 1 };
		new_rel_1 = { main[0] + 1, main[1] };
		new_rel_2 = { main[0] + 2, main[1] };
		new_rel_3 = { main[0] + 3, main[1] };
	}
	else if (orientation == 2)
	{
		newmain = { main[0] + 1, main[1] - 2 };
		new_rel_1 = { main[0], main[1] + 1 };
		new_rel_1 = { main[0], main[1] + 2 };
		new_rel_2 = { main[0], main[1] + 3 };

	}
	else 
	{
		newmain = { main[0] + 2, main[1] + 1 };
		new_rel_1 = { main[0] - 1, main[1] };
		new_rel_2 = { main[0] - 2, main[1] };
		new_rel_3 = { main[0] - 3, main[1] };
	}

	Board[main[0]][main[1]] = ' ';
	Board[rel_1[0]][rel_2[1]] = ' ';
	Board[rel_2[0]][rel_2[1]] = ' ';
	Board[rel_3[0]][rel_3[1]] = ' ';

	return Movement_Check_Helper(newmain, new_rel_1, new_rel_2, new_rel_3, Board); 
}
