#ifndef _CUSTOMER_TYPE_H
#define _CUSTOMER_TYPE_H

#include <iostream>
#include <string>
#include "PersonType.h"
#include "videoListType.h"
#include "videoType.h"
#include "RentedDvdList.h"

using namespace std;

class CustomerType : public PersonType
{
private:
	string accountNumber;
	videoListType videosCheckedOut;
	RentedDvdList rentedDvd;
public:
	void printAccountInformation();
	void printAccountNumber();
	void setNameAndAccountNumber(string firstName, string lastName, string accountNumber);
	void rentDVD(string title);
	void returnDVD(string title);
	void printDvdRented(CustomerType customer);
	bool operator==(const CustomerType other);
	bool operator!=(const CustomerType other);
	bool operator>(const CustomerType other);
	bool operator<(const CustomerType other);
	bool operator>=(const CustomerType other);
	bool operator<=(const CustomerType other);

	friend ostream& operator<<(ostream& os, const CustomerType other);

	CustomerType();
	CustomerType(string accountNumber);
	CustomerType(string firstName, string lastName, string accNum);
	
	void setAccountNumber(string accountNum);
	string getAccountNumber() const;
};

void CustomerType::printAccountInformation()
{
	cout << "Name: ";
	this->print(); 
	cout << "Account#: " << accountNumber << endl;
	rentedDvd.printDvDList();
}

void CustomerType::printAccountNumber()
{
	cout << "Account#: " << accountNumber << endl;
}

void CustomerType::setNameAndAccountNumber(string firstName, string lastName, string accountNumber)
{
	this->accountNumber = accountNumber;
	this->setName(firstName, lastName);
}

void CustomerType::rentDVD(string title)
{
	rentedDvd.insertDvd(title);
}

void CustomerType::returnDVD(string title)
{	
	rentedDvd.deleteDvD(title);
}

void CustomerType::printDvdRented(CustomerType customer)
{
	customer.rentedDvd.printDvDList();
}

bool CustomerType::operator==(const CustomerType other)
{
	return this->accountNumber.compare(other.accountNumber) == 0;
}

bool CustomerType::operator!=(const CustomerType other)
{
	return this->accountNumber.compare(other.accountNumber) != 0;
}

bool CustomerType::operator<(const CustomerType other)
{
	return this->accountNumber.compare(other.accountNumber) < 0;
}

bool CustomerType::operator>(const CustomerType other)
{
	return this->accountNumber.compare(other.accountNumber) > 0;
}

bool CustomerType::operator<=(const CustomerType other)
{
	return this->accountNumber.compare(other.accountNumber) <= 0;
}

bool CustomerType::operator>=(const CustomerType other)
{
	return this->accountNumber.compare(other.accountNumber) >= 0;
}

ostream& operator<<(ostream& os, const CustomerType other)
{
	os << other.getAccountNumber() << " " << other.getLastName() << ", " << other.getFirstName();
	return os;
}

void CustomerType::setAccountNumber(string accountNum)
{
	accountNumber = accountNum;
}

string CustomerType::getAccountNumber() const
{
	return accountNumber;
}

CustomerType::CustomerType()
{
	this->setNameAndAccountNumber("", "", "");
}

CustomerType::CustomerType(string accountNumber)
{
	this->accountNumber = accountNumber;
}

CustomerType::CustomerType(string firstName, string lastName, string accNum)
{
	this->setNameAndAccountNumber(firstName, lastName, accNum);
}

#endif