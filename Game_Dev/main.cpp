#define _CRT_SECURE_NO_WARNINGS
#include<SFML/Graphics.hpp>
#include<iostream>
#include<utility>
#include<fstream>
#include<sstream>
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
#include"Radioactive.h"
#include"Totems.h"
#include"Wall.h"
#include"MainMenu.h"
#include"SFML/Audio.hpp"
int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Nawiwat 63010522",sf::Style::Close);
	window.setFramerateLimit(300);
	//sound
	sf::SoundBuffer ClickSound;
	ClickSound.loadFromFile("click.wav");
	sf::Sound Click;
	Click.setBuffer(ClickSound);
	Click.setVolume(20.0);
	sf::SoundBuffer mainsound;
	mainsound.loadFromFile("mainback.wav");
	sf::Sound mainSound;
	mainSound.setBuffer(mainsound);
	mainSound.setVolume(20.0);
	sf::SoundBuffer typeSound;
	typeSound.loadFromFile("type.wav");
	sf::Sound Type;
	Type.setBuffer(typeSound);
	Type.setVolume(20.0);
	sf::SoundBuffer reloadSound;
	reloadSound.loadFromFile("reload.wav");
	sf::Sound Reload;
	Reload.setBuffer(reloadSound);
	Reload.setVolume(20.0);
	sf::SoundBuffer shootSound;
	shootSound.loadFromFile("shot1.wav");
	sf::Sound Shoot;
	Shoot.setBuffer(shootSound);
	Shoot.setVolume(20.0);
	sf::SoundBuffer waveSound;
	waveSound.loadFromFile("wave.wav");
	sf::Sound Wave;
	Wave.setBuffer(waveSound);
	Wave.setVolume(20.0);
	sf::SoundBuffer dieSound;
	dieSound.loadFromFile("die.wav");
	sf::Sound Die;
	Die.setBuffer(dieSound);
	Die.setVolume(20.0);
	sf::SoundBuffer buySound;
	buySound.loadFromFile("buy.wav");
	sf::Sound Buy;
	Buy.setBuffer(buySound);
	Buy.setVolume(20.0);
	sf::SoundBuffer equipSound;
	equipSound.loadFromFile("equip.wav");
	sf::Sound Equip;
	Equip.setBuffer(equipSound);
	Equip.setVolume(20.0);
	sf::SoundBuffer wallSound;
	wallSound.loadFromFile("hitted.wav");
	sf::Sound Wallhit;
	Wallhit.setBuffer(wallSound);
	Wallhit.setVolume(20.0);
	sf::SoundBuffer slimeSound;
	slimeSound.loadFromFile("slime.wav");
	sf::Sound Slime;
	Slime.setBuffer(slimeSound);
	Slime.setVolume(20.0);
	sf::SoundBuffer backgroundmenu;
	backgroundmenu.loadFromFile("background1.wav");
	sf::Sound BgSound1;
	BgSound1.setBuffer(backgroundmenu);
	BgSound1.setVolume(20.0);
	sf::SoundBuffer totemsound;
	totemsound.loadFromFile("totemSound.wav");
	sf::Sound Totemsound;
	Totemsound.setBuffer(totemsound);
	Totemsound.setVolume(20.0);
	//menuclass
	sf::Font damagefont;
	damagefont.loadFromFile("Rosskey.otf");
	sf::Texture modetext;
	modetext.loadFromFile("mode.png");
	sf::Font hpfont;
	hpfont.loadFromFile("damage.ttf");
	class MainMenu Menu;
	sf::Text leaderText, easyText, hardText, normalText;
	leaderText.setFont(hpfont);
	easyText.setFont(hpfont);
	normalText.setFont(hpfont);
	hardText.setFont(hpfont);
	sf::Text gamename;
	gamename.setFont(hpfont);
	gamename.setCharacterSize(150);
	gamename.setPosition(30, 30);
	gamename.setString("Bruh");
	gamename.setOutlineThickness(3);
	gamename.setFillColor(sf::Color::Blue);
	//easyText.setFillColor(sf::Color::White);
	easyText.setCharacterSize(65);
	easyText.setPosition(120, 230);
	easyText.setString("Easy");
	easyText.setOutlineThickness(3);
	//normalText.setFillColor(sf::Color::White);
	normalText.setCharacterSize(65);
	normalText.setPosition(500, 230);
	normalText.setString("Normal");
	normalText.setOutlineThickness(3);
	//hardText.setFillColor(sf::Color::White);
	hardText.setCharacterSize(65);
	hardText.setPosition(930, 230);
	hardText.setString("Hard");
	hardText.setOutlineThickness(3);
	easyText.setFillColor(sf::Color::Color(227, 149, 187));
	normalText.setFillColor(sf::Color::Color(27, 92, 235));
	hardText.setFillColor(sf::Color::Color(133, 31, 17));
	//
	leaderText.setFillColor(sf::Color::White);
	leaderText.setCharacterSize(80);
	leaderText.setPosition(420, 80);
	leaderText.setString("Leaderboard");
	leaderText.setOutlineThickness(3);
	Menu.easysprite.setTexture(modetext);
	Menu.normalsprite.setTexture(modetext);
	Menu.hardsprite.setTexture(modetext);
	sf::Sprite menupic;
	sf::Texture menutecture;
	menutecture.loadFromFile("grass.jpg");
	menupic.setTexture(menutecture);
	Menu.start.setFont(hpfont);
	Menu.index.setFont(hpfont);
	Menu.leaderboard.setFont(hpfont);
	Menu.exit.setFont(hpfont);
	Menu.backtext.setFont(hpfont);
	Menu.easy.setFont(hpfont);
	Menu.normal.setFont(hpfont);
	Menu.hard.setFont(hpfont);
	Menu.confirm.setFont(hpfont);
	Menu.cancel.setFont(hpfont);
	Menu.pause.setFont(hpfont);
	Menu.mode.setFont(hpfont);
	Menu.wave.setFont(damagefont);
	Menu.Input.setFont(hpfont);
	Menu.Next.setFont(hpfont);
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
	sf::Sprite map1;
	sf::Texture grasses;
	grasses.loadFromFile("map1.jpg");
	map1.setTexture(grasses);
	sf::Texture grasses1;
	grasses1.loadFromFile("map2.png");
	sf::Texture grasses2;
	grasses2.loadFromFile("map3.png");
	map1.setScale(2.4, 2.6);

	sf::Texture menuback;
	menuback.loadFromFile("mainbg.jpg");
	sf::Sprite menubackg;
	menubackg.setTexture(menuback);
	menubackg.setScale(0.9, 0.9);
	menubackg.setPosition(-5, -5);
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
	gamescore.text.setFont(hpfont);
	enemyhpdisplay.text.setFont(hpfont);
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
	mainVend.button6.setTexture(buttonstexture);
	mainVend.button7.setTexture(buttonstexture);
	mainVend.text1.setFont(hpfont);
	mainVend.text2.setFont(hpfont);
	mainVend.text3.setFont(hpfont);
	mainVend.text4.setFont(hpfont);
	mainVend.text5.setFont(hpfont);
	mainVend.text6.setFont(hpfont);
	mainVend.text7.setFont(hpfont);
	mainVend.bloodrust.setTexture(venditem);
	mainVend.breakTotem.setTexture(venditem);


	//enemy effect
	class radioactive slime1;
	std::vector <radioactive> ::const_iterator iter9;
	std::vector <radioactive> slimeArray;
	sf::Texture slimetexture;
	slimetexture.loadFromFile("slime.png");
	slime1.sprite.setTexture(slimetexture);
	class Totems totem1;
	std::vector <Totems> ::const_iterator iter10;
	std::vector <Totems> totemarray;
	sf::Texture totemtexture;
	totemtexture.loadFromFile("totem.png");
	totem1.sprite.setTexture(totemtexture);
	//wall
	class Wall mainwall;
	sf::Texture walltexture;
	walltexture.loadFromFile("wall.png");
	mainwall.sprite.setTexture(walltexture);
	sf::Texture wallgui;
	wallgui.loadFromFile("wallgui.png");
	mainwall.hpgui.setTexture(wallgui);
	mainwall.text.setFont(hpfont);
	sf::Sprite bloodRusrgui;
	sf::Sprite totemgui;
	totemgui.setTexture(venditem);
	bloodRusrgui.setTexture(venditem);
	bloodRusrgui.setPosition(597, 638);
	totemgui.setPosition(597, 702);
	sf::Text bloodtext;
	bloodtext.setFont(hpfont);
	bloodtext.setFillColor(sf::Color::Red);
	bloodtext.setCharacterSize(15);
	bloodtext.setPosition(608, 670);
	bloodRusrgui.setTextureRect(sf::IntRect(448, 0, 64, 64));
	totemgui.setTextureRect(sf::IntRect(512, 0, 64, 64));
	mainwall.hammer.setTexture(venditem);
	mainwall.shield.setTexture(venditem);

	//????
	srand(time(NULL));
	sf::Clock clock1;
	sf::Clock clock2;
	sf::Clock clock3;
	sf::Clock clockability;
	sf::Clock menuclock;
	sf::Clock waveclock;
	sf::Clock shootclock;
	sf::Clock musicClock;
	sf::Clock musicClock2;
	Player1.sprite.setTexture(texture); 
	int windowtype = 1;
	int enemycount = 0;
	int counter1,counter2,counter3;
	//weapon main
	int bulletcount = 0;
	int bulletcooldown = 0;
	bool reload = false;
	int killscore = 0;	
	bool cheat = false;
	bool ingame = false;
	bool wavedone = false;
	int gamemode;
	int enemyrand;
	int spawnrate = 0;
	int wave = 0;
	int bloodcount = 0;
	sf::String Input;
	sf::Text PlayerName[11];
	sf::Text PlayerScore[7];
	sf::Text PlayerName1[11];
	sf::Text PlayerScore1[7];
	sf::Text PlayerName2[11];
	sf::Text PlayerScore2[7];
	bool bloodon = false;
	int bloodrop;
	int textcooldown = 0;
	int difficulty = 100;
	int enemyleft = 0;
	bool inwave = false;
	BgSound1.play();
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
		// background music
		sf::Time elapseSong = musicClock.getElapsedTime();
		sf::Time elapseSong2 = musicClock2.getElapsedTime();
		//std::cout << elapseSong.asSeconds() << std::endl;
		if (windowtype != 3 && ingame == false && elapseSong.asSeconds() > 95)
		{
			BgSound1.play();
			musicClock.restart();
		}
		if (windowtype == 3 || ingame == true )
		{
			BgSound1.stop();
		}
		if (windowtype == 3  && elapseSong.asSeconds() > 90)
		{
			mainSound.play();
			musicClock2.restart();
		}
		else if (windowtype != 3)
		{
			mainSound.stop();
		}
		
		//menu
		if (windowtype == 1)
		{
			window.clear();
			window.draw(menubackg);
			window.draw(gamename);
			Menu.exit.setPosition(30, 500);
			Menu.exitRect.setPosition(22, 500);
			//Menu.index.setPosition(30, 500);
			//Menu.indexRect.setPosition(22, 500);
			Menu.indexRect.setSize(sf::Vector2f(400, 72));
			Menu.exitRect.setSize(sf::Vector2f(400, 72));
			//window.draw(Menu.startRect);
			//window.draw(Menu.indexRect);
			//window.draw(Menu.leaderRect);
			//window.draw(Menu.exitRect);
			Menu.rect.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
			if (Menu.rect.getGlobalBounds().intersects(Menu.startRect.getGlobalBounds()))
			{
				Menu.start.setFillColor(sf::Color::Green);
				window.draw(Menu.start);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Click.play();
					Menu.modeselected = false;
					windowtype = 2;
					enemycount = 0;
					bulletcount = 0;
					bulletprojectile.weapontype = 1;
					bulletprojectile.weaponrarity = 1;
					bulletprojectile.laserequiped = false;
					bulletprojectile.magtype = 1;
					mainwall.repairTool = false;
					mainwall.shieldequip = false;
					mainwall.hp = 100;
					mainwall.maxhp = 100;
					Player1.mymoney = 200;
					Player1.mypower = 0;
					mainVend.avalible = true;
					mainVend.magbought = false;
					mainVend.laserbought = false;
					mainVend.hammerbought = false;
					mainVend.shieldbought = false;
					mainVend.btbought = false;
					mainVend.bloodrustbought = false;
					mainVend.magtype = 1;
					totem1.breakTotem = false;
					enemyleft = 0;
					cheat = false;
					wavedone = false;
					bloodcount = 0;
					bloodon = false;
					difficulty = 100;
					wave = 0;
					inwave = false;
					mainVend.locked = true;
					menuclock.restart();
					killscore = 0;
					if (Input.getSize() > 0)
					{
						for (int i = 0; i < Input.getSize();)
						{
							Input.erase(Input.getSize() - 1);
						}
					}
				}
			}
			else 
			{
				Menu.start.setFillColor(sf::Color::White);
				window.draw(Menu.start);
			}
			/*if (Menu.rect.getGlobalBounds().intersects(Menu.indexRect.getGlobalBounds()))
			{
				Menu.index.setFillColor(sf::Color::Green);
				window.draw(Menu.index);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Click.play();
					windowtype = 5;
				}
			}
			else
			{
				Menu.index.setFillColor(sf::Color::White);
				window.draw(Menu.index);
			}*/
			if (Menu.rect.getGlobalBounds().intersects(Menu.leaderRect.getGlobalBounds()))
			{
				Menu.leaderboard.setFillColor(sf::Color::Green);
				window.draw(Menu.leaderboard);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Click.play();
					windowtype = 6; 
					std::string Name[11], Name1[11] , Name2[11];
					FILE* fp;
					char temp[255], temp1[255] , temp2[255];
					int score[7], score1[7] , score2[7];

					std::vector <std::pair<int, std::string>> userScore, userScore1, userScore2;

					fp = fopen("./Score.txt", "r");
					for (int i = 0; i < 5; i++)
					{
						fscanf(fp, "%s", &temp);
						Name[i] = temp;
						PlayerName[i].setString(Name[i]);
						fscanf(fp, "%d", &score[i]);
						PlayerScore[i].setString(std::to_string(score[i]));
						userScore.push_back(std::make_pair(score[i], Name[i]));
					}

					for (int i = 0; i < 5; i++)
					{
						PlayerName[i].setFont(hpfont);
						PlayerName[i].setCharacterSize(50);
						PlayerName[i].setFillColor(sf::Color::Color(227, 149, 187));
						PlayerName[i].setPosition(window.getSize().x / 2 - 580, window.getSize().y / 2 - 80 + (60 * i));
						PlayerScore[i].setFont(hpfont);
						PlayerScore[i].setCharacterSize(50);
						PlayerScore[i].setFillColor(sf::Color::Color(227, 149, 187));
						PlayerScore[i].setPosition(window.getSize().x / 2 - 330, window.getSize().y / 2 - 80 + (60 * i));
						PlayerName[i].setOutlineThickness(3);
						PlayerScore[i].setOutlineThickness(3);
					}
					fp = fopen("./Score1.txt", "r");
					for (int i = 0; i < 5; i++)
					{
						fscanf(fp, "%s", &temp1);
						Name1[i] = temp1;
						PlayerName1[i].setString(Name1[i]);
						fscanf(fp, "%d", &score1[i]);
						PlayerScore1[i].setString(std::to_string(score1[i]));
						userScore1.push_back(std::make_pair(score1[i], Name1[i]));
					}

					for (int i = 0; i < 5; i++)
					{
						PlayerName1[i].setFont(hpfont);
						PlayerName1[i].setCharacterSize(50);
						PlayerName1[i].setFillColor(sf::Color::Color(27, 92, 235));
						PlayerName1[i].setPosition(window.getSize().x / 2 - 180, window.getSize().y / 2 - 80 + (60 * i));
						PlayerScore1[i].setFont(hpfont);
						PlayerScore1[i].setCharacterSize(50);
						PlayerScore1[i].setFillColor(sf::Color::Color(27, 92, 235));
						PlayerScore1[i].setPosition(window.getSize().x / 2 + 70, window.getSize().y / 2 - 80 + (60 * i));
						PlayerName1[i].setOutlineThickness(3);
						PlayerScore1[i].setOutlineThickness(3);
					}
					fp = fopen("./Score2.txt", "r");
					for (int i = 0; i < 5; i++)
					{
						fscanf(fp, "%s", &temp2);
						Name2[i] = temp2;
						PlayerName2[i].setString(Name2[i]);
						fscanf(fp, "%d", &score2[i]);
						PlayerScore2[i].setString(std::to_string(score2[i]));
						userScore2.push_back(std::make_pair(score2[i], Name2[i]));
					}

					for (int i = 0; i < 5; i++)
					{
						PlayerName2[i].setFont(hpfont);
						PlayerName2[i].setCharacterSize(50);
						PlayerName2[i].setFillColor(sf::Color::Color(133, 31, 17));
						PlayerName2[i].setPosition(window.getSize().x / 2 + 220, window.getSize().y / 2 - 80 + (60 * i));
						PlayerScore2[i].setFont(hpfont);
						PlayerScore2[i].setCharacterSize(50);
						PlayerScore2[i].setFillColor(sf::Color::Color(133, 31, 17));
						PlayerScore2[i].setPosition(window.getSize().x / 2 + 470, window.getSize().y / 2 - 80 + (60 * i));
						PlayerName2[i].setOutlineThickness(3);
						PlayerScore2[i].setOutlineThickness(3);
					}
				}
			}
			else
			{
				Menu.leaderboard.setFillColor(sf::Color::White);
				window.draw(Menu.leaderboard);
			}
			if (Menu.rect.getGlobalBounds().intersects(Menu.exitRect.getGlobalBounds()))
			{

				Menu.exit.setFillColor(sf::Color::Green);
				window.draw(Menu.exit);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Click.play();
					break;
				}
			}
			else
			{
				Menu.exit.setFillColor(sf::Color::White);
				window.draw(Menu.exit);
			}
			window.display();
		}

		//mode select
		if (windowtype == 2)
		{
			window.clear();
			sf::Time menuelspse = menuclock.getElapsedTime();
			window.draw(menubackg);
			//window.draw(Menu.backRect);
			if (Menu.modeselected == false)
			{
				Menu.easyRect.setFillColor(sf::Color::Color(227, 149, 187));
				Menu.normalRect.setFillColor(sf::Color::Color(27, 92, 235));
				Menu.hardRect.setFillColor(sf::Color::Color(133, 31, 17));
			}
			Menu.rect.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
			window.draw(Menu.easyRect);
			window.draw(Menu.easysprite);
			window.draw(Menu.normalRect);
			window.draw(Menu.normalsprite);
			window.draw(Menu.hardRect);
			window.draw(Menu.hardsprite);
			//mode select
			if (Menu.rect.getGlobalBounds().intersects(Menu.easyRect.getGlobalBounds()) && menuelspse.asSeconds() > 2 && Menu.modeselected == false)
			{
				Menu.easy.setFillColor(sf::Color::Green);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Click.play();
					Menu.modeselected = true;
					gamemode = 1;
					Menu.easy.setFillColor(sf::Color::Color(227,149,187));
					Menu.easyRect.setFillColor(sf::Color::Green);
					Menu.inputtext = true;
					map1.setTexture(grasses1);
				}
			}
			else if (Menu.modeselected == false)
			{
				Menu.easy.setFillColor(sf::Color::White);
			}
			if (Menu.rect.getGlobalBounds().intersects(Menu.normalRect.getGlobalBounds()) && menuelspse.asSeconds() > 2 && Menu.modeselected == false)
			{
				Menu.normal.setFillColor(sf::Color::Green);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Click.play();
					gamemode = 2;
					Menu.modeselected = true;
					Menu.normal.setFillColor(sf::Color::Color(27, 92, 235));
					mainVend.locked = false;
					Menu.normalRect.setFillColor(sf::Color::Green);
					Menu.inputtext = true;
					map1.setTexture(grasses);
				}
			}
			else if (Menu.modeselected == false)
			{
				Menu.normal.setFillColor(sf::Color::White);
			}
			if (Menu.rect.getGlobalBounds().intersects(Menu.hardRect.getGlobalBounds()) && menuelspse.asSeconds() > 2 && Menu.modeselected == false)
			{
				Menu.hard.setFillColor(sf::Color::Green);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Click.play();
					gamemode = 3;
					Menu.modeselected = true;
					Menu.hard.setFillColor(sf::Color::Color(133, 31, 17));
					mainVend.locked = false;
					Menu.hardRect.setFillColor(sf::Color::Green);
					Menu.inputtext = true;
					map1.setTexture(grasses2);
				}
			}
			else if (Menu.modeselected == false)
			{
				Menu.hard.setFillColor(sf::Color::White);
			}

			//confirm
			if (Menu.modeselected == true)
			{
				textcooldown++;
				if (textcooldown >= 100)
				{
					if (event.type == sf::Event::TextEntered)
					{
						if (event.text.unicode < 128)
						{
							if (event.text.unicode == static_cast <sf::Uint32>(8) && Input.getSize() > 0)
							{

								Input.erase(Input.getSize() - 1);
								Type.play();
							}
							else
							{
								if (Input.getSize() < 10 && event.text.unicode != 13)
								{
									if (event.text.unicode == 32)
									{
										event.text.unicode = 95;
									}
									Input += event.text.unicode;
									Type.play();
								}
							}
						}
						textcooldown = 0;
					}
					
				}
				Menu.Input.setString(Input);
				
				//window.draw(Menu.confirmRect);
				//window.draw(Menu.cancelRect);
				if (Menu.rect.getGlobalBounds().intersects(Menu.confirmRect.getGlobalBounds()) && Input.getSize() > 0)
				{
					Menu.confirm.setFillColor(sf::Color::Green);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						Click.play();
						windowtype = 3;
						ingame = true;
						waveclock.restart();
					}
				}
				else
				{
					Menu.confirm.setFillColor(sf::Color::White);
				}
				if (Menu.rect.getGlobalBounds().intersects(Menu.cancelRect.getGlobalBounds()))
				{
					Menu.cancel.setFillColor(sf::Color::Green);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						Click.play();
						Menu.modeselected = false;
						if (Input.getSize() > 0)
						{
							for (int i = 0; i < Input.getSize();)
							{
								Input.erase(Input.getSize() - 1);
							}
						}
					}
				}
				else
				{
					Menu.cancel.setFillColor(sf::Color::White);
				}
				window.draw(Menu.confirm);
				window.draw(Menu.cancel);
				window.draw(Menu.nameRect);
				window.draw(Menu.Input);
			}

			//back
			if (Menu.rect.getGlobalBounds().intersects(Menu.backRect.getGlobalBounds()) && Menu.modeselected == false)
			{
				Menu.backtext.setFillColor(sf::Color::Green);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Click.play();
					windowtype = 1;
				}
			}
			else
			{
				Menu.backtext.setFillColor(sf::Color::White);
			}
			
			window.draw(Menu.easy);
			window.draw(Menu.normal);
			window.draw(Menu.hard);
			window.draw(Menu.backtext);
			window.display();
		}

		//game window
		if(windowtype == 3)
		{
		window.clear();

		//time
		sf::Time elapse1 = clock1.getElapsedTime();
		sf::Time elapse2 = clock2.getElapsedTime();
		sf::Time elapse3 = clock3.getElapsedTime();
		sf::Time elapseShoot = shootclock.getElapsedTime();
		sf::Time waveElapse = waveclock.getElapsedTime();
		sf::Time elspseability = clockability.getElapsedTime();
		

		
		//wave 
		if (inwave == true && enemycount == 0 && wavedone == true && enemyleft == 0)
		{
			waveclock.restart();
			Player1.mymoney = Player1.mymoney + 50 + (10 * wave);
			inwave = false;
			mainVend.avalible = true;
			if (bulletprojectile.magtype < 4)
			{
				mainVend.magtype = bulletprojectile.magtype;
				mainVend.magbought = false;
			}
		}
		if (inwave == true && enemyleft == 0 && wavedone == false)
		{
			if (gamemode == 1)
			{
				if (wave == 1)
				{
					difficulty = 100;
					enemyleft = difficulty / 20;
				}
				else if (wave <= 10)
				{
					difficulty = difficulty * 105 / 100;
					enemyleft = difficulty / 19;
				}
				else if (wave <= 20)
				{
					difficulty = difficulty * 110 / 100;
					enemyleft = difficulty / 18;
				}
				else
				{
					difficulty = difficulty * 120 / 100;
					enemyleft = difficulty / 17;
				}
			}
			if (gamemode == 2)
			{
				if (wave == 1)
				{
					difficulty = 100;
					enemyleft = difficulty / 20;
				}
				else if (wave <= 10)
				{
					difficulty = difficulty * 105 / 100;
					enemyleft = difficulty / 16;
				}
				else if (wave <= 20)
				{
					difficulty = difficulty * 110 / 100;
					enemyleft = difficulty / 13;
				}
				else
				{
					difficulty = difficulty * 120 / 100;
					enemyleft = difficulty / 10;
				}
			}
			if (gamemode == 3)
			{
				if (wave == 1)
				{
					difficulty = 100;
					enemyleft = difficulty / 20;
				}
				else if (wave <= 10)
				{
					difficulty = difficulty * 110 / 100;
					enemyleft = difficulty / 16;
				}
				else if (wave <= 20)
				{
					difficulty = difficulty * 120 / 100;
					enemyleft = difficulty / 13;
				}
				else
				{
					difficulty = difficulty * 130 / 100;
					enemyleft = difficulty / 10;
				}
			}
			wavedone = true;
		}
		

		//playerupdate
		window.draw(map1);

		//player and weapon update
		Player1.update();
		bulletprojectile.WeaponCheck();
		bulletprojectile.Weaponraritycheck();
		bulletprojectile.equipmentcheck();
		bulletprojectile.bulletdamage = bulletprojectile.bulletdamage * (100 + bloodcount) / 100;
		bulletprojectile.gunsprite.setScale(2.5, 2.5);
		bulletprojectile.gunsprite.setOrigin(20, 20);
		bulletprojectile.weapondirection = Player1.direction;
		
		//enemy update
		counter1 = 0;
		for (iter1 = enemyArray.begin();iter1 != enemyArray.end();iter1++)
		{
			enemyArray[counter1].typeupdate();
			counter1++;
		}

		//cheats
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && sf::Keyboard::isKeyPressed(sf::Keyboard::Num0) && sf::Keyboard::isKeyPressed(sf::Keyboard::Num9) && cheat == false)
		{
			cheat = true;
			std::cout << "Cheat on" << std::endl;
			std::cout << "Press SHIFT + Z for money" << std::endl;
			std::cout << "Press SHIFT + X for best gun rarity" << std::endl;
			std::cout << "Press SHIFT + C to repair wall" << std::endl;
			std::cout << "Press SHIFT + V to kill all enemy" << std::endl;
			std::cout << "Press SHIFT + B to skip wave" << std::endl;
			std::cout << "Press SHIFT + N to BloodRust" << std::endl;
			std::cout << "Press SHIFT + M to die" << std::endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && cheat == true )
		{
			Player1.mymoney += 50;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && sf::Keyboard::isKeyPressed(sf::Keyboard::X) && cheat == true)
		{
			bulletprojectile.weaponrarity = 5;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && sf::Keyboard::isKeyPressed(sf::Keyboard::C) && cheat == true)
		{
			mainwall.hp = mainwall.maxhp;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && sf::Keyboard::isKeyPressed(sf::Keyboard::V) && cheat == true)
		{
			counter1 = 0;
			for (iter1 = enemyArray.begin();iter1 != enemyArray.end();iter1++)
			{
				if (enemyArray[counter1].alive == true)
				{
					enemyArray[counter1].runtime = 0;
					enemyArray[counter1].alive = false;
				}
				counter1++;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && sf::Keyboard::isKeyPressed(sf::Keyboard::B) && cheat == true)
		{
			if (inwave == false && waveElapse.asMilliseconds() > 100)
			{
				wave++;
				waveclock.restart();
				if (gamemode == 1)
				{
					if (wave == 1)
					{
						difficulty = 100;
					}
					else if (wave <= 10)
					{
						difficulty = difficulty * 105 / 100;
					}
					else if (wave <= 20)
					{
						difficulty = difficulty * 110 / 100;
					}
					else
					{
						difficulty = difficulty * 120 / 100;
					}
				}
				if (gamemode == 2)
				{
					if (wave == 1)
					{
						difficulty = 100;
					}
					else if (wave <= 10)
					{
						difficulty = difficulty * 105 / 100;
					}
					else if (wave <= 20)
					{
						difficulty = difficulty * 110 / 100;
					}
					else
					{
						difficulty = difficulty * 120 / 100;
					}
				}
				if (gamemode == 3)
				{
					if (wave == 1)
					{
						difficulty = 100;
					}
					else if (wave <= 10)
					{
						difficulty = difficulty * 110 / 100;
					}
					else if (wave <= 20)
					{
						difficulty = difficulty * 120 / 100;
					}
					else
					{
						difficulty = difficulty * 130 / 100;
					}
				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && sf::Keyboard::isKeyPressed(sf::Keyboard::N) && cheat == true)
		{
			bloodcount ++;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && sf::Keyboard::isKeyPressed(sf::Keyboard::M) && cheat == true)
		{
			mainwall.hp = 0;
		}

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
		
		//totems
		counter1 = 0;
		for (iter1 = enemyArray.begin();iter1 != enemyArray.end();iter1++)
		{
			if (enemyArray[counter1].canuseskill == true)
			{
				Totemsound.play();
				totem1.type = rand() % (3);
				totem1.sprite.setPosition(rand() % (400) + 600,80);
				totem1.typeupdate();
				totemarray.push_back(totem1);
				enemyArray[counter1].canuseskill = false;
			}
			counter1++;
		}
		counter1 = 0;
		for (iter10 = totemarray.begin();iter10 != totemarray.end();iter10++)
		{
			totemarray[counter1].update();
			//window.draw(totemarray[counter1].rect);
			window.draw(totemarray[counter1].sprite);
			counter1++;
		}
		counter1 = 0;
		for (iter10 = totemarray.begin();iter10 != totemarray.end();iter10++)
		{
			if (totemarray[counter1].life == false)
			{
				totemarray.erase(iter10);
				break;
			}
			counter1++;
		}
		counter1 = 0;
		for (iter10 = totemarray.begin();iter10 != totemarray.end();iter10++)
		{
			if (totemarray[counter1].type == 0)
			{
				bulletprojectile.bulletdamage = bulletprojectile.bulletdamage*90/100;
			}
			else if (totemarray[counter1].type == 1)
			{
				counter2 = 0;
				for (iter1 = enemyArray.begin();iter1 != enemyArray.end();iter1++)
				{
					enemyArray[counter2].movespeed = enemyArray[counter2].movespeed*120/100;
					counter2++;
				}
			}
			else if (totemarray[counter1].type == 2)
			{
				counter2 = 0;
				for (iter1 = enemyArray.begin();iter1 != enemyArray.end();iter1++)
				{
					enemyArray[counter2].damage = enemyArray[counter2].damage * 120 / 100;
					counter2++;
				}
			}
			counter1++;

		}

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
						if (enemyArray[counter2].enemytype == 5)
						{
							enemyArray[counter2].enemytype = 4;
						}
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
		
		//slimes
		counter1 = 0;
		for (iter9 = slimeArray.begin();iter9 != slimeArray.end();iter9++)
		{
			slimeArray[counter1].update();
			window.draw(slimeArray[counter1].sprite);
			//window.draw(slimeArray[counter1].rect);
			counter1++;
		}
		counter1 = 0;
		for (iter9 = slimeArray.begin();iter9 != slimeArray.end();iter9++)
		{
			if (slimeArray[counter1].lifetime == false)
			{
				slimeArray.erase(iter9);
				break;
			}
			counter1++;
		}
		counter1 = 0;
		for (iter9 = slimeArray.begin();iter9 != slimeArray.end();iter9++)
		{
			if (slimeArray[counter1].effect == true && Player1.rect.getGlobalBounds().intersects(slimeArray[counter1].rect.getGlobalBounds()))
			{
				Player1.slowed = true;
			}
			counter1++;
		}
		//std::cout << Player1.rect.getPosition().y << std::endl;
		
		//shootbullet&checkreload
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (bulletcooldown < 1 && reload == false)
			{
				bulletprojectile.rect.setPosition(Player1.rect.getPosition().x + 31, Player1.rect.getPosition().y + 26);
				bulletprojectile.direction = Player1.direction;
				bulletArray.push_back(bulletprojectile);
				bulletcount++;
				if (bulletprojectile.weapontype < 6)
				{
					Shoot.setVolume(8.0);
				}
				else
				{
					Shoot.setVolume(20.0);
				}
				if (elapseShoot.asMilliseconds() > 120)
				{
					Shoot.play();
					shootclock.restart();
				}
				if (inusepower.infbullet == true)
				{
					bulletcount = 0;
				}
				//std::cout << 30 - bulletcount << std::endl;
			}
			else if (bulletcount >= bulletprojectile.weaponmag && reload == false)
			{
				Reload.play();
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

		if (enemyleft > 0 && enemycount <= 20)
		{
			spawnrate = spawnrate + difficulty/10;

			if (spawnrate >= 10000)
			{
				spawnrate = 0;
				enemyrand = rand() % (100) + 1;
				enemy1.rect.setPosition(rand() % (20) + 1200, rand() % (260) + 180);
				if (gamemode == 1)
				{
					if (enemyrand <= 10)
					{
						enemy1.enemytype = 2;
					}
					else if (enemyrand <= 40)
					{
						enemy1.enemytype = 1;
					}
					else
					{
						enemy1.enemytype = 0;
					}
				}
				if (gamemode == 2)
				{
					if (enemyrand <= 5)
					{
						enemy1.enemytype = 4;
					}
					else if (enemyrand <= 20)
					{
						enemy1.enemytype = 3;
					}
					else if (enemyrand <= 35)
					{
						enemy1.enemytype = 2;
					}
					else if (enemyrand <= 60)
					{
						enemy1.enemytype = 1;
					}
					else
					{
						enemy1.enemytype = 0;
					}
				}
				if (gamemode == 3)
				{
					if (enemyrand <= 10)
					{
						enemy1.enemytype = 4;
					}
					else if (enemyrand <= 30)
					{
						enemy1.enemytype = 3;
					}
					else if (enemyrand <= 50)
					{
						enemy1.enemytype = 2;
					}
					else if (enemyrand <= 70)
					{
						enemy1.enemytype = 1;
					}
					else
					{
						enemy1.enemytype = 0;
					}
				}
				//std::cout << enemy1.enemytype << std::endl;
				enemy1.difficulty = difficulty;
				enemy1.typeupdate();
				enemy1.hp = enemy1.totalhp;
				enemyArray.push_back(enemy1);
				enemyhpdisplay.text.setPosition(enemy1.rect.getPosition().x, enemy1.rect.getPosition().y - 37);
				enemyhpdisplay.text.setCharacterSize(9);
				enemyhpdisplay.text.setFillColor(sf::Color::Black);
				enemyhptextArray.push_back(enemyhpdisplay);
				enemycount++;
				enemyleft--;
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
						//std::cout << enemyArray[counter2].movespeed << std::endl;
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
				Die.play();
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
				if (enemyArray[counter1].enemytype == 3)
				{
					slime1.sprite.setPosition(rand() % (260) + 40, rand() % (320) + 140);
					slimeArray.push_back(slime1);
					Slime.play();
				}
				if (inusepower.coinboost == true)
				{
					enemyArray[counter1].coindropmax *= 2;
				}
				droptext.moneydropmax = enemyArray[counter1].coindropmax;
				droptext.powerdrop = enemyArray[counter1].powerdropchance;
				droptext.dropupdate();
				if (bloodon == true)
				{
					bloodrop = rand() % (50) + 1;
					if (bloodrop <= enemyArray[counter1].bloodbonus && gamemode == 3)
					{
						bloodcount += 10;
						//std::cout << bloodcount << std::endl;
					}
					else if (bloodrop <= enemyArray[counter1].bloodrop)
					{
						bloodcount++;
						//std::cout << bloodcount << std::endl;
					}
				}
				droptext.text.setPosition(enemyArray[counter1].rect.getPosition().x + 24, enemyArray[counter1].rect.getPosition().y - 32);
				dropdisplayArray.push_back(droptext);
				enemyArray.erase(iter1);
				waveclock.restart();
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
					bloodcount = 0;
					mainVend.cratebought = false;
					Equip.play();
				}
			}
			if (elapse3.asSeconds() > 8)
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
				Buy.play();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && mainVend.laserbought == false && bulletprojectile.laserequiped == false && Player1.mymoney >= 100)
			{
				bulletprojectile.laserequiped = true;
				mainVend.laserbought = true;
				Player1.mymoney -= 100;
				Buy.play();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && mainVend.hammerbought == false && Player1.mymoney >= 300)
			{
				mainwall.repairTool = true;
				mainVend.hammerbought = true;
				Player1.mymoney -= 300;
				Buy.play();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) && mainVend.shieldbought == false && Player1.mymoney >= 300)
			{
				mainwall.shieldequip = true;
				mainwall.hp = 150;
				mainVend.shieldbought = true;
				Player1.mymoney -= 300;
				Buy.play();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) && mainVend.cratebought == false && Player1.mymoney >= 200)
			{
				mainVend.cratebought = true;
				mainCrate.bought = true;
				Player1.mymoney -= 200;
				Buy.play();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6) && mainVend.bloodrustbought == false && Player1.mymoney >= 1000)
			{
				mainVend.bloodrustbought = true;
				bloodon = true;
				bloodcount = 0;
				Player1.mymoney -= 1000;
				Buy.play();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7) && mainVend.btbought == false && Player1.mymoney >= 700)
			{
				mainVend.btbought = true;
				totem1.breakTotem = true;
				Player1.mymoney -= 700;
				Buy.play();
			}
		}
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && mainVend.magbought == true && bulletprojectile.magtype < 4)
		{
			mainVend.magtype = bulletprojectile.magtype;
			mainVend.magbought = false;
		}*/

		//wall && check enemy hit wall
		mainwall.update();
		window.draw(mainwall.sprite);
		counter1 = 0;
		for (iter1 = enemyArray.begin();iter1 != enemyArray.end();iter1++)
		{
			if (enemyArray[counter1].rect.getGlobalBounds().intersects(mainwall.rect.getGlobalBounds()))
			{
				mainwall.hp -= enemyArray[counter1].damage;
				enemyArray[counter1].runtime = 0;
				enemyArray[counter1].alive = false;
				Wallhit.play();
			}
			counter1++;
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
				window.draw(mainVend.bloodrust);
				window.draw(mainVend.breakTotem);
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
				if (mainVend.locked == false)
				{
					if (mainVend.bloodrustbought == false)
					{
						window.draw(mainVend.button6);
						window.draw(mainVend.text6);
					}
					if (mainVend.btbought == false)
					{
						window.draw(mainVend.button7);
						window.draw(mainVend.text7);
					}
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
		
		//draw alot + gui
		lowgui.rarity = bulletprojectile.weaponrarity;
		lowgui.update();
		window.draw(lowgui.topgui);
		window.draw(lowgui.weapongui);
		window.draw(bulletprojectile.gungui);
		window.draw(bulletprojectile.maggui);
		window.draw(bulletprojectile.lasergui);
		mainwall.guiupdate();
		window.draw(mainwall.hpbar);
		window.draw(mainwall.hpgui);
		window.draw(mainwall.text);
		if (totem1.breakTotem == true)
		{
			window.draw(totemgui);
		}
		if (bloodon == true)
		{
			bloodtext.setString(std::to_string(bloodcount));
			window.draw(bloodRusrgui);
			window.draw(bloodtext);
		}
		if (mainwall.repairTool == true)
		{
			window.draw(mainwall.hammer);
		}
		if (mainwall.shieldequip == true)
		{
			window.draw(mainwall.shield);
		}
		
		//score
		gamescore.text.setPosition(480, 10);
		gamescore.text.setFillColor(sf::Color::Cyan);
		gamescore.text.setCharacterSize(36);
		gamescore.text.setString("SCORE : " + std::to_string(killscore));
		window.draw(gamescore.text);
		
		//pause
		Menu.rect.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
		if (Menu.rect.getGlobalBounds().intersects(Menu.pauseRect.getGlobalBounds()))
		{
			Menu.pause.setFillColor(sf::Color::Green);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				Click.play();
				windowtype = 31;
			}
		}
		else
		{
			Menu.pause.setFillColor(sf::Color::White);
		}
		//window.draw(Menu.pauseRect);
		window.draw(Menu.pause);

		//wave display / wave buttons
		if (inwave == false && waveElapse.asSeconds() >= 3)
		{
			if (wave == 0)
			{
				Menu.Next.setString("Start Wave");
			}
			else
			{
				Menu.Next.setString("Next Wave");
			}
			if (Menu.rect.getGlobalBounds().intersects(Menu.NextRect.getGlobalBounds()))
			{
				Menu.Next.setFillColor(sf::Color::Red);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Wave.play();
					wave++;
					inwave = true;
					mainVend.avalible = false;
					wavedone = false;
				}
			}
			else
			{
				Menu.Next.setFillColor(sf::Color::White);
			}
			//window.draw(Menu.NextRect);
			window.draw(Menu.Next);
		}
		if (gamemode == 1)
		{
			Menu.mode.setFillColor(sf::Color::Color(227, 149, 187));
			Menu.mode.setString("Easy");
			Menu.wave.setPosition(200, -35);
			Menu.wave.setString("wave : " + std::to_string(wave));
		}
		else if (gamemode == 2)
		{
			Menu.mode.setFillColor(sf::Color::Color(27, 92, 235));
			Menu.mode.setString("Normal");
			Menu.wave.setPosition(250, -35);
			Menu.wave.setString("wave : " + std::to_string(wave));
		}
		else if (gamemode == 3)
		{
			Menu.mode.setFillColor(sf::Color::Color(133, 31, 17));
			Menu.mode.setString("Hard");
			Menu.wave.setPosition(200, -35);
			Menu.wave.setString("wave : " + std::to_string(wave));
		}
		window.draw(Menu.wave);
		window.draw(Menu.mode);

		//check gameover
		if (mainwall.hp <= 0)
		{
			if (gamemode == 1)
			{
				mainSound.stop();
				FILE* fp;
				char temp[255];
				int score[7];
				std::string names[11];
				std::vector <std::pair<int, std::string>> userScore;
				fp = fopen("./Score.txt", "r");

				for (int i = 0; i < 6; i++)
				{
					fscanf(fp, "%s", &temp);
					names[i] = temp;
					fscanf(fp, "%d", &score[i]);
					userScore.push_back(std::make_pair(score[i], names[i]));
				}

				names[10] = Input;
				score[6] = killscore;
				userScore.push_back(std::make_pair(score[6], names[10]));
				sort(userScore.begin(), userScore.end());

				fclose(fp);
				fopen("./Score.txt", "w");

				for (int i = 6; i >= 1; i--)
				{
					strcpy(temp, userScore[i].second.c_str());
					fprintf(fp, "%s %d\n", temp, userScore[i].first);
				}
				fclose(fp);
			}
			else if (gamemode == 2)
			{
				FILE* fp;
				char temp[255];
				int score[7];
				std::string names[11];
				std::vector <std::pair<int, std::string>> userScore;
				fp = fopen("./Score1.txt", "r");

				for (int i = 0; i < 6; i++)
				{
					fscanf(fp, "%s", &temp);
					names[i] = temp;
					fscanf(fp, "%d", &score[i]);
					userScore.push_back(std::make_pair(score[i], names[i]));
				}

				names[10] = Input;
				score[6] = killscore;
				userScore.push_back(std::make_pair(score[6], names[10]));
				sort(userScore.begin(), userScore.end());

				fclose(fp);
				fopen("./Score1.txt", "w");

				for (int i = 6; i >= 1; i--)
				{
					strcpy(temp, userScore[i].second.c_str());
					fprintf(fp, "%s %d\n", temp, userScore[i].first);
				}
				fclose(fp);
			}
			else if (gamemode == 3)
			{
				FILE* fp;
				char temp[255];
				int score[7];
				std::string names[11];
				std::vector <std::pair<int, std::string>> userScore;
				fp = fopen("./Score2.txt", "r");

				for (int i = 0; i < 6; i++)
				{
					fscanf(fp, "%s", &temp);
					names[i] = temp;
					fscanf(fp, "%d", &score[i]);
					userScore.push_back(std::make_pair(score[i], names[i]));
				}

				names[10] = Input;
				score[6] = killscore;
				userScore.push_back(std::make_pair(score[6], names[10]));
				sort(userScore.begin(), userScore.end());

				fclose(fp);
				fopen("./Score2.txt", "w");

				for (int i = 6; i >= 1; i--)
				{
					strcpy(temp, userScore[i].second.c_str());
					fprintf(fp, "%s %d\n", temp, userScore[i].first);
				}
				fclose(fp);
			}
			windowtype = 4;
		}

		//std::cout << bulletprojectile.bulletfirerate << std::endl;
		window.display();
		}
		
		//game pause
		if (windowtype == 31)
		{
			window.clear();
			Menu.exit.setPosition(558, 400);
			Menu.exitRect.setPosition(550, 400);
			//Menu.index.setPosition(540, 300);
			//Menu.indexRect.setPosition(532, 300);
			Menu.indexRect.setSize(sf::Vector2f(155, 72));
			Menu.exitRect.setSize(sf::Vector2f(110, 72));
			window.draw(map1);
			//exit index
			/*if (Menu.rect.getGlobalBounds().intersects(Menu.indexRect.getGlobalBounds()))
			{
				Menu.index.setFillColor(sf::Color::Green);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Click.play();
					windowtype = 5;
				}
			}
			else
			{
				Menu.index.setFillColor(sf::Color::White);
			}*/
			if (Menu.rect.getGlobalBounds().intersects(Menu.exitRect.getGlobalBounds()))
			{
				Menu.exit.setFillColor(sf::Color::Green);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					BgSound1.play();
					musicClock.restart();
					Click.play();
					ingame = false;
					windowtype = 1;
					for (int i = 0; i < 100; i++)
					{
						counter1 = 0;
						for (iter1 = enemyArray.begin();iter1 != enemyArray.end();iter1++)
						{
							enemyArray.erase(iter1);
							break;
							counter1++;
						}
						counter1 = 0;
						for (iter9 = slimeArray.begin();iter9 != slimeArray.end();iter9++)
						{
							slimeArray.erase(iter9);
							break;
							counter1++;
						}
						counter1 = 0;
						for (iter10 = totemarray.begin();iter10 != totemarray.end();iter10++)
						{
							totemarray.erase(iter10);
							break;
							counter1++;
						}
						counter1 = 0;
						for (iter = bulletArray.begin();iter != bulletArray.end();iter++)
						{
							bulletArray.erase(iter);
							break;
							counter1++;
						}
					}
				}
			}
			else
			{
				Menu.exit.setFillColor(sf::Color::White);
			}
			//back
			Menu.rect.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
			if (Menu.rect.getGlobalBounds().intersects(Menu.backRect.getGlobalBounds()))
			{
				Menu.backtext.setFillColor(sf::Color::Green);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Click.play();
					windowtype = 3;
				}
			}
			else
			{
				Menu.backtext.setFillColor(sf::Color::White);
			}
			//window.draw(Menu.exitRect);
			//window.draw(Menu.indexRect);
			window.draw(Menu.exit);
			//window.draw(Menu.index);
			window.draw(Menu.backtext);
			window.display();
		}

		//gameover
		if (windowtype == 4)
		{
			window.clear();
			//window.draw(menupic);
			//totems
			counter1 = 0;
			for (iter1 = enemyArray.begin();iter1 != enemyArray.end();iter1++)
			{
				if (enemyArray[counter1].canuseskill == true)
				{
					totem1.type = rand() % (3);
					totem1.sprite.setPosition(rand() % (400) + 600, 80);
					totem1.typeupdate();
					totemarray.push_back(totem1);
					enemyArray[counter1].canuseskill = false;
				}
				counter1++;
			}
			counter1 = 0;
			for (iter10 = totemarray.begin();iter10 != totemarray.end();iter10++)
			{
				totemarray[counter1].update();
				//window.draw(totemarray[counter1].rect);
				window.draw(totemarray[counter1].sprite);
				counter1++;
			}
			counter1 = 0;
			for (iter10 = totemarray.begin();iter10 != totemarray.end();iter10++)
			{
				if (totemarray[counter1].life == false)
				{
					totemarray.erase(iter10);
					break;
				}
				counter1++;
			}
			//slime
			counter1 = 0;
			for (iter9 = slimeArray.begin();iter9 != slimeArray.end();iter9++)
			{
				slimeArray[counter1].update();
				window.draw(slimeArray[counter1].sprite);
				//window.draw(slimeArray[counter1].rect);
				counter1++;
			}
			counter1 = 0;
			for (iter9 = slimeArray.begin();iter9 != slimeArray.end();iter9++)
			{
				if (slimeArray[counter1].lifetime == false)
				{
					slimeArray.erase(iter9);
					break;
				}
				counter1++;
			}
			//enemy movement
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
							enemyArray[counter2].gameEnd = true;
							if (enemyArray[counter2].enemytype == 4 || enemyArray[counter2].enemytype == 5)
							{
								enemyArray[counter2].enemytype = 4;
								enemyArray[counter2].walkable = true;
							}
							enemyArray[counter2].update();
							enemyArray[counter2].updatemovement();
							window.draw(enemyArray[counter2].sprite);
						}
						//else if (enemyArray[counter2].alive == false && enemyArray[counter2].died == false)
						else if (enemyArray[counter2].alive == false)
						{
							if (enemyArray[counter2].enemytype == 5)
							{
								enemyArray[counter2].enemytype = 4;
							}
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
			//back
			Menu.rect.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
			if (Menu.rect.getGlobalBounds().intersects(Menu.backRect.getGlobalBounds()))
			{
				Menu.backtext.setFillColor(sf::Color::Green);
				window.draw(Menu.backtext);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					BgSound1.play();
					musicClock.restart();
					Click.play();
					ingame = false;
					windowtype = 1;
					for (int i = 0; i < 100; i++)
					{
						counter1 = 0;
						for (iter1 = enemyArray.begin();iter1 != enemyArray.end();iter1++)
						{
							enemyArray.erase(iter1);
							break;
							counter1++;
						}
						counter1 = 0;
						for (iter9 = slimeArray.begin();iter9 != slimeArray.end();iter9++)
						{
							slimeArray.erase(iter9);
							break;
							counter1++;
						}
						counter1 = 0;
						for (iter10 = totemarray.begin();iter10 != totemarray.end();iter10++)
						{
							totemarray.erase(iter10);
							break;
							counter1++;
						}
						counter1 = 0;
						for (iter = bulletArray.begin();iter != bulletArray.end();iter++)
						{
							bulletArray.erase(iter);
							break;
							counter1++;
						}
					}
				}
			}
			else
			{
				Menu.backtext.setFillColor(sf::Color::White);
				window.draw(Menu.backtext);
			}

			window.display();
		}
		
		//index
		/*if (windowtype == 5)
		{
			window.clear();
			window.draw(menubackg);
			//window.draw(Menu.backRect);
			Menu.rect.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
			if (Menu.rect.getGlobalBounds().intersects(Menu.backRect.getGlobalBounds()))
			{
				Menu.backtext.setFillColor(sf::Color::Green);
				window.draw(Menu.backtext);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Click.play();
					if (ingame == true)
					{
						windowtype = 3;
					}
					else
					{
						windowtype = 1;
					}
					
				}
			}
			else
			{
				Menu.backtext.setFillColor(sf::Color::White);
				window.draw(Menu.backtext);
			}
			window.display();
		}*/

		//leaderboard
		if (windowtype == 6)
		{
			window.clear();
			window.draw(menubackg);
			window.draw(leaderText);
			window.draw(easyText);
			window.draw(normalText);
			window.draw(hardText);
			//window.draw(Menu.backRect);
			for (int i = 0; i < 5; i++)
			{
				window.draw(PlayerName[i]);
				window.draw(PlayerScore[i]);
				window.draw(PlayerName1[i]);
				window.draw(PlayerScore1[i]);
				window.draw(PlayerName2[i]);
				window.draw(PlayerScore2[i]);
			}
			Menu.rect.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
			if (Menu.rect.getGlobalBounds().intersects(Menu.backRect.getGlobalBounds()))
			{
				Menu.backtext.setFillColor(sf::Color::Green);
				window.draw(Menu.backtext);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Click.play();
					windowtype = 1;
				}
			}
			else
			{
				Menu.backtext.setFillColor(sf::Color::White);
				window.draw(Menu.backtext);
			}
			window.display();
		}
		}
	return 0;
}