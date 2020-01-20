#include "Game_Logic.h"
#include "I_Block.h"
#include "J_Block.h"
#include "L_Block.h"
#include "O_Block.h"
#include "S_Block.h"
#include "Z_Block.h"
#include "T_Block.h"
#include <SFML/Graphics.hpp>
#pragma once
using namespace sf;

#define border 'o'
#define shape0 '0'
#define shape1 '1'
#define shape2 '2'
#define shape3 '3'
#define shape4 '4'
#define shape5 '5'
#define shape6 '6'
#define shape7 '7'
#define space ' '

class game
{
private:
	vector<vector<char>> Board;
	vector<int> Row_Fullness;
	void initAry(); //init Board and row fullness ary
	unsigned int getRandom(unsigned int range);//get a number between 0 - range
	void producePiece(unsigned int index); // get a random piece
	Piece* ptr;
	unsigned int width;
	unsigned int height;
	vector<int> startPos;
	void updateWhenLanded();
	void drop();
	float timer;
	float delay;
public:
	bool run(); // run the game
	game(unsigned int width, unsigned int height);
	~game();
};

