/*******************************************************************************
 * Programmer: Alexander Lao                                                   *
 * Class: CptS 122; Lab Section 2                                              *
 * Programming Assignment: Data Analysis in Binary Search Trees                *
 * Date: 11/20/2015                                                            *
 *                                                                             *
 * Description: This application analyzes trends seen in a binary search tree. *                                               
 ******************************************************************************/

#include "Node.h"

///////////////////////////////////////////////////////////////////////
/// ~Node ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: virtual destructor for a node; does nothing
///////////////////////////////////////////////////////////////////////

// virtual destructor
Node::~Node ()
{
	// does nothing
}

///////////////////////////////////////////////////////////////////////
/// Node (string newData)
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: dynamically allocates memory for a node
///////////////////////////////////////////////////////////////////////

// parameterized constructor
Node::Node (string newData)
{
	this -> mData = newData;
	this -> mpLeft = nullptr;
	this -> mpRight = nullptr;
}

///////////////////////////////////////////////////////////////////////
/// getData ()
/// \pre    
/// \post   
/// \param
/// \return: string mData
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

// getters
string Node::getData ()
{
	return mData;
}

///////////////////////////////////////////////////////////////////////
/// getLeft ()
/// \pre    
/// \post   
/// \param
/// \return: Node mpLeft
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

Node *& Node::getLeft ()
{
	return mpLeft;
}

///////////////////////////////////////////////////////////////////////
/// getRight ()
/// \pre    
/// \post   
/// \param
/// \return: Node mpRight
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

Node *& Node::getRight ()
{
	return mpRight;
}

///////////////////////////////////////////////////////////////////////
/// setData (string newData)
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

// setters
void Node::setData (string newData)
{
	mData = newData;
}

///////////////////////////////////////////////////////////////////////
/// setLeftPtr (Node *newLeftPtr)
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

void Node::setLeftPtr (Node *newLeftPtr)
{
	mpLeft = newLeftPtr;
}

///////////////////////////////////////////////////////////////////////
/// setRightPtr (Node *newRightPtr)
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

void Node::setRightPtr (Node *newRightPtr)
{
	mpRight = newRightPtr;
}