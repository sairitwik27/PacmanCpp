/*
Author: Venkata Sai Ritwik Kotra
Author: Venkata Sai Ritwik Kotra
Description:

Main file for Pacman. Contains rendering code and text.

*/


#include <SFML/graphics.hpp>
#include <random>
#include <time.h>

#include <array>
#include <chrono>
#include <ctime>


#include<iostream>
#include<string>
#include<vector>
#include <windows.h>
#include "Layout.h"

#include "Game.h"


using namespace std;
// Make code easier to type with "using namespace"
using namespace sf;
// This is where our game starts from


int checkKey()
{

	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		return -1;
	}
	if (Keyboard::isKeyPressed(Keyboard::Enter))
	{
		return -2;
	}

}

int main()
{
	bool flag_start{ false }; // to indicate if the game has started
	bool flag_end{ false };
	bool Energizer_eaten{ false };

	Layout makelayout;

	//// Create a video mode object
	VideoMode vm(641, 728);		
	// Create and open a window for the game
	RenderWindow window(vm, "Pacman");	//, Style::Fullscreen
	window.setFramerateLimit(60);


	////////////////////////////////////////////////////////////////////
	sf::Text text;
	sf::Text text_score;
	Font font;
	font.loadFromFile("fonts/KOMIKAB_.ttf");
	// select the font
	text.setFont(font); // font is a sf::Font
	text_score.setFont(font); // font is a sf::Font
	// set the string to display
	text.setString("PRESS ENTER TO START");
	// set the character size
	text.setCharacterSize(30); // in pixels, not points!
	// set the color
	text.setFillColor(sf::Color::White);
	// set the text style
	text.setStyle(sf::Text::Bold);// | sf::Text::Underlined);
	//set position of text
	text.setPosition(175, 300);
	////////////////////////////////////////////////////////////////////

	Game game;	


	while (window.isOpen())
	{
		
		/*
		**************
		Check for enter and escape
		**************
		*/

		int keyFlag = checkKey();

		if (keyFlag == -2)
		{
			flag_start = true;
		}

		if (keyFlag == -1)
		{
			flag_end = true;
		}

/*
**************
Rendering
**************
*/

// Clear everything from the last frame
		window.clear();
		//// Draw our game scene here
		window.draw(game.spriteBg);

		if (flag_end || game.ghostHit || game.coins.size() == 0)
		{


			window.close();

		}

		else
		{
			if (!flag_start)
			{
				window.draw(game.spriteStart);
				window.draw(text);
			}
			if (flag_start)
			{
				game.update();
				for (int i = 0; i < game.walls.size(); i++)
				{
					window.draw(game.walls[i]);
				}
				for (int j = 0; j < game.coins.size(); j++)
				{
					window.draw(game.coins[j]);
				}
				for (int j = 0; j < game.Energizers.size(); j++)
				{
					window.draw(game.Energizers[j]);
				}
				for (int i = 0; i < 4; ++i)
				{
					if (game.ghostValid[i])
					{
						window.draw(game.ghosts[i]);
					}

				}

				window.draw(game.spritePacman);

			}

		}


		// // Show everything we just drew
		window.display();


	}
	return 0;
}