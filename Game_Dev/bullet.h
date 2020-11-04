#pragma once
#include"entity.h"
#include"bullet.h"
class bullet : public entity
{
public:
	int bulletspeed = 5;
	int damege = 5;
	int direction = 1;

	bullet();
	void Bullet();
};