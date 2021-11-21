#include <time.h>
#include <iostream>
#include <iomanip>

#include "Date.h"

#pragma warning(disable : 4996)		//Щоб не ї###о мозок

using namespace std;

Date::Date()
{
	struct tm* tim;
	time_t tt = time(NULL);		//взяття часу
	tim = localtime(&tt);

	this->day = tim->tm_mday;
	this->mounth = tim->tm_mon + 1;
	this->year = tim->tm_year - 100;
}

Date::Date(int day, int mounth, int year)
{
	this->day = day;
	this->mounth = mounth;
	this->year = year;
}

Date::Date(Date& temp)
{
	this->day = temp.day;
	this->mounth = temp.mounth;
	this->year = temp.year;
}

Date::~Date()
{
}

void Date::show()
{
	cout << this->day << "." << this->mounth << "." << this->year;
}

Date& Date::operator+(int _day)
{
	Date temp(*this);

	temp.day += _day;
	int k = 0;
	while (temp.day > k) {

		switch (temp.mounth) {
		case 1:
			k = 31;
		case 2:
			if (temp.year % 4 == 0) {
				k = 29;
			}
			else {
				k = 28;
			}
		case 3:
			k = 31;
		case 4:
			k = 30;
		case 5:
			k = 31;
		case 6:
			k = 30;
		case 7:
			k = 31;
		case 8:
			k = 31;
		case 9:
			k = 30;
		case 10:
			k = 31;
		case 11:
			k = 30;
		case 12:
			k = 31;
		}

		if (temp.day > k) {
			temp.day -= k;
			temp.mounth += 1;
		}
	}

	return temp;
}

int Date::get_day()
{
	return this->day;
}

int Date::get_mounth()
{
	return this->mounth;
}

int Date::get_year()
{
	return this->year;
}

Date& Date::set_day(int day)
{
	this->day = day;
	return *this;
}

Date& Date::set_mounth(int mounth)
{
	this->mounth = mounth;
	return *this;
}

Date& Date::set_year(int year)
{
	this->year = year;
	return *this;
}
