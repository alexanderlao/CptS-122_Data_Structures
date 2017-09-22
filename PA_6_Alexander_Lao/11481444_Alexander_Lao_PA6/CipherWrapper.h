/*******************************************************************************
 * Programmer: Alexander Lao                                                   *
 * Class: CptS 122; Lab Section 2                                              *
 * Programming Assignment: Cipher Objects                                      *
 * Date: 11/04/2015                                                            *
 *                                                                             *
 * Description: This application encodes/decodes Caesar Cipher and             *
 *				Substitution Cipher objects.                                   *                                               
 ******************************************************************************/

#ifndef CIPHER_WRAPPER_H
#define CIPHER_WRAPPER_H

#include <iostream>
#include <string>
#include <cstring> // i.e. string.h

#include "Caesar.h"
#include "Substitution.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class CipherWrapper
{
	public:

		// constructor
		CipherWrapper ();

		// copy constructor
		CipherWrapper (CipherWrapper &copy);

		// destructor
		~CipherWrapper ();

		// getter
		int getMenuChoice ();

		// setter
		void setMenuChoice (int newMenuChoice);

		void displayMenu ();
		void caesarSubMenu ();
		void substitutionSubMenu ();

	private:
		int menuChoice;
};

#endif