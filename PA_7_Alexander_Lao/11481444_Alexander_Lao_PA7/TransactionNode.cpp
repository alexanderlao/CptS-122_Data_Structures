/*******************************************************************************
 * Programmer: Alexander Lao                                                   *
 * Class: CptS 122; Lab Section 2                                              *
 * Programming Assignment: Data Analysis in Binary Search Trees                *
 * Date: 11/20/2015                                                            *
 *                                                                             *
 * Description: This application analyzes trends seen in a binary search tree. *                                               
 ******************************************************************************/

#include "TransactionNode.h"

///////////////////////////////////////////////////////////////////////
/// ~TransactionNode ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: destructor for a TransactionNode; does nothing
///////////////////////////////////////////////////////////////////////

// destructor
TransactionNode::~TransactionNode ()
{
	// does nothing
}

///////////////////////////////////////////////////////////////////////
/// TransactionNode (string newData, int newUnits) : Node (newData)
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: dynamically allocates memory for a TransactionNode;
/// \publicly inherits from Node's constructor
///////////////////////////////////////////////////////////////////////

// constructor
TransactionNode::TransactionNode (string newData, int newUnits) : Node (newData)
{
	this -> mUnits = newUnits;
}

///////////////////////////////////////////////////////////////////////
/// getUnits ()
/// \pre    
/// \post   
/// \param
/// \return: int mUnits
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

// getter
int TransactionNode::getUnits ()
{
	return mUnits;
}

///////////////////////////////////////////////////////////////////////
/// setUnits (int newUnits)
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

// setter
void TransactionNode::setUnits (int newUnits)
{
	mUnits = newUnits;
}

///////////////////////////////////////////////////////////////////////
/// printData ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: prints out a TransactionNode's mData and mUnits to the console;
/// \overrides the pure virtual function found in Node
///////////////////////////////////////////////////////////////////////

// overrides the pure virtual function in Node
void TransactionNode::printData ()
{
	cout << "Type: " << mData << ", ";
	cout << "Units: " << mUnits << endl;
}