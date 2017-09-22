/*******************************************************************************
 * Programmer: Alexander Lao                                                   *
 * Class: CptS 122; Lab Section 2                                              *
 * Programming Assignment: Cipher Objects                                      *
 * Date: 11/04/2015                                                            *
 *                                                                             *
 * Description: This application encodes/decodes Caesar Cipher and             *
 *				Substitution Cipher objects.                                   *                                               
 ******************************************************************************/

#ifndef SUBSTITUTION_H
#define SUBSTITUTION_H

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

class Substitution : public Cipher
{
	public:
		// default constructor
		Substitution ();

		// parameterized constructor
		Substitution (string newMessage, bool newStatus);

		// destructor
		~Substitution ();

		void encode ();
		void decode ();		
};

#endif