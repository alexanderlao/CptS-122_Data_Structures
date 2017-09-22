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

/*************************************************************
 * Function: maximum_occurrences ()                          *
 * Date Created: 09/01/15                                    *
 * Date Last Modified: 09/04/15                              *
 * Description: This program takes in a string, determines   *
 *				the most frequent character in that string   *
 *				and prints out its frequency.                *
 * Input parameters: char *pChar, struct Occurrences (int    *
 *					 num_occurrences, double frequency),     *
 *					 int *pFrequency and char                *
 *					 *pFrequentSymbol                        * 
 * Returns: int *pFrequency and char *pFrequentSymbol        *
 *************************************************************/

//create a function that determines the most frequent symbol in a character
//and determine how many times that symbol appears
void maximum_occurrences (char *pChar, Occurrences *pOccurrences, 
						  int *pFrequency, char *pFrequentSymbol)
{
	//defining integer i
	int i;

	//defining char c
	char c;
	
	//the symbol being analyzed is given a number
	//that corresponds to that symbol
	int symbolToNumber = 0;

	int numberOfFrequentCharacter = -1;
	int frequentCharacter = -1;

	//loop through each character in the string
	//and convert it to lowercase
	//****PROBLEM HERE****
	/*for (i = 0; i < (int)strlen(pChar); i++)
	{
		c = pChar[i];
		c = tolower(c);
		pChar[i] = c;
	}*/

	//loop through each character in the string
	//and determine which symbol appears the most
	for (i = 0; i < (int)strlen(pChar); i++)
	{
		//cast the index of the string to an integer
		symbolToNumber = (int)pChar[i];

		//increment the occurrence of that index
		pOccurrences[symbolToNumber].num_occurrences++;

		//find the frequency of that occurrence by dividing the
		//number of one character symbol by the total number of characters 
		pOccurrences[symbolToNumber].frequency = *pFrequency / strlen(pChar);
	}

	//loop through each index of the array that
	//covers all 256 ASCII characters to determine
	//the most frequent character and the number of times
	//that character appears
	for (i = 0; i < 256; i++)
	{
		if (numberOfFrequentCharacter < pOccurrences[i].num_occurrences)
		{
			numberOfFrequentCharacter = pOccurrences[i].num_occurrences;
			frequentCharacter = i;
		}
	}

	//set the frequent character and the number of times it
	//appears to the argument of the function
	*pFrequency = numberOfFrequentCharacter;
	*pFrequentSymbol = (char)frequentCharacter;
}
