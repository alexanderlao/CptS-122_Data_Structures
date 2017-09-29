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

#ifndef TEST_GROCERY_STORE_SIMULATION_H
#define TEST_GROCERY_STORE_SIMULATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "GroceryStoreSimulation.h"

void testMakeQueue (void);
void testEnqueue (void);
void testDequeue (void);

#endif