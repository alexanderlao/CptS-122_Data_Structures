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

#include "ListNode.h"

///////////////////////////////////////////////////////////////////////
/// ListNode ()
/// \pre    
/// \post   
/// \param
/// \return ListNode object
/// \throw  
/// \description: dynamically allocates memory for a new ListNode
///////////////////////////////////////////////////////////////////////

// constructor
ListNode::ListNode (int newRecordNumber, int newID, string newName, string newEmail,
				    string newUnits, string newProgram, string newLevel)
{
	this -> mRecordNumber = newRecordNumber;
	this -> mID = newID;
	this -> mName = newName;
	this -> mEmail = newEmail;
	this -> mUnits = newUnits;
	this -> mProgram = newProgram;
	this -> mLevel = newLevel;
	this -> mNumberOfAbsences = 0;

	// make a loop index
	int i;

	// loop through each index of the array
	// and set it to the empty string
	for (i = 0; i < 100; i++)
	{
		this -> mAbsentDates[i] = "";
	}

	this -> mNextPtr = NULL;
}

///////////////////////////////////////////////////////////////////////
/// ListNode (ListNode &copy)
/// \pre    
/// \post   
/// \param
/// \return copyNode
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

// copy constructor
ListNode::ListNode (ListNode &copy)
{
	// shallow copy
	this -> mRecordNumber = copy.mRecordNumber;
	this -> mID = copy.mID;
	this -> mName = copy.mName;
	this -> mEmail = copy.mEmail;
	this -> mUnits = copy.mUnits;
	this -> mProgram = copy.mProgram;
	this -> mLevel = copy.mLevel;
	this -> mNumberOfAbsences = copy.mNumberOfAbsences;
	this -> mAbsentDates[100] = copy.mAbsentDates[100];
	this -> mNextPtr = copy.mNextPtr;
}

///////////////////////////////////////////////////////////////////////
/// ~ListNode ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: does nothing, relies on List's destructor
///////////////////////////////////////////////////////////////////////

// destructor
ListNode::~ListNode ()
{
	// all deleting will be done by List's destructor
}

///////////////////////////////////////////////////////////////////////
/// getRecordNumber ()
/// \pre    
/// \post   
/// \param
/// \return int mRecordNumber
/// \throw  
/// \discription
///////////////////////////////////////////////////////////////////////

// getters/accessors - access private data members
int ListNode::getRecordNumber ()
{
	return mRecordNumber;
}

///////////////////////////////////////////////////////////////////////
/// getID ()
/// \pre    
/// \post   
/// \param
/// \return int mID
/// \throw  
/// \discription
///////////////////////////////////////////////////////////////////////

int ListNode::getID ()
{
	return mID;
}

///////////////////////////////////////////////////////////////////////
/// getName ()
/// \pre    
/// \post   
/// \param
/// \return string mName
/// \throw  
/// \discription
///////////////////////////////////////////////////////////////////////

string ListNode::getName ()
{
	return mName;
}

///////////////////////////////////////////////////////////////////////
/// getEmail ()
/// \pre    
/// \post   
/// \param
/// \return string mEmail
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

string ListNode::getEmail ()
{
	return mEmail;
}

///////////////////////////////////////////////////////////////////////
/// getUnits ()
/// \pre    
/// \post   
/// \param
/// \return string mUnits
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

string ListNode::getUnits ()
{
	return mUnits;
}

///////////////////////////////////////////////////////////////////////
/// getProgram ()
/// \pre    
/// \post   
/// \param
/// \return string mProgram
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

string ListNode::getProgram ()
{
	return mProgram;
}

///////////////////////////////////////////////////////////////////////
/// getLevel ()
/// \pre    
/// \post   
/// \param
/// \return string mLevel
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

string ListNode::getLevel ()
{
	return mLevel;
}

///////////////////////////////////////////////////////////////////////
/// getNumberOfAbsences ()
/// \pre    
/// \post   
/// \param
/// \return int mNumberOfAbsences
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

int ListNode::getNumberOfAbsences ()
{
	return mNumberOfAbsences;
}

///////////////////////////////////////////////////////////////////////
/// getAbsentDates ()
/// \pre    
/// \post   
/// \param
/// \return string mAbsentDates[i]
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

string ListNode::getAbsentDates ()
{
	int i;

	for (i = 0; i < 100; i++)
	{
		return mAbsentDates[i];
	}
}

///////////////////////////////////////////////////////////////////////
/// getNextPtr ()
/// \pre    
/// \post   
/// \param
/// \return ListNode *mNextPtr
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

ListNode * ListNode::getNextPtr ()
{
	return mNextPtr;
}

///////////////////////////////////////////////////////////////////////
/// setRecordNumber (int newRecordNumber)
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

// setters/mutators - modify private data members
void ListNode::setRecordNumber (int newRecordNumber)
{
	mRecordNumber = newRecordNumber;
}

///////////////////////////////////////////////////////////////////////
/// setID (int newID)
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

void ListNode::setID (int newID)
{
	mID = newID;
}

///////////////////////////////////////////////////////////////////////
/// setName (string newName)
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

void ListNode::setName (string newName)
{
	mName = newName;
}

///////////////////////////////////////////////////////////////////////
/// setEmail (string newEmail)
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

void ListNode::setEmail (string newEmail)
{
	mEmail = newEmail;
}

///////////////////////////////////////////////////////////////////////
/// setUnits (string newUnits)
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

void ListNode::setUnits (string newUnits)
{
	mUnits = newUnits;
}

///////////////////////////////////////////////////////////////////////
/// setProgram (string newProgram)
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

void ListNode::setProgram (string newProgram)
{
	mProgram = newProgram;
}

///////////////////////////////////////////////////////////////////////
/// setLevel (string newLevel)
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

void ListNode::setLevel (string newLevel)
{
	mLevel = newLevel;
}

///////////////////////////////////////////////////////////////////////
/// setNumberOfAbsences (int newNumberOfAbsences)
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

void ListNode::setNumberOfAbsences (int newNumberOfAbsences)
{
	mNumberOfAbsences = newNumberOfAbsences;
}

///////////////////////////////////////////////////////////////////////
/// setAbsentDates (string newAbsenceDate, int index)
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

void ListNode::setAbsentDates (string newAbsenceDate, int index)
{
	mAbsentDates[index] = newAbsenceDate;
}

///////////////////////////////////////////////////////////////////////
/// setNextPtr (ListNode * nextPtr)
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

void ListNode::setNextPtr (ListNode * nextPtr)
{
	mNextPtr = nextPtr;
}