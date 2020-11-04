#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"entity.h"
#include"Player.h"
#include"object.h"

class player : public entity
{
public:
	float movespeed = 0.3;
	int runtime = 0;
	int runtimecount = 0;
	int direction = 1;
	player();
	void update();
	void updatemovement();
};