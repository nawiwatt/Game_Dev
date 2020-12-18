#include<iostream>
#include"Totems.h"
#include"entity.h"

Totems::Totems()
{
	sprite.setScale(2.2, 2.2);
	rect.setSize(sf::Vector2f(44, 80));
}
void Totems::update()
{
	rect.setPosition(sprite.getPosition().x+48, sprite.getPosition().y+32);
	duration++;
	if (breakTotem == true)
	{
		duration ++;
	}
	if (duration >= 3000)
	{
		timeout = true;
	}
	runtimecount++;
	if (runtimecount >= 35)
	{
		if (timeout == true)
		{
			runtime--;
		}
		else
		{
			runtime++;
		}
		runtimecount = 0;
	}
	if (runtime >= 12)
	{
		runtime = 6;
	}
	if (runtime < 0)
	{
		life = false;
	}
	sprite.setTextureRect(sf::IntRect(64 * runtime, 64 * type, 64, 64));
}

void Totems::typeupdate()
{

}