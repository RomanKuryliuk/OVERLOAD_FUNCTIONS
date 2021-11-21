#include <string>
#include <iostream>

#include "Dish.h"

using namespace std;

Dish::Dish()
{
	name_dish = new char[7];
	strcpy_s(name_dish, sizeof "noname", "noname");

	price = 0;
	time = 0;

	category = Category::NONE;

	//cout << "Конструктор Dish за замовчування " << this << endl;
}

Dish::Dish(char* _name_dish, int _price, int _time, Category& _category) :
	Cook()
{
	name_dish = new char[strlen(_name_dish) + 1];
	strcpy_s(name_dish, strlen(_name_dish) + 1, _name_dish);

	price = _price;
	time = _time;

	category = _category;

	//cout << "Конструктор Dish з параметрами " << this << endl;
}

Dish::Dish(char* _name_dish, int _price, int _time, Category& _category, Cook& _cook) :
	Cook(_cook)
{
	name_dish = new char[strlen(_name_dish) + 1];
	strcpy_s(name_dish, strlen(_name_dish) + 1, _name_dish);

	price = _price;
	time = _time;

	category = _category;

	//cout << "Конструктор Dish з параметрами " << this << endl;
}

Dish::Dish(char* _name_dish, int _price, int _time, Category& _category, char* _name, char* _surname) :
	Cook(_name, _surname)
{
	name_dish = new char[strlen(_name_dish) + 1];
	strcpy_s(name_dish, strlen(_name_dish) + 1, _name_dish);

	price = _price;
	time = _time;

	category = _category;

	//cout << "Конструктор Dish з параметрами " << this << endl;
}

Dish::Dish(Dish& _dish) :
	Cook(_dish.get_name(), _dish.get_surname())
{
	name_dish = new char[strlen(_dish.name_dish) + 1];
	strcpy_s(name_dish, strlen(_dish.name_dish) + 1, _dish.name_dish);

	price = _dish.price;
	time = _dish.time;

	category = _dish.category;

	//cout << "Конструктор Dish копіювання " << this << endl;
}

Dish::~Dish()
{
	//cout << "Деструктор Dish " << this << endl;
}

char* Dish::get_name_dish()
{
	return name_dish;
}

int Dish::get_price()
{
	return price;
}

int Dish::get_time()
{
	return time;
}

Category& Dish::get_category()
{
	return category;
}

Dish& Dish::set_name_dish(char* _name_dish)
{
	delete[] name_dish;
	name_dish = new char[strlen(_name_dish) + 1];
	strcpy_s(name_dish, strlen(_name_dish) + 1, _name_dish);
	return *this;
}

Dish& Dish::set_price(int price)
{
	price = price;
	return *this;
}

Dish& Dish::set_time(int time)
{
	time = time;
	return *this;
}

Dish& Dish::set_category(Category& category)
{
	category = category;
	return *this;
}

Dish& Dish::set_category(int _category)
{
	switch (_category) {
	case 0:
		category = Category::NONE;
		break;
	case 1:
		category = Category::COLD_SNACKS;
		break;
	case 2:
		category = Category::FIRST_COURSES;
		break;
	case 3:
		category = Category::SECOND_COURSES;
		break;
	case 4:
		category = Category::DESSERTS;
		break;
	case 5:
		category = Category::DRINKS;
		break;
	default:
		break;
	}

	return *this;
}

void Dish::show()
{
	cout << name_dish << ", " << price << " грн";
}

bool Dish::operator>(Dish& _dish)
{
	return price > _dish.price;
}

bool Dish::operator<(Dish& _dish)
{
	return  price < _dish.price;
}

istream& operator>>(istream& input, Dish _dish)
{
	return input >> _dish.name_dish >> _dish.price >> _dish.time >> _dish.category;
}

ostream& operator<<(ostream& output, Dish _dish)
{
	return	output << _dish.get_name_dish() << ", " << _dish.get_price() << ", " << _dish.get_time() << ", " << _dish.get_category();

}
