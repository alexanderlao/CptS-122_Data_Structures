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

#ifndef GROCERY_STORE_SIMULATION_H
#define GROCERY_STORE_SIMULATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queueNode
{
	int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
	int serviceTime;   // Random time; varies between express and normal lanes; units in minutes
	int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes
 
	struct queueNode *pNext;
} QueueNode;

typedef struct queue
{
	// encapsulate the pointers necessary for a queue
	QueueNode *pHead;
	QueueNode *pTail;
} Queue;

typedef enum boolean
{
	FALSE, TRUE
} Boolean;

QueueNode * makeNode (QueueNode newQueueNode);
void printQueue (QueueNode *pCur);
Boolean isEmpty (QueueNode *pHead);
Boolean enqueue (Queue *pQ, QueueNode newQueueNode);
// precondition: queue is not empty!
int dequeue (Queue *pQ);
int runSimulation (void);

#endif