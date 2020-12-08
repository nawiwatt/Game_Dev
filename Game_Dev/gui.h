#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"entity.h"
class maingui : public entity
{
public:
	maingui();
	sf::Sprite topgui;
	sf::Sprite guicoin;
	sf::Sprite weapongui;
	sf::Sprite weaponingui;
	int rarity = 1;
	void update();
};