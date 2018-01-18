#pragma once
#include "Event.h"
#include <string>
#include <vector>

class Day
{
public:



	Day();
	Day(int dayNumber)
	{
		this->NameOfDay = DayNames.at(dayNumber);
		this->DayNumber = dayNumber;
	};


	~Day()
	{

	}

	std::list<Event> EventList;

	std::string NameOfDay;
	int DayNumber;

	std::vector<std::string> DayNames = { "Monday", "Teusday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	
};