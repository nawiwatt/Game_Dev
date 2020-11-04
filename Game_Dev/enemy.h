#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"entity.h"
#include"object.h"

class enemy : public entity
{
public:
	float movespeed = 0.1;
	int runtime = 0;
	int runtimecount = 0;
	int direction = 1;
	enemy();
	void update();
	void updatemovement();
};
