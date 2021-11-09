#include <string>
#include <iostream>

#include "Cook.h"

using namespace std;

Cook::Cook()
{
	name = new char[7];
	strcpy_s(name, sizeof "noname", "noname");
	surname = new char[10];
	strcpy_s(surname, sizeof "nosurname", "nosurname");

	cout << "Конструктор Cook за замовчування " << this << endl;
}

Cook::Cook(char* _name, char* _surname)
{
	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);
	surname = new char[strlen(_surname) + 1];
	strcpy_s(surname, strlen(_surname) + 1, _surname);

	cout << "Конструктор Cook з параметрами " << this << endl;
}

Cook::Cook(Cook& _cook)
{
	name = new char[strlen(_cook.name) + 1];
	strcpy_s(name, strlen(_cook.name) + 1, _cook.name);
	surname = new char[strlen(_cook.surname) + 1];
	strcpy_s(surname, strlen(_cook.surname) + 1, _cook.surname);

	cout << "Конструктор Cook копіювання " << this << endl;
}

Cook::~Cook()
{
	cout << "Деструктор Cook " << this << endl;
}

char* Cook::get_name()
{
	return name;
}

char* Cook::get_surname()
{
	return surname;
}

Cook& Cook::set_name(char* _name)
{
	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);
	return *this;
}

Cook& Cook::set_surname(char* _surname)
{
	surname = new char[strlen(_surname) + 1];
	strcpy_s(surname, strlen(_surname) + 1, _surname);
	return *this;
}

void Cook::show()
{
	cout << name << ", " << surname << endl;
}
