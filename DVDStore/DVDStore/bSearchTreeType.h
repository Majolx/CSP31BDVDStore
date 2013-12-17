//binarySearchTree.h
//Header File Binary Search Tree

#ifndef H_binarySearchTree
#define H_binarySearchTree
#include <iostream>
#include "binaryTree.h"

#ifdef _base
#undef _base
#endif
#define _base(v) (binaryTreeType<elemType>::v)


using namespace std;

template <class elemType>
class bSearchTreeType: public binaryTreeType<elemType>
{
public:
    bool search(const elemType& searchItem) const;
      //Function to determine if searchItem is in the binary 
      //search tree.
      //Postcondition: Returns true if searchItem is found in 
      //               the binary search tree; otherwise, 
      //               returns false.

    void insert(const elemType& insertItem);
      //Function to insert insertItem in the binary search tree.
      //Postcondition: If there is no node in the binary search
      //               tree that has the same info as 
      //               insertItem, a node with the info 
      //               insertItem is created and inserted in the
      //               binary search tree.

    void deleteNode(const elemType& deleteItem);
      //Function to delete deleteItem from the binary search tree 
      //Postcondition: If a node with the same info as deleteItem
      //               is found, it is deleted from the binary 
      //               search tree.
      //               If the binary tree is empty or deleteItem
      //               is not in the binary tree, an appropriate
      //               message is printed.

	void getNode(elemType& node);

private:
    void deleteFromTree(node<elemType>* &p);
      //Function to delete the node to which p points is 
      //deleted from the binary search tree.
      //Postcondition: The node to which p points is deleted
      //               from the binary search tree.
};

template <class elemType>
void bSearchTreeType<elemType>::getNode(elemType& searchItem)
{
	node<elemType> *current = NULL;
	bool found = false;

	if (treeHeight() == NULL)
		cout << "The tree is empty." << endl;
	else
	{
		current = _base(root);

		while (current != NULL && !found)
		{
			if (current->info == searchItem)
				found == true;
			else if (current->info > searchItem)
				current = current->lLink;
			else
				current = current->rLink;
		}
	}

	if (found)
		searchItem = current->info;
}

template <class elemType>
bool bSearchTreeType<elemType>::search
                    (const elemType& searchItem) const
{
    node<elemType> *current = NULL;
    bool found = false;

    if (_base(root) == NULL)
        cout << "Cannot search an empty tree." << endl;
    else
    { 
       current = _base(root);

       while (current != NULL && !found)
        {
            if (current->info == searchItem)
                found = true;
            else if (current->info > searchItem)
                current = current->lLink;
            else
                current = current->rLink;
        }//end while
    }//end else

    return found;
}//end search

template <class elemType>
void bSearchTreeType<elemType>::insert
                 (const elemType& insertItem)  {
    node<elemType> *current = NULL,*trailCurrent = NULL, *newNode = NULL;  
    newNode = new node<elemType>;
    newNode->info = insertItem;
    newNode->lLink = NULL;
    newNode->rLink = NULL;

    if (_base(root) == NULL)
        _base(root) = newNode;
    else {
        current = _base(root);
        while (current != NULL){
            trailCurrent = current;

            if (current->info == insertItem) {
                cout << "Item exist - No duplicate\n";     
                return;
            }  else if (current->info > insertItem)
                current = current->lLink;
            else
                current = current->rLink;
        }//end while
        if (trailCurrent->info > insertItem)
            trailCurrent->lLink = newNode;
        else
            trailCurrent->rLink = newNode;
    }
}//end insert

template <class elemType>
void bSearchTreeType<elemType>::deleteNode
                                (const elemType& deleteItem)  {
    node<elemType> *current = NULL; //pointer to traverse the tree
    node<elemType> *trailCurrent = NULL; //pointer behind current
    bool found = false;

    if (_base(root) == NULL)
        cout << "Cannot delete from an empty tree.\n";
    else  {
        current = _base(root);
        trailCurrent = _base(root);
        while (current != NULL && !found)
        {
            if (current->info == deleteItem)
                found = true;
            else {
                trailCurrent = current;
                if (current->info > deleteItem)
                    current = current->lLink;
                else
                    current = current->rLink;
            }//end else
        }//end while

        if (current == NULL)
            cout << "The item to be deleted is not in the tree." 
                 << endl;
        else if (found)
        {
            if (current == _base(root))
                deleteFromTree(_base(root));
            else if (trailCurrent->info > deleteItem)
                deleteFromTree(trailCurrent->lLink);
            else
                deleteFromTree(trailCurrent->rLink);
        }
        else
            cout << "The item to be deleted is not in the tree."
                 << endl;
    }
} //end deleteNode

template <class elemType>
void bSearchTreeType<elemType>::deleteFromTree
                                 (node<elemType>* &p)
{
    node<elemType> *cur = NULL,*prev = NULL,*temp = NULL;
    if (p == NULL)
        cout << "Error: The node to be deleted is NULL.\n";
    else if (p->lLink == NULL && p->rLink == NULL)    {
        temp = p;  //leaf node
        p = NULL;
        delete temp;

    }    else if (p->lLink == NULL)    
	{              //right subtree
        temp = p;
        p = temp->rLink;
        delete temp;

    }    else if (p->rLink == NULL)   
	{              //left subtree
        temp = p;
        p = temp->lLink;
        delete temp;

    }    else    
	{
        cur = p->lLink;
        prev = NULL;

        while (cur->rLink != NULL)   {
            prev = cur;
            cur = cur->rLink;
        }//end while

        p->info = cur->info;

        if (prev == NULL) //current did not move; 
                               //current == p->lLink; adjust p
            p->lLink = cur->lLink;
        else
            prev->rLink = cur->lLink;
 
        delete cur;
    }//end else
} //end deleteFromTree

#endif