#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"entity.h"
class Crate : public entity
{
public:
	sf::CircleShape circle;
	sf::Sprite gunRarity;
	Crate();
	void update();
	void GunCrate();
	bool opened = false;
	bool opendone = false;
	bool ready = true;
	bool bought = false;
	int luck;
	int luck2;
	int rarity ;
	int guntype ;
	int runtime ;
	int runtimecount = 0;
};
