/*******************************************************************************
 * Programmer: Alexander Lao                                                   *
 * Class: CptS 122; Lab Section 2                                              *
 * Programming Assignment: Cipher Objects                                      *
 * Date: 11/04/2015                                                            *
 *                                                                             *
 * Description: This application encodes/decodes Caesar Cipher and             *
 *				Substitution Cipher objects.                                   *                                               
 ******************************************************************************/

#ifndef CAESAR_H
#define CAESAR_H

#include <iostream>
#include <fstream>
#include <string>

#include "Cipher.h"

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

class Caesar : public Cipher
{
	public:
		// default constructor
		Caesar ();

		// parameterized constructor
		Caesar (string newMessage, bool newStatus, int newKey);

		// destructor
		~Caesar ();

		// getter
		int getKey ();

		// setter
		void setKey (int newKey);

		void encode ();
		void decode ();

	private:
		int key;
};

#endif