#pragma once
#include"entity.h"
#include"bullet.h"
class bullet : public entity
{
public:
	sf::Sprite gunsprite;
	sf::Sprite gungui;
	sf::Sprite maggui;
	sf::Sprite lasergui;
	sf::RectangleShape Lasers;
	int weapontype = 1;
	int weapondirection = 2;
	int direction = 1;
	bool bulletin = true;
	//weapon
	int weaponrarity = 1;
	float bulletspeed;
	int bulletdamage;
	int bulletfirerate;
	float reloadspeed;
	int weaponmag;
	int magtype = 1;
	bool laserequiped = false;
	int laserdirection = 2;
	bullet();
	void Bullet();
	void WeaponCheck();
	void Weaponraritycheck();
	void equipmentcheck();
};