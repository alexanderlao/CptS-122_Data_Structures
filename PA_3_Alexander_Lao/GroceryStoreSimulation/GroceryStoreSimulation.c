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

#include "GroceryStoreSimulation.h"

/*************************************************************
 * Function: makeNode ()                                     *
 * Date Created: 9/21/2015                                   *
 * Date Last Modified: 9/21/2015                             *
 * Description: This function creates a queue node.          *                                 
 * Input parameters: A QueueNode struct.                     *
 * Returns: A pointer to the QueueNode struct.               *
 * Preconditions: None.                                      *
 * Postconditions: None.                                     *
 *************************************************************/

QueueNode * makeNode (QueueNode newQueueNode)
{
	QueueNode *pMem = NULL;

	// allocate memory for pMem, use sizeof to find
	// the right amount of memory to allocate
	pMem = (QueueNode * ) malloc (sizeof (QueueNode));

	if (pMem != NULL)
	{
		// allocate memory
		pMem -> pNext = NULL;
		pMem -> customerNumber = newQueueNode.customerNumber;
		pMem -> serviceTime = newQueueNode.serviceTime;
		pMem -> totalTime = newQueueNode.totalTime;
	}

	return pMem;
}

/*************************************************************
 * Function: printQueue ()                                   *
 * Date Created: 9/21/2015                                   *
 * Date Last Modified: 9/23/2015                             *
 * Description: This function recursively prints out a       *
 *				QueueNode.                                   *                                 
 * Input parameters: A QueueNode struct.                     *
 * Returns: Nothing.                                         *
 * Preconditions: None.                                      *
 * Postconditions: None.                                     *
 *************************************************************/

void printQueue (QueueNode *pCur)
{
	// printing the queue recursively
	// base case
	if (pCur == NULL)
	{
		printf ("\n");
		return;
	}
	else
	{
		printf ("Customer Number: %d; ", pCur -> customerNumber);
		printf ("Service Time: %d minutes; ", pCur -> serviceTime);
		printf ("Total Time: %d minutes <--\n", pCur -> totalTime);

		// set pCur to the next node and print it out
		printQueue (pCur -> pNext);
	}
}

/*************************************************************
 * Function: isEmpty ()                                      * 
 * Date Created: 9/22/2015                                   *
 * Date Last Modified: 9/23/2015                             *
 * Description: This function determines whether a queue     *
 *				node is empty or not.                        *                                 
 * Input parameters: A QueueNode struct.                     *
 * Returns: A boolean value.                                 *
 * Preconditions: None.                                      *
 * Postconditions: None.                                     *
 *************************************************************/

Boolean isEmpty (QueueNode *pHead)
{
	// if the head is empty, the queue is empty
	if (pHead == NULL)
	{
		printf ("The queue is empty!\n");
		return ((Boolean)(pHead == NULL));
	}
	else
	{
		printf ("The queue is not empty!\n");
		return ((Boolean)(pHead != NULL));
	}
}

/*************************************************************
 * Function: enqueue ()                                      *
 * Date Created: 9/21/2015                                   *
 * Date Last Modified: 9/23/2015                             *
 * Description: This function adds a QueueNode to the end    *
 *				of a Queue or at the front if the Queue is   *
 *				empty.                                       *                                 
 * Input parameters: A Queue and a QueueNode.                *
 * Returns: A boolean value.                                 *
 * Preconditions: None.                                      *
 * Postconditions: None.                                     *
 *************************************************************/

Boolean enqueue (Queue *pQ, QueueNode newQueueNode)
{
	QueueNode *pMem = makeNode (newQueueNode);
	
	Boolean success = FALSE;
	int customerNumber = 0;

	// think state of queue
	// empty or not empty
	if (pMem != NULL)
	{
		if (pQ -> pHead == NULL)
		{
			// queue is empty
			pQ -> pHead = pQ -> pTail = pMem;
		}
		else
		{
			// queue is not empty
			pQ -> pTail -> pNext = pMem;
			pQ -> pTail = pMem;
		}
		success = TRUE;

		// whenever a customer enters the line,
		// increment their customer number
		customerNumber++;

		pMem -> customerNumber = customerNumber;
	}
	return success;
}

/*************************************************************
 * Function: dequeue ()                                      *
 * Date Created: 9/22/2015                                   *
 * Date Last Modified: 9/23/2015                             *
 * Description: This function deletes QueueNodes from the    *
 *				front of the Queue.                          *                                 
 * Input parameters: A Queue.                                *
 * Returns: The customer's number and total time they were   *
 *			in the queue.                                    *
 * Preconditions: The queue is not empty.                    *
 * Postconditions: None.                                     *
 *************************************************************/

int dequeue (Queue *pQ)
{
	QueueNode *pTemp = NULL;
	int pReturnCustomerNumber = 0;
	int pReturnTotalTime = 0;

	// check for the case with just one node
	if ((pQ -> pTail) == (pQ -> pHead))
	{
		pReturnCustomerNumber = pQ -> pHead -> customerNumber;
		pReturnTotalTime = pQ -> pHead -> totalTime;
		free (pQ -> pHead);
		pQ -> pHead = pQ -> pTail = NULL;
	}
	else // more than one node in queue
	{
		pReturnCustomerNumber = pQ -> pHead -> customerNumber;
		pReturnTotalTime = pQ -> pHead -> totalTime;
		pTemp = pQ -> pHead;
		pQ -> pHead = pQ -> pHead -> pNext;
		free (pTemp);
	}

	return pReturnCustomerNumber, pReturnTotalTime;
}

/*************************************************************
 * Function: runSimulation ()                                *
 * Date Created: 9/23/2015                                   *
 * Date Last Modified: 9/23/2015                             *
 * Description: This function runs the simulation by calling *
 *				the other functions.                         *                                 
 * Input parameters: None.                                   *
 * Returns: A dummy integer.                                 *
 * Preconditions: None.                                      *
 * Postconditions: None.                                     *
 *************************************************************/

int runSimulation (void)
{
	int runtime = 0;
	int i = 0;
	int arrivalTime;

	Queue *expressGroceryLine = NULL;
	Queue *normalGroceryLine = NULL;
	QueueNode *customer = NULL;

	// prompt the user for the duration of the simulation
	printf ("How many minutes would you like the run the simulation?\n");
	scanf ("%d", &runtime);

	// run the simulation based on the user's input
	for  (i = 0; i < runtime; i++)
	{
		// every ten minutes...
		if (i % 10 == 0)
		{
			// print out each line
		}

		// generate a random number between 0 - 8
		arrivalTime = rand() % 9;

		// if the arrival time is zero
		while (arrivalTime == 0)
		{
			// re-roll the number
			// we don't want zeros
			arrivalTime = rand() % 9;
		}

		if (arrivalTime <= 3)
		{
			// we are in the express lane!
			//enqueue (expressGroceryLine, *customer);
		}
		else if (arrivalTime >= 4)
		{
			// we are in the normal lane!
			//enqueue (normalGroceryLine, *customer);
		}
	}

	return 0;
}