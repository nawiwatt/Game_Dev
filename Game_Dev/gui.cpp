#include<iostream>
#include"gui.h"
#include"entity.h"
maingui::maingui()
{
	rect.setSize(sf::Vector2f(0, 0));
}
void maingui::update()
{
	sprite.setPosition(rect.getPosition());
	if (rarity == 1)
	{
		weapongui.setTextureRect(sf::IntRect(0, 0, 96, 64));
	}
	else if (rarity == 2)
	{
		weapongui.setTextureRect(sf::IntRect(96, 0, 96, 64));
	}
	else if (rarity == 3)
	{
		weapongui.setTextureRect(sf::IntRect(192, 0, 96, 64));
	}
	else if (rarity == 4)
	{
		weapongui.setTextureRect(sf::IntRect(288, 0, 96, 64));
	}
	else if (rarity == 5)
	{
		weapongui.setTextureRect(sf::IntRect(384, 0, 96, 64));
	}
}