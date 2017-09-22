/*******************************************************************************
 * Programmer: Alexander Lao                                                   *
 * Class: CptS 122; Lab Section 2                                              *
 * Programming Assignment: Cipher Objects                                      *
 * Date: 11/04/2015                                                            *
 *                                                                             *
 * Description: This application encodes/decodes Caesar Cipher and             *
 *				Substitution Cipher objects.                                   *                                               
 ******************************************************************************/

#ifndef CIPHER_H
#define CIPHER_H

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// Cipher is the base class
class Cipher
{
	public:
		// default constructor
		Cipher ();

		// parameterized constructor
		Cipher (string newMessage, bool newStatus);

		// copy constructor
		Cipher (Cipher &copy);

		// destructor
		~Cipher ();

		// getters
		string getMessage ();
		bool getStatus ();

		// setters
		void setMessage (string newMessage);
		void setStatus (bool newStatus);

		void encode ();
		void decode ();

	protected:
		string message;
		bool status;
};

#endif