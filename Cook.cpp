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

bool Cook::operator==(Cook& _cook)
{
	if (name == _cook.name) {
		if (surname == _cook.surname) {
			return true;
		}
	}
	return false;
}

bool Cook::operator!=(Cook& _cook)
{
	if (name != _cook.name) {
		return true;
	}
	if (surname != _cook.surname) {
		return true;
	}
	return false;
}

istream& operator>>(istream& input, Cook _cook)
{
	char* _name = nullptr, * _surname = nullptr;
	input >> _name >> _surname;
	_cook.set_name(_name);
	_cook.set_surname(_surname);
	return input;
}

ostream& operator<<(ostream& output, Cook _cook)
{
	return output << _cook.get_name() << ", " << _cook.get_surname();
}
