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
#define HIDDEN_ABOVE 4
class game
{
private:
	vector<vector<char>> Board;
	vector<int> Row_Fullness;
	void initAry(); //init Board and row fullness ary
	unsigned int getRandom(unsigned int range);//get a number between 0 - range
	static vector<int> startPos;
	void producePiece(unsigned int index, vector<int> startPos = startPos, Piece*& ptr = ptr); // get a random piece
	static Piece* ptr;
	Piece* backup;
	unsigned int score;
	unsigned int width;
	unsigned int height;
	void updateWhenLanded();
	void drop();
	float timer;
	float delay;
	unsigned int color;
public:
	bool run(); // run the game
	game(unsigned int width, unsigned int height);
	~game();
};

