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

using namespace std;

class CustomerType : public PersonType
{
private:
	string accountNumber;
	videoListType videosCheckedOut;
public:
	void printAccountInformation();
	void printAccountNumber();
	void setAccountNumber(string accountNumber);
	void rentDVD(videoType dvd);
	void returnDVD(videoType dvd);

	string getAccountNumber() const;
};

void CustomerType::printAccountInformation()
{
	cout << "Name: " << this->getName() << endl;
	cout << "Account#: " << accountNumber << endl;
	cout << "Currently checked out: " << endl;
	videosCheckedOut.videoPrintTitle();
}

void CustomerType::printAccountNumber()
{
	cout << "Account#: " << accountNumber << endl;
}

void CustomerType::setAccountNumber(string accountNumber)
{
	this->accountNumber = accountNumber;
}

void CustomerType::rentDVD(videoType dvd)
{
	videosCheckedOut.videoCheckIn(dvd.getTitle());
}

void CustomerType::returnDVD(videoType dvd)
{
	videosCheckedOut.videoCheckOut(dvd.getTitle());
}

string CustomerType::getAccountNumber() const
{
	return accountNumber;
}

#endif