/*******************************************************************************
 * Programmer: Alexander Lao                                                   *
 * Class: CptS 122; Lab Section 2                                              *
 * Programming Assignment: Attendance Tracker                                  *
 * Date: 10/23/2015                                                            *
 *                                                                             *
 * Description: This application marks absences, reads from text/csv files,    *
 *				and writes to text files.                                      * 
 *                                                                             *
 * Note: Lung-Chi Lin helped me on this assignment. Some functions were        *
 *		 adapted from the in-class examples (destroyList, overloaded           *
 *		 assignment operator).                                                 *
 ******************************************************************************/

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#include "ListNode.h"

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::ifstream;
using std::ofstream;

class AttendanceWrapper; // foward declaration

class List 
{
	friend class AttendanceWrapper;

	public:
		// constructor
		List ();

		// copy constructor
		List (List &copy);

		// destructor
		~List ();

		// overloaded assignment operator
		List & operator= (const List &rhs);

		// getters
		int getListSize ();
		ListNode * getStartPtr ();

		// setters
		void setListSize (int newListSize);
		void setStartPtr (ListNode * newStartPtr);

		bool insertAtFront (int newRecordNumber, int newID, string newName, string newEmail,
							string newUnits, string newProgram, string newLevel);

	private:
		int mListSize;
		ListNode * mStartPtr;

		// will only call within insert functions
		ListNode * makeNode (int newRecordNumber, int newID, string newName, string newEmail,
							 string newUnits, string newProgram, string newLevel);
		bool destroyList ();
};

#endif