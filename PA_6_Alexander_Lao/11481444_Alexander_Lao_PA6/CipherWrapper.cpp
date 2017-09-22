/*******************************************************************************
 * Programmer: Alexander Lao                                                   *
 * Class: CptS 122; Lab Section 2                                              *
 * Programming Assignment: Cipher Objects                                      *
 * Date: 11/04/2015                                                            *
 *                                                                             *
 * Description: This application encodes/decodes Caesar Cipher and             *
 *				Substitution Cipher objects.                                   *                                               
 ******************************************************************************/

#include "CipherWrapper.h"

///////////////////////////////////////////////////////////////////////
/// CipherWrapper ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: dynamically allocates memory for a CipherWrapper object
///////////////////////////////////////////////////////////////////////

// constructor
CipherWrapper::CipherWrapper ()
{
	this -> menuChoice = 0;
}

///////////////////////////////////////////////////////////////////////
/// CipherWrapper (CipherWrapper &copy)
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: dynamically allocates memory for a copy of a CipherWrapper object
///////////////////////////////////////////////////////////////////////

// copy constructor
CipherWrapper::CipherWrapper (CipherWrapper &copy)
{
	this -> menuChoice = copy.menuChoice;
}

///////////////////////////////////////////////////////////////////////
/// ~CipherWrapper ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: does nothing
///////////////////////////////////////////////////////////////////////

// destructor
CipherWrapper::~CipherWrapper ()
{
	// does nothing
}

///////////////////////////////////////////////////////////////////////
/// getMenuChoice ()
/// \pre    
/// \post   
/// \param
/// \return: int menuChoice
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

// getter
int CipherWrapper::getMenuChoice ()
{
	return menuChoice;
}

///////////////////////////////////////////////////////////////////////
/// setMenuChoice ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

// setter
void CipherWrapper::setMenuChoice (int newMenuChoice)
{
	menuChoice = newMenuChoice;
}

///////////////////////////////////////////////////////////////////////
/// displayMenu ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: displays the main menu for the Cipher program;
/// \invokes methods based on user input
///////////////////////////////////////////////////////////////////////

void CipherWrapper::displayMenu ()
{
	// initialize local variables
	bool running = true;

	while (running)
	{
		cout << "Welcome to Cipher Central!" << endl;
		cout << "1. Perform a Caesar Cipher" << endl;
		cout << "2. Perform a Substitution Cipher" << endl;
		cout << "3. Exit" << endl;
		cout << "Your choice: ";
		cin >> menuChoice;
		cout << endl; // blank line

		if (menuChoice == 1)
		{
			caesarSubMenu ();
		}
		else if (menuChoice == 2)
		{
			substitutionSubMenu ();
		}
		else if (menuChoice == 3)
		{
			running = false;
		}
		else
		{
			cout << "Please enter a valid option." << endl;
			cout << endl; // blank line
		}
	}
}

///////////////////////////////////////////////////////////////////////
/// caesarSubMenu ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: displays the sub menu for the Caesar shift;
/// \invokes methods based on user input
///////////////////////////////////////////////////////////////////////

void CipherWrapper::caesarSubMenu ()
{
	Caesar c1;

	cout << "Would you like to encode or decode a message?" << endl;
	cout << "1. Encode" << endl;
	cout << "2. Decode" << endl;
	cout << "Your choice: ";
	cin >> menuChoice;
	cout << endl; // blank line

	if (menuChoice == 1)
	{
		c1.encode ();
	}
	else if (menuChoice == 2)
	{
		c1.decode ();
	}
	else
	{
		cout << "Please enter a valid option." << endl;
		cout << endl; // blank line
	}
}

///////////////////////////////////////////////////////////////////////
/// substitutionSubMenu ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: displays the sub menu for the Substitution cipher;
/// \invokes methods based on user input
///////////////////////////////////////////////////////////////////////

void CipherWrapper::substitutionSubMenu ()
{
	Substitution s1;

	cout << "Would you like to encode or decode a message?" << endl;
	cout << "1. Encode" << endl;
	cout << "2. Decode" << endl;
	cout << "Your choice: ";
	cin >> menuChoice;
	cout << endl; // blank line

	if (menuChoice == 1)
	{
		s1.encode ();
	}
	else if (menuChoice == 2)
	{
		s1.decode ();
	}
	else
	{
		cout << "Please enter a valid option." << endl;
		cout << endl; // blank line
	}
}