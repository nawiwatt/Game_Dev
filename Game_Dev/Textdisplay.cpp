#include<iostream>
#include"entity.h"
#include"Textdisplay.h"
textdisplay::textdisplay()
{
	text.setFillColor(sf::Color::Red);
	text.setCharacterSize(50);
	text.setString(stringtext);
}
void textdisplay::update()
{
	text.move(0, -0.2);
	counter++;
	if (counter >= lifetime)
	{
		textend = true;
	}
}
void textdisplay::dropupdate()
{
	moneydrop = generateRandom(1,moneydropmax);
	checkmoneydrop = true;
	if (generateRandom(0, powerdrop) == 0)
	{
		checkpowerdrop = true;
	}
	else
	{
		checkpowerdrop = false;
	}
}