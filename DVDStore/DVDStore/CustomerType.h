/**
 * CustomerType.h
 * A customer who uses the DVD Store program.
 *
 * Written by:	Mathew Larribas
 * Date:		November 25, 2013
**/

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
	void rentDVD(videoType dvd);
	void returnDVD(videoType dvd);
	void printDvdRented();
	bool operator==(const CustomerType other);
	bool operator!=(const CustomerType other);

	CustomerType();
	CustomerType(string firstName, string lastName, string accNum);
	
	string getAccountNumber() const;
};

void CustomerType::printAccountInformation()
{
	cout << "Name: ";
	this->print(); 
	cout << endl;
	cout << "Account#: " << accountNumber << endl;
	cout << "Currently checked out: " << endl;
	videosCheckedOut.videoPrintTitle();
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

void CustomerType::rentDVD(videoType dvd)
{
	videosCheckedOut.videoCheckIn(dvd.getTitle());
	rentedDvd.insertDvd(dvd.getTitle());
}

void CustomerType::returnDVD(videoType dvd)
{
	videosCheckedOut.videoCheckOut(dvd.getTitle());
	rentedDvd.deleteDvD(dvd.getTitle());
}

void CustomerType::printDvdRented()
{
	rentedDvd.printDvDList();
}

bool CustomerType::operator==(const CustomerType other)
{
	if (this->accountNumber == other.accountNumber &&
		this->getFirstName() == other.getFirstName() &&
		this->getLastName() == other.getLastName())
		return true;
	else
		return false;
}

bool CustomerType::operator!=(const CustomerType other)
{
	if (this->accountNumber != other.accountNumber &&
		this->getFirstName() != other.getFirstName() &&
		this->getLastName() != other.getLastName())
		return true;
	else
		return false;
}

string CustomerType::getAccountNumber() const
{
	return accountNumber;
}

CustomerType::CustomerType()
{
	this->setNameAndAccountNumber("", "", "");
}

CustomerType::CustomerType(string firstName, string lastName, string accNum)
{
	this->setNameAndAccountNumber(firstName, lastName, accNum);
}

#endif