#include "header.h"
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>

// The <signature> function definition(s)
std::string toString(Item const& item)
{
	std::stringstream stream;

	stream << std::fixed << std::setprecision(2) << item.price;

	return "Item: " + item.category + " - " + item.name + " : " + stream.str() + " NOK";
}
double totalPrice(Item const& itemOne, Item const& itemTwo, Item const& itemThree)
{
	return itemOne.price + itemTwo.price + itemThree.price;
}
Person createRecord(std::string const& first_name, std::string const& last_name,
	int year_of_birth)
{
	Person person;

	person.name = first_name + " " + last_name;
	person.age = 2022 - year_of_birth;

	return person;
}
int yearOfBirth(Person const& record)
{
	return 2022 - record.age;
}
bool canBuy(Person const& record, Item const& item)
{
	return item.age_limit < record.age;
}
void restrictFromBuying(Item& item, Person const& record1,
	Person const& record2, Person const& record3)
{
	item.age_limit = std::max({ record1.age, record2.age, record3.age });

	bool person1_can_buy = canBuy(record1, item);
	bool person2_can_buy = canBuy(record2, item);
	bool person3_can_buy = canBuy(record3, item);
}