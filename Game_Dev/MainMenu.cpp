#include<iostream>
#include"Totems.h"
#include"MainMenu.h"

MainMenu::MainMenu()
{
	start.setFillColor(sf::Color::White);
	start.setCharacterSize(60);
	start.setPosition(30, 400);
	start.setString("Start");
	start.setOutlineThickness(3);
	index.setFillColor(sf::Color::White);
	index.setCharacterSize(60);
	index.setPosition(30, 500);
	index.setString("Index");
	index.setOutlineThickness(3);
	leaderboard.setFillColor(sf::Color::White);
	leaderboard.setCharacterSize(60);
	leaderboard.setPosition(30, 600);
	leaderboard.setString("Leaderboard");
	leaderboard.setOutlineThickness(3);
	exit.setFillColor(sf::Color::White);
	exit.setCharacterSize(60);
	exit.setPosition(30, 700);
	exit.setString("Exit");
	exit.setOutlineThickness(3);
	startRect.setPosition(22, 400);
	startRect.setSize(sf::Vector2f(400, 72));
	leaderRect.setPosition(22, 600);
	leaderRect.setSize(sf::Vector2f(400, 72));
	exitRect.setPosition(22, 700);
	exitRect.setSize(sf::Vector2f(400, 72));
	rect.setPosition(0,0);
	rect.setSize(sf::Vector2f(2, 2));
	backtext.setFillColor(sf::Color::Green);
	backtext.setCharacterSize(60);
	backtext.setPosition(1030, 700);
	backtext.setString("Back");
	backtext.setOutlineThickness(3);
	backRect.setPosition(1015, 700);
	backRect.setSize(sf::Vector2f(150, 72));
	easyRect.setPosition(100, 100);
	easyRect.setSize(sf::Vector2f(300, 500));
	normalRect.setPosition(450, 100);
	normalRect.setSize(sf::Vector2f(300, 500));
	hardRect.setPosition(800, 100);
	hardRect.setSize(sf::Vector2f(300, 500));
	easy.setFillColor(sf::Color::White);
	easy.setCharacterSize(60);
	easy.setPosition(280, 520);
	easy.setString("Easy");
	easy.setOutlineThickness(3);
	normal.setFillColor(sf::Color::White);
	normal.setCharacterSize(60);
	normal.setPosition(563, 520);
	normal.setString("Normal");
	normal.setOutlineThickness(3);
	hard.setFillColor(sf::Color::White);
	hard.setCharacterSize(60);
	hard.setPosition(970, 520);
	hard.setString("Hard");
	hard.setOutlineThickness(3);
	nameRect.setPosition(100, 650);
	nameRect.setOutlineThickness(4);
	nameRect.setOutlineColor(sf::Color::Black);
	nameRect.setSize(sf::Vector2f(620, 120));
	confirm.setFillColor(sf::Color::White);
	confirm.setCharacterSize(60);
	confirm.setPosition(750, 640);
	confirm.setString("Confirm");
	confirm.setOutlineThickness(3);
	cancel.setFillColor(sf::Color::White);
	cancel.setCharacterSize(60);
	cancel.setPosition(750, 710);
	cancel.setString("Cancel");
	cancel.setOutlineThickness(3);
	confirmRect.setPosition(740, 646);
	confirmRect.setSize(sf::Vector2f(220, 62));
	cancelRect.setPosition(740, 716);
	cancelRect.setSize(sf::Vector2f(220, 62));
	pauseRect.setPosition(1050, 0);
	pauseRect.setSize(sf::Vector2f(105, 60));
	pause.setFillColor(sf::Color::White);
	pause.setCharacterSize(35);
	pause.setPosition(1060, 5);
	pause.setString("Pause");
	pause.setOutlineThickness(3);
	wave.setFillColor(sf::Color::Black);
	wave.setCharacterSize(80);
	wave.setPosition(100, 0);
	wave.setString("Pause");
	mode.setFillColor(sf::Color::White);
	mode.setCharacterSize(50);
	mode.setPosition(80, 0);
	mode.setString("Pause");
	mode.setOutlineThickness(3);
	Next.setFillColor(sf::Color::White);
	Next.setCharacterSize(50);
	Next.setPosition(950, 540);
	Next.setString("Pause");
	Next.setOutlineThickness(3);
	NextRect.setPosition(942, 540);
	NextRect.setSize(sf::Vector2f(230, 65));
	Input.setFillColor(sf::Color::Black);
	Input.setCharacterSize(80);
	Input.setPosition(110, 660);
	easysprite.setPosition(easyRect.getPosition());
	easysprite.setScale(5, 5);
	easysprite.setTextureRect(sf::IntRect(0, 0, 60, 100));
	normalsprite.setPosition(normalRect.getPosition());
	normalsprite.setScale(5, 5);
	normalsprite.setTextureRect(sf::IntRect(60, 0, 60, 100));
	hardsprite.setPosition(hardRect.getPosition());
	hardsprite.setScale(5, 5);
	hardsprite.setTextureRect(sf::IntRect(120, 0, 60, 100));
}
void MainMenu::update()
{

}