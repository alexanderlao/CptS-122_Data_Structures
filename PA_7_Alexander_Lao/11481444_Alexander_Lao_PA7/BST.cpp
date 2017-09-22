/*******************************************************************************
 * Programmer: Alexander Lao                                                   *
 * Class: CptS 122; Lab Section 2                                              *
 * Programming Assignment: Data Analysis in Binary Search Trees                *
 * Date: 11/20/2015                                                            *
 *                                                                             *
 * Description: This application analyzes trends seen in a binary search tree. *                                               
 ******************************************************************************/

#include "BST.h"

///////////////////////////////////////////////////////////////////////
/// ~BST ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: destructor for a BST; calls the destroyTree function
///////////////////////////////////////////////////////////////////////

// destructor
BST::~BST ()
{
	destroyTree (mpRoot);
}

///////////////////////////////////////////////////////////////////////
/// BST ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: dynamically allocates memory for a BST object
///////////////////////////////////////////////////////////////////////

// default constructor
BST::BST ()
{
	this -> mpRoot = nullptr;
}

///////////////////////////////////////////////////////////////////////
/// getRoot ()
/// \pre    
/// \post   
/// \param
/// \return: Node mpRoot
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

// getter
Node * BST::getRoot ()
{
	return mpRoot;
}

///////////////////////////////////////////////////////////////////////
/// setRoot (Node *newRoot)
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description
///////////////////////////////////////////////////////////////////////

// setter
void BST::setRoot (Node *newRoot)
{
	mpRoot = newRoot;
}

// ---------------- public member functions below ----------------

///////////////////////////////////////////////////////////////////////
/// insert (string newData, int newUnits)
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: public insert function into a BST; used to hide the
/// \root pointer
///////////////////////////////////////////////////////////////////////

void BST::insert (string newData, int newUnits)
{
	// calls the private insert function
	// hides pointer information
	insert (*&mpRoot, newData, newUnits);
}

///////////////////////////////////////////////////////////////////////
/// inOrderTraversal ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: public inOrderTraversal function of a BST; used to hide the
/// \root pointer
///////////////////////////////////////////////////////////////////////

void BST::inOrderTraversal ()
{
	inOrderTraversal ((TransactionNode *&)mpRoot);
}

///////////////////////////////////////////////////////////////////////
/// findSmallest ()
/// \pre    
/// \post   
/// \param
/// \return: a TransactionNode
/// \throw  
/// \description: traverses to the furthest left point of a BST and returns
/// \that node after casting it to a TransactionNode
///////////////////////////////////////////////////////////////////////

TransactionNode & BST::findSmallest ()
{
	Node *pCur = mpRoot;

	while ((pCur -> getLeft ()) != nullptr)
	{
		pCur = pCur -> getLeft ();
	}

	// pCur is originally a node, so we dynamic cast
	return *(dynamic_cast <TransactionNode*>(pCur));
}

///////////////////////////////////////////////////////////////////////
/// findLargest ()
/// \pre    
/// \post   
/// \param
/// \return: a TransactionNode
/// \throw  
/// \description: traverses to the furthest right point of a BST and returns
/// \that node after casting it to a TransactionNode
///////////////////////////////////////////////////////////////////////

TransactionNode & BST::findLargest ()
{
	Node *pCur = mpRoot;

	while ((pCur -> getRight ()) != nullptr)
	{
		pCur = pCur -> getRight ();
	}

	// pCur is originally a node, so we dynamic cast
	return *(dynamic_cast <TransactionNode*>(pCur));
}

// ---------------- private member functions below ----------------

///////////////////////////////////////////////////////////////////////
/// destroyTree (Node *&pTree)
/// \pre    
/// \post   
/// \param
/// \return:
/// \throw  
/// \description: visits each node in a BST and deletes them
///////////////////////////////////////////////////////////////////////

void BST::destroyTree (Node *&pTree)
{
	if (pTree != nullptr)
	{
		destroyTree (pTree -> getLeft ());
		destroyTree (pTree -> getRight ());
		delete pTree;
	}
}

///////////////////////////////////////////////////////////////////////
/// insert (Node *&pTree, string newData, int newUnits)
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: inserts into a BST
///////////////////////////////////////////////////////////////////////

void BST::insert (Node *&pTree, string newData, int newUnits)
{
	// base case
	if (pTree == nullptr)
	{
		pTree = new TransactionNode (newData, newUnits);
	}
	// have to cast pTree in order to have access to the getter
	else if (newUnits < ((TransactionNode*)pTree) -> getUnits ()) // left
	{
		insert ((((TransactionNode*)pTree) -> getLeft ()), newData, newUnits);
	}
	else if (newUnits > ((TransactionNode*)pTree) -> getUnits ()) // right
	{
		insert ((((TransactionNode*)pTree) -> getRight ()), newData, newUnits);
	}
}

///////////////////////////////////////////////////////////////////////
/// inOrderTraversal (TransactionNode *&pTree)
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: traverses a BST in order and prints out the data
///////////////////////////////////////////////////////////////////////

void BST::inOrderTraversal (TransactionNode *&pTree)
{
	if (pTree != nullptr)
	{
		inOrderTraversal ((TransactionNode *&)pTree -> getLeft ());
		pTree -> printData ();
		inOrderTraversal ((TransactionNode *&)pTree -> getRight ());
	}
}