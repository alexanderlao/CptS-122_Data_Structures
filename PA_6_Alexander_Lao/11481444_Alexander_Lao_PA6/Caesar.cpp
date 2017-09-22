/*******************************************************************************
 * Programmer: Alexander Lao                                                   *
 * Class: CptS 122; Lab Section 2                                              *
 * Programming Assignment: Cipher Objects                                      *
 * Date: 11/04/2015                                                            *
 *                                                                             *
 * Description: This application encodes/decodes Caesar Cipher and             *
 *				Substitution Cipher objects.                                   *                                               
 ******************************************************************************/

#include "Caesar.h"

///////////////////////////////////////////////////////////////////////
/// Caesar ()
/// \pre    
/// \post   
/// \param
/// \return Caesar object
/// \throw  
/// \description: dynamically allocates memory for a new Caesar object
///////////////////////////////////////////////////////////////////////

// default constructor
Caesar::Caesar ()
{
	this -> message = "";
	this -> status = false;
	this -> key = 0;
}

///////////////////////////////////////////////////////////////////////
/// Caesar (string newMessage, bool newStatus, int newKey)
/// \pre    
/// \post   
/// \param
/// \return Caesar object
/// \throw  
/// \description: dynamically allocates memory for a new Caesar object;
/// \inherited from Cipher's constructor
///////////////////////////////////////////////////////////////////////

// parameterized constructor
Caesar::Caesar (string newMessage, bool newStatus, int newKey) : Cipher (newMessage, newStatus)
{
	this -> key = newKey;
}

///////////////////////////////////////////////////////////////////////
/// ~Caesar ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: does nothing
///////////////////////////////////////////////////////////////////////

// destructor
Caesar::~Caesar ()
{
	// does nothing
}

///////////////////////////////////////////////////////////////////////
/// getKey ()
/// \pre    
/// \post   
/// \param
/// \return int key
/// \throw  
/// \discription
///////////////////////////////////////////////////////////////////////

// getter
int Caesar::getKey ()
{
	return key;
}

///////////////////////////////////////////////////////////////////////
/// setKey (int newKey)
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \discription
///////////////////////////////////////////////////////////////////////

// setter
void Caesar::setKey (int newKey)
{
	key = newKey;
}

///////////////////////////////////////////////////////////////////////
/// encode ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \discription: Caesar shifts a user inputted string based on a user inputted key;
/// \then writes it the the encoded.txt file
///////////////////////////////////////////////////////////////////////

void Caesar::encode ()
{
	// initialize local variables
	int length;
	string newMessage;

	cout << "Please enter a message to encode: ";
	cin.clear ();
	cin.sync ();
	getline (cin, newMessage);

	// prompt the user
	cout << "Please enter a key (1 - 25): ";
	cin >> key;

	if (key > 25 || key < 1) // invalid key
	{
		cout << "Please enter a valid key." << endl;
		cout << endl; // blank line for readability
	}
	else // valid key
	{
		// set the length to the length of the string
		length = newMessage.length ();

		// loop through each index of the string
		for (int i = 0; i < length; i++)
		{
			// check for alphabetical characters
			if (isalpha (newMessage[i]))
			{
				// convert the character to upper case
				newMessage[i] = toupper (newMessage[i]);
			
				// apply the shift
				newMessage[i] += key;

				//if the shift goes beyond the letter Z
				//subtract the 26 letters in the alphabet
				//to bring it back to letter A
				if (newMessage[i] > 'Z')
				{
					newMessage[i] -= 26;
				}

				//if the shift goes before the letter A
				//add the 26 letters in the alphabet
				//to bring it back to letter Z
				else if (newMessage[i] < 'A')
				{
					newMessage[i] += 26;
				}
			}
		}

		// print out the new message
		cout << "Your encoded message: " << newMessage << endl;
		cout << endl; // blank line for readability

		// open the master.txt file
		ofstream output;
		output.open ("encoded.txt", std::ios::app);

		// write the encoded message to the file
		output << newMessage << endl;

		// close the ofstream
		system ("pause");
		system ("cls");
		output.close ();

		cout << "Encoded message successfully stored in the encoded.txt file!" << endl;
		cout << endl; // blank line
	}
}

///////////////////////////////////////////////////////////////////////
/// decode ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \discription: decodes an encrypted string. if the key is known, it's a
/// \simple shift backwards. if not, brute force is applied
///////////////////////////////////////////////////////////////////////

void Caesar::decode ()
{
	// declare local variables
	string userChoice;
	int userKey;
	int length;
	string encodedMessage;

	// prompt the user
	cout << "Please enter a message to decode: ";
	cin.clear ();
	cin.sync ();
	getline (cin, encodedMessage);

	cout << "Do you know the key? (Y/N): "; 
	cin >> userChoice;

	if (userChoice == "Y" || userChoice == "y")
	{
		cout << "What is the key? (1-25): "; 
		cin >> userKey;

		// set the length to the length of the string
		length = encodedMessage.length ();

		// loop through each index of the string
		for (int i = 0; i < length; i++)
		{
			// check for alphabetical characters
			if (isalpha (encodedMessage[i]))
			{
				// convert the character to upper case
				encodedMessage[i] = toupper (encodedMessage[i]);
			
				// apply the reversed shift
				encodedMessage[i] -= userKey;

				//if the shift goes beyond the letter Z
				//subtract the 26 letters in the alphabet
				//to bring it back to letter A
				if (encodedMessage[i] > 'Z')
				{
					encodedMessage[i] -= 26;
				}

				//if the shift goes before the letter A
				//add the 26 letters in the alphabet
				//to bring it back to letter Z
				else if (encodedMessage[i] < 'A')
				{
					encodedMessage[i] += 26;
				}
			}
		}

		// print out the decoded message
		cout << "Your decoded message: " << encodedMessage << endl;
		cout << endl; // blank line for readability
	}
	else if (userChoice == "N" || userChoice == "n")
	{
		// loop through all of the possible shift amounts
		for (int shift = 1; shift <= 25; shift++)
		{
			// set the length variable to the length of the string
			length = encodedMessage.length ();

			// loop through each index of the string
			for (int i = 0; i < length; i++)
			{
				// check for alphabetical characters
				if (isalpha (encodedMessage[i]))
				{
					// convert the character to upper case
					encodedMessage[i] = toupper (encodedMessage[i]);
			
					// apply the reversed shift
					encodedMessage[i] -= shift;

					//if the shift goes beyond the letter Z
					//subtract the 26 letters in the alphabet
					//to bring it back to letter A
					if (encodedMessage[i] > 'Z')
					{
						encodedMessage[i] -= 26;
					}

					//if the shift goes before the letter A
					//add the 26 letters in the alphabet
					//to bring it back to letter Z
					else if (encodedMessage[i] < 'A')
					{
						encodedMessage[i] += 26;
					}
				}
			}

			// ask the user if the shift was correct
			cout << "Is this the correct message: " << encodedMessage << endl;
			cout << "(Y/N): ";
			cin >> userChoice;
			cout << endl;

			if (userChoice == "Y" || userChoice == "y")
			{
				cout << "The shift key was: " << shift << "." << endl;
				cout << endl; // blank line for readability
				break; // break out of the loop; we found the correct shift
			}
			else if (userChoice == "N" || userChoice == "n")
			{
				for (int j = 0; j < length; j++)
				{
					// check for alphabetical characters
					if (isalpha (encodedMessage[j]))
					{
						// reset the encoded message and continue the for-loop
						encodedMessage[j] += shift;

						//if the shift goes beyond the letter Z
						//subtract the 26 letters in the alphabet
						//to bring it back to letter A
						if (encodedMessage[j] > 'Z')
						{
							encodedMessage[j] -= 26;
						}

						//if the shift goes before the letter A
						//add the 26 letters in the alphabet
						//to bring it back to letter Z
						else if (encodedMessage[j] < 'A')
						{
							encodedMessage[j] += 26;
						}
					}
				}
			}
		}
	}
}