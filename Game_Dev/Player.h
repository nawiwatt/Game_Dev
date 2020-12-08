#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"entity.h"
#include"Player.h"
#include"object.h"

class player : public entity
{
public:
	float movespeed = 0.6;
	int runtime = 0;
	float runtimecount = 0;
	float runtimelimit = 12;
	int direction = 2;
	int mymoney = 10000;
	int maxpower = 3;
	int mypower = 3;
	int mapcap = 0;
	player();
	void update();
	void updatemovement();
};