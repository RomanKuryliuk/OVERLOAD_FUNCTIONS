#include <locale.h>
#include <iostream>
#include <conio.h>

#include "Dish.h"

using namespace std;

int main() {

	setlocale(LC_ALL, "Ukrainian");

	cout << "¬ведiть iм'€ i прiзвище кухар€" << endl;
	char* name_cook = new char;
	char* surname_cook = new char;

	cin >> name_cook >> surname_cook;

	Cook cook(name_cook, surname_cook);

	cook.show();

	cout << endl << "¬ведiть iм'€ страви, цiну, час приготуванн€, категорiю, iм'€ i прiзвище кухар€" << endl;
	char* name_dish = new char;
	int price = 0, time = 0, category = 0;
	Category temp_category;

	cin >> name_dish >> price >> time >> category >> name_cook >> surname_cook;
	switch (category) {
	case 0:
		temp_category = NONE;
		break;
	case 1:
		temp_category = COLD_SNACKS;
		break;
	case 2:
		temp_category = FIRST_COURSES;
		break;
	case 3:
		temp_category = SECOND_COURSES;
		break;
	case 4:
		temp_category = DESSERTS;
		break;
	case 5:
		temp_category = DRINKS;
		break;
	default:
		break;
	}

	Dish dish(name_dish, price, time, temp_category, name_cook, surname_cook);
	dish.show();



	
	return 0;
}