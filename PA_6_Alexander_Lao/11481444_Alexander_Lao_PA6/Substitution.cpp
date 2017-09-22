/*******************************************************************************
 * Programmer: Alexander Lao                                                   *
 * Class: CptS 122; Lab Section 2                                              *
 * Programming Assignment: Cipher Objects                                      *
 * Date: 11/04/2015                                                            *
 *                                                                             *
 * Description: This application encodes/decodes Caesar Cipher and             *
 *				Substitution Cipher objects.                                   *                                               
 ******************************************************************************/

#include "Substitution.h"

///////////////////////////////////////////////////////////////////////
/// Substitution ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \discription: implicitly invoked when creating a new Substitution object
///////////////////////////////////////////////////////////////////////

// default constructor
Substitution::Substitution ()
{
	// just exists
}

///////////////////////////////////////////////////////////////////////
/// Substitution (string newMessage, bool newStatus)
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \discription: creates a new Substitution object, inherited from Cipher's
/// \constructor
///////////////////////////////////////////////////////////////////////

// parameterized constructor
Substitution::Substitution (string newMessage, bool newStatus) : Cipher (newMessage, newStatus)
{
	// all constructing is done by cipher's constructor
}

///////////////////////////////////////////////////////////////////////
/// ~Substitution ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: does nothing
///////////////////////////////////////////////////////////////////////

// destructor
Substitution::~Substitution ()
{
	// does nothing
}

///////////////////////////////////////////////////////////////////////
/// encode ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: generates a randomly ordered alphabet and encrypts a user
/// \inputted string based on the randomized alphabet
///////////////////////////////////////////////////////////////////////

void Substitution::encode ()
{
	// initialize local variables
	int length;
	string newMessage;
	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int randomIndex;
	
	cout << "Please enter a message to encode: ";
	cin.clear ();
	cin.sync ();
	getline (cin, newMessage);

	// set the length variable to the length of the string
	length = newMessage.length ();

	// loop through each index of the string
	for (int i = 0; i < length; i++)
	{
		// generate a random number between 0 - 25
		randomIndex = rand () % 26;

		// check for alphabetical characters
		if (isalpha (newMessage[i]))
		{
			// convert the character to upper case
			newMessage[i] = toupper (newMessage[i]);
			newMessage[i] = alphabet[randomIndex];
		}
	}

	// print out the new message
	cout << "Your encoded message: " << newMessage << endl;
	cout << endl; // blank line for readability
}

///////////////////////////////////////////////////////////////////////
/// decode ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: is supposed to decrypt a string based on frequent characters
/// \and a look-up table
///////////////////////////////////////////////////////////////////////

void Substitution::decode ()
{
	// initialize local variables
	int length;
	string encodedMessage;
	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int randomIndex;

	// prompt the user
	cout << "Please enter a message to decode: ";
	cin.clear ();
	cin.sync ();
	getline (cin, encodedMessage);

	// set the length variable to the length of the string
	length = encodedMessage.length ();

	// loop through each index of the string
	for (int i = 0; i < length; i++)
	{
		// generate a random number between 0 - 25
		randomIndex = rand () % 26;

		// check for alphabetical characters
		if (isalpha (encodedMessage[i]))
		{
			// convert the character to upper case
			encodedMessage[i] = toupper (encodedMessage[i]);
			encodedMessage[i] = alphabet[randomIndex];
		}
	}

	// print out the new message
	cout << "Your decoded message: " << encodedMessage << endl;
	cout << endl; // blank line for readability
}