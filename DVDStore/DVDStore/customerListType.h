/*	This class will create and maintain a list of customer.
	Name: Norlan Prudente
	Date: 11/25/2013
*/
#ifndef _customerListType_h
#define _customerListType_h

#include "CustomerType.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <class Type>
struct customerNode
{
	Type info;
	customerNode<Type> *link;
};

template <class Type>
class customerListType : public CustomerType<Type>
{
public:
	void newCustomer(const Type& newPerson);
	void deleteAccount(const Type& person);
	bool searchAccount(string accNum);
	void saveData(ofstream& outFile);
	void loadData();


private:
	customerNode<Type> *first;
};

template <class Type>
void customerListType<Type>::newCustomer(const Type& newPerson)
{
	customerNode<Type> *currentNode;
	customerNode<Type> *newNode;
	
	newNode = new customerNode<Type>;
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

template <class Type>
void customerListType<Type>::deleteAccount(const Type& person)
{
	customerNode<Type> *previousNode;
	customerNode<Type> *currentNode;
	customerNode<Type> *nodeToBeConnected;

	if (first->info == accNum)
	{
		first = first->link;
		delete first;
	}
	else
	{
		currentNode = first;

		while (currentNode != NULL)
		{
			previousNode = currentNode;
			currentNode = currentNode->link;
			if (currentNode->info == accNum)
			{
				nodeToBeConnected = currentNode->link;
				delete currentNode;
				previousNode->link = nodeToBeConnected->info;
			}
			else if (currentNode->link == NULL)
				cout << "Account not found." << endl;
				
		}
	}
}

template <class Type>
bool customerListType<Type>::searchAccount(string accNum)
{
	customerNode<Type> *currentNode;

	if (first->info == accNum)
	{
		return true;
	}
	else
	{
		currentNode = first;

		while (currentNode != NULL)
		{
			currentNode = currentNode->link;

			if (currentNode == accNUm)
				return true;
			else if (currentNode->link == NULL)
				return false;
		}
	}
}

template <class Type>
void customerListType<Type>::saveData(ofstream& outFile)
{
	customerNode<Type> *currentNode;
	currentNode = first;

	int entryCount = 0;

	while (currentNode != NULL)
	{
		outFile << currentNode->info.getFirstName() << " " << currentNode->info.getLastName() << endl;
		outFile << currentNode->info.getAccountNumber() << endl;
		outFile << endl;
	}
}
#endif