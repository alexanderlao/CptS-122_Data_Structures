/*******************************************************************************
 * Programmer: Alexander Lao                                                   *
 * Class: CptS 122; Lab Section 2                                              *
 * Programming Assignment: Data Analysis in Binary Search Trees                *
 * Date: 11/20/2015                                                            *
 *                                                                             *
 * Description: This application analyzes trends seen in a binary search tree. *                                               
 ******************************************************************************/

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// abstract base class Node
class Node
{
	public:
		// virtual destructor
		virtual ~Node ();

		// parameterized constructor
		Node (string newData);

		// getters
		string getData ();
		Node *& getLeft ();
		Node *& getRight ();

		// setters
		void setData (string newData);
		void setLeftPtr (Node *newLeftPtr);
		void setRightPtr (Node *newRightPtr);

		// pure virtual
		virtual void printData () = 0; 

	protected:
		string mData;
		Node *mpLeft;
		Node *mpRight;
};

#endif