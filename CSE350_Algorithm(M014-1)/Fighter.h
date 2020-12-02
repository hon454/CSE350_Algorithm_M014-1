#pragma once

#include <string>
using namespace std;

class Fighter
{
private:
	string name;
	string country;
	string year;
	string status;
	string number;
	int numberByInteger;
	int yearByInteger;
public:
	Fighter();
	Fighter(string name, string country, string year, string status, string number);
	string getName();
	string getCountry();
	string getYear();
	string getStatus();
	string getNumber();
	int getNumberByInteger();
	int getYearByInteger();
};