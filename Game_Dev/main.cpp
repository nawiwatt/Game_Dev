#include<SFML/Graphics.hpp>
#include<iostream>
#include<algorithm>
#include"entity.h"
#include"Player.h"
#include"bullet.h"
#include"object.h"
#include"enemy.h"
#include"map.h"
#include"gui.h"
#include"Textdisplay.h"
#include"randompower.h"
#include"Crate.h"
#include"Vending.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Game dev",sf::Style::Close);
	window.setFramerateLimit(300);
	//menuclass
	sf::Sprite menupic;
	sf::Texture menutecture;
	menutecture.loadFromFile("grass.jpg");
	menupic.setTexture(menutecture);
	//game class
	//buttons 
	sf::Texture buttonstexture;
	sf::Sprite buttonq;
	buttonq.setPosition(144, 720);
	buttonstexture.loadFromFile("buttons.png");
	buttonq.setTexture(buttonstexture);
	buttonq.setTextureRect(sf::IntRect(64, 0, 64, 64));
	buttonq.setScale(0.5, 0.5);
	sf::Sprite buttonE;
	buttonE.setTexture(buttonstexture);
	buttonE.setTextureRect(sf::IntRect(0, 0, 64, 64));
	buttonE.setScale(0.3, 0.3);
	buttonE.setPosition(210, 120);
	//gui
	class maingui lowgui;
	sf::Texture lowergui;
	sf::Texture guitop;
	sf::Texture coingui;
	sf::Texture raritygui;
	raritygui.loadFromFile("raritygui.png");
	coingui.loadFromFile("coingui.png");
	guitop.loadFromFile("topgui2.png");
	lowgui.weapongui.setTexture(raritygui);
	lowgui.weapongui.setPosition(729, 637);
	lowgui.weapongui.setScale(2,2);
	lowgui.topgui.setTexture(guitop);
	lowgui.topgui.setPosition(-10,-100);
	lowgui.topgui.setScale(7.45, 8);
	lowergui.loadFromFile("gui1.png");
	lowgui.sprite.setTexture(lowergui);
	lowgui.guicoin.setTexture(coingui);
	lowgui.guicoin.setPosition(79, 652);
	lowgui.guicoin.setScale(1.5,1.5);
	//???
	class::movemap map1;
	sf::Texture grasses;
	grasses.loadFromFile("map1.jpg");
	map1.sprite.setTexture(grasses);
	sf::Texture texture;
	texture.loadFromFile("betasprite.png");
	//power sprite / class
	class player Player1;
	class powerup playerpower;
	class powerup inusepower;
	sf::Texture powertexture;
	powertexture.loadFromFile("powerdrop.png");
	playerpower.sprite.setTexture(powertexture);
	inusepower.sprite.setTexture(powertexture);
	//bullet / guns/ class
	sf::Texture maingun;
	maingun.loadFromFile("guns.png");
	sf::Texture magingui;
	magingui.loadFromFile("magazine.png");
	sf::Texture laseringui;
	laseringui.loadFromFile("laser.png");
	std :: vector <bullet> :: const_iterator iter;
	std :: vector <bullet> bulletArray;
	class bullet bulletprojectile;
	bulletprojectile.maggui.setTexture(magingui);
	bulletprojectile.gunsprite.setTexture(maingun);
	bulletprojectile.gungui.setTexture(maingun);
	bulletprojectile.lasergui.setTexture(laseringui);
	sf::Texture bulletfire;
	bulletfire.loadFromFile("bulletfire.png");
	bulletprojectile.sprite.setTexture(bulletfire);
	//enemy sprite / class
	sf::Texture textureenemy;
	textureenemy.loadFromFile("enemyrunbeta.png");
	sf::Texture textureenemydie;
	textureenemydie.loadFromFile("enemydie.png");
	std::vector <enemy> ::const_iterator iter1;
	std::vector <enemy> ::const_iterator iter11;
	std::vector <enemy> enemyArray;
	class enemy enemy1;
	enemy1.sprite.setTexture(textureenemy);
	enemy1.diesprite.setTexture(textureenemydie);
	//text / font  /class
	class textdisplay damagedisplay;
	std::vector <textdisplay> ::const_iterator iter5;
	std::vector <textdisplay> textdisplayArray;
	class textdisplay bullettext;
	class textdisplay moneytext;
	class textdisplay droptext;
	class textdisplay enemyhpdisplay;
	class textdisplay gamescore;
	std::vector <textdisplay> ::const_iterator iter6;
	std::vector <textdisplay> enemyhptextArray;
	sf::Font damagefont;
	sf::Font hpfont;
	hpfont.loadFromFile("damage.ttf");
	gamescore.text.setFont(hpfont);
	enemyhpdisplay.text.setFont(hpfont);
	damagefont.loadFromFile("Rosskey.otf");
	damagedisplay.text.setFont(damagefont);
	bullettext.text.setFont(hpfont);
	moneytext.text.setFont(hpfont);
	droptext.text.setFont(hpfont);
	std::vector <textdisplay> ::const_iterator iter7;
	std::vector <textdisplay> dropdisplayArray;

	//Crate / weapon raity class
	sf::Texture Raritygun;
	Raritygun.loadFromFile("gunrarity.png");
	sf::Texture cratetextture;
	cratetextture.loadFromFile("crate.png");
	class Crate mainCrate;
	mainCrate.gunRarity.setTexture(Raritygun);
	mainCrate.sprite.setTexture(cratetextture);
	//vending machine
	class Vending mainVend;
	sf::Texture mainvending;
	mainvending.loadFromFile("vending.png");
	mainVend.sprite.setTexture(mainvending);
	sf::Texture vendgui;
	vendgui.loadFromFile("vendingui.png");
	mainVend.gui.setTexture(vendgui);
	sf::Texture venditem;
	venditem.loadFromFile("vending item.png");
	mainVend.gun.setTexture(venditem);
	mainVend.mag.setTexture(venditem);
	mainVend.shield.setTexture(venditem);
	mainVend.hammer.setTexture(venditem);
	mainVend.laser.setTexture(venditem);
	mainVend.button1.setTexture(buttonstexture);
	mainVend.button2.setTexture(buttonstexture);
	mainVend.button3.setTexture(buttonstexture);
	mainVend.button4.setTexture(buttonstexture);
	mainVend.button5.setTexture(buttonstexture);
	mainVend.text1.setFont(hpfont);
	mainVend.text2.setFont(hpfont);
	mainVend.text3.setFont(hpfont);
	mainVend.text4.setFont(hpfont);
	mainVend.text5.setFont(hpfont);
	//????
	srand(time(NULL));
	sf::Clock clock1;
	sf::Clock clock2;
	sf::Clock clock3;
	sf::Clock clockability;
	Player1.sprite.setTexture(texture); 
	int windowtype = 1;
	int enemycount = 0;
	int counter1,counter2,counter3;
	//weapon main
	int bulletcount = 0;
	int bulletcooldown = 0;
	bool reload = false;
	int killscore = 0;	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				break;
			}

		}

		//manu
		if (windowtype == 1)
		{
			window.clear();
			window.draw(menupic);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
			{
				windowtype = 2;
				//break;
			}
			window.display();
		}

		//game window
		if(windowtype == 2)
		{
		window.clear();

		//time
		sf::Time elapse1 = clock1.getElapsedTime();
		sf::Time elapse2 = clock2.getElapsedTime();
		sf::Time elapse3 = clock3.getElapsedTime();
		sf::Time elspseability = clockability.getElapsedTime();


		
		//playerupdate
		window.draw(map1.sprite);

		//weapon update
		bulletprojectile.WeaponCheck();
		bulletprojectile.Weaponraritycheck();
		bulletprojectile.equipmentcheck();
		bulletprojectile.gunsprite.setScale(2.5, 2.5);
		bulletprojectile.gunsprite.setOrigin(20, 20);
		bulletprojectile.weapondirection = Player1.direction;

		
		//ability chack
		if (playerpower.poweron == true && elspseability.asSeconds() > 10)
		{
			playerpower.poweron = false;
			inusepower.damageup = false;
			inusepower.coinboost = false;
			inusepower.speedboost = false;
			inusepower.infbullet = false;
		}
		if (inusepower.damageup == true)
		{
			bulletprojectile.bulletdamage *= 2;
		}
		else if (inusepower.speedboost == true)
		{
			bulletprojectile.bulletfirerate *= 2;
			bulletprojectile.reloadspeed /= 2;
		}
		
		//reload
		if (reload == true && elapse1.asSeconds() >= bulletprojectile.reloadspeed)
		{
			//std::cout << "reloaded!" << std::endl;
			reload = false;
			bulletcount = 0;
		}
		
		//enemy update

		/*counter1 = 0;
		for (iter1 = enemyArray.begin();iter1 != enemyArray.end();iter1++)
		{
			enemyArray[counter1].typeupdate();
			counter1++;
		}*/

		//enemymovement
		counter1 = 0;
		counter2 = 0;
		for (iter1 = enemyArray.begin();iter1 != enemyArray.end();iter1++)
		{
			enemyArray[counter2].rank = 0;
			for (iter11 = enemyArray.begin();iter11 != enemyArray.end();iter11++)
			{
				if (enemyArray[counter2].rect.getPosition().y > enemyArray[counter1].rect.getPosition().y)
				{
					enemyArray[counter2].rank++;
				}
				counter1++;
			}
			counter1 = 0;
			counter2++;
		}
		counter1 = 0;
		counter2 = 0;
		for (iter1 = enemyArray.begin();iter1 != enemyArray.end();iter1++)
		{
			for (iter11 = enemyArray.begin();iter11 != enemyArray.end();iter11++)
			{
				if (enemyArray[counter2].rank == counter1)
				{
					if (enemyArray[counter2].alive == true)
					{
						enemyArray[counter2].update();
						enemyArray[counter2].updatemovement();

						//window.draw(enemyArray[counter1].rect);
						window.draw(enemyArray[counter2].sprite);
						window.draw(enemyArray[counter2].hpbar);
						//window.draw(enemyHpbarArray[counter2].rect);
						enemyhptextArray[counter2].text.setPosition(enemyArray[counter2].rect.getPosition().x, enemyArray[counter2].rect.getPosition().y - 37);
						enemyhptextArray[counter2].text.setString(std::to_string(enemyArray[counter2].hp));
						window.draw(enemyhptextArray[counter2].text);
					}
					//else if (enemyArray[counter2].alive == false && enemyArray[counter2].died == false)
					else if (enemyArray[counter2].alive == false )
					{
						enemyArray[counter2].update();
						enemyArray[counter2].enemydie();
						enemyArray[counter2].rect.setSize(sf::Vector2f(0, 0));
						//window.draw(enemyArray[counter1].rect);
						window.draw(enemyArray[counter2].diesprite);
					}
				}
				counter2++;
			}
			counter2 = 0;
			counter1++;
		}
		counter1 = 0;
		
		//shootbullet&checkreload
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (bulletcooldown < 1 && reload == false)
			{
				bulletprojectile.rect.setPosition(Player1.rect.getPosition().x + 31, Player1.rect.getPosition().y + 26);
				bulletprojectile.direction = Player1.direction;
				bulletArray.push_back(bulletprojectile);
				bulletcount++;
				if (inusepower.infbullet == true)
				{
					bulletcount = 0;
				}
				//std::cout << 30 - bulletcount << std::endl;
			}
			else if (bulletcount >= bulletprojectile.weaponmag && reload == false)
			{
				reload = true;
				clock1.restart();
				//std::cout << "need reload!" << std::endl;
			}
		}
		
		//bullet firerate
		bulletcooldown += bulletprojectile.bulletfirerate;
		if (bulletcooldown >= 1000)
		{
			bulletcooldown = 0;
		}
		
		//check bullet's status
		counter1 = 0;
		for (iter = bulletArray.begin();iter != bulletArray.end();iter++)
		{
			if (bulletArray[counter1].bulletin == false)
			{
				bulletArray.erase(iter);
				break;
			}
			counter1++;
		}
		/*sf::Vector2f boxpos = box1.rectobject.getPosition();
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
			//Player1.sprite.setScale(3, 3);
			//box1.rectobject.setPosition(9999, 9999);
		}*/
		
		//spawn enemy
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			if (enemycount < 20)
			{
				enemy1.rect.setPosition(rand() % (20) + 1200, rand() % (260) + 180);
				enemy1.enemytype = rand() % (3);
				enemy1.typeupdate();
				enemyArray.push_back(enemy1);
				enemyhpdisplay.text.setPosition(enemy1.rect.getPosition().x, enemy1.rect.getPosition().y - 37);
				enemyhpdisplay.text.setCharacterSize(9);
				enemyhpdisplay.text.setFillColor(sf::Color::Black);
				enemyhptextArray.push_back(enemyhpdisplay);
				enemycount++;
			}
		}
		
		//check bullet hit enemy & textdisplay
		counter1 = 0;
		for (iter = bulletArray.begin();iter != bulletArray.end();iter++)
		{
			counter2 = 0;
			for (iter1 = enemyArray.begin();iter1 != enemyArray.end();iter1++)
			{
				if (bulletArray[counter1].rect.getGlobalBounds().intersects(enemyArray[counter2].rect.getGlobalBounds()))
				{
					if (enemyArray[counter2].hp < bulletArray[counter1].bulletdamage)
					{
						damagedisplay.text.setString(std::to_string(enemyArray[counter2].hp));
						bulletArray[counter1].bulletdamage -= enemyArray[counter2].hp;
						enemyArray[counter2].hp = 0;
						//damagedisplay.text.setString(std::to_string(bulletArray[counter1].bulletdamage));
						damagedisplay.text.setPosition(enemyArray[counter2].rect.getPosition().x + 24, enemyArray[counter2].rect.getPosition().y - 32);
						//textdisplayArray.push_back(damagedisplay);

					}
					else
					{
						enemyArray[counter2].hp = enemyArray[counter2].hp - bulletArray[counter1].bulletdamage;
						bulletArray[counter1].bulletin = false;
						damagedisplay.text.setString(std::to_string(bulletArray[counter1].bulletdamage));
						damagedisplay.text.setPosition(enemyArray[counter2].rect.getPosition().x + 24, enemyArray[counter2].rect.getPosition().y - 32);
						//textdisplayArray.push_back(damagedisplay);
					}

					damagedisplay.text.setPosition(enemyArray[counter2].rect.getPosition().x + 24, enemyArray[counter2].rect.getPosition().y - 32);
					textdisplayArray.push_back(damagedisplay);
					//std::cout << enemyArray[counter2].hp << std::endl;
				}
				counter2++;
			}
			counter1++;
		}
		
		//check enemy alive
		counter1 = 0;
		for (iter1 = enemyArray.begin();iter1 != enemyArray.end();iter1++)
		{
			if (enemyArray[counter1].hp <= 0 && enemyArray[counter1].alive == true)
			{
				enemyArray[counter1].runtime = 0;
				enemyArray[counter1].alive = false;
			}
			counter1++;
		}
		
		//check enemy remove , money&power drop text
		counter1 = 0;
		for (iter1 = enemyArray.begin();iter1 != enemyArray.end();iter1++)
		{
			if (enemyArray[counter1].died == true)
			{
				if (inusepower.coinboost == true)
				{
					enemyArray[counter1].coindropmax *= 2;
				}
				droptext.moneydropmax = enemyArray[counter1].coindropmax;
				droptext.powerdrop = enemyArray[counter1].powerdropchance;
				droptext.dropupdate();
				droptext.text.setPosition(enemyArray[counter1].rect.getPosition().x + 24, enemyArray[counter1].rect.getPosition().y - 32);
				dropdisplayArray.push_back(droptext);
				enemyArray.erase(iter1);
				enemycount--;
				killscore++;
				break;
			}
			counter1++;
		}
		
		//check text end & text moveup (damage and droptext)
		counter1 = 0;
		for (iter5 = textdisplayArray.begin();iter5 != textdisplayArray.end();iter5++)
		{
			if (textdisplayArray[counter1].textend == true)
			{
				textdisplayArray.erase(iter5);
				break;
			}
			else
			{
				textdisplayArray[counter1].update();
				window.draw(textdisplayArray[counter1].text);
			}
			counter1++;
		}
		counter1 = 0;
		for (iter7 = dropdisplayArray.begin();iter7 != dropdisplayArray.end();iter7++)
		{
			if (dropdisplayArray[counter1].textend == true)
			{
				Player1.mymoney += dropdisplayArray[counter1].moneydrop;
				if (dropdisplayArray[counter1].checkpowerdrop == true && Player1.mypower < Player1.maxpower)
				{
					Player1.mypower++;
				}
				dropdisplayArray.erase(iter7);
				break;
			}
			else if (dropdisplayArray[counter1].checkmoneydrop == true && dropdisplayArray[counter1].checkpowerdrop == true && Player1.mypower < Player1.maxpower)
			{
				dropdisplayArray[counter1].text.setCharacterSize(15);
				dropdisplayArray[counter1].text.setString(std::to_string(dropdisplayArray[counter1].moneydrop));
				dropdisplayArray[counter1].text.setFillColor(sf::Color::Magenta);
				dropdisplayArray[counter1].update();
				window.draw(dropdisplayArray[counter1].text);
			}
			else if (dropdisplayArray[counter1].checkmoneydrop == true)
			{
				dropdisplayArray[counter1].text.setCharacterSize(15);
				dropdisplayArray[counter1].text.setString(std::to_string(dropdisplayArray[counter1].moneydrop));
				dropdisplayArray[counter1].text.setFillColor(sf::Color::Yellow);
				dropdisplayArray[counter1].update();
				window.draw(dropdisplayArray[counter1].text);
			}
			counter1++;
		}
		
		//draw gui
		lowgui.sprite.setPosition(0, 600);
		lowgui.sprite.setScale(3.55, 3.1);
		window.draw(lowgui.sprite);
		
		//reload , money text in gui
		window.draw(lowgui.guicoin);
		moneytext.text.setFillColor(sf::Color::Yellow);
		moneytext.text.setPosition(95, 657);
		moneytext.text.setCharacterSize(23);
		moneytext.text.setString(std::to_string(Player1.mymoney) + "  COINS");
		window.draw(moneytext.text);
		if (reload == false)
		{
			bullettext.text.setFillColor(sf::Color::Black);
			bullettext.text.setPosition(960, 670);
			bullettext.text.setString(std::to_string(bulletprojectile.weaponmag - bulletcount) + " / " + std::to_string(bulletprojectile.weaponmag));
			window.draw(bullettext.text);
		}
		else if (reload == true)
		{
			bullettext.text.setFillColor(sf::Color::Black);
			bullettext.text.setPosition(940, 670);
			bullettext.text.setString("reloading");
			window.draw(bullettext.text);
		}
		
		//power sprite in gui
		playerpower.mypower = Player1.mypower;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && Player1.mypower > 0)
		{
			if (playerpower.poweron == false)
			{
				Player1.mypower -= 1;
				playerpower.poweron = true;
				playerpower.powerisused();
				inusepower.powertype = rand() % (4) + 1;
				clockability.restart();
			}
		}
		playerpower.sprite.setPosition(144, 690);
		playerpower.update();
		window.draw(playerpower.sprite);
		
		//crate
		if (Player1.rect.getGlobalBounds().intersects(mainCrate.circle.getGlobalBounds()))
		{
			if (mainCrate.bought == true && mainCrate.ready == true)
			{
				mainCrate.runtime = 0;
				mainCrate.opened = true;
				mainCrate.ready = false;
				mainCrate.luck = rand() % (100) + 1;
				mainCrate.luck2 = rand() % (100) + 1;
				clock3.restart();
				mainCrate.bought = false;
			}
		}
		
		//crate & random
		mainCrate.update();
		//window.draw(mainCrate.circle);
		window.draw(mainCrate.sprite);
		if (mainCrate.opendone == true)
		{
			mainCrate.GunCrate();
			window.draw(mainCrate.gunRarity);
			if (Player1.rect.getGlobalBounds().intersects(mainCrate.circle.getGlobalBounds()))
			{
				window.draw(buttonE);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && mainCrate.opendone == true)
				{
					mainCrate.ready = true;
					mainCrate.opendone = false;
					bulletprojectile.weaponrarity = ++mainCrate.rarity;
					bulletprojectile.weapontype = ++mainCrate.guntype;
					bulletcount = 0;
					mainVend.cratebought = false;
				}
			}
			if (elapse3.asSeconds() > 10)
			{
				mainCrate.ready = true;
				mainCrate.opendone = false;
				mainVend.cratebought = false;
			}
		}
		
		//vending machine
		window.draw(mainVend.sprite);
		if (Player1.rect.getGlobalBounds().intersects(mainCrate.circle.getGlobalBounds()) && mainVend.avalible == true)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && mainVend.magbought == false && bulletprojectile.magtype != 4 && Player1.mymoney >= mainVend.magprice)
			{
				bulletprojectile.magtype++;
				mainVend.magbought = true;
				Player1.mymoney -= mainVend.magprice;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && mainVend.laserbought == false && bulletprojectile.laserequiped == false && Player1.mymoney >= 100)
			{
				bulletprojectile.laserequiped = true;
				mainVend.laserbought = true;
				Player1.mymoney -= 100;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && mainVend.hammerbought == false && Player1.mymoney >= 300)
			{
				//Put hammer effect
				mainVend.hammerbought = true;
				Player1.mymoney -= 300;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) && mainVend.shieldbought == false && Player1.mymoney >= 300)
			{
				//Put shield effect
				mainVend.shieldbought = true;
				Player1.mymoney -= 300;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) && mainVend.cratebought == false && Player1.mymoney >= 200)
			{
				mainVend.cratebought = true;
				mainCrate.bought = true;
				Player1.mymoney -= 200;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && mainVend.magbought == true && bulletprojectile.magtype < 4)
		{
			mainVend.magtype = bulletprojectile.magtype;
			mainVend.magbought = false;
		}

		//bullet draw
		counter1 = 0;
		for (iter = bulletArray.begin();iter != bulletArray.end();iter++)
		{
			bulletArray[counter1].Bullet();
			window.draw(bulletArray[counter1].rect);
			//window.draw(bulletArray[counter1].sprite);
			counter1++;
		}
		
		//player gun laser
		Player1.update();
		Player1.updatemovement();
		//window.draw(Player1.rect);
		window.draw(Player1.sprite);
		if (bulletprojectile.laserequiped == true)
		{
			bulletprojectile.lasergui.setTextureRect(sf::IntRect(64, 0, 64, 64));
			bulletprojectile.laserdirection = Player1.direction;
			if (bulletprojectile.laserdirection == 2)
			{
				bulletprojectile.Lasers.setPosition(Player1.rect.getPosition().x + 36, Player1.rect.getPosition().y + 28);
			}
			else
			{
				bulletprojectile.Lasers.setPosition(Player1.rect.getPosition().x - 1474, Player1.rect.getPosition().y + 28);
			}
			window.draw(bulletprojectile.Lasers);
		}
		else if (bulletprojectile.laserequiped == false)
		{
			bulletprojectile.lasergui.setTextureRect(sf::IntRect(0, 0, 64, 64));
		}
		bulletprojectile.gunsprite.setPosition(Player1.sprite.getPosition());
		window.draw(bulletprojectile.gunsprite);
		
		//vending gui
		if (Player1.rect.getGlobalBounds().intersects(mainCrate.circle.getGlobalBounds()))
		{
			if (mainVend.avalible == true)
			{
				mainVend.update();
				window.draw(mainVend.gui);
				window.draw(mainVend.mag);
				window.draw(mainVend.hammer);
				window.draw(mainVend.shield);
				window.draw(mainVend.gun);
				window.draw(mainVend.laser);
				if (mainVend.magbought == false && mainVend.magtype < 4)
				{
					mainVend.text1.setString(std::to_string(mainVend.magprice));
					window.draw(mainVend.text1);
					window.draw(mainVend.button1);
				}
				if (mainVend.laserbought == false)
				{
					window.draw(mainVend.text2);
					window.draw(mainVend.button2);
				}
				if (mainVend.hammerbought == false)
				{
					window.draw(mainVend.text3);
					window.draw(mainVend.button3);
				}
				if (mainVend.shieldbought == false)
				{
					window.draw(mainVend.text4);
					window.draw(mainVend.button4);
				}
				if (mainVend.cratebought == false)
				{
					window.draw(mainVend.text5);
					window.draw(mainVend.button5);
				}
			}
		}

		//buttons
		if (Player1.mypower > 0 && playerpower.poweron == false)
		{
			window.draw(buttonq);
		}
		
		//power sprite in use
		if (playerpower.poweron == true)
		{
			inusepower.powerisused();
			window.draw(inusepower.sprite);
		}
		
		//draw alot
		lowgui.rarity = bulletprojectile.weaponrarity;
		lowgui.update();
		window.draw(lowgui.topgui);
		window.draw(lowgui.weapongui);
		window.draw(bulletprojectile.gungui);
		window.draw(bulletprojectile.maggui);
		window.draw(bulletprojectile.lasergui);
		
		//score
		gamescore.text.setPosition(80, 0);
		gamescore.text.setCharacterSize(40);
		gamescore.text.setString("SCORE  " + std::to_string(killscore));
		window.draw(gamescore.text);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
		{
			windowtype = 3;
		}
		
		//std::cout << bulletprojectile.bulletfirerate << std::endl;
		window.display();
		}

		if (windowtype == 3)
		{
			window.clear();
			window.draw(menupic);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
			{
				windowtype = 2;
				//break;
			}
			window.display();
		}
	} 
	return 0;
}