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

#include "AttendanceWrapper.h"

///////////////////////////////////////////////////////////////////////
/// AttendanceWrapper (List newMasterList)
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: dynamically allocates memory for an AttendanceWrapper object
///////////////////////////////////////////////////////////////////////

// constructor
AttendanceWrapper::AttendanceWrapper (List newMasterList)
{
	this -> mMasterList = newMasterList;
}

///////////////////////////////////////////////////////////////////////
/// AttendanceWrapper (AttendanceWrapper &copy)
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

// copy constructor
AttendanceWrapper::AttendanceWrapper (AttendanceWrapper &copy)
{
	mMasterList = copy.mMasterList;
}

///////////////////////////////////////////////////////////////////////
/// ~AttendanceWrapper ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

// destructor
AttendanceWrapper::~AttendanceWrapper ()
{
	// all deleting will be done by List's destructor
}

///////////////////////////////////////////////////////////////////////
/// getMasterList ()
/// \pre    
/// \post   
/// \param
/// \return List mMasterList
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

// getter
List AttendanceWrapper::getMasterList ()
{
	return mMasterList;
}

///////////////////////////////////////////////////////////////////////
/// setMasterList (List newMasterList)
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

// setter
void AttendanceWrapper::setMasterList (List newMasterList)
{
	mMasterList = newMasterList;
}

///////////////////////////////////////////////////////////////////////
/// import ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: clears the master list, opens a .csv file, reads in the values, stores them
/// \in their respective variables, makes the node, and inserts the node
/// \at the front of the linked list
///////////////////////////////////////////////////////////////////////

void AttendanceWrapper::import ()
{
	mMasterList.destroyList (); // refresh the master list

	// prompt the user to enter a file name to work with
	string fileName;
	cout << "Please enter a file name (.csv): ";
	cin >> fileName;

	// open the file
	ifstream input;
	input.open (fileName, std::ios::in);

	// accomodating the header of the .csv file
	char record[100];
	input.getline (record, 100, '\n'); // reads headers of columns

	while (!input.eof ())
	{
		// create a char array that will store the
		// read in lines
		char field[100];

		// reading in lines and storing them in their respective variables
		int recordNumber;
		input.getline (field, 100, ',');
		recordNumber = atoi (field); // converting strings to ints

		int idNumber;
		input.getline (field, 100, ',');
		idNumber = atoi (field); // converting strings to ints

		string lastName;
		char finalLast[100];
		input.getline (field, 100, ',');
		strcpy (finalLast, &field[1]); // accomodating the quotation marks in the .csv file
		lastName = finalLast;

		string firstName;
		input.getline (field, 100, ',');
		field[strlen (field) - 1] = '\0'; // accomodating the quotation marks in the .csv file
		firstName = field;

		// concatenate the first and last name 
		string fullName = lastName + ", " + firstName;

		string email;
		input.getline (field, 100, ',');
		email = field;

		string units;
		input.getline (field, 100, ',');
		units = field;

		string program;
		input.getline (field, 100, ',');
		program = field;

		string level;
		input.getline (field, 100, '\n');
		level = field;

		// insert the values at the front of the master list
		mMasterList.insertAtFront (recordNumber, idNumber, fullName, 
								   email, units, program, level); 

		mMasterList.mListSize ++;
	}

	cout << "List successfully imported from " << fileName << " file!" << endl;
	cout << endl; // blank line
}

///////////////////////////////////////////////////////////////////////
/// load ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: reads values from a .txt file, makes a node out of the
/// \read values, and inserts the node at the front of the list
///////////////////////////////////////////////////////////////////////

void AttendanceWrapper::load ()
{
	// open the file
	ifstream input;
	input.open ("master.txt", std::ios::in);

	while (!input.eof ())
	{
		// create a char array that will store the
		// read in lines
		char field[100];

		// reading in lines and storing them in their respective variables
		int recordNumber;
		input.getline (field, 100, '\n');
		recordNumber = atoi (field); // converting strings to ints

		int idNumber;
		input.getline (field, 100, '\n');
		idNumber = atoi (field); // converting strings to ints

		string name;
		input.getline (field, 100, '\n');
		name = field;

		string email;
		input.getline (field, 100, '\n');
		email = field;

		string units;
		input.getline (field, 100, '\n');
		units = field;

		string program;
		input.getline (field, 100, '\n');
		program = field;

		string level;
		input.getline (field, 100, '\n');
		level = field;

		int numberOfAbsences;
		input.getline (field, 100, '\n');
		numberOfAbsences = atoi (field); // converting strings to ints

		// insert the values at the front of the master list
		mMasterList.insertAtFront (recordNumber, idNumber, name, 
								   email, units, program, level); 

		mMasterList.mListSize ++;
	}

	cout << "Items from master.txt successfully stored in the master list!" << endl;
	cout << endl; // blank line
}

///////////////////////////////////////////////////////////////////////
/// store ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: transfers values from the master list into a .txt file
///////////////////////////////////////////////////////////////////////

void AttendanceWrapper::store ()
{
	// make a temporary ListNode to store the nodes
	ListNode *pTemp;

	// set the temporary node to the head of the master list
	pTemp = mMasterList.getStartPtr ();

	// open the master.txt file
	ofstream output;
	output.open ("master.txt", std::ios::out);

	while (pTemp != NULL)
	{
		output << pTemp -> mRecordNumber << endl;
		output << pTemp -> mID << endl;
		output << pTemp -> mName << endl;
		output << pTemp -> mEmail << endl;
		output << pTemp -> mUnits << endl;
		output << pTemp -> mProgram << endl;
		output << pTemp -> mLevel << endl;
		output << pTemp -> mNumberOfAbsences << endl;

		// make a loop index
		int i;

		// loop through each index of the array
		// and set it to the empty string
		for (i = 0; i < 100; i++)
		{
			output << pTemp -> mAbsentDates[i];
		}

		pTemp = pTemp -> mNextPtr;
	}

	system ("pause");
	system ("cls");
	output.close ();

	cout << "List successfully stored in master.txt file!" << endl;
	cout << endl; // blank line
}

///////////////////////////////////////////////////////////////////////
/// markAbsences ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: loops through the nodes in the master list and 
/// \marks absences based on user input
///////////////////////////////////////////////////////////////////////

void AttendanceWrapper::markAbsences ()
{
	// make a temporary ListNode to store the nodes
	ListNode *pTemp;

	// set the temporary node to the head of the master list
	pTemp = mMasterList.getStartPtr ();

	// initialize local variables
	string response;

	while (pTemp != NULL)
	{
		// set the loop index to the number of absences
		// so it is unique for each student
		int i = (pTemp -> mNumberOfAbsences);

		cout << "Was " << pTemp -> mName << " absent today?" << endl;
		cout << "Please enter yes or no (Y/N): ";
		cin >> response;

		if ((response == "Y") || (response == "y"))
		{
			pTemp -> mAbsentDates[i] = currentDateTime ();
			pTemp -> mNumberOfAbsences++;
		}

		cout << endl; // blank line

		pTemp = pTemp -> mNextPtr;
	}
}

///////////////////////////////////////////////////////////////////////
/// editByName ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: loops through the nodes of the master list, finds a node based
/// \on a user inputted search name, and removes a student's absence on a user inputted date
///////////////////////////////////////////////////////////////////////

void AttendanceWrapper::editByName ()
{
	// make a temporary ListNode to store the nodes
	ListNode *pTemp;

	// set the temporary node to the head of the master list
	pTemp = mMasterList.getStartPtr ();

	// declare search variables
	string userSearchName;
	string userSearchDate;
	int i;

	// prompt the user
	cout << "Please enter a name to search for (LastName, FirstName): ";
	cin.clear ();
	cin.sync ();
	getline (cin, userSearchName);

	// loop through each node in the master list
	while (pTemp != NULL)
	{
		if ((pTemp -> getName ()) == userSearchName) // found the student
		{
			// prompt the user
			cout << "Please enter a date to edit (MM-DD-YYYY): ";
			cin >> userSearchDate;
			cout << endl; // blank line

			// loop through each index of the absent array
			for (i = 0; i < 100; i++)
			{
				if ((pTemp -> mAbsentDates[i]) == userSearchDate) // found the absent date to edit
				{
					pTemp -> setAbsentDates("", i); // get rid of the absence
					pTemp -> mNumberOfAbsences--;
					
					cout << "Absence on " << userSearchDate << " for " 
						 << pTemp -> getName () << " was updated!" << endl;
					cout << endl; // blank line
				}
			}
		}

		pTemp = pTemp -> mNextPtr;
	}
}

///////////////////////////////////////////////////////////////////////
/// editByID ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: loops through the nodes of the master list, finds a node based
/// \on a user inputted search ID, and removes a student's absence on a user inputted date
///////////////////////////////////////////////////////////////////////

void AttendanceWrapper::editByID ()
{
	// make a temporary ListNode to store the nodes
	ListNode *pTemp;

	// set the temporary node to the head of the master list
	pTemp = mMasterList.getStartPtr ();

	// declare search variables
	int userSearchID;
	string userSearchDate;
	int i;

	// prompt the user
	cout << "Please enter an ID to search for: ";
	cin >> userSearchID;

	// loop through each node in the master list
	while (pTemp != NULL)
	{
		if ((pTemp -> getID ()) == userSearchID) // found the student
		{
			// prompt the user
			cout << "Please enter a date to edit (MM-DD-YYYY): ";
			cin >> userSearchDate;
			cout << endl; // blank line

			// loop through each index of the absent array
			for (i = 0; i < 100; i++)
			{
				if ((pTemp -> mAbsentDates[i]) == userSearchDate) // found the absent date to edit
				{
					pTemp -> setAbsentDates("", i); // get rid of the absence
					pTemp -> mNumberOfAbsences--;

					cout << "Absence on " << userSearchDate << " for " 
						 << pTemp -> getName () << " was updated!" << endl;
					cout << endl; // blank line
				}
			}
		}

		pTemp = pTemp -> mNextPtr;
	}
}

///////////////////////////////////////////////////////////////////////
/// currentDateTime ()
/// \pre    
/// \post   
/// \param
/// \return a string of the current date
/// \throw  
/// \description: the current date is based on the computer's clock
/// \NOTE: THIS METHOD WAS RETRIEVED FROM http://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
///////////////////////////////////////////////////////////////////////

string AttendanceWrapper::currentDateTime ()
{
	time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%m-%d-%Y", &tstruct);

    return buf;
}

///////////////////////////////////////////////////////////////////////
/// generateAll ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: loops through every node in the master list, writes the
/// \student's name, email, number of absences, and absence dates to a .txt file
///////////////////////////////////////////////////////////////////////

void AttendanceWrapper::generateAll ()
{
	// make a temporary ListNode to store the nodes
	ListNode *pTemp;

	// set the temporary node to the head of the master list
	pTemp = mMasterList.getStartPtr ();

	// open the allReport.txt file
	ofstream output;
	output.open ("allReport.txt", std::ios::out);

	while (pTemp != NULL)
	{
		output << "Name: " << pTemp -> mName << endl;
		output << "Email: " << pTemp -> mEmail << endl;
		output << "Number of absences: " << pTemp -> mNumberOfAbsences << endl;

		// make a loop index
		int i;

		output << "Absent dates: ";

		// loop through each index of the absent array
		for (i = 0; i < 100; i++)
		{
			output << pTemp -> mAbsentDates[i] << " ";
		}

		// improve file readability
		output << endl; // blank line
		output << endl; // blank line

		pTemp = pTemp -> mNextPtr;
	}

	system ("pause");
	system ("cls");
	output.close ();

	cout << "Report successfully generated to allReport.txt file!" << endl;
	cout << endl; // blank line
}

///////////////////////////////////////////////////////////////////////
/// generateSearch ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: loops through every node in the master list, writes the
/// \student's name, email, number of absences, and absence dates to a .txt file based
/// \on a number of absence threshold provided by user input
///////////////////////////////////////////////////////////////////////

void AttendanceWrapper::generateSearch ()
{
	// make a temporary ListNode to store the nodes
	ListNode *pTemp;

	// set the temporary node to the head of the master list
	pTemp = mMasterList.getStartPtr ();

	// open the searchReport.txt file
	ofstream output;
	output.open ("searchReport.txt", std::ios::out);

	// declare a local variable for user input
	int userAbsenceNumber;

	cout << "Please enter a threshold number of absences: ";
	cin >> userAbsenceNumber;
	cout << endl; // blank line

	// loop through the master list array
	while (pTemp != NULL)
	{
		// we found a student who fits the search criteria
		if ((pTemp -> getNumberOfAbsences ()) >= userAbsenceNumber)
		{
			output << "Name: " << pTemp -> mName << endl;
			output << "Email: " << pTemp -> mEmail << endl;
			output << "Number of absences: " << pTemp -> mNumberOfAbsences << endl;

			// make a loop index
			int i;

			output << "Absent dates: ";

			// loop through each index of the absent array
			for (i = 0; i < 100; i++)
			{
				output << pTemp -> mAbsentDates[i] << " ";
			}
		}

		// improve file readability
		output << endl; // blank line
		output << endl; // blank line

		pTemp = pTemp -> mNextPtr;
	}

	system ("pause");
	system ("cls");
	output.close ();

	cout << "Report successfully generated to searchReport.txt file!" << endl;
	cout << endl; // blank line
}

///////////////////////////////////////////////////////////////////////
/// generateDate ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: loops through every node in the master list, writes the
/// \student's name, email, number of absences, and absence dates to a .txt file based
/// \on a search date provided by user input
///////////////////////////////////////////////////////////////////////

void AttendanceWrapper::generateDate ()
{
	// make a temporary ListNode to store the nodes
	ListNode *pTemp;

	// set the temporary node to the head of the master list
	pTemp = mMasterList.getStartPtr ();

	// open the dateReport.txt file
	ofstream output;
	output.open ("dateReport.txt", std::ios::out);

	// declare a local variable for user input
	string userSearchDate;

	// loop index variable
	int i;

	cout << "Please enter a date (MM-DD-YYYY): ";
	cin >> userSearchDate;
	cout << endl; // blank line

	// loop through the master list
	while (pTemp != NULL)
	{
		// loop through the students' absent dates
		for (i = 0; i < 100; i++)
		{
			if ((pTemp -> getAbsentDates ()) == userSearchDate) // find a matching search date
			{
				output << "Name: " << pTemp -> mName << endl;
				output << "Email: " << pTemp -> mEmail << endl;
				output << "Number of absences: " << pTemp -> mNumberOfAbsences << endl;
				output << "Absent dates: ";

				// loop through each index of the absent array
				for (i = 0; i < 100; i++)
				{
					output << pTemp -> mAbsentDates[i] << " ";
				}
				
				break; // if we find a matching date, we're done - don't need to loop anymore
			}
		}

		// improve file readability
		output << endl; // blank line
		output << endl; // blank line

		pTemp = pTemp -> mNextPtr;
	}

	system ("pause");
	system ("cls");
	output.close ();

	cout << "Report successfully generated to dateReport.txt file!" << endl;
	cout << endl; // blank line
}