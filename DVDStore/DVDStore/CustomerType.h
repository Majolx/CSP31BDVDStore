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

template <class Type>
struct nodeTypeDvd
{
	Type info;
	nodeTypeDvd<Type> *link;
};

template <class Type>
class CustomerType : public PersonType<Type>
{
private:
	nodeTypeDvd<Type> *first;
	string accountNumber;
	videoListType videosCheckedOut;
public:
	void printAccountInformation();
	void printAccountNumber();
	void setNameAndAccountNumber(string firstName, string lastName, string accountNumber);
	void rentDVD(videoType dvd);
	void returnDVD(videoType dvd);
	void load();

	CustomerType();
	CustomerType(string firstName, string lastName, string accNum);
	
	string getAccountNumber() const;
};

template <class Type>
void CustomerType<Type>::printAccountInformation()
{
	nodeTypeDvd<Type> *current;

	cout << "Name: ";
	this->print(); 
	cout << endl;
	cout << "Account#: " << accountNumber << endl;
	cout << "Currently checked out: " << endl;
	while (current != NULL)
	{
		cout << current->info;
		current = current->link;
	}
}

template <class Type>
void CustomerType<Type>::printAccountNumber()
{
	cout << "Account#: " << accountNumber << endl;
}

template <class Type>
void CustomerType<Type>::setNameAndAccountNumber(string firstName, string lastName, string accountNumber)
{
	this->accountNumber = accountNumber;
	this->setName(firstName, lastName);
}

template <class Type>
void CustomerType<Type>::rentDVD(videoType dvd)
{
	nodeTypeDvd<Type> *current;

	current = first;
	videosCheckedOut.videoCheckIn(dvd.getTitle());
	
	if (first == NULL)
	{
		first = dvd.getTitle();
	}
	else
	{
		current = current->link;
		if (current == NULL)
			current = dvd.getTitle();
	}
}

template <class Type>
void CustomerType<Type>::returnDVD(videoType dvd)
{
	nodeTypeDvd<Type> *current;
	nodeTypeDvd<Type> *previousNode;

	current = first;

	videosCheckedOut.videoCheckOut(dvd.getTitle());
	
	if (dvd.getTitle() == first.info)
	{
		first = first->link;
		delete current;
	}
	else
	{
		while (current != NULL)
		{
			previousNode = current;
			current = current->link;
			if (current == dvd.getTitle())
			{
				previousNode->link = current->link;
				delete current;
			}
		}
	}
}

template <class Type>
string CustomerType<Type>::getAccountNumber() const
{
	return accountNumber;
}

template <class Type>
CustomerType<Type>::CustomerType()
{
	this->setNameAndAccountNumber("", "", "");
}

template <class Type>
CustomerType<Type>::CustomerType(string firstName, string lastName, string accNum)
{
	this->setNameAndAccountNumber(firstName, lastName, accNum);
}

template <class Type>
void CustomerType<Type>::load()
{

}
#endif