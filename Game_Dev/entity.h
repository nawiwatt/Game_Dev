#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
class entity
{
public:
	sf::RectangleShape rect;
	sf::Sprite sprite;
	sf::Text text;
	sf::Sprite diesprite;
	entity();
	int generateRandom(int min, int max);
};