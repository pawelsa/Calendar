#include "Calendar.h"
#include "Year.h"


	sf::RenderWindow window(sf::VideoMode(1280, 720), "Calendar");



int main() {

	auto Year = new Year(2018);


	while (window.isOpen())
	{

		Calendar *newCalendar = new Calendar();


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		newCalendar->display();

		window.display();
	}

	return 0;





}