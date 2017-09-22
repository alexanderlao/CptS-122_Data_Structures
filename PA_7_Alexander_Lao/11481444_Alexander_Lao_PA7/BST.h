/*******************************************************************************
 * Programmer: Alexander Lao                                                   *
 * Class: CptS 122; Lab Section 2                                              *
 * Programming Assignment: Data Analysis in Binary Search Trees                *
 * Date: 11/20/2015                                                            *
 *                                                                             *
 * Description: This application analyzes trends seen in a binary search tree. *                                               
 ******************************************************************************/

#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>

#include "Node.h"
#include "TransactionNode.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class BST
{
	public:
		// destructor
		~BST ();

		// default constructor
		BST ();

		// getter
		Node * getRoot ();

		// setter
		void setRoot (Node *newRoot);

		void insert (string newData, int newUnits);
		void inOrderTraversal ();
		TransactionNode & findSmallest ();
		TransactionNode & findLargest ();

	private:
		Node *mpRoot;

		void destroyTree (Node *&pTree);
		void insert (Node *&pTree, string newData, int newUnits);
		void inOrderTraversal (TransactionNode *&pTree);
};

#endif