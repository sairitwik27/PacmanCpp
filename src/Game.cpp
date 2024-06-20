/*
Author: Venkata Sai Ritwik Kotra

Description:
The methods of Game class. Has movements,ghosts,energizations,initializations,etc

*/

#include "Game.h"

void Game::moveSprite()
{
	if ((this->spritePacman.getPosition().x > 603 && this->spritePacman.getPosition().y > 290) && (this->spritePacman.getPosition().y < 360))
	{
		this->spritePacman.setPosition(19, 310);
		this->spritePacman.move(4.f, 0.f);

	}

	else if ((this->spritePacman.getPosition().x < 27 && this->spritePacman.getPosition().y > 290) && (this->spritePacman.getPosition().y < 360))
	{
		this->spritePacman.setPosition(603, 310);
		this->spritePacman.move(-4.f, 0.f);
	}


	for (int i = 0; i < this->coins.size(); i++)
	{
		if (this->spritePacman.getGlobalBounds().intersects(this->coins[i].getGlobalBounds()))
		{
			this->coins.erase(this->coins.begin() + i);
		}
	}

	int dirFlag = -5;

	if (sf::Keyboard::isKeyPressed(Keyboard::Up))
	{
		dirFlag = 0;
	}

	if (sf::Keyboard::isKeyPressed(Keyboard::Right))
	{
		dirFlag = 1;
	}

	if (sf::Keyboard::isKeyPressed(Keyboard::Down))
	{
		dirFlag = 2;
	}

	if (sf::Keyboard::isKeyPressed(Keyboard::Left))
	{
		dirFlag = 3;
	}


	switch (dirFlag)
	{
	case 0:
	{
		bool contact = false;
		this->spritePacman.move(0, -4.f);
		for (int i = 0; i < this->walls.size(); i++)
		{
			if (this->spritePacman.getGlobalBounds().intersects(this->walls[i].getGlobalBounds()))
			{
				contact = true;
				break;
			}
		}
		if (contact)
		{
			this->spritePacman.move(0.f, 4.f);

		}
		break;
	}


	case 1:
	{
		bool contact = false;
		this->spritePacman.move(4.f, 0.f);
		for (int i = 0; i < this->walls.size(); i++)
		{
			if (this->spritePacman.getGlobalBounds().intersects(this->walls[i].getGlobalBounds()))
			{
				contact = true;
				break;
			}
		}
		if (contact)
		{
			this->spritePacman.move(-4.f, 0.f);

		}
		break;
	}

	case 2:
	{
		bool contact = false;
		this->spritePacman.move(0.f, 4.f);
		for (int i = 0; i < this->walls.size(); i++)
		{
			if (this->spritePacman.getGlobalBounds().intersects(this->walls[i].getGlobalBounds()))
			{
				contact = true;
				break;
			}
		}
		if (contact)
		{
			this->spritePacman.move(0.f, -4.f);
		}
		break;
	}

	case 3:
	{
		bool contact = false;
		this->spritePacman.move(-4.f, 0.f);
		for (int i = 0; i < this->walls.size(); i++)
		{
			if (this->spritePacman.getGlobalBounds().intersects(this->walls[i].getGlobalBounds()))
			{
				contact = true;
				break;
			}
		}
		if (contact)
		{
			this->spritePacman.move(4.f, 0.f);

		}
		break;
	}

	}
}


void Game::makeLayout()
{
	// Setting walls coins and Energizers

	this->walls = this->layout.wallsmake;
	this->coins = this->layout.coins;
	this->Energizers = this->layout.Energizers;
}


void Game::initializations()
{


	//textures and sprites
	this->textureBg.loadFromFile("graphics/maze.bmp");
	this->textureStart.loadFromFile("graphics/pac-man.bmp");
	this->spriteStart.setTexture(this->textureStart);
	this->spriteBg.setTexture(this->textureBg);

	this->texturePacman.loadFromFile("graphics/pacman.bmp");
	this->spritePacman.setTexture(this->texturePacman);
	this->spritePacman.setPosition(Vector2f(302.f, 491.f));
	//font and texts
	this->font.loadFromFile("fonts/KOMIKAB_.ttf");

	this->startText.setFont(this->font);

	//Ghosts
	this->initGhosts();

	for (int i = 0; i < 4; ++i)
	{
		this->setGhostRandomDirection(i);
	}

	//Energized
	this->energized = false;

	//GhostHit
	this->ghostHit = false;

}



Game::Game()
{
	// Constructor
	this->initializations();
	this->makeLayout();
}



void Game::setGhostRandomDirection(int id)
{
	//Randomizing the ghost directions
	if (this->ghostValid[id])
	{
		std::random_device myRandomDevice;
		unsigned seed = myRandomDevice();

		std::default_random_engine generator(seed);
		std::uniform_int_distribution<int> distribution(0, 3);

		this->ghostDirection[id] = distribution(generator);
	}

}


void Game::initGhosts()
{
	//Initializing the 4 ghosts

	this->textureGhost[0].loadFromFile("graphics/orange_ghost.bmp");
	this->ghosts[0].setTexture(this->textureGhost[0]);
	this->ghosts[0].setScale(0.85f, 0.85f);
	this->ghosts[0].setPosition(302, 246);
	this->ghostDirection[0] = -1;
	this->ghostValid[0] = true;

	this->textureGhost[1].loadFromFile("graphics/pink_ghost.bmp");
	this->ghosts[1].setTexture(this->textureGhost[1]);
	this->ghosts[1].setScale(0.85f, 0.85f);
	this->ghosts[1].setPosition(302, 246);
	this->ghostDirection[1] = -1;
	this->ghostValid[1] = true;

	this->textureGhost[2].loadFromFile("graphics/red_ghosts.bmp");
	this->ghosts[2].setTexture(this->textureGhost[2]);
	this->ghosts[2].setScale(0.85f, 0.85f);
	this->ghosts[2].setPosition(302, 246);
	this->ghostDirection[2] = -1;
	this->ghostValid[2] = true;

	this->textureGhost[3].loadFromFile("graphics/blue_ghost.bmp");
	this->ghosts[3].setTexture(this->textureGhost[3]);
	this->ghosts[3].setScale(0.85f, 0.85f);
	this->ghosts[3].setPosition(302, 246);
	this->ghostDirection[3] = -1;
	this->ghostValid[3] = true;


}

void Game::checkEnergizerEaten()
{
	// Checking if the Ghost was eaten

	for (int i = 0; i < Energizers.size(); ++i)
	{
		if (this->spritePacman.getGlobalBounds().intersects(Energizers[i].getGlobalBounds()))
		{
			this->energized = true;
			this->energizeTime = clock();
			this->Energizers.erase(this->Energizers.begin() + i);
		}
	}
}


void Game::ghostCollide()
{

	//Checking Pacman with ghost collision(kills ghost with energizer, kills Pacman without)
	for (int i = 0; i < 4; ++i)
	{
		if (this->ghostValid[i])
		{
			if (this->spritePacman.getGlobalBounds().intersects(this->ghosts[i].getGlobalBounds()))
			{
				clock_t nowTime;
				nowTime = clock();
				if (this->energized)
				{
					if (((nowTime - this->energizeTime) / CLOCKS_PER_SEC) < 5)
					{
						this->ghostValid[i] = false;

					}
					else
					{
						this->energized = false;
					}

				}
				if (!this->energized)
				{
					this->ghostHit = true;

				}



			}
		}
	}


}



void Game::moveGhost(int id)
{
	// Setting ghost moving speed(half the pacman speed)
	if (this->ghostValid[id])
	{
		switch (this->ghostDirection[id])
		{
		case 0:
			this->ghosts[id].move(0.f, -2.f);
			break;
		case 1:
			this->ghosts[id].move(0.f, 2.f);
			break;
		case 2:
			this->ghosts[id].move(-2.f, 0.f);
			break;
		case 3:
			this->ghosts[id].move(2.f, 0.f);
			break;
		}


	}

}

void Game::checkGhostWallColliding()
{

	// Ghost movement upon wall collision

	for (int i = 0; i < 4; i++)
	{

		if (this->ghostValid[i])
		{
			bool contact = false;
			for (int j = 0; j < this->walls.size(); ++j)
			{
				if (this->ghosts[i].getGlobalBounds().intersects(this->walls[j].getGlobalBounds()))
				{
					contact = true;
					break;

				}


			}
			if (contact)
			{
				switch (this->ghostDirection[i])
				{
				case 0:
					this->ghosts[i].move(0.f, 2.f);
					break;

				case  1:
					this->ghosts[i].move(0.f, -2.f);
					break;

				case 2:
					this->ghosts[i].move(2.f, 0.f);
					break;
				case 3:
					this->ghosts[i].move(-2.f, 0.f);
					break;
				}

				this->setGhostRandomDirection(i);



			}



		}
	}
}




void Game::ghostTunnelling()
{
	// Ghost movement for tunneling 
	for (int i = 0; i < 4; ++i)
	{
		if (this->ghostValid[i])
		{
			if ((this->ghosts[i].getPosition().x > 603 && this->ghosts[i].getPosition().y > 290) && (this->ghosts[i].getPosition().y < 360))
			{
					this->ghosts[i].setPosition(28, 310);
					this->ghosts[i].move(2.f, 0.f);
					this->ghostDirection[i] = 3;

			}

			else if ((this->ghosts[i].getPosition().x < 27 && this->ghosts[i].getPosition().y > 290) && (this->ghosts[i].getPosition().y < 360))
			{
				this->ghosts[i].setPosition(602, 310);
				this->ghosts[i].move(-2.f, 0.f);
				this->ghostDirection[i] = 2;
			}

		}
	}

}


void Game::update()
{
	// Calling all the methods together
	this->moveSprite();

	//move ghosts

	this->ghostTunnelling();
	this->checkGhostWallColliding();

	for (int i = 0; i < 4; ++i)
	{
		this->moveGhost(i);
	}

	//Energizer Eaten
	this->checkEnergizerEaten();

	this->ghostCollide();

}