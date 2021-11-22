#include <locale.h>
#include <iostream>
#include <conio.h>
#include <fstream>

#include "Dish.h"
#include "Date.h"
#include "Order.h"

using namespace std;

int main() {

	setlocale(LC_ALL, "Ukrainian");

	Date date1;

	date1.show();
	cout << endl;

	date1 = date1 + 5;

	date1.show();
	cout << endl;

	Cook cook1;

	cout << "¬вед≥ть першого кухар€" << endl;
	cin >> cook1;
	cout << endl;

	Cook cook2;

	cout << "¬вед≥ть другого кухар€" << endl;
	cin >> cook2;
	cout << endl;


	cook1.show();
	cook2.show();
	cout << endl;
	cout << (cook1 == cook2) << endl;

	Dish dish1;

	cout << "¬вед≥ть першу страву" << endl;
	cin >> dish1;
	cout << endl;

	Dish dish2;

	cout << "¬вед≥ть другу страву" << endl;
	cin >> dish2;
	cout << endl;

	dish1.show();
	dish2.show();
	cout << endl;

	cout << (dish1 > dish2) << endl;
	cout << endl;

	Order order1;

	order1.add_dish(dish1);
	order1.add_dish(dish2);

	order1[1].show();
	order1[2].show();


	return 0;
}