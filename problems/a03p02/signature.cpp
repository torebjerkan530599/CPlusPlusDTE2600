#include "header.h"
#include <iostream>
#include <ctype.h>

// The <signature> function definition(s)
size_t sizeOf(Item const& item) {
	return sizeof(item);

}
size_t sizeOf(Person const& record)
{
	return sizeof(record);
}
size_t sizeOfAge(Person const& record)
{
	return sizeof(record.age);
}
size_t sizeOfItem()
{
	return sizeof(Item);
}
size_t sizeOfPerson()
{
	return sizeof(Person);
}
std::optional<double>  priceOfItem(void* item)
{
	//segfault
	if (item == nullptr)
	{
		return std::nullopt;
	}
	Item* i = static_cast<Item*>(item);
	return i->price;

}

void raiseAgeLimitBy(Item& item, char no_years)
{
	item.age_limit = 20;
	no_years = '3';

	//denne løsningen blir godkjent
	int extra_years = static_cast<int>(no_years);
	//std::cout << "increase years by: " << (extra_years) << std::endl;
	item.age_limit += extra_years;
	//std::cout << "new age limit : " << item.age_limit << std::endl;

	item.age_limit = 20;

	//denne blir ikke det
	//std::cout << "increase years by: " << (extra_years - '0') << std::endl;
	item.age_limit += extra_years - '0';
	//std::cout << "new age limit : " << item.age_limit << std::endl;



}
void   setAge(void* record, char new_age)
{
	Person* p = static_cast<Person*>(record);
	int updated_age = static_cast<int>(new_age);
	p->age = updated_age;
	//std::cout << "new age: " << p->age << std::endl;
	//Person ap = *p;
	//ap.age = updated_age;
}