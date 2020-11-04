#include"entity.h"
#include"object.h"
#include"Player.h"
object::object()
{
	rectobject.setSize(sf::Vector2f(128, 128));
	rectobject.setPosition(200,200);
	rectobject.setFillColor(sf::Color::Blue);
}
void object::checkbox()
{
	sf::Vector2f boxpos = rectobject.getPosition(); 
	sf::Vector2f boxsize = rectobject.getSize() / 2.0f;
	sf::Vector2f playerpos = rect.getPosition();
	sf::Vector2f playersize = rect.getSize() / 2.0f; 
/*	float deltax = boxpos.x - (playerpos.x + playersize.x);
	float deltay = boxpos.y - (playerpos.y + playersize.y);

	float interx = abs(deltax) - (boxsize.x + playersize.x);
	float intery = abs(deltay) - (boxsize.y + playersize.y);
	
	if (interx < 0.0f || intery < 0.0f)
	{
		
	}*/
	float longx = boxpos.x - playerpos.x + 32;
	float longy = boxpos.y - playerpos.y + 32;
	if (longx - boxsize.x - playersize.x <= 0 || longy - boxsize.y - playersize.y <= 0)
	{
		rect.setPosition(536, 336);
	}
}