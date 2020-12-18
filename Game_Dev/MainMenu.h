#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"entity.h"

class MainMenu : public entity
{
public:
	bool modeselected = false;
	sf::Sprite hpgui;
	sf::CircleShape hpbar;
	sf::Sprite shield;
	sf::Sprite hammer;
	sf::Text start;
	sf::Text index;
	sf::Text leaderboard;
	sf::Text exit;
	sf::Text backtext;
	sf::Text easy;
	sf::Text normal;
	sf::Text hard;
	sf::Text confirm;
	sf::Text cancel;
	sf::Text pause;
	sf::Text wave;
	sf::Text mode;
	sf::Text Next;
	sf::Text Input;
	sf::Sprite easysprite;
	sf::Sprite normalsprite;
	sf::Sprite hardsprite;
	bool inputtext = false;
	sf::RectangleShape startRect;
	sf::RectangleShape indexRect;
	sf::RectangleShape leaderRect;
	sf::RectangleShape exitRect;
	sf::RectangleShape backRect;
	sf::RectangleShape easyRect;
	sf::RectangleShape normalRect;
	sf::RectangleShape hardRect;
	sf::RectangleShape confirmRect;
	sf::RectangleShape cancelRect;
	sf::RectangleShape nameRect;
	sf::RectangleShape pauseRect;
	sf::RectangleShape NextRect;
	MainMenu();
	void update();

};
