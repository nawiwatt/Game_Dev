#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"entity.h"

class Wall : public entity
{
public:
	sf::Sprite hpgui;
	sf::CircleShape hpbar;
	sf::Sprite shield;
	sf::Sprite hammer;
	int runtime = 0;
	int runtimecount = 0;
	int maxhp = 100;
	int hp =100;
	bool repairTool = false;
	bool shieldequip = false;
	bool timeout = false;
	bool life = true;
	int repairCooldown = 0;
	int rad = 50;
	Wall();
	void update();
	void guiupdate();
};
