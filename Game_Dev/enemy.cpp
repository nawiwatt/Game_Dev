#include<iostream>
#include"entity.h"
#include"object.h"
#include"enemy.h"
enemy::enemy()
{
	rect.setSize(sf::Vector2f(64, 64));
	rect.setFillColor(sf::Color::Green);
	sprite.setScale(2, 2);
	sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
}
void enemy::update()
{
	sprite.setPosition(rect.getPosition());
}

void enemy::updatemovement()
{
	direction = generateRandom(0,6);
	if (direction ==1)
	{
			rect.move(-movespeed, 0);
			sprite.setTextureRect(sf::IntRect(64 * runtime, 0, 64, 64));
	}
	else if (direction==2)
	{
			rect.move(movespeed, 0);
			sprite.setTextureRect(sf::IntRect(64 * runtime, 64, 64, 64));
	}
	else if (direction==3)
	{
			rect.move(0, -movespeed);
			sprite.setTextureRect(sf::IntRect(64 * runtime, 0, 64, 64));
	}
	else if (direction==4)
	{
			rect.move(0, movespeed);
			sprite.setTextureRect(sf::IntRect(64 * runtime, 64, 64, 64));
	}
	else
	{
		sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
	}
	runtimecount++;
	if (runtimecount == 100)
	{
		runtime++;
		runtimecount = 0;
	}
	if (runtime == 9)
	{
		runtime = 0;
		direction = generateRandom(0,6);
	if (direction ==1)
	{
			rect.move(-movespeed, 0);
			sprite.setTextureRect(sf::IntRect(64 * runtime, 0, 64, 64));
	}
	else if (direction==2)
	{
			rect.move(movespeed, 0);
			sprite.setTextureRect(sf::IntRect(64 * runtime, 64, 64, 64));
	}
	else if (direction==3)
	{
			rect.move(0, -movespeed);
			sprite.setTextureRect(sf::IntRect(64 * runtime, 0, 64, 64));
	}
	else if (direction==4)
	{
			rect.move(0, movespeed);
			sprite.setTextureRect(sf::IntRect(64 * runtime, 64, 64, 64));
	}
	else
	{
		sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
	}
	}
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		
		if (rect.getPosition().x >= 100)
		{
			rect.move(-movespeed, 0);
			sprite.setTextureRect(sf::IntRect(64 * runtime, 0, 64, 64));
			direction = 1;
		}
		else
		{
			sprite.setTextureRect(sf::IntRect(64 * runtime, 0, 64, 64));
			direction = 1;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (rect.getPosition().x <= 972)
		{
			rect.move(movespeed, 0);
			sprite.setTextureRect(sf::IntRect(64 * runtime, 64, 64, 64));
			direction = 2;
		}
		else
		{
			sprite.setTextureRect(sf::IntRect(64 * runtime, 64, 64, 64));
			direction = 2;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (rect.getPosition().y >= 50)
		{
			rect.move(0, -movespeed);
			sprite.setTextureRect(sf::IntRect(64 * runtime, 0, 64, 64));
			direction = 1;
		}
		else
		{
			sprite.setTextureRect(sf::IntRect(64 * runtime, 0, 64, 64));
			direction = 1;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (rect.getPosition().y <= 622)
		{
			rect.move(0, movespeed);
			sprite.setTextureRect(sf::IntRect(64 * runtime, 64, 64, 64));
			direction = 2;
		}
		else
		{
			sprite.setTextureRect(sf::IntRect(64 * runtime, 64, 64, 64));
			direction = 2;
		}
	}
	else
	{
		sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
	}
	runtimecount++;
	if (runtimecount == 100)
	{
		runtime++;
		runtimecount = 0;
	}
	if (runtime == 9)
	{
		runtime = 0;
	}*/
}