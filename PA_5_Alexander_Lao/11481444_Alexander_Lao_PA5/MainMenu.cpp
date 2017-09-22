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

#include "MainMenu.h"

///////////////////////////////////////////////////////////////////////
/// getMenuChoice ()
/// \pre    
/// \post   
/// \param
/// \return int menuChoice
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

// getter
int MainMenu::getMenuChoice ()
{
	return menuChoice;
}

///////////////////////////////////////////////////////////////////////
/// setMenuChoice (int newMenuChoice)
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

// setter
void MainMenu::setMenuChoice (int newMenuChoice)
{
	menuChoice = newMenuChoice;
}

///////////////////////////////////////////////////////////////////////
/// runMenu ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: displays the menu options to the window application,
/// \reads in a menu choice, and invokes a method based on the user's inputted menu choice
///////////////////////////////////////////////////////////////////////

void MainMenu::runMenu ()
{
	List masterList;
	AttendanceWrapper run (masterList);
	bool running = true;

	while (running)
	{
		cout << "Welcome to the Attendance Tracker Application!" << endl;
		cout << "1. Import course list" << endl;
		cout << "2. Load master list" << endl;
		cout << "3. Store master list" << endl;
		cout << "4. Mark absences" << endl;
		cout << "5. Edit absences" << endl;
		cout << "6. Generate report" << endl;
		cout << "7. Exit" << endl;
		cout << "Please choose an option: ";

		cin >> menuChoice;

		cout << endl; // blank line

		if (menuChoice == 1)
		{
			run.import ();
		}
		else if (menuChoice == 2)
		{
			run.load ();
		}
		else if (menuChoice == 3)
		{
			run.store ();
		}
		else if (menuChoice == 4)
		{
			run.markAbsences ();
		}
		else if (menuChoice == 5)
		{
			runEditMenu ();

			if (menuChoice == 1)
			{
				run.editByName ();
			}
			else if (menuChoice == 2)
			{
				run.editByID ();
			}
			else
			{
				cout << "Please enter a valid option." << endl;
				cout << endl; // blank line
			}
		}
		else if (menuChoice == 6)
		{
			runReportMenu ();

			if (menuChoice == 1)
			{
				run.generateAll ();
			}
			else if (menuChoice == 2)
			{
				run.generateSearch ();
			}
			else if (menuChoice == 3)
			{
				run.generateDate ();
			}
			else
			{
				cout << "Please enter a valid option." << endl;
				cout << endl; // blank line
			}
		}
		else if (menuChoice == 7)
		{
			break;
		}
		else
		{
			cout << "Please enter a valid option." << endl;
			cout << endl; // blank line
		}
	}
}

///////////////////////////////////////////////////////////////////////
/// runReportMenu ()
/// \pre    
/// \post   
/// \param
/// \return int menuChoice
/// \throw  
/// \description: displays the submenu for the generate report option,
/// \ reads in a user inputted menu choice, and returns that menu choice
///////////////////////////////////////////////////////////////////////

int MainMenu::runReportMenu ()
{
	// prompt the user
	cout << "Generate a report for..." << endl;
	cout << "1. All students" << endl;
	cout << "2. Students with absences more than or equal to _" << endl;
	cout << "3. Students absent on a specific date" << endl;
	cout << "Please enter an option: ";

	// read in the menu choice
	cin >> menuChoice;

	cout << endl; // blank line

	return menuChoice;
}

///////////////////////////////////////////////////////////////////////
/// runEditMenu ()
/// \pre    
/// \post   
/// \param
/// \return int menuChoice
/// \throw  
/// \description: displays the submenu for the edit option,
/// \ reads in a user inputted menu choice, and returns that menu choice
///////////////////////////////////////////////////////////////////////

int MainMenu::runEditMenu ()
{
	// prompt the user
	cout << "Search by..." << endl;
	cout << "1. Name" << endl;
	cout << "2. ID" << endl;
	cout << "Please enter an option: ";

	// read in the menu choice
	cin >> menuChoice;

	cout << endl; // blank line

	return menuChoice;
}