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
	bool slowed = false;
	int runtime = 0;
	float runtimecount = 0;
	float runtimelimit = 12;
	int direction = 2;
	int mymoney = 200;
	int maxpower = 3;
	int mypower = 0;
	int mapcap = 0;
	player();
	void update();
	void updatemovement();
};