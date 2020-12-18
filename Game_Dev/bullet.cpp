#include"bullet.h"
#include"entity.h"
bullet::bullet()
{
	rect.setSize(sf::Vector2f(12, 3));
	rect.setPosition(0,0);
	rect.setFillColor(sf::Color::Yellow);
	sprite.setScale(0.5, 0.7);
	Lasers.setSize(sf::Vector2f(1500, 1));
	Lasers.setFillColor(sf::Color::Red);
	maggui.setPosition(860, 638);
	lasergui.setPosition(863, 708);
	lasergui.setScale(0.8, 0.8);
}
void bullet::Bullet()
{
	sprite.setPosition(rect.getPosition());
	if (direction == 1 && rect.getPosition().x > 0 )
	{
		rect.move(-bulletspeed, 0);
	}
	else if (direction == 2 && rect.getPosition().x < 1200)
	{
		rect.move(bulletspeed, 0);
	}
	else
	{
		bulletin = false;
	}
}
void bullet::WeaponCheck()
{
	if (weapontype == 1)
	{
		//dmr 1.0
		bulletspeed = 6;
		bulletdamage = 16;
		bulletfirerate = 10;
		reloadspeed = 3;
		weaponmag = 10;
		if (weapondirection == 2)
		{
			gunsprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
		}
		else
		{
			gunsprite.setTextureRect(sf::IntRect(0, 64, 64, 64));
		}
		gungui.setPosition(559, 487);
		gungui.setTextureRect(sf::IntRect(0,0, 64, 64));
		gungui.setScale(6,6);
	}
	else if (weapontype == 2)
	{
		//dmr 1.5
		bulletspeed = 9;
		bulletdamage = 30;
		bulletfirerate = 6;
		reloadspeed = 4;
		weaponmag = 7;
		if (weapondirection == 2)
		{
			gunsprite.setTextureRect(sf::IntRect(64, 0, 64, 64));
		}
		else
		{
			gunsprite.setTextureRect(sf::IntRect(64, 64, 64, 64));
		}
		gungui.setPosition(559, 487);
		gungui.setTextureRect(sf::IntRect(64, 0, 64, 64));
		gungui.setScale(6, 6);
	}
	else if (weapontype == 3)
	{
		//dmr 2
		bulletspeed = 6;
		bulletdamage = 16;
		bulletfirerate = 33;
		reloadspeed = 4;
		weaponmag = 20;
		if (weapondirection == 2)
		{
			gunsprite.setTextureRect(sf::IntRect(128, 0, 64, 64));
		}
		else
		{
			gunsprite.setTextureRect(sf::IntRect(128, 64, 64, 64));
		}
		gungui.setPosition(565, 487);
		gungui.setTextureRect(sf::IntRect(128, 0, 64, 64));
		gungui.setScale(6, 6);
	}
	else if (weapontype == 4)
	{
		//dmr 3.5
		bulletspeed = 7;
		bulletdamage = 20;
		bulletfirerate = 25;
		reloadspeed = 4;
		weaponmag = 35;
		if (weapondirection == 2)
		{
			gunsprite.setTextureRect(sf::IntRect(192, 0, 64, 64));
		}
		else
		{
			gunsprite.setTextureRect(sf::IntRect(192, 64, 64, 64));
		}
		gungui.setPosition(679, 572);
		gungui.setTextureRect(sf::IntRect(192, 0, 64, 64));
		gungui.setScale(3.2, 3.2);
	}
	else if (weapontype == 5)
	{
		//dmr = 3.5
		bulletspeed = 8;
		bulletdamage = 28;
		bulletfirerate = 20;
		reloadspeed = 4;
		weaponmag = 25;
		if (weapondirection == 2)
		{
			gunsprite.setTextureRect(sf::IntRect(256, 0, 64, 64));
		}
		else
		{
			gunsprite.setTextureRect(sf::IntRect(256, 64, 64, 64));
		}
		gungui.setPosition(684, 577);
		gungui.setTextureRect(sf::IntRect(256, 0, 64, 64));
		gungui.setScale(3.1, 3.1);
	}
	else if (weapontype == 6)
	{
		//dmr 3
		bulletspeed = 15;
		bulletdamage = 90;
		bulletfirerate = 3;
		reloadspeed = 5;
		weaponmag = 7;
		if (weapondirection == 2)
		{
			gunsprite.setTextureRect(sf::IntRect(320, 0, 64, 64));
		}
		else
		{
			gunsprite.setTextureRect(sf::IntRect(320, 64, 64, 64));
		}
		gungui.setPosition(692, 600);
		gungui.setTextureRect(sf::IntRect(320, 0, 64, 64));
		gungui.setScale(2.6, 2.6);
	}
	else if (weapontype == 7)
	{
		//dmr 4.5
		bulletspeed = 20;
		bulletdamage = 250;
		bulletfirerate = 2;
		reloadspeed = 6;
		weaponmag = 5;
		if (weapondirection == 2)
		{
			gunsprite.setTextureRect(sf::IntRect(384, 0, 64, 64));
		}
		else
		{
			gunsprite.setTextureRect(sf::IntRect(384, 64, 64, 64));
		}
		gungui.setPosition(702, 607);
		gungui.setTextureRect(sf::IntRect(384, 0, 64, 64));
		gungui.setScale(2.3, 2.3);
	}
}
void bullet::Weaponraritycheck()
{
	if (weaponrarity == 1)
	{
		bulletdamage;
		bulletfirerate;
	}
	else if (weaponrarity == 2)
	{
		if (weapontype == 6 || weapontype == 7)
		{
			bulletdamage *= 2;
		}
		else
		{
			bulletdamage *= 1.4;
			bulletfirerate *= 1.2;
		}
	}
	else if (weaponrarity == 3)
	{
		if (weapontype == 6 || weapontype == 7)
		{
			bulletdamage *= 3.2;
		}
		else
		{
			bulletdamage *= 2;
			bulletfirerate *= 1.4;
		}
	}
	else if (weaponrarity == 4)
	{
		if (weapontype == 6 || weapontype == 7)
		{
			bulletdamage *= 5;
		}
		else
		{
			bulletdamage *= 3;
			bulletfirerate *= 1.6;
		}
	}
	else if (weaponrarity == 5)
	{
		if (weapontype == 6 || weapontype == 7)
		{
			bulletdamage *= 8;
		}
		else
		{
			bulletdamage *= 5;
			bulletfirerate *= 2;
		}
	}
}
void bullet::equipmentcheck()
{
	if (magtype == 1)
	{
		weaponmag;
		reloadspeed;
		maggui.setTextureRect(sf::IntRect(0, 0, 64, 64));
	}
	else if (magtype == 2)
	{
		weaponmag;
		reloadspeed /= 2;
		maggui.setTextureRect(sf::IntRect(64, 0, 64, 64));
	}
	else if (magtype == 3)
	{
		weaponmag *= 2;
		reloadspeed;
		maggui.setTextureRect(sf::IntRect(128, 0, 64, 64));
	}
	else if (magtype == 4)
	{
		weaponmag *= 2;
		reloadspeed /= 2;
		maggui.setTextureRect(sf::IntRect(192, 0, 64, 64));
	}
}