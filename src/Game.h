/*
Author: Venkata Sai Ritwik Kotra

Description:

Game Class, contains ghost and energizers along with a few miscellaneous helper functions

*/

#pragma once

#include<SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <iostream>
#include <vector>
#include <ctime>
#include <random>

#include "Layout.h"

class Game
{
public:
	//Layout init

	Layout layout;

	vector<sf::RectangleShape> walls;
	vector<CircleShape>coins;
	vector<CircleShape>Energizers;

	//Score
	unsigned int score;

	//Sprite
	sf::Sprite spriteStart;
	sf::Sprite spriteBg;
	

	//Textures
	sf::Texture textureStart;
	sf::Texture textureBg;


	//Texts
	sf::Text startText;

	//Font
	sf::Font font;

	Texture texturePacman;

	//Timing 
	clock_t energizeTime;
	bool energized;




	void checkEnergizerEaten();

	void initGhosts();
	void setGhostRandomDirection(int id);
	void moveGhost(int id);
	void checkGhostWallColliding();
	void ghostTunnelling();

	void ghostCollide();

	void initializations();

	void makeLayout();
	void moveSprite();




	//ghosts
	sf::Sprite ghosts[4];
	int ghostDirection[4];
	bool ghostValid[4];
	sf::Sprite spritePacman;
	sf::Texture textureGhost[4];

	bool ghostHit;
	//Accessors
	Game();

	//Functions

	void update();

};

