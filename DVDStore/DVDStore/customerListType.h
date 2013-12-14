/*	This class will create and maintain a list of customer.
	Name: Norlan Prudente
	Date: 11/25/2013
*/
#ifndef _customerListType_h
#define _customerListType_h

#include "videoListType.h"
#include "videoType.h"
#include "unorderedLinkedList.h"
#include "CustomerType.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class customerListType : public unorderedLinkedList<CustomerType>
{
public:
	void newCustomer(const CustomerType& newPerson);
	void deleteAccount(string accountNumber);
	bool searchAccount(string accNum);
	void printCustomerInfo();
	void rentDvd(string account, string title);
	void returnDvd(string account, string title);
	void setVideoList(videoListType& dvd);
	videoType findDvd(string title);
	void saveData(ofstream& outFile);
private:
	videoListType dvdList;
};

void customerListType::newCustomer(const CustomerType& newPerson)
{
	nodeType<CustomerType> *currentNode;
	nodeType<CustomerType> *newNode;
	
	newNode = new nodeType<CustomerType>;
	newNode->info = newPerson;
	newNode->link = NULL;

	count++;

	if (first == NULL)
		first = newNode;
	else
	{
		currentNode = first;

		
		while(currentNode != NULL)
		{
			if (currentNode->link == NULL)
			{
				currentNode->link = newNode;
				return;
			}

			currentNode = currentNode->link;

		}
	}

}

void customerListType::deleteAccount(string accountNumber)
{
	nodeType<CustomerType> *previousNode = new nodeType<CustomerType>;
	nodeType<CustomerType> *currentNode = new nodeType<CustomerType>;
	nodeType<CustomerType> *nodeToBeConnected = new nodeType<CustomerType>;
	
	currentNode = first;

	while (currentNode != NULL)
	{
		if (currentNode->info.getAccountNumber() == accountNumber)
		{
			if (currentNode->link != NULL)
			{
				nodeToBeConnected = currentNode->link;
				previousNode->link = nodeToBeConnected;
			}
			else
			{
				previousNode->link = NULL;
			}
			if (currentNode == first)
			{
				first = NULL;
			}
			delete currentNode;
			count--;
			return;
		}
		else if (currentNode->link == NULL)
		{
			cout << "Account not found." << endl;
			return;
		}
		
		previousNode = currentNode;
		currentNode = currentNode->link;
	}
}

bool customerListType::searchAccount(string accNum)
{
	nodeType<CustomerType> *currentNode;

	currentNode = first;

	if (currentNode->info.getAccountNumber() == accNum)
	{
		return true;
	}
	else
	{
		currentNode = first;

		while (currentNode != NULL)
		{
			currentNode = currentNode->link;

			if (currentNode->info.getAccountNumber() == accNum)
				return true;
		}
		return false;
	}

}

void customerListType::printCustomerInfo()
{
	nodeType<CustomerType> *currentNode = new nodeType<CustomerType>;

	currentNode = first;

	if (first == NULL)
		cout << "Empty List." << endl << endl;
	else
	{
		while (currentNode != NULL)
		{
			currentNode->info.printAccountInformation();
			currentNode = currentNode->link;
		}
	}
}

void customerListType::rentDvd(string accountNum, string title)
{
	// Index of the customer to rent the DVD
	int custIndex = 0;

	nodeType<CustomerType> *currentNode;

	currentNode = first;

	// Find the right customer
	while(currentNode != NULL && currentNode->info.getAccountNumber() != accountNum)
	{
		if (currentNode->link == NULL)
		{
			cout << "Account not found!\n";
			return;
		}
		currentNode = currentNode->link;
	}

	// Rent the DVD
	currentNode->info.rentDVD(title);
}

void customerListType::returnDvd(string accountNum, string title)
{
	nodeType<CustomerType> *currentNode;

	currentNode = first;

	while(currentNode != NULL && currentNode->info.getAccountNumber() != accountNum)
	{
		currentNode = currentNode->link;
	}

	if (currentNode != NULL)
	{
		currentNode->info.returnDVD(title);
	}
	else
	{
		cout << "You didn't rent that video." << endl;
	}
}

void customerListType::setVideoList(videoListType& dvd)
{
	dvdList = dvd;
}

void customerListType::saveData(ofstream& outFile)
{
	nodeType<CustomerType> *currentNode;

	int entryCount = 0;

	currentNode = first;

	while (currentNode != NULL)
	{
		outFile << currentNode->info.getFirstName() << " " << currentNode->info.getLastName() << endl;
		outFile << currentNode->info.getAccountNumber() << endl;
		outFile << endl;
	}
}
#endif