#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"entity.h"
#include"object.h"
class enemy : public entity
{
public:
	sf::RectangleShape hpbar;
	float movespeed ;
	int runtime = 0;
	int runtimecount = 0;
	int direction = 1;
	int directioncooldown = 0;
	int runcooldown;
	int rank = 0;
	int enemytype;
	bool alive = true;
	bool died = false;
	bool ahead = false;
	int coindropmax ;
	int powerdropchance ;
	int totalhp ;
	int hp ;
	int typemovement;
	enemy();
	void update();
	void updatemovement();
	void enemydie();
	void typeupdate();
};
