#include<iostream>
#include"map.h"
#include"entity.h"
movemap::movemap()
{
	sprite.setScale(3,3);
}
void movemap::update()
{
	sprite.setPosition(rect.getPosition());
	runtimecount++;
	if (runtimecount == 20)
	{
		runtime++;
		runtimecount = 0;
	}
	if (runtime == 9)
	{
		runtime = 0;
	}
	if (mapcap == 1)
	{
		rect.move(movespeed, 0);
		//sprite.setTextureRect(sf::IntRect(1200, 0, 1200, 800));
	}
	else if (mapcap == 2)
	{
		rect.move(-movespeed, 0);
		//sprite.setTextureRect(sf::IntRect(1200, 0, 1200, 800));
	}
}