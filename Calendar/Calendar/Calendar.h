#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include "Year.h"
#include <time.h>

extern sf::RenderWindow window;

class Calendar {

	std::vector<Year*> yearList;

	sf::RectangleShape ramka;
	const sf::Vector2f size = sf::Vector2f(window.getSize()) - sf::Vector2f(200, 200);

public:

	Calendar() {

		try {
			if (!dim::font.loadFromFile("arial.ttf")) {

				throw "Error. Cannot load font !";
			}
		}
		catch (char *e) {

			std::cout << e;
		}


		for (int i = 2014; i < 2025; i++) {

			yearList.push_back(new Year(i));

		}

		ramka.setPosition(sf::Vector2f(100, 100));
		ramka.setSize(size);
		ramka.setOutlineThickness(100);
		ramka.setOutlineColor(sf::Color::Black);
		ramka.setFillColor(sf::Color::Transparent);

	}


	void display() {


		time_t theTime = time(NULL);
		struct tm *aTime = localtime(&theTime);

		sf::Vector2f window_size = sf::Vector2f(window.getSize().x, window.getSize().y);
		int maxItems = window_size.y / dim::sizeOfItem_Year.y;


		int i;

		for (i = 0; yearList.at(i)->returnYear() != (aTime->tm_year + 1900); i++);

		i--;

		for (int j = i; j < i + maxItems; j++) {

			yearList.at(j)->dispalay(j - i);
		}

		window.draw(ramka);

	}




};