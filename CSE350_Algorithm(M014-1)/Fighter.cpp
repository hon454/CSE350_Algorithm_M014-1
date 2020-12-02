#include "Fighter.h"

#include <string>

Fighter::Fighter()
{
}

Fighter::Fighter(string name, string country, string year, string status, string number)
	:name(name), country(country), year(year), status(status), number(number)
{
	numberByInteger = stoi(number);
	yearByInteger = stoi(year);
}

string Fighter::getName()
{
	return name;
}

string Fighter::getCountry()
{
	return country;
}

string Fighter::getYear()
{
	return year;
}

std::string Fighter::getStatus()
{
	return status;
}

string Fighter::getNumber()
{
	return number;
}

int Fighter::getNumberByInteger()
{
	return numberByInteger;
}

int Fighter::getYearByInteger()
{
	return yearByInteger;
}