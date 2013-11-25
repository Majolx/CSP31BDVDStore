#ifndef _PersonType_H
#define _PersonType_H

#include <string>
#include <iostream>

using namespace std;

class PersonType
{
private:
	string firstName;	//variable holder for the first name
	string lastName;	//variable holder for the last name
public:
	void setName(string f, string l);
	//A function that will set the first and last name
	string getFirstName() const;
	//return the first name
	string getLastName() const;
	//return the last name
	void getName(string& f, string& l) const;
	//return both first and last name
	void print() const;

	//default constructor
	PersonType();
	//constructor that accepts 2 parameter
	PersonType(string f, string l);
};

#endif