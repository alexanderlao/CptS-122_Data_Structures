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

#include "List.h"

///////////////////////////////////////////////////////////////////////
/// List ()
/// \pre    
/// \post   
/// \param
/// \return List object
/// \throw  
///////////////////////////////////////////////////////////////////////

// constructor
List::List ()
{
	this -> mListSize = 0;
	mStartPtr = NULL;
}

///////////////////////////////////////////////////////////////////////
/// List (List &copy)
/// \pre    
/// \post   
/// \param
/// \return List object
/// \throw  
///////////////////////////////////////////////////////////////////////

// copy constructor
List::List (List &copy)
{
	this -> mListSize = copy.mListSize;
	this -> mStartPtr = copy.mStartPtr;
}

///////////////////////////////////////////////////////////////////////
/// ~List ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw
/// \description: invokes destroyList () which deletes every node in the list
///////////////////////////////////////////////////////////////////////

// destructor
List::~List ()
{
	destroyList ();
}

///////////////////////////////////////////////////////////////////////
/// operator= (const List &rhs)
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: allows the assignment operator to work with List types
///////////////////////////////////////////////////////////////////////

// overloaded assignment operator
List & List::operator= (const List &rhs)
{
	if (this != &rhs) // Check for self-assignment
	{
		ListNode *pCur = rhs.mStartPtr, *pTemp = NULL;
		
		this -> destroyList (); // Release any memory before we assign a new list to the other list
		this -> mStartPtr = NULL;

		while (pCur != NULL) // We are making a deep copy of rhs' list; create new dynamic memory
		{
			ListNode *pMem = new ListNode (pCur -> mRecordNumber, pCur -> mID, pCur -> mName, 
										   pCur -> mEmail, pCur -> mUnits, pCur -> mProgram, pCur -> mLevel);

			// walk through the list
			if (this -> mStartPtr == NULL) // list is empty
			{
				this -> mStartPtr = pMem;
				pTemp = this -> mStartPtr;
			}
			else // list is not empty
			{
				pTemp -> mNextPtr = pMem;
				pTemp = pTemp -> mNextPtr;
			}
			pCur = pCur -> mNextPtr;
		}
	}

	return (*this);
}

///////////////////////////////////////////////////////////////////////
/// getListSize ()
/// \pre    
/// \post   
/// \param
/// \return List mListSize
/// \throw  
///////////////////////////////////////////////////////////////////////

// getters
int List::getListSize ()
{
	return mListSize;
}

///////////////////////////////////////////////////////////////////////
/// getStartPtr ()
/// \pre    
/// \post   
/// \param
/// \return List mStartPtr
/// \throw  
///////////////////////////////////////////////////////////////////////

ListNode * List::getStartPtr ()
{
	return mStartPtr;
}

///////////////////////////////////////////////////////////////////////
/// setListSize ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

// setters
void List::setListSize (int newListSize)
{
	mListSize = newListSize;
}

///////////////////////////////////////////////////////////////////////
/// setStartPtr ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

void List::setStartPtr (ListNode * newStartPtr)
{
	mStartPtr = mStartPtr;
}

///////////////////////////////////////////////////////////////////////
/// insertAtFront ()
/// \pre    
/// \post   
/// \param
/// \return bool success
/// \throw  
/// \description: calls makeNode, adds the node to the front of the list
///////////////////////////////////////////////////////////////////////

bool List::insertAtFront (int newRecordNumber, int newID, string newName, string newEmail,
						  string newUnits, string newProgram, string newLevel)
{
	bool success = false;

	ListNode * newNode = makeNode (newRecordNumber, newID, newName, newEmail, newUnits, newProgram, newLevel);

	if (newNode != NULL) // if the node is not empty
	{
		newNode -> setNextPtr (this -> mStartPtr); // set newNode's next pointer to the start pointer of the list
		this -> mStartPtr = newNode; // the start pointer will point to newNode

		success = true;
	}

	return success;
}

///////////////////////////////////////////////////////////////////////
/// makeNode ()
/// \pre    
/// \post   
/// \param
/// \return newNode
/// \throw  
/// \description: dynamically allocates memory for a new node by using keyword new
///////////////////////////////////////////////////////////////////////

ListNode * List::makeNode (int newRecordNumber, int newID, string newName, string newEmail,
						   string newUnits, string newProgram, string newLevel)
{
	ListNode * newNode = new ListNode (newRecordNumber, newID, newName, newEmail,
									   newUnits, newProgram, newLevel);

	return newNode;
}

///////////////////////////////////////////////////////////////////////
/// destroyList ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: deletes all of the nodes in the list
///////////////////////////////////////////////////////////////////////

bool List::destroyList ()
{
	// create temporary pointers of ListNode type
	ListNode *tempPtr = NULL, *deletePtr = NULL;
	
	bool success = false;

	// set the temporary pointer to the beginning of the list pointer
	tempPtr = this -> mStartPtr;

	while (tempPtr != NULL) // while the temp pointer is not null
	{
		deletePtr = tempPtr; // set the temp pointer to the delete pointer
		tempPtr = tempPtr -> getNextPtr (); // set the temp pointer to the next pointer
		delete deletePtr; // delete the delete pointer (the old temp pointer)

		success = true;
	}

	return success;
}