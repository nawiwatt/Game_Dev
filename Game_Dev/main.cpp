#include<SFML/Graphics.hpp>
#include<iostream>
#include"entity.h"
#include"Player.h"
#include"bullet.h"
#include"object.h"
#include"enemy.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Game dev",sf::Style::Close);
	sf::Texture texture;
	texture.loadFromFile("mainspriterun.png");
	class player Player1;
	sf::Texture textureenemy;
	textureenemy.loadFromFile("run2.png");
	std :: vector <bullet> :: const_iterator iter;
	std :: vector <bullet> bulletArray;
	class bullet bulletprojectile;
	std::vector <enemy> ::const_iterator iter1;
	std::vector <enemy> enemyArray;
	class enemy enemy1;
	enemy1.sprite.setTexture(textureenemy);
	enemy1.rect.setPosition(700, 500);
	enemyArray.push_back(enemy1);
	class object box1;
	Player1.sprite.setTexture(texture); 
	int bulletcount = 0;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{	
				window.close();
				break;
			}
		}
		window.clear();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			bulletprojectile.rect.setPosition(Player1.rect.getPosition().x+44,Player1.rect.getPosition().y + 54);
			bulletprojectile.direction = Player1.direction;
			bulletArray.push_back(bulletprojectile);
		}
		bulletcount = 0;
		for (iter = bulletArray.begin();iter != bulletArray.end();iter++)
		{
				bulletArray[bulletcount].Bullet();
				window.draw(bulletArray[bulletcount].rect);
				bulletcount++;	
		}
		bulletcount = 0;
		for (iter1 = enemyArray.begin();iter1 != enemyArray.end();iter1++)
		{
			enemyArray[bulletcount].update();
			enemyArray[bulletcount].updatemovement();
			//window.draw(enemyArray[bulletcount].rect);
			window.draw(enemyArray[bulletcount].sprite);
			bulletcount++;
		}
		sf::Vector2f boxpos = box1.rectobject.getPosition();
		sf::Vector2f boxsize = box1.rectobject.getSize() / 2.0f;
		sf::Vector2f playerpos = Player1.rect.getPosition();
		sf::Vector2f playersize = Player1.rect.getSize() / 2.0f;
		float longx = boxpos.x - playerpos.x;
		float longy = boxpos.y - playerpos.y;
		float hitx = abs(longx) - boxsize.x - playersize.x;
		float hity = abs(longy) - boxsize.y - playersize.y;
		if (hitx <= 0 && hity <= 0)
		{
			Player1.rect.setPosition(536, 336);
		}

		box1.boxspeed = Player1.movespeed;
		window.draw(box1.rectobject);
		Player1.update();
		Player1.updatemovement();
		window.draw(Player1.sprite);
		window.display();
	} 
	return 0;
}