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

#ifndef LIST_NODE_H
#define LIST_NODE_H

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class List; // forward declaration
class AttendanceWrapper;

class ListNode
{
	friend class List;
	friend class AttendanceWrapper;

	public:
		// parameterized constructor
		ListNode (int newRecordNumber, int newID, string newName, string newEmail,
				  string newUnits, string newProgram, string newLevel);
		
		// copy constructor
		ListNode (ListNode &copy);

		// destructor
		~ListNode ();

		// getters/accessors - access private data members
		int getRecordNumber ();
		int getID ();
		string getName ();
		string getEmail ();
		string getUnits ();
		string getProgram ();
		string getLevel ();
		int getNumberOfAbsences ();
		string getAbsentDates ();
		ListNode * getNextPtr ();

		// setters/mutators - modify private data members
		void setRecordNumber (int newRecordNumber);
		void setID (int newID);
		void setName (string newName);
		void setEmail (string newEmail);
		void setUnits (string newUnits);
		void setProgram (string newProgram);
		void setLevel (string newLevel);
		void setNumberOfAbsences (int newNumberOfAbsences);
		void setAbsentDates (string newAbsenceDates, int index);
		void setNextPtr (ListNode * nextPtr);

	private:
		int mRecordNumber;
		int mID;
		string mName;
		string mEmail;
		string mUnits;
		string mProgram;
		string mLevel;
		int mNumberOfAbsences;
		string mAbsentDates[100];
		ListNode *mNextPtr;
};

#endif