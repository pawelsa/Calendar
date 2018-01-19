#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Dimensions.h"

extern sf::RenderWindow window;

class Year {

	sf::RectangleShape year_overview;
	sf::Text year_number;
	const int year;
	

public:

	Year(int mYear) :year(mYear) {


		year_overview.setSize(dim::sizeOfItem_Year);
		year_overview.setFillColor(sf::Color::Transparent);
		year_overview.setOutlineThickness(5);

		try {

			

			year_number.setFont(dim::font);
			year_number.setCharacterSize(25);
			year_number.setFillColor(sf::Color::White);

		}
		catch (char *e) {

			std::cout << e;
			exit(1);
		}

		year_number.setString(std::to_string(mYear));

	}

	void dispalay(int which_on_screen) {

		year_overview.setPosition(dim::itemOffset_Year + sf::Vector2f(0, which_on_screen * 170));
		year_number.setPosition(dim::itemOffset_Year + sf::Vector2f(0, which_on_screen * 170) + dim::textOffset_Year);

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

	}

	int returnYear() {

		return year;
	}




};
