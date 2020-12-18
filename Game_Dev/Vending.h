#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"entity.h"
class Vending : public entity
{
public:
	sf::Sprite button1;
	sf::Sprite button2;
	sf::Sprite button3;
	sf::Sprite button4;
	sf::Sprite button5;
	sf::Sprite button6;
	sf::Sprite button7;
	sf::Text text1;
	sf::Text text2;
	sf::Text text3;
	sf::Text text4;
	sf::Text text5;
	sf::Text text6;
	sf::Text text7;
	sf::Sprite gui;
	sf::Sprite mag;
	int magtype = 1;
	bool magbought = false;
	int magprice;
	sf::Sprite laser;
	bool laserbought = false;
	sf::Sprite hammer;
	bool hammerbought = false;
	sf::Sprite shield;
	bool shieldbought = false;
	sf::Sprite gun;
	bool avalible = true;
	sf::Sprite bloodrust;
	bool bloodrustbought = false;
	sf::Sprite breakTotem;
	bool locked = true;
	bool btbought = false;
	bool cratebought = false;
	Vending();
	void update();
	
};