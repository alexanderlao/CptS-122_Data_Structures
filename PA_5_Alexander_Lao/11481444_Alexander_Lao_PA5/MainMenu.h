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

#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <iostream>
#include <string>

#include "AttendanceWrapper.h"

class MainMenu
{
	public:
		// getter
		int getMenuChoice ();

		// setter
		void setMenuChoice (int newMenuChoice);

		// member functions
		void runMenu ();
		int runReportMenu ();
		int runEditMenu ();

	private:
		int menuChoice;
};

#endif