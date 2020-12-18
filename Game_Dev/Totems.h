#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"entity.h"

class Totems : public entity
{
public:
	int type;
	int runtime = 0;
	int runtimecount = 0;
	int duration = 0;
	bool breakTotem = false;
	bool timeout = false;
	bool life = true;
	Totems();
	void update();
	void typeupdate();
};