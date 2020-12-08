#include<iostream>
#include"randompower.h"
#include"entity.h"
powerup::powerup()
{
	sprite.setScale(2, 2);
	sprite.setPosition(80, 690);
	sprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
}
void powerup::update()
{
	if (mypower == 3)
	{
		sprite.setTextureRect(sf::IntRect(0, 0, 96, 32));
	}
	else if (mypower == 2)
	{
		sprite.setTextureRect(sf::IntRect(0, 0, 64, 32));
	}
	else if (mypower == 1)
	{
		sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	}
	else
	{
		sprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
	}
}
void powerup::powerisused()
{
		if (powertype == 1)
		{
			sprite.setTextureRect(sf::IntRect(96, 0, 32, 32));
			infbullet = true;
		}
		else if (powertype == 2)
		{
			sprite.setTextureRect(sf::IntRect(128, 0, 32, 32));
			speedboost = true;
		}
		else if (powertype == 3)
		{
			sprite.setTextureRect(sf::IntRect(160, 0, 32, 32));
			damageup = true;
		}
		else if (powertype == 4)
		{
			sprite.setTextureRect(sf::IntRect(192, 0, 32, 32));
			coinboost = true;
		}
}