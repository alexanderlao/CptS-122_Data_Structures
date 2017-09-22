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

#include "MaximumOccurrences.h"

int main (void)
{
	//set initial values to test the
	//maximum_occurrences function
	char *pChar = "teSt string";
	Occurrences pOccurrences[256] = {{0, 0}};
	int pFrequency;
	char pFrequentSymbol;

	maximum_occurrences(pChar, pOccurrences, &pFrequency, &pFrequentSymbol);

	printf ("The most frequent character is %c and it appears %d times!\n", pFrequentSymbol, pFrequency);

	return 0;
}