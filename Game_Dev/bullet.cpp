#include"bullet.h"
#include"entity.h"
bullet::bullet()
{
	rect.setSize(sf::Vector2f(16, 4));
	rect.setPosition(0,0);
	rect.setFillColor(sf::Color::Green);
}
void bullet::Bullet()
{
	if (direction == 1)
	{
		rect.move(-bulletspeed, 0);
	}
	if (direction == 2)
	{
		rect.move(bulletspeed, 0);
	}
}