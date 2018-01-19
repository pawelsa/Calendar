#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include "Year.h"
#include <time.h>

extern sf::RenderWindow window;

class Calendar {


	sf::RectangleShape BlackOutliner;
	const sf::Vector2f SizeOfBlackOutliner = sf::Vector2f(window.getSize()) - sf::Vector2f(200, 200);	//200 black outlier around calendar

	sf::RectangleShape year_overview;	//One square

	std::vector<Year*> YearList;


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




		time_t theTime = time(NULL);
		struct tm *aTime = localtime(&theTime);


		for (int i = aTime->tm_year; i < 2025; i++) {

			YearList.push_back(new Year(i));

		}


		year_overview.setSize(dim::sizeOfItem_Year);
		year_overview.setFillColor(sf::Color::Transparent);
		year_overview.setOutlineThickness(5);

		try {

			year_number.setFont(dim::font);
			year_number.setCharacterSize(dim::NumberSizeInYear);
			year_number.setFillColor(sf::Color::White);

		}
		catch (char *e) {

			std::cout << e;
			exit(1);
		}

		year_number.setString(std::to_string(mYear));


		BlackOutliner.setPosition(sf::Vector2f(100, 100));
		BlackOutliner.setSize(SizeOfBlackOutliner);
		BlackOutliner.setOutlineThickness(100);
		BlackOutliner.setOutlineColor(sf::Color::Black);
		BlackOutliner.setFillColor(sf::Color::Transparent);








	}


	void display() {


		time_t theTime = time(NULL);
		struct tm *aTime = localtime(&theTime);

		sf::Vector2f window_size = sf::Vector2f(window.getSize().x, window.getSize().y);
		int maxItems = window_size.y / dim::sizeOfItem_Year.y;


		int i;

		for (i = 0; YearList.at(i)->returnYear() != (aTime->tm_year + 1900); i++);

		i--;

		for (int j = i; j < i + maxItems; j++) {

			YearList.at(j)->dispalay(j - i);
		}


	}

	void dispalay(int which_on_screen) {



		year_overview.setPosition(dim::itemOffset_Year + sf::Vector2f(0, which_on_screen * (dim::sizeOfItem_Year.y + 20)));		//20 - distance between squares
		year_number.setPosition(dim::itemOffset_Year + sf::Vector2f(0, which_on_screen * (dim::sizeOfItem_Year.y + 20)) + dim::textOffset_Year);

		int control = (window.getSize().y / dim::sizeOfItem_Year.y) - 1;

		if (which_on_screen == 0 || which_on_screen == control) {

			sf::Color to_alpha = year_overview.getOutlineColor();
			to_alpha.a = 135;

			year_overview.setOutlineColor(to_alpha);
		}
		else if (year_overview.getOutlineColor().a == 135) {

			sf::Color to_alpha = year_overview.getOutlineColor();
			to_alpha.a = 255;

			year_overview.setOutlineColor(to_alpha);
		}

		window.draw(year_overview);
		window.draw(year_number);

		window.draw(BlackOutliner);		//have to be the last
	}


};