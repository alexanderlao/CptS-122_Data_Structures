/*******************************************************************************
 * Programmer: Alexander Lao                                                   *
 * Class: CptS 122; Lab Section 2                                              *
 * Programming Assignment: GroceryStoreSimulation                              *
 * Date: 9/23/2015                                                             *
 *                                                                             *
 * Description: This program simulates two grocery store lines in order        *
 *				to better understand how to select the fastest line.           *
 *																			   *
 * IMPORTANT NOTES: The majority of these functions were adapted from the      *
 *					queue example we did in class. They have been modified to  *
 *					fit the functionality of this assignment.                  *
 *					Lung-Chi Lin and Kelsey Cairns assisted me on this         *
 *					assignment.                                                *
 ******************************************************************************/

#include "TestGroceryStoreSimulation.h"

void testMakeQueue (void)
{
	QueueNode testQueueNode;
	QueueNode *pMem = NULL;

	// hard code values for the testQueueNode
	testQueueNode.customerNumber = 37;
	testQueueNode.serviceTime = 6;
	testQueueNode.totalTime = 12;

	// make the node with the values we hard coded
	pMem = makeNode (testQueueNode);

	if ((pMem != NULL) && pMem -> customerNumber == 37)
	{
		printf ("Data was successfully allocated!\n");
	}
	else
	{
		printf ("Data was not successfully allocated!\n");
	}

	printQueue (pMem);
}

void testEnqueue (void)
{
	QueueNode testQueueNode;
	QueueNode secondTestQueueNode;
	QueueNode thirdTestQueueNode;
	QueueNode *pMem = NULL;
	Queue testPQ;

	testPQ.pHead = NULL;
	testPQ.pTail = NULL;

	// hard code values for the first queue node
	testQueueNode.customerNumber = 38;
	testQueueNode.serviceTime = 3;
	testQueueNode.totalTime = 9;

	// hard code values for the second queue node
	secondTestQueueNode.customerNumber = 39;
	secondTestQueueNode.serviceTime = 7;
	secondTestQueueNode.totalTime = 12;

	// hard code values for the third queue node
	thirdTestQueueNode.customerNumber = 40;
	thirdTestQueueNode.serviceTime = 10;
	thirdTestQueueNode.totalTime = 15;
	
	// make the node using the first queue node
	pMem = makeNode (testQueueNode);
	
	// add the first queue node to the queue
	enqueue (&testPQ, *pMem);

	// make the next node using the second queue node
	// and point pMem's pNext to the second queue node
	pMem -> pNext = makeNode (secondTestQueueNode);

	// add the second queue node to the queue
	enqueue (&testPQ, *(pMem -> pNext));

	// make the next node using the third queue node
	// and point pMem's pNext pNext to the third queue node
	pMem -> pNext -> pNext = makeNode (thirdTestQueueNode);

	// add the third queue node to the queue
	enqueue (&testPQ, *(pMem -> pNext -> pNext));

	// print out the items in the queue
	printQueue (pMem);
}

void testDequeue (void)
{
	QueueNode testQueueNode;
	QueueNode secondTestQueueNode;
	QueueNode thirdTestQueueNode;
	QueueNode *pMem = NULL;
	Queue testPQ;

	testPQ.pHead = NULL;
	testPQ.pTail = NULL;

	// hard code values for the first queue node
	testQueueNode.customerNumber = 38;
	testQueueNode.serviceTime = 3;
	testQueueNode.totalTime = 9;

	// hard code values for the second queue node
	secondTestQueueNode.customerNumber = 39;
	secondTestQueueNode.serviceTime = 7;
	secondTestQueueNode.totalTime = 12;

	// hard code values for the third queue node
	thirdTestQueueNode.customerNumber = 40;
	thirdTestQueueNode.serviceTime = 10;
	thirdTestQueueNode.totalTime = 15;
	
	// make the node using the first queue node
	pMem = makeNode (testQueueNode);
	
	// add the first queue node to the queue
	enqueue (&testPQ, *pMem);

	// make the next node using the second queue node
	// and point pMem's pNext to the second queue node
	pMem -> pNext = makeNode (secondTestQueueNode);

	// add the second queue node to the queue
	enqueue (&testPQ, *(pMem -> pNext));

	// make the next node using the third queue node
	// and point pMem's pNext pNext to the third queue node
	pMem -> pNext -> pNext = makeNode (thirdTestQueueNode);

	// add the third queue node to the queue
	enqueue (&testPQ, *(pMem -> pNext -> pNext));

	// print out the items in the queue
	printQueue (pMem);

	// dequeue the first person in the queue (customer number #38)
	dequeue (&testPQ);
}