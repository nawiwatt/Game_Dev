#include"Crate.h"
#include"entity.h"
Crate::Crate()
{
	//rect.setPosition(120, 80);
	circle.setPosition(20, -30);
	circle.setRadius(150);
	circle.setFillColor(sf::Color::Green);
	//rect.setSize(sf::Vector2f(180, 180));
	sprite.setScale(0.8, 0.8);
	sprite.setPosition(150, 110);
	sprite.setTextureRect(sf::IntRect(0, 0, 132, 132));
	gunRarity.setPosition(150, 60);
	gunRarity.setScale(1.8, 1.8);
}
void Crate::update()
{
	if (opened == true && opendone == false&& ready == false)
	{
		sprite.setTextureRect(sf::IntRect(runtime*132, 0, 132, 132));
		if (runtime == 22)
		{
			if(luck <= 2)
			{
				rarity = 4;
			}
			else if (luck <= 6)
			{
				rarity = 3;
			}
			else if (luck <= 18)
			{
				rarity = 2;
			}
			else if (luck <= 42)
			{
				rarity = 1;
			}
			else
			{
				rarity = 0;
			}
			if (luck2 <= 4)
			{
				guntype = 6;
			}
			else if (luck2 <= 11)
			{
				guntype = 4;
			}
			else if (luck2 <= 19)
			{
				guntype = 3;
			}
			else if (luck2 <= 33)
			{
				guntype = 5;
			}
			else if (luck2 <= 48)
			{
				guntype = 2;
			}
			else if (luck2 <= 72)
			{
				guntype = 1;
			}
			else
			{
				guntype = 0;
			}
			opendone = true;
		}
		if (runtime == 24)
		{
			opened = false;
			runtime = 0;
		}
	}
	else
	{
		sprite.setTextureRect(sf::IntRect(0, 0, 132, 132));
	}
	runtimecount++;
	if (runtimecount == 30)
	{
		runtimecount = 0;
		runtime++;
	}
}
void Crate::GunCrate()
{
	gunRarity.setTextureRect(sf::IntRect(rarity*64,guntype*64, 64, 64));
}