#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"entity.h"
#include"object.h"
class movemap : public entity
{
public:
	float movespeed = 0.6;
	int mapcap = 0;
	int runtime=0;
	int runtimecount = 0;
	movemap();
	void update();
};
