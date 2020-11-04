#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
class entity
{
public:
	sf::RectangleShape rect;
	sf::Sprite sprite;
	sf::Text text;
	int generateRandom(int min, int max) 
	{
		return rand() % (max - min) + min;
	}
};