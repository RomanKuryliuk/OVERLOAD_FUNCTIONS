#pragma once

#include <vector>

#include "Date.h"
#include "Dish.h"

class Order
{
private:
	char* name;
	Date date;
	int number;
	vector<Dish> dishes;

public:
	Order();
	Order(char*, Date, int, vector<Dish>);
	Order(Order&);
	~Order();

	char* get_name();
	Date& get_date();
	int get_number();
	vector<Dish> get_dishes();

	Order& set_name(char*);
	Order& set_date(Date&);
	Order& set_number(int);
	Order& set_dishes(vector<Dish>);

	void add_dish(Dish&);

	void show();
	void short_show();

	Dish& operator[](int);
};

