#include"Vending.h"
#include"entity.h"
Vending::Vending()
{
	sprite.setPosition(50, 80);
	sprite.setScale(1.2, 1.2);
	gui.setPosition(20, 120);
	gui.setScale(0.9,0.9);
	gun.setTextureRect(sf::IntRect(384, 0, 64, 64));
	mag.setPosition(23, 123);
	laser.setPosition(23, 190);
	hammer.setPosition(23, 255);
	shield.setPosition(23, 320);
	bloodrust.setPosition(23, 450);
	breakTotem.setPosition(23, 515);
	gun.setPosition(23, 383);
	button1.setTextureRect(sf::IntRect(128, 0, 64, 64));
	button2.setTextureRect(sf::IntRect(192, 0, 64, 64));
	button3.setTextureRect(sf::IntRect(256, 0, 64, 64));
	button4.setTextureRect(sf::IntRect(320, 0, 64, 64));
	button5.setTextureRect(sf::IntRect(384, 0, 64, 64));
	button6.setTextureRect(sf::IntRect(448, 0, 64, 64));
	button7.setTextureRect(sf::IntRect(512, 0, 64, 64));
	button1.setPosition(63, 163);
	button2.setPosition(63, 228);
	button3.setPosition(63, 293);
	button4.setPosition(63, 358);
	button5.setPosition(63, 423);
	button6.setPosition(63, 488);
	button7.setPosition(63, 553);
	button1.setScale(0.4, 0.4);
	button2.setScale(0.4, 0.4);
	button3.setScale(0.4, 0.4);
	button4.setScale(0.4, 0.4);
	button5.setScale(0.4, 0.4);
	button6.setScale(0.4, 0.4);
	button7.setScale(0.4, 0.4);
	text1.setPosition(30, 166);
	text2.setPosition(30, 231);
	text3.setPosition(30, 296);
	text4.setPosition(30, 361);
	text5.setPosition(30, 426);
	text1.setCharacterSize(18);
	text2.setCharacterSize(18);
	text3.setCharacterSize(18);
	text4.setCharacterSize(18);
	text5.setCharacterSize(18);
	text1.setFillColor(sf::Color::Yellow);
	text2.setFillColor(sf::Color::Yellow);
	text3.setFillColor(sf::Color::Yellow);
	text4.setFillColor(sf::Color::Yellow);
	text5.setFillColor(sf::Color::Yellow);
	text2.setString("100");
	text3.setString("300");
	text4.setString("300");
	text5.setString("200");
	text6.setString("1000");
	text7.setString("700");
	text6.setFillColor(sf::Color::Yellow);
	text7.setFillColor(sf::Color::Yellow);
	text6.setCharacterSize(15);
	text7.setCharacterSize(18);
	text6.setPosition(28, 491);
	text7.setPosition(30, 556);
}
void Vending::update()
{
	if (laserbought == false)
	{
		laser.setTextureRect(sf::IntRect(192, 0, 64, 64));
	}
	else if (laserbought == true)
	{
		laser.setTextureRect(sf::IntRect(192, 64, 64, 64));
	}
	if (hammerbought == false)
	{
		hammer.setTextureRect(sf::IntRect(256, 0, 64, 64));
	}
	else if (hammerbought == true)
	{
		hammer.setTextureRect(sf::IntRect(256, 64, 64, 64));
	}
	if (shieldbought == false)
	{
		shield.setTextureRect(sf::IntRect(320, 0, 64, 64));
	}
	else if (shieldbought == true)
	{
		shield.setTextureRect(sf::IntRect(320, 64, 64, 64));
	}
	if (magtype == 1 && magbought == false)
	{
		mag.setTextureRect(sf::IntRect(0, 0, 64, 64));
		magprice = 200;
	}
	else if (magtype == 1 && magbought == true)
	{
		mag.setTextureRect(sf::IntRect(0, 64, 64, 64));
	}
	else if (magtype == 2 && magbought == false)
	{
		mag.setTextureRect(sf::IntRect(64, 0, 64, 64));
		magprice = 250;
	}
	else if (magtype == 2 && magbought == true)
	{
		mag.setTextureRect(sf::IntRect(64, 64, 64, 64));
	}
	else if (magtype == 3 && magbought == false)
	{
		mag.setTextureRect(sf::IntRect(128, 0, 64, 64));
		magprice = 400;
	}
	else if (magtype == 3 && magbought == true)
	{
		mag.setTextureRect(sf::IntRect(128, 64, 64, 64));
	}
	if (locked == false)
	{
		if (bloodrustbought == false)
		{
			bloodrust.setTextureRect(sf::IntRect(448, 0, 64, 64));
		}
		else if (bloodrustbought == true)
		{
			bloodrust.setTextureRect(sf::IntRect(448, 64, 64, 64));
		}
		if (btbought == false)
		{
			breakTotem.setTextureRect(sf::IntRect(512, 0, 64, 64));
		}
		else if (btbought == true)
		{
			breakTotem.setTextureRect(sf::IntRect(512, 64, 64, 64));
		}
	}
	else
	{
		bloodrust.setTextureRect(sf::IntRect(0, 128, 64, 64));
		breakTotem.setTextureRect(sf::IntRect(0, 128, 64, 64));
	}
}