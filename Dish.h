#pragma once

#include "Category.cpp"
#include "Cook.h"

class Dish :
	public Cook
{
private:
	char* name_dish;
	int price, time;
	Category category;
public:
	Dish();
	Dish(char*, int, int, Category&);
	Dish(char*, int, int, Category&, Cook&);
	Dish(char*, int, int, Category&, char*, char*);
	Dish(Dish&);
	~Dish();

	char* get_name_dish();
	int get_price();
	int get_time();
	Category& get_category();

	Dish& set_name_dish(char*);
	Dish& set_price(int);
	Dish& set_time(int);
	Dish& set_category(Category&);
	Dish& set_category(int);

	virtual void show();

	bool operator>(Dish&);
	bool operator<(Dish&);

	friend istream& operator>>(istream&, Dish&);
	friend ostream& operator<<(ostream&, Dish);
};

