#include "header.h"

// The <signature> function definition(s)

// Item
Item::Item()
{

}
Item::Item(std::string const& name, double price)
{
	m_name = name;
	m_price = price;
}

std::string const& Item::category() const
{
	return m_category;
}
std::string const& Item::name() const
{
	return m_name;
}
double Item::price() const
{
	return m_price;
}
int   Item::ageLimit() const 
{
	return m_age_limit;
}

void  Item::setCategory(std::string const& category) 
{
	m_category = category;
}

void  Item::setName(std::string const& name) 
{
	m_name = name;
}
void  Item::setPrice(double price) 

{
	m_price = price;
}

void  Item::setAgeLimit(int limit) 
{
	m_age_limit = limit;
}

// Person
Person::Person() 
{
	s_next_id = generateNextId();

}
Person::Person(std::string const& name, int age) 
{
	m_name = name;
	m_year_of_birth = CURRENT_YEAR - age;
	s_next_id = generateNextId();
}

std::string const& Person::name() const 
{
	return m_name;
}
int Person::yearOfBirth() const 
{
	return m_year_of_birth;
}

void Person::setAge(int age) 
{
	m_year_of_birth = CURRENT_YEAR - age;
}
void Person::setName(std::string const& name) 
{
	m_name = name;

}

// Static members
int Person::s_next_id;
int Person::generateNextId() 
{
	s_next_id++;
	return s_next_id;
}

// Other
std::string toString(Person const& person) 
{
	using namespace std;
	//"Person ([id]): [name] - [age] year[s] of age"
	string s_age = "years of age";
	int age = CURRENT_YEAR - person.m_year_of_birth;

	if (age < 2)
		s_age = "year of age";
		

	string s = "Person " + std::to_string(Person::s_next_id) + 
		": " + person.m_name + " - " + std::to_string(age) + " " + s_age;
	return s;
}
