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

#ifndef ATTENDANCE_WRAPPER
#define ATTENDANCE_WRAPPER

#include <iostream>
#include <string>
#include <fstream>
#include <cstring> // i.e. string.h
#include <ctime>

#include "List.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ctime;

class AttendanceWrapper
{
	public:
		// constructor
		AttendanceWrapper (List newMasterList);

		// copy constructor
		AttendanceWrapper (AttendanceWrapper &copy);

		// destructor
		~AttendanceWrapper ();

		// getter
		List getMasterList ();

		// setter
		void setMasterList (List newMasterList);

		// member functions
		void import ();
		void load ();
		void store ();
		void markAbsences ();
		void editByName ();
		void editByID ();
		string currentDateTime ();
		void generateAll ();
		void generateSearch ();
		void generateDate ();

	private:
		List mMasterList;
};

#endif