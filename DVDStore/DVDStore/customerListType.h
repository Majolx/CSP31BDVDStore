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
	bool validateAccount(string accNum);

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

#endif