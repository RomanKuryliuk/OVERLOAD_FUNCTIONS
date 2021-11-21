#include <iostream>

using namespace std;

enum class Category {
	NONE,
	COLD_SNACKS,
	FIRST_COURSES,
	SECOND_COURSES,
	DESSERTS,
	DRINKS	
};

std::istream& operator>>(std::istream& input, Category& _category)
{
    int temp;
	input >> temp;
	switch (temp) {
	case 0:
		_category = Category::NONE;
		break;
	case 1:
		_category = Category::COLD_SNACKS;
		break;
	case 2:
		_category = Category::FIRST_COURSES;
		break;
	case 3:
		_category = Category::SECOND_COURSES;
		break;
	case 4:
		_category = Category::DESSERTS;
		break;
	case 5:
		_category = Category::DRINKS;
	default:
		return input;
	}
    return input;
}

std::ostream& operator<<(std::ostream& output, Category& _category)
{
	switch (_category) {
	case Category::NONE:
		return output << 0;
	case Category::COLD_SNACKS:
		return output << 1;
	case Category::FIRST_COURSES:
		return output << 2;
	case Category::SECOND_COURSES:
		return output << 3;
	case Category::DESSERTS:
		return output << 4;
	case Category::DRINKS:
		return output << 5;
	default:
		return output;
	}
}