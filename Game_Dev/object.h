#pragma once
#include"entity.h"
#include "Player.h"
class object : public entity
{
public:
	float boxspeed = 0;
	sf::RectangleShape rectobject;
	object();
	void update();
	void checkbox();
};