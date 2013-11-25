#include "PersonType.h"
#include <string>
#include <iostream>

using namespace std;

void PersonType::setName(string f, string l)
{
	firstName = f;	//assign f to firstName
	lastName = l;	//assign l to lastName
}

string PersonType::getFirstName() const
{
	return firstName;
}

string PersonType::getLastName() const
{
	return lastName;
}

void PersonType::getName(string& f, string& l) const
{
	f = firstName;
	l = lastName;
}

void PersonType::print() const
{
	//print the last name then first
	cout << lastName << " " << firstName << endl;
}

PersonType::PersonType()
{
	firstName = "";
	lastName = "";
}

PersonType::PersonType(string n, string l)
{
	firstName = n;
	lastName = l;
}