#include <SFML/Graphics.hpp>
#include<vector>
using namespace std;
using namespace sf;

#include "Layout.h"

void Layout::setLayoutInitial(flag_start)
{

	// Create a video mode object
	/*this->vm(641, 728);*/
	// Create and open a window for the game
	this->window = new sf::RenderWindow(sf::VideoMode(641,728), "Pacman");	//, Style::Fullscreen
	//this->window.setFramerateLimit(60);
	Texture textureBackground;
	Texture textureStartup;
	// Load a graphic into the texture
	textureBackground.loadFromFile("graphics/maze.bmp");
	textureStartup.loadFromFile("graphics/pac-man.bmp");
	// Create a sprite
	Sprite spriteBackground;
	Sprite spriteStartup;
	// Attach the texture to the sprite
	spriteBackground.setTexture(textureBackground);
	spriteStartup.setTexture(textureStartup);

	// Set the spriteBackground to cover the screen
	spriteBackground.setPosition(0, 0);

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
}