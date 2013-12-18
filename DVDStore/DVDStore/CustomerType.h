/*	This class will create an object of type CustomerType
	
	Name: Mathew Larribas
	Date: 12/14/2013

	Modified by:
	Norlan Prudente
	12/18/2013

	Commented by:
	Bruce Willis
	12/18/2013
*/

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
	// Constructors
	CustomerType();
	CustomerType(string accountNumber);
	CustomerType(string firstName, string lastName, string accNum);

	// Getters and Setters
	void setAccountNumber(string accountNum);
	string getAccountNumber() const;
	void setNameAndAccountNumber(string firstName, string lastName, string accountNumber);

	// Print / Output
	friend ostream& operator<<(ostream& os, const CustomerType other);
	void printAccountInformation();
	void printAccountNumber();
	void printDvdRented(CustomerType customer);
	
	// Program Methods
	void rentDVD(string title);
	void returnDVD(string title);
	
	// Operator Overloads
	bool operator==(const CustomerType other);
	bool operator!=(const CustomerType other);
	bool operator>(const CustomerType other);
	bool operator<(const CustomerType other);
	bool operator>=(const CustomerType other);
	bool operator<=(const CustomerType other);	
};


// ================================================================ /
// Constructors                                                     /
// =================================================================/

// Empty String													(0)
CustomerType::CustomerType()
{
	this->setNameAndAccountNumber("", "", "");
}

// Account Number												(1)
CustomerType::CustomerType(string accountNumber)
{
	this->accountNumber = accountNumber;
}

// Account Number and Name										(3)
CustomerType::CustomerType(string firstName, string lastName, string accNum)
{
	this->setNameAndAccountNumber(firstName, lastName, accNum);
}


// ================================================================ /
// Getters and Setters                                              /
// =================================================================/

// Set Account Number											SET
void CustomerType::setAccountNumber(string accountNum)
{
	accountNumber = accountNum;
}

// Get Account Number											GET
string CustomerType::getAccountNumber() const
{
	return accountNumber;
}

// Set Name and Account Number									SET
void CustomerType::setNameAndAccountNumber(string firstName, string lastName, string accountNumber)
{
	this->accountNumber = accountNumber;
	this->setName(firstName, lastName);
}


// ================================================================ /
// Print / Output                                                   /
// =================================================================/

// Output Stream												<<
ostream& operator<<(ostream& os, const CustomerType other)
{
	os << other.getAccountNumber() << " " << other.getLastName() << ", " << other.getFirstName();
	return os;
}

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

void CustomerType::printDvdRented(CustomerType customer)
{
	customer.rentedDvd.printDvDList();
}


// ================================================================ /
// Program Methods                                                  /
// =================================================================/

// Rents a DVD and adds it to the customer's inventory.
void CustomerType::rentDVD(string title)
{
	rentedDvd.insertDvd(title);
}

// Returns a DVD, removing it from the customer's inventory.
void CustomerType::returnDVD(string title)
{	
	rentedDvd.deleteDvD(title);
}


// ================================================================ /
// Operator Overloads                                               /
// =================================================================/

// Equals														==
bool CustomerType::operator==(const CustomerType other)
{
	return this->accountNumber.compare(other.accountNumber) == 0;
}

// Not Equals													!=
bool CustomerType::operator!=(const CustomerType other)
{
	return this->accountNumber.compare(other.accountNumber) != 0;
}

// Less Than													<
bool CustomerType::operator<(const CustomerType other)
{
	return this->accountNumber.compare(other.accountNumber) < 0;
}

// Greater Than													>
bool CustomerType::operator>(const CustomerType other)
{
	return this->accountNumber.compare(other.accountNumber) > 0;
}

// Less Than or Equal											<=
bool CustomerType::operator<=(const CustomerType other)
{
	return this->accountNumber.compare(other.accountNumber) <= 0;
}

// Greater Than or Equal										>=
bool CustomerType::operator>=(const CustomerType other)
{
	return this->accountNumber.compare(other.accountNumber) >= 0;
}


#endif