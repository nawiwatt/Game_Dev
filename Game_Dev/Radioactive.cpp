#include<iostream>
#include"entity.h"
#include"object.h"
#include"Radioactive.h"
radioactive::radioactive()
{
	sprite.setScale(2, 2);
	rect.setSize(sf::Vector2f(100, 90));
}
void radioactive::update()
{
	rect.setPosition(sprite.getPosition().x + 14, sprite.getPosition().y);
	sprite.setTextureRect(sf::IntRect(64 * runtime, 0, 64, 64));
	runtimecount++;
	lifetimecount++;
	if (runtimecount >= 40 && effect == false)
	{
		runtime++;
		runtimecount = 0;
	}
	else if (runtime == 5)
	{
		effect = true;
	}
	if (lifetimecount >= 1800)
	{
		lifetime = false;
	}
}