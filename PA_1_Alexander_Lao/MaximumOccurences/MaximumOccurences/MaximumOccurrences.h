/*******************************************************************************
 * Programmer: Alexander Lao                                                   *
 * Class: CptS 122; Lab Section 2                                              *
 * Programming Assignment: Maximum Occurrences PA #1                           *
 * Date: 09/04/15                                                              *
 *                                                                             *
 * Description: This program takes in a string, determines the most frequent   *
 *              character in that string and prints out its frequency.         *
 *																			   *
 * Note: Lung Chi helped me on this assignment. Also, there is a bug that      *
 *       causes the program to crash when trying to convert the string to      *
 *		 lowercase. It has been commented out below.                           *														               
 ******************************************************************************/

#ifndef MAXIMUM_OCCURRENCES_H
#define MAXIMUM_OCCURRENCES_H

#include <stdio.h> // printf (), scanf ()
#include <stdlib.h> // malloc (), realloc (), free ()
#include <string.h> // strlen ()
#include <ctype.h> // tolower ()

//create a structure that holds two variables for the occurrences
typedef struct occurrences
{
	int num_occurrences;
	double frequency;
} Occurrences;

void maximum_occurrences (char *pChar, Occurrences *pOccurrences, 
						  int *pFrequency, char *pFrequentSymbol);

#endif