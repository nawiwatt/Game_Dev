#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"entity.h"
class powerup : public entity
{
public:
	int powertype = 0;
	int mypower = 0;
	bool poweron = false;
	bool coinboost = false;
	bool infbullet = false;
	bool damageup = false;
	bool speedboost = false;
	powerup();
	void update();
	void powerisused();
};