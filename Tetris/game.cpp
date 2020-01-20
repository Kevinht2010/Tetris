#include "game.h"
#include <time.h>

game::game(unsigned int width, unsigned int height) :width(width), height(height), startPos({ 2, 3 }), delay(0.3)
{
	srand(time(0));
	initAry();
}


game::~game()
{
}

void game::initAry(){
	Board.resize(height);
	for (size_t i = 0; i < height; i++)
	{
		Board[i].resize(width);
	}
	Row_Fullness.resize(height);


	//init board
	for (size_t i = 0; i < Board.size(); i++)
	{
		for (size_t j = 0; j < Board[i].size(); j++)
		{
			if (i == Board.size()-1 || j == 0 || j == Board[i].size()-1)

				Board[i][j] = border;
			else
				Board[i][j] = space;

		}
	}

	// init row
	for (size_t i = 0; i < height; i++)
	{
		Row_Fullness[i] = 0;
	}
}


void game::producePiece(unsigned int index){
	switch (index)
	{
	case 0:
		ptr = new I_Block(startPos);
		break;
	case 1:
		ptr = new J_Block(startPos);
		break;
	case 2:
		ptr = new L_Block(startPos);
		break;

	case 3:
		ptr = new O_Block(startPos);
		break;

	case 4:
		ptr = new S_Block(startPos);
		break;
	case 5:
		ptr = new T_Block(startPos);
		break;
	case 6:
		ptr = new Z_Block(startPos);
		break;

	default:
		break;
	}
}


unsigned int game::getRandom(unsigned int range){
	return rand() % 7;
}
void game::updateWhenLanded(){
	color = getRandom(7);
	Update_Row_Fullness(&Row_Fullness, *ptr);
	Update_Piece(&Board, *ptr);
	delete ptr;
	producePiece(color
		);
	Update_Board(&Board, &Row_Fullness, width - 2);
}


bool game::run(){
	RenderWindow window(VideoMode(18 * width, 18 * (height - 1 - HIDDEN_ABOVE)), "The Game!");
	Texture t1, t2, t3;
	t1.loadFromFile("images/tiles.png");
	t2.loadFromFile("images/background.png");
	t3.loadFromFile("images/frame.png");
	producePiece(1);

	Clock clock;
	float timel;
	while (window.isOpen()){
	Event e;
	timel = clock.getElapsedTime().asSeconds();
	clock.restart();
	timer += timel;
	while (window.pollEvent(e))
	{
		if (e.type == Event::Closed)
			window.close();

		if (e.type == Event::KeyPressed)
			if (e.key.code == Keyboard::Up && ptr->Rotate_Test(Board)) ptr->Rotate();
			else if (e.key.code == Keyboard::Left) ptr->Movement(Board,'l');
			else if (e.key.code == Keyboard::Right) ptr->Movement(Board,'r');
			else if (e.key.code == Keyboard::Down) {
				ptr->Hard_Drop(Board);
				updateWhenLanded();
			}

	}

	Sprite s(t1);
	
	if (timer>delay)
	{
		if (!(ptr->Movement(Board, 'd'))){
			updateWhenLanded();
		}

		timer = 0;
	}


		window.clear(Color::White);
		s.setTextureRect(IntRect(color * 18, 0, 18, 18));
		s.setPosition(ptr->main[1] * 18-18, (ptr->main[0]-HIDDEN_ABOVE) * 18);
		window.draw(s);
		s.setPosition(ptr->rel_1[1] * 18 - 18, (ptr->rel_1[0] - HIDDEN_ABOVE) * 18);
		window.draw(s);
		s.setPosition(ptr->rel_2[1] * 18 - 18, (ptr->rel_2[0] - HIDDEN_ABOVE) * 18);
		window.draw(s);
		s.setPosition(ptr->rel_3[1] * 18 - 18, (ptr->rel_3[0] - HIDDEN_ABOVE) * 18);
		window.draw(s);

		for (size_t i = 0; i < width; i++)
		{
			
			for (size_t j = 0; j < height; j++)
			{
				if (Board[j][i] != ' '&&Board[j][i] != 'o')
				{
					if (Board[j][i] <= '6'&&Board[j][i]>='0')
					{
						s.setTextureRect(IntRect((Board[j][i]-'0') * 18, 0, 18, 18));
						s.setPosition(i * 18 - 18, (j-HIDDEN_ABOVE) * 18);
						window.draw(s);
					}
					
				}
			}
		}

		if (!Lost(Row_Fullness))
		{
			break;
		}

		window.display();
	}
	return 0;

}