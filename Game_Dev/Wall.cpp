#include<iostream>
#include"Totems.h"
#include"Wall.h"

Wall::Wall()
{
	sprite.setScale(1.8, 2);
	rect.setSize(sf::Vector2f(115,512));
	rect.setPosition(330, 100);
	sprite.setPosition(330, 100);
	hpgui.setPosition(410, 638);
	hpgui.setScale(2, 2);
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(40);
	text.setPosition(440, 678);
	hpbar.setPosition(421, 652);
	hpbar.setRadius(50);
	hpbar.setFillColor(sf::Color::Green);
	hammer.setTextureRect(sf::IntRect(256, 0, 64, 64));
	shield.setTextureRect(sf::IntRect(320, 0, 64, 64));
	hammer.setPosition(532, 638);
	shield.setPosition(532, 702);
}
void Wall::update()
{
	if (shieldequip == true)
	{
		maxhp = 150;
	}
	repairCooldown++;
	if (repairCooldown >= 6000 &&repairTool == true && hp < maxhp)
	{
		hp = hp + 10;
		repairCooldown = 0;
	}
	if (hp > maxhp)
	{
		hp = maxhp;
	}
}

void Wall::guiupdate()
{
	if (hp >= 100)
	{
		text.setPosition(440, 678);
		text.setString(std::to_string(hp));
	}
	else if (hp >= 10)
	{
		text.setPosition(448, 678);
		text.setString(std::to_string(hp));
	}
	else
	{
		text.setPosition(460, 678);
		text.setString(std::to_string(hp));
	}
	rad = 50 * hp / maxhp;
	hpbar.setRadius(rad);
	hpbar.setPosition(421 + 50 - rad, 652 + 50 - rad);
}