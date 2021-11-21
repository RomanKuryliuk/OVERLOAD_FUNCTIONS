#pragma once

#include <iostream>
#include <fstream>

using namespace std;

class Cook {
private:
	char* name, * surname;

public:
	Cook();
	Cook(char*, char*);
	Cook(Cook&);
	~Cook();

	char* get_name();
	char* get_surname();

	Cook& set_name(char*);
	Cook& set_surname(char*);

	virtual void show();

	bool operator==(Cook&);
	bool operator!=(Cook&);

	friend istream& operator>>(istream&, Cook&);
	friend ostream& operator<<(ostream&, Cook);
};