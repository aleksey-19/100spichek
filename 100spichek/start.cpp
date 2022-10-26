#include <SFML/Graphics.hpp>
#include <iostream>
#include <locale.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "start.h"
#include "game.h"

int menuopen = 1;

void menu(sf::RenderWindow& window)
{
	sf::Texture menuTexture1, menuTexture2, aboutTexture, menuBackground;
	sf::Sprite menu1, menu2, about, menuBg;

	bool isMenu = true;
	int menuNum = 0;

	//ÇÀÃĞÓÇÊÀ ÒÅÊÑÒÓĞ
	menuTexture1.loadFromFile("resources/Knopka.png");
	menuTexture2.loadFromFile("resources/Exit.png");
	aboutTexture.loadFromFile("resources/namr_game.png");
	menuBackground.loadFromFile("resources/fon_menu.png");

	// ÎÁÚßÂËÅÍÈÅ ÊÍÎÏÊÈ "ÍÀ×ÒÜ ÈÃĞÓ"
	menu1.setTexture(menuTexture1);
	menu1.setPosition(100, 30);
	menu1.setScale(0.167, 0.167);

	// ÎÁÚßÂËÅÍÈÅ ÊÍÎÏÊÈ "ÂÛÕÎÄ ÈÇ ÈÃĞÛ"
	menu2.setTexture(menuTexture2);
	menu2.setPosition(100, 150);
	menu2.setScale(0.167, 0.167);

	// ÇÀÃĞÓÇÊÀ ÔÎÍÀ ÄËß ÌÅÍŞ
	menuBg.setTexture(menuBackground);
	menuBg.setPosition(0, 0);
	menuBg.setScale(0.167, 0.167);

	while (isMenu)
	{
		menu1.setColor(sf::Color::White);
		menu2.setColor(sf::Color::White);
		menuNum = 0;

		//ÏĞÎÈÑÕÎÄÈÒ ÏÎÄÑÒÂÅÒÊÀ ÏĞÈ ÍÀÂÅÄÅÍÈÅ ÍÀ ÊÍÎÏÊÓ "ÍÀ×ÀÒÜ ÈÃĞÓ"
		if (sf::IntRect(100, 30, 250, 50).contains(sf::Mouse::getPosition(window)))
		{
			menu1.setColor(sf::Color::Blue);
			menuNum = 1;
		}

		//ÏĞÎÈÑÕÎÄÈÒ ÏÎÄÑÒÂÅÒÊÀ ÏĞÈ ÍÀÂÅÄÅÍÈÅ ÍÀ ÊÍÎÏÊÓ "ÂÛÕÎÄ"
		if (sf::IntRect(100, 150, 250, 50).contains(sf::Mouse::getPosition(window)))
		{
			menu2.setColor(sf::Color::Blue);
			menuNum = 2;
		}

		//ÑÎÁÛÒÈß ÍÀÆÀÒÈß ÍÀ "ËÊÌ"
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (menuNum == 1)  //ÂÛÊËŞ×ÈÒÜ ÎÊÍÎ Ñ "ÌÅÍŞ" ÄËß ÄÀËÜÍÅÉØÅÃÎ ÇÀÏÓÑÊÀ ÏĞÎÃĞÀÌÌÛ
			{	
				isMenu = false;
				window.clear(sf::Color(129, 181, 221));
				menuopen = 0;
			}
			if (menuNum == 2)	//ÂÛÊËŞ×ÈÒÜ ÏĞÎÃĞÀÌÌÓ
			{
				window.close();
				exit(0);
			}
		}
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) 
			{
				window.close();
				exit(0);
			}
		}
		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.display();
	}
}

int start()
{
	HWND hConsole = GetConsoleWindow(); //Åñëè êîìïèëÿòîğ ñòàğûé çàìåíèòü íà GetForegroundWindow()
	ShowWindow(hConsole, SW_HIDE);      //ïğÿ÷åì îêîíî êîíñîëè

	sf::RenderWindow window(sf::VideoMode(640, 400), L"100 ñïè÷åê");
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		if (menuopen == 1)
		{
			menu(window);   //âûçîâ ìåíş
		}
		if (menuopen == 0)
		{
			game(window);   //çàêğûòèå ìåíş
			menuopen = 1;
		}
	}
	return 0;
}