#include <SFML/Graphics.hpp>
#include <iostream>
#include <locale.h>
#include <ctime>
#include <cstdlib>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <string>
#include <sstream>
#include "game.h"

sf::RenderWindow window;
sf::Image image, image2, kucka1, INPUTs, menuplayer, player1, player2, fonSchetcik, spichka;
sf::Texture texture, texture2, tex_kucka1, tex_INPUTs, tex_menuplayer, tex_player1, tex_player2, tex_fonSchetcik, tex_spichka;
sf::Sprite sprite, sprite2, sprite_kucha1, sp_INPUTs, sp_menuplayer, sp_player1, sp_player2, sp_fonSchetcik, sp_spichka;
sf::Font font;
sf::Text text, winner;

bool funFonGame()
{
	//ÔÎÍ ÈÃÐÛ
	image.loadFromFile("resources/fon1.png");
	if (image.loadFromFile("resources/fon1.png"))
	{
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setPosition(0, 0);
		sprite.setScale(0.167f, 0.167f);
		return true;
	}
	else
	{
		return false;
	}
}

bool funKychaSpichek()
{
	//ÊÓ×À ÑÏÈ×ÅÊ
	kucka1.loadFromFile("resources/kucha1.png");
	if (kucka1.loadFromFile("resources/kucha1.png"))
	{
		tex_kucka1.loadFromImage(kucka1);
		sprite_kucha1.setTexture(tex_kucka1);
		sprite_kucha1.setPosition(270, 150);
		sprite_kucha1.setScale(0.167f, 0.167f);
		return true;
	}
	else
	{
		return false;
	}
}

bool funSpichka()
{
	//ÑÏÈ×ÊÀ
	spichka.loadFromFile("resources/spichka_1.png");
	if (spichka.loadFromFile("resources/spichka_1.png"))
	{
		tex_spichka.loadFromImage(spichka);
		sp_spichka.setTexture(tex_spichka);
		sp_spichka.setScale(0.167f, 0.167f);
		return true;
	}
	else
	{
		return false;
	}
}

bool funKnopki()
{
	//ÊÍÎÏÊÈ ÂÛÁÎÐÀ ÊÎËÈ×ÅÑÒÂÀ ÑÏÈ×ÅÊ ÄËß ÇÀÁÎÐÀ
	INPUTs.loadFromFile("resources/INPUT.png");
	if (INPUTs.loadFromFile("resources/INPUT.png"))
	{
		tex_INPUTs.loadFromImage(INPUTs);
		sp_INPUTs.setTexture(tex_INPUTs);
		sp_INPUTs.setPosition(70, 300);
		sp_INPUTs.setScale(0.167f, 0.167f);
		return true;
	}
	else
	{
		return false;
	}
}

bool funFonPlayers()
{
	//ÔÎÍ ÄËß ÈÃÐÎÊÎÂ
	menuplayer.loadFromFile("resources/bumplayer.png");
	if (menuplayer.loadFromFile("resources/bumplayer.png"))
	{
		tex_menuplayer.loadFromImage(menuplayer);
		sp_menuplayer.setTexture(tex_menuplayer);
		sp_menuplayer.setPosition(70, 70);
		sp_menuplayer.setScale(0.167f, 0.167f);
		return true;
	}
	else
	{
		return false;
	}
}

bool funSpTwoPlayer()
{
	//ÑÏÐÀÉÒ ÂÒÎÐÎÃÎ ÈÃÐÎÊÀ
	player1.loadFromFile("resources/player1.png");
	if (player1.loadFromFile("resources/player1.png"))
	{
		tex_player1.loadFromImage(player1);
		sp_player1.setTexture(tex_player1);
		sp_player1.setPosition(80, 80);
		sp_player1.setScale(0.167f, 0.167f);
		return true;
	}
	else
	{
		return false;
	}
}

bool funSpOnePlayer()
{
	//ÑÏÐÀÉÒ ÏÅÐÂÎÃÎ ÈÃÐÎÊÀ
	player2.loadFromFile("resources/player2.png");
	if (player2.loadFromFile("resources/player2.png"))
	{
		tex_player2.loadFromImage(player2);
		sp_player2.setTexture(tex_player2);
		sp_player2.setPosition(80, 80);
		sp_player2.setScale(0.167f, 0.167f);
		return true;
	}
	else
	{
		return false;
	}
}

bool funFont()
{
	//ÎÁÚßÂËßÅÌ ÒÈÏ ØÐÈÔÒÀ
	font.loadFromFile("resources/text.otf");
	if (font.loadFromFile("resources/text.otf"))
		return true;
	else
		return false;
}

bool funSchetchik()
{
	//Ñ×¨Ò×ÈÊ
	fonSchetcik.loadFromFile("resources/bumplayer.png");
	if (fonSchetcik.loadFromFile("resources/bumplayer.png"))
	{
		tex_fonSchetcik.loadFromImage(fonSchetcik);
		sp_fonSchetcik.setTexture(tex_fonSchetcik);
		sp_fonSchetcik.setPosition(255, 78);
		sp_fonSchetcik.setScale(0.137, 0.167);
		//ÒÅÊÑÒ Ñ×¨Ò×ÈÊÀ
		text.setFont(font);
		text.setCharacterSize(48);
		text.setFillColor(sf::Color::Black);
		text.setPosition(280, 75);
		return true;
	}
	else
		return false;
}

bool funTxtWinner()
{
	//ÒÅÊÑÒ ÏÎÁÅÄÈÒÅËß
	winner.setFont(font);
	winner.setCharacterSize(40);
	winner.setFillColor(sf::Color::Black);
	winner.setPosition(170, 80);
	return true;
}

void loadGame()
{
	funFonGame();
	funKychaSpichek();
	funSpichka();
	funKnopki();
	funFonPlayers();
	funSpTwoPlayer();
	funSpOnePlayer();
	funFont();
	funSchetchik();
	funTxtWinner();
}

void game(sf::RenderWindow& window)
{
	int InitialCount = 100;
	int Count, Num, Player;
	bool Correct;
	int menuNum = 0;
	int gameNum = 0;
	bool isGame = true;

	Player = 1;

	window.clear(sf::Color::Black);

	loadGame();

	while (isGame)
	{
		window.clear(sf::Color::Black);
		window.draw(sprite);
		window.draw(sprite_kucha1);
		window.draw(sp_INPUTs);
		window.draw(sp_fonSchetcik);
		window.draw(text);

		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				exit(0);
			}
			if (InitialCount > 0 && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
			{
				if (sf::IntRect(75, 303, 42, 75).contains(sf::Mouse::getPosition(window)))
				{
					if (gameNum == 1 && Player == 1)
					{
						InitialCount = InitialCount - 1;
						Player = 2;
					}
					else
					{
						InitialCount = InitialCount - 1;
						Player = 1;
					}
				}
				if (sf::IntRect(119, 303, 47, 75).contains(sf::Mouse::getPosition(window)))
				{
					if (gameNum == 2 && Player == 1)
					{
						InitialCount = InitialCount - 2;
						Player = 2;
					}
					else
					{
						InitialCount = InitialCount - 2;
						Player = 1;
					}
				}
				if (sf::IntRect(170, 303, 40, 75).contains(sf::Mouse::getPosition(window)))
				{
					if (gameNum == 3 && Player == 1)
					{
						InitialCount = InitialCount - 3;
						Player = 2;
					}
					else
					{
						InitialCount = InitialCount - 3;
						Player = 1;
					}
				}
				if (sf::IntRect(215, 303, 40, 75).contains(sf::Mouse::getPosition(window)))
				{
					if (gameNum == 4 && Player == 1)
					{
						InitialCount = InitialCount - 4;
						Player = 2;
					}
					else
					{
						InitialCount = InitialCount - 4;
						Player = 1;
					}
				}
				if (sf::IntRect(260, 303, 44, 75).contains(sf::Mouse::getPosition(window)))
				{
					if (gameNum == 5 && Player == 1)
					{
						InitialCount = InitialCount - 5;
						Player = 2;
					}
					else
					{
						InitialCount = InitialCount - 5;
						Player = 1;
					}
				}
				if (sf::IntRect(306, 303, 44, 75).contains(sf::Mouse::getPosition(window)))
				{
					if (gameNum == 6 && Player == 1)
					{
						InitialCount = InitialCount - 6;
						Player = 2;
					}
					else
					{
						InitialCount = InitialCount - 6;
						Player = 1;
					}
				}
				if (sf::IntRect(354, 303, 44, 75).contains(sf::Mouse::getPosition(window)))
				{
					if (gameNum == 7 && Player == 1)
					{
						InitialCount = InitialCount - 7;
						Player = 2;
					}
					else
					{
						InitialCount = InitialCount - 7;
						Player = 1;
					}
				}
				if (sf::IntRect(402, 303, 44, 75).contains(sf::Mouse::getPosition(window)))
				{
					if (gameNum == 8 && Player == 1)
					{
						InitialCount = InitialCount - 8;
						Player = 2;
					}
					else
					{
						InitialCount = InitialCount - 8;
						Player = 1;
					}
				}
				if (sf::IntRect(449, 303, 44, 75).contains(sf::Mouse::getPosition(window)))
				{
					if (gameNum == 9 && Player == 1)
					{
						InitialCount = InitialCount - 9;
						Player = 2;
					}
					else
					{
						InitialCount = InitialCount - 9;
						Player = 1;
					}
				}
				if (sf::IntRect(499, 303, 50, 75).contains(sf::Mouse::getPosition(window)))
				{
					if (gameNum == 10 && Player == 1)
					{
						InitialCount = InitialCount - 10;
						Player = 2;
					}
					else
					{
						InitialCount = InitialCount - 10;
						Player = 1;
					}
				}
			}
			text.setString(std::to_string(InitialCount));
		}
		if (sf::IntRect(100, 30, 50, 50).contains(sf::Mouse::getPosition(window)))
			gameNum = 1;
		if (sf::IntRect(82, 303, 42, 75).contains(sf::Mouse::getPosition(window)))
			gameNum = 1;
		if (sf::IntRect(122, 303, 42, 75).contains(sf::Mouse::getPosition(window)))
			gameNum = 2;
		if (sf::IntRect(162, 303, 42, 75).contains(sf::Mouse::getPosition(window)))
			gameNum = 3;
		if (sf::IntRect(207, 303, 42, 75).contains(sf::Mouse::getPosition(window)))
			gameNum = 4;
		if (sf::IntRect(257, 303, 42, 75).contains(sf::Mouse::getPosition(window)))
			gameNum = 5;
		if (sf::IntRect(297, 303, 42, 75).contains(sf::Mouse::getPosition(window)))
			gameNum = 6;
		if (sf::IntRect(347, 303, 42, 75).contains(sf::Mouse::getPosition(window)))
			gameNum = 7;
		if (sf::IntRect(390, 303, 42, 75).contains(sf::Mouse::getPosition(window)))
			gameNum = 8;
		if (sf::IntRect(450, 303, 42, 75).contains(sf::Mouse::getPosition(window)))
			gameNum = 9;
		if (sf::IntRect(490, 303, 58, 75).contains(sf::Mouse::getPosition(window)))
			gameNum = 10;
		if (sf::IntRect(0, 0, 640, 250).contains(sf::Mouse::getPosition(window)))
			gameNum = 11;

		if (Player == 1)
		{
			window.draw(sp_menuplayer);
			window.draw(sp_player1);
			if (InitialCount <= 0)
			{
				winner.setString(L"Ïîáåäèòåëü Èãðîê 2");
				window.draw(sprite);
				window.draw(winner);
				if (gameNum == 11 && event.type == sf::Event::MouseButtonReleased)
				{
					isGame = false;
				}
			}
		}
		if (Player == 2)
		{
			window.draw(sp_menuplayer);
			window.draw(sp_player2);
			if (InitialCount <= 0)
			{
				winner.setString(L"Ïîáåäèòåëü Èãðîê 1");
				window.draw(sprite);
				window.draw(winner);
				if (gameNum == 11 && event.type == sf::Event::MouseButtonReleased)
				{
					isGame = false;
				}
			}
		}
		window.display();
	}
}