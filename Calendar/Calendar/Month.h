#pragma once
#include "Week.h"
#include <list>
#include <string.h>


class Month
{
public:
	Month();
	~Month();

	std::list<Week> Weeks;
	std::string Name;


};