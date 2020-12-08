#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"entity.h"
class textdisplay : public entity
{
public:
	std::string stringtext  ;
	int lifetime = 100;
	int counter = 0;
	int moneydrop = 0;
	int moneydropmax = 0;
	bool checkmoneydrop = false;
	int powerdrop = 0;
	bool checkpowerdrop = false;
	bool textend = false;
	textdisplay();
	void update();
	void dropupdate();
};
