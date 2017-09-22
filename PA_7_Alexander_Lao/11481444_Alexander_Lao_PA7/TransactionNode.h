/*******************************************************************************
 * Programmer: Alexander Lao                                                   *
 * Class: CptS 122; Lab Section 2                                              *
 * Programming Assignment: Data Analysis in Binary Search Trees                *
 * Date: 11/20/2015                                                            *
 *                                                                             *
 * Description: This application analyzes trends seen in a binary search tree. *                                               
 ******************************************************************************/

#ifndef TRANSACTION_NODE_H
#define TRANSACTION_NODE_H

#include <iostream>
#include <string>

#include "Node.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

// publicly inherits from abstract base class Node
class TransactionNode : public Node
{
	public:
		// destructor
		~TransactionNode ();

		// constructor
		TransactionNode (string newData, int newUnits);

		// getter
		int getUnits ();

		// setter
		void setUnits (int newUnits);

		// overrides the pure virtual function in Node
		void printData ();

	private:
		int mUnits;
};

#endif