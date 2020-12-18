#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"entity.h"


class radioactive : public entity
{
public:
	bool effect = false;
	bool lifetime = true;
	int lifetimecount = 0;
	int runtime = 0;
	int runtimecount = 0;
	radioactive();
	void update();
};
