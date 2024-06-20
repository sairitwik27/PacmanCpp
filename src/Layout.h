/*
Author: Venkata Sai Ritwik Kotra

Description:

Layout file, lays out the walls and coins

*/

#pragma once

#include <SFML/Graphics.hpp>
#include<vector>
using namespace std;
using namespace sf;

class Layout
{


public:
	sf::RectangleShape rectangle;
	std::vector<sf::RectangleShape> wallsmake;
	std::vector<CircleShape> coins;
	vector<CircleShape>Energizers;


	sf::RenderWindow* window;

	//sf::CircleShape coin;

	Layout()
	{

		rectangle.setSize(sf::Vector2f(10, 10));
		rectangle.setFillColor(sf::Color(30, 200, 240, 0));
		//rectangle.setOutlineThickness(1.f);
		for (int i = 30; i < 600; i += 10)
		{
			rectangle.setPosition(i, 652.5);			// Bottom Wall
			this->wallsmake.push_back(rectangle);
		}

		for (int i = 30; i < 600; i += 10)
		{
			rectangle.setPosition(i, 26.5);		// Top wall
			this->wallsmake.push_back(rectangle);
		}

		for (int i = 420; i <= 650; i += 10)
		{
			rectangle.setPosition(595, i);		//Right Bottom wall
			this->wallsmake.push_back(rectangle);
		}

		for (int i = 420; i <= 650; i += 10)
		{
			rectangle.setPosition(30, i);		// Left Bottom Wall
			this->wallsmake.push_back(rectangle);
		}

		for (int i = 30; i <= 220; i += 10)
		{
			rectangle.setPosition(595, i);		//Right Top wall
			this->wallsmake.push_back(rectangle);
		}

		for (int i = 30; i <= 220; i += 10)
		{
			rectangle.setPosition(30, i);		// Left Top Wall
			this->wallsmake.push_back(rectangle);
		}

		for (int i = 30; i <= 70; i += 10)
		{
			for (int j = 530; j <= 540; j += 10)
			{
				rectangle.setPosition(i, j);		// Left Bottom Hinge
				this->wallsmake.push_back(rectangle);
			}

		}

		for (int i = 555; i <= 595; i += 10)
		{
			for (int j = 530; j <= 540; j += 10)
			{
				rectangle.setPosition(i, j);		// Right Bottom Hinge
				this->wallsmake.push_back(rectangle);
			}
		}

		for (int i = 30; i < 140; i += 10)
		{
			rectangle.setPosition(i, 415);			// Bottom Left Horizontal Wall
			this->wallsmake.push_back(rectangle);
		}

		for (int i = 495; i < 605; i += 10)
		{
			rectangle.setPosition(i, 415);			// Bottom Right Horizontal Wall
			this->wallsmake.push_back(rectangle);
		}

		for (int i = 30; i < 140; i += 10)
		{
			rectangle.setPosition(i, 220);			// Bottom Left Horizontal Wall
			this->wallsmake.push_back(rectangle);
		}

		for (int i = 495; i < 605; i += 10)
		{
			rectangle.setPosition(i, 220);			// Bottom Right Horizontal Wall
			this->wallsmake.push_back(rectangle);
		}

		for (int i = 30; i < 140; i += 10)
		{
			rectangle.setPosition(i, 295);			// Tunnel Top Wall
			this->wallsmake.push_back(rectangle);
		}

		for (int i = 495; i < 605; i += 10)
		{
			rectangle.setPosition(i, 295);			// Tunnel Bottom Wall
			this->wallsmake.push_back(rectangle);
		}

		for (int i = 30; i < 140; i += 10)
		{
			rectangle.setPosition(i, 345);			// Tunnel Top Wall
			this->wallsmake.push_back(rectangle);
		}

		for (int i = 495; i < 605; i += 10)
		{
			rectangle.setPosition(i, 345);			// Tunnel Bottom Wall
			this->wallsmake.push_back(rectangle);
		}


		for (int i = 345; i <= 415; i += 10)
		{
			rectangle.setPosition(495, i);		//Right Top wall
			this->wallsmake.push_back(rectangle);
		}

		for (int i = 345; i <= 415; i += 10)
		{
			rectangle.setPosition(135, i);		// Left Top Wall
			this->wallsmake.push_back(rectangle);
		}

		for (int i = 225; i <= 295; i += 10)
		{
			rectangle.setPosition(495, i);		//Right Top wall
			this->wallsmake.push_back(rectangle);
		}

		for (int i = 225; i <= 295; i += 10)
		{
			rectangle.setPosition(135, i);		// Left Top Wall
			this->wallsmake.push_back(rectangle);
		}

		for (int i = 185; i <= 195; i += 10)
		{
			for (int j = 345; j <= 415; j += 10)
			{
				rectangle.setPosition(i, j);		// Left Middle
				this->wallsmake.push_back(rectangle);
			}
		}

		for (int i = 432; i <= 442; i += 10)
		{
			for (int j = 345; j <= 415; j += 10)
			{
				rectangle.setPosition(i, j);		// Right Middle
				this->wallsmake.push_back(rectangle);
			}
		}

		for (int i = 432; i <= 442; i += 10)
		{
			for (int j = 162; j <= 292; j += 10)
			{
				rectangle.setPosition(i, j);		// Right Bottom Hinge
				this->wallsmake.push_back(rectangle);
			}
		}

		for (int i = 185; i <= 195; i += 10)
		{
			for (int j = 162; j <= 292; j += 10)
			{
				rectangle.setPosition(i, j);		// Right Bottom Hinge
				this->wallsmake.push_back(rectangle);
			}
		}

		for (int i = 197; i <= 257; i += 10)
		{
			for (int j = 221; j <= 231; j += 10)
			{
				rectangle.setPosition(i, j);		// Left Top Hinge
				this->wallsmake.push_back(rectangle);
			}
		}

		for (int i = 370; i <= 430; i += 10)
		{
			for (int j = 221; j <= 231; j += 10)
			{
				rectangle.setPosition(i, j);		// Right Top Hinge
				this->wallsmake.push_back(rectangle);
			}
		}

		for (int i = 85; i <= 255; i += 10)
		{
			for (int j = 591; j <= 601; j += 10)
			{
				rectangle.setPosition(i, j);		// Bottom medium Hinge
				this->wallsmake.push_back(rectangle);
			}
		}

		for (int i = 372; i <= 542; i += 10)
		{
			for (int j = 590; j <= 600; j += 10)
			{
				rectangle.setPosition(i, j);		// Bottom medium Hinge
				this->wallsmake.push_back(rectangle);
			}
		}

		for (int i = 185; i <= 195; i += 10)
		{
			for (int j = 530; j <= 590; j += 10)
			{
				rectangle.setPosition(i, j);		// Bottom medium Hinge
				this->wallsmake.push_back(rectangle);
			}
		}

		for (int i = 430; i <= 440; i += 10)
		{
			for (int j = 530; j <= 590; j += 10)
			{
				rectangle.setPosition(i, j);		// Bottom medium Hinge
				this->wallsmake.push_back(rectangle);
			}
		}

		for (int i = 85; i <= 135; i += 10)
		{
			for (int j = 80; j <= 110; j += 10)
			{
				rectangle.setPosition(i, j);		// Top left box
				this->wallsmake.push_back(rectangle);
			}
		}

		for (int i = 495; i <= 545; i += 10)
		{
			for (int j = 80; j <= 110; j += 10)
			{
				rectangle.setPosition(i, j);		// Top right box
				this->wallsmake.push_back(rectangle);
			}
		}

		for (int i = 370; i <= 440; i += 10)
		{
			for (int j = 80; j <= 110; j += 10)
			{
				rectangle.setPosition(i, j);		// Top right box
				this->wallsmake.push_back(rectangle);
			}
		}

		for (int i = 185; i <= 255; i += 10)
		{
			for (int j = 80; j <= 110; j += 10)
			{
				rectangle.setPosition(i, j);		// Top right box
				this->wallsmake.push_back(rectangle);
			}
		}

		for (int i = 186; i <= 256; i += 10)
		{
			for (int j = 468; j < 488; j += 10)
			{
				rectangle.setPosition(i, j);		// Top right box
				this->wallsmake.push_back(rectangle);
			}
		}

		for (int i = 370; i <= 440; i += 10)
		{
			for (int j = 468; j < 488; j += 10)
			{
				rectangle.setPosition(i, j);		// Top right box
				this->wallsmake.push_back(rectangle);
			}
		}

		for (int i = 83; i <= 133; i += 10)
		{
			for (int j = 160; j < 180; j += 10)
			{
				rectangle.setPosition(i, j);		// Top right box
				this->wallsmake.push_back(rectangle);
			}
		}

		for (int i = 493; i <= 493 + 50; i += 10)
		{
			for (int j = 160; j < 180; j += 10)
			{
				rectangle.setPosition(i, j);		// Top right box
				this->wallsmake.push_back(rectangle);
			}
		}

		for (int i = 250; i <= 380; i += 10)
		{
			for (int j = 530; j < 550; j += 10)
			{
				rectangle.setPosition(i, j);		// Top right box
				this->wallsmake.push_back(rectangle);
			}
		}

		for (int i = 250; i <= 380; i += 10)
		{
			for (int j = 405; j < 425; j += 10)
			{
				rectangle.setPosition(i, j);		// Top right box
				this->wallsmake.push_back(rectangle);
			}
		}

		for (int i = 250; i <= 380; i += 10)
		{
			for (int j = 160; j < 180; j += 10)
			{
				rectangle.setPosition(i, j);		// Top right box
				this->wallsmake.push_back(rectangle);
			}
		}

		for (int i = 309; i <= 319; i += 10)
		{
			for (int j = 550; j < 610; j += 10)
			{
				rectangle.setPosition(i, j);		// Top right box
				this->wallsmake.push_back(rectangle);
			}
		}

		for (int i = 309; i <= 319; i += 10)
		{
			for (int j = 425; j < 485; j += 10)
			{
				rectangle.setPosition(i, j);
				this->wallsmake.push_back(rectangle);
			}
		}

		for (int i = 309; i <= 319; i += 10)
		{
			for (int j = 180; j < 240; j += 10)
			{
				rectangle.setPosition(i, j);		// Top right box
				this->wallsmake.push_back(rectangle);
			}
		}

		for (int i = 309; i <= 319; i += 10)
		{
			for (int j = 38; j < 118; j += 10)
			{
				rectangle.setPosition(i, j);		// Top right box
				this->wallsmake.push_back(rectangle);
			}
		}


		for (int i = 493; i <= 503; i += 10)
		{
			for (int j = 487; j < 547; j += 10)
			{
				rectangle.setPosition(i, j);
				this->wallsmake.push_back(rectangle);
			}
		}

		for (int i = 123; i <= 133; i += 10)
		{
			for (int j = 487; j < 547; j += 10)
			{
				rectangle.setPosition(i, j);
				this->wallsmake.push_back(rectangle);
			}
		}

		for (int i = 85; i <= 135; i += 10)
		{
			for (int j = 468; j < 488; j += 10)
			{
				rectangle.setPosition(i, j);
				this->wallsmake.push_back(rectangle);
			}
		}

		for (int i = 495; i <= 545; i += 10)
		{
			for (int j = 468; j < 488; j += 10)
			{
				rectangle.setPosition(i, j);
				this->wallsmake.push_back(rectangle);
			}
		}

		for (int i = 249; i <= 379; i += 10)
		{
			for (int j = 285; j < 365; j += 10)
			{
				rectangle.setPosition(i, j);
				this->wallsmake.push_back(rectangle);
			}
		}



		///Set coins and Energizers!
		
		CircleShape coin;
		coin.setRadius(2);
		
		CircleShape Energizer;
		Energizer.setRadius(5);

		float coinx, coiny, offset;
		coinx = 42;
		coiny = 37;
		offset = 20.5;


		for (int i = 1; i <= 26; i += 1)
		{
			for (int j = 1; j <= 29; j += 1)
			{
				if (((i <= 5 || i >= 22) && (j > 8 && j < 19)) || ((i >= 7 && i <= 20) && (j > 8 && j < 20)))
					continue;

				if ((i == 1 && j == 3 || i == 1 && j == 22 || i == 26 && j == 3 || i == 26 && j == 22))
				{
					Energizer.setPosition(coinx + i * offset, coiny + j * offset);
					this->Energizers.push_back(Energizer);
				}
				else
				{
					coin.setPosition(coinx + i * offset, coiny + j * offset);
					this->coins.push_back(coin);

				}

			}

		}


		for (int i = 0; i < wallsmake.size(); i++)
		{
			sf::FloatRect bB = wallsmake[i].getGlobalBounds();
			sf::RectangleShape rectangle;
			rectangle.setSize(sf::Vector2f(bB.width + 10, bB.height + 10));
			rectangle.setPosition(bB.left - 5, bB.top - 5);
			for (int j = 0; j < coins.size(); j++)
				if (this->coins[j].getGlobalBounds().intersects(rectangle.getGlobalBounds()))
				{
					this->coins.erase(this->coins.begin() + j);
				}
		}
	}

	//void setLayoutInitial();
};