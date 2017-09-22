/*******************************************************************************
 * Programmer: Alexander Lao                                                   *
 * Class: CptS 122; Lab Section 2                                              *
 * Programming Assignment: Cipher Objects                                      *
 * Date: 11/04/2015                                                            *
 *                                                                             *
 * Description: This application encodes/decodes Caesar Cipher and             *
 *				Substitution Cipher objects.                                   *                                               
 ******************************************************************************/

#include "Cipher.h"

///////////////////////////////////////////////////////////////////////
/// Cipher ()
/// \pre    
/// \post   
/// \param
/// \return Cipher object
/// \throw  
/// \description: dynamically allocates memory for a new Cipher object
///////////////////////////////////////////////////////////////////////

// default constructor
Cipher::Cipher ()
{
	this -> message = "";
	this -> status = false;
}

///////////////////////////////////////////////////////////////////////
/// Cipher (string newMessage, bool newStatus)
/// \pre    
/// \post   
/// \param
/// \return Cipher object
/// \throw  
/// \description: dynamically allocates memory for a new Cipher object
///////////////////////////////////////////////////////////////////////

// parameterized constructor
Cipher::Cipher (string newMessage, bool newStatus)
{
	this -> message = newMessage;
	this -> status = newStatus;
}

///////////////////////////////////////////////////////////////////////
/// Cipher (Cipher &copy)
/// \pre    
/// \post   
/// \param
/// \return Cipher object
/// \throw  
/// \description: returns a copy of a Cipher object
///////////////////////////////////////////////////////////////////////

// copy constructor
Cipher::Cipher (Cipher &copy)
{
	this -> message = copy.message;
	this -> status = copy.status;
}

///////////////////////////////////////////////////////////////////////
/// ~Cipher ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: does nothing
///////////////////////////////////////////////////////////////////////

// destructor
Cipher::~Cipher ()
{
	// does nothing
}

///////////////////////////////////////////////////////////////////////
/// getMessage ()
/// \pre    
/// \post   
/// \param
/// \return string message
/// \throw  
/// \discription
///////////////////////////////////////////////////////////////////////

// getters
string Cipher::getMessage ()
{
	return message;
}

///////////////////////////////////////////////////////////////////////
/// getStatus ()
/// \pre    
/// \post   
/// \param
/// \return bool status
/// \throw  
/// \discription
///////////////////////////////////////////////////////////////////////

bool Cipher::getStatus ()
{
	return status;
}

///////////////////////////////////////////////////////////////////////
/// setMessage (string newMessage)
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

// setters
void Cipher::setMessage (string newMessage)
{
	message = newMessage;
}

///////////////////////////////////////////////////////////////////////
/// setStatus (bool newStatus)
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

void Cipher::setStatus (bool newStatus)
{
	status = newStatus;
}