/*	This class will create and maintain a list of customer.
	Name: Norlan Prudente
	Date: 11/25/2013
*/
#ifndef _customerListType_h
#define _customerListType_h

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
	void deleteAccount(const CustomerType& person);
	bool searchAccount(string accNum);
	void saveData(ofstream& outFile);
	void loadData();

	customerListType();
};

void customerListType::newCustomer(const CustomerType& newPerson)
{
	nodeType<CustomerType> *currentNode;
	nodeType<CustomerType> *newNode;
	
	newNode = new nodeType<CustomerType>;
	newNode->info = newPerson;
	newNode->link = NULL;

	if (first == NULL)
		first = newNode;
	else
	{
		currentNode = first;

		while(currentNode != NULL)
		{
			currentNode = currentNode->link;
			if (currentNode == NULL)
				currentNode = newNode;

		}
	}

}

void customerListType::deleteAccount(const CustomerType& person)
{
	nodeType<CustomerType> *previousNode;
	nodeType<CustomerType> *currentNode;
	nodeType<CustomerType> *nodeToBeConnected;
	
	while (currentNode != NULL)
	{
		if (currentNode->info.getAccountNumber() == person.getAccountNumber())
		{
			nodeToBeConnected = currentNode->link;
			delete currentNode;
			previousNode->link = nodeToBeConnected;
		}
		else if (currentNode->link == NULL)
			cout << "Account not found." << endl;
		
		previousNode = currentNode;
		currentNode = currentNode->link;
	}
}

bool customerListType::searchAccount(string accNum)
{
	nodeType<CustomerType> *currentNode;

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
			else if (currentNode->link == NULL)
				return false;
		}
	}
}

void customerListType<Type>::saveData(ofstream& outFile)
{
	nodeType<CustomerType> *currentNode;

	int entryCount = 0;

	while (currentNode != NULL)
	{
		outFile << currentNode->info.getFirstName() << " " << currentNode->info.getLastName() << endl;
		outFile << currentNode->info.getAccountNumber() << endl;
		while (currentNode->info.get endl;
	}
}
#endif