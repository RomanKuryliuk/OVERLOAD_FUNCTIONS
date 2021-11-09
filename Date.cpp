#include <time.h>
#include <iostream>
#include <iomanip>

#include "Date.h"

#pragma warning(disable : 4996)		//��� �� �###� �����

using namespace std;

Date::Date()
{
	struct tm* tim;
	time_t tt = time(NULL);		//������ ����
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
