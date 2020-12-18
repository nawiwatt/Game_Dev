#include<iostream>
#include"entity.h"
#include"object.h"
#include"enemy.h"
enemy::enemy()
{
	rect.setSize(sf::Vector2f(64, 64));
	rect.setFillColor(sf::Color::Green);
	sprite.setScale(2, 2);
	//sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
	sprite.setOrigin(16, 16);
	diesprite.setScale(2, 2);
	diesprite.setOrigin(16, 16);
	hpbar.setSize(sf::Vector2f(60, 7));
	hpbar.setFillColor(sf::Color::Green);
}
void enemy::update()
{
	hpbar.setSize(sf::Vector2f(60 - 60 * (totalhp - hp) / totalhp, 7));
	hpbar.setPosition(rect.getPosition().x, rect.getPosition().y - 35);
	if (alive == false)
	{
		diesprite.setPosition(rect.getPosition());
	}
	else
	{
		sprite.setPosition(rect.getPosition());
	}
}

void enemy::updatemovement()
{

	runtimecount ++;
	if (runtimecount >= typemovement)
	{
		runtime++;
		runtimecount = 0;
	}
	if (runtime >= runtimelimit )
	{
		runtime = 0;
		runtimelimit = 9;
		if (useskill == true)
		{
			enemytype--;
			canuseskill = true;
			useskill = false;
		}
	}
	directioncooldown++;
	if (directioncooldown >= runcooldown)
	{
		if (enemytype == 1)
		{
			direction = 3;
		}
		else
		{
			direction = generateRandom(0, 5);
		}
		
		directioncooldown = 0;
	}
	if (enemytype == 4)
	{
		skillcooldown++;
	}
	if (skillcooldown >= 2000 && walkable == false)
	{
		skillable = true;
		skillcooldown = 0;
	}
	if (rect.getPosition().x <= 1130 && enemytype == 4 && walkable == true && gameEnd == false)
	{
		walkable = false;
	}
	if (skillable == true)
	{
		enemytype++;
		runtime = 0;
		runtimelimit = 4;
		useskill = true;
		skillable = false;
	}
	if (rect.getPosition().x >= -100 && direction > 1 && walkable == true)
	{
			rect.move(-movespeed, 0 );
			sprite.setTextureRect(sf::IntRect(64 * runtime, 64*enemytype, 64, 64));
	}
	else if(useskill == true)
	{
		sprite.setTextureRect(sf::IntRect(64 * runtime, 64 * enemytype, 64, 64));
	}
	else 
	{
		sprite.setTextureRect(sf::IntRect(0, 64 * enemytype, 64, 64));
	}
}

void enemy::enemydie()
{
	runtimecount++;
	if (runtimecount >= 30 && runtime < 10)
	{
		runtime++;
		runtimecount = 0;
	}
	if (runtime >= 10)
	{
		died = true;
	}
	diesprite.setTextureRect(sf::IntRect(64 * runtime, 64*enemytype, 64, 64));
}


void enemy::typeupdate()
{
	if (enemytype == 0)
	{
		movespeed = 0.1;
		coindropmax = 10;
		powerdropchance = 20;
		totalhp = 60 * difficulty / 100;
		//hp = 200;
		typemovement = 35;
		runcooldown = 200;
		damage = 10;
		bloodrop = 20;
		bloodbonus = 1;
	}
	else if (enemytype == 1)
	{
		movespeed = 0.15;
		coindropmax = 12;
		powerdropchance = 15;
		totalhp = 30 * difficulty / 100;
		//hp = 150;
		typemovement = 15;
		runcooldown = 180;
		damage = 10;
		bloodrop = 25;
		bloodbonus = 1;
	}
	else if (enemytype == 2)
	{
		movespeed = 0.05;
		coindropmax = 20;
		powerdropchance = 15;
		totalhp = 150 * difficulty / 100;
		//hp = 500;
		typemovement = 40;
		runcooldown = 300;
		damage = 20;
		bloodrop = 40;
		bloodbonus = 2;
	}
	else if (enemytype == 3)
	{
		movespeed = 0.1;
		coindropmax = 15;
		powerdropchance = 15;
		totalhp = 50 * difficulty / 100;
		//hp = 200;
		typemovement = 35;
		runcooldown = 200;
		damage = 10;
		bloodrop = 30;
		bloodbonus = 1;
	}
	else if (enemytype == 4)
	{
		movespeed = 0.1;
		coindropmax = 25;
		powerdropchance = 10;
		totalhp = 80 * difficulty / 100;
		//hp = 200;
		typemovement = 35;
		runcooldown = 200;
		damage = 10;
		bloodrop = 50;
		bloodbonus = 5;
	}
}