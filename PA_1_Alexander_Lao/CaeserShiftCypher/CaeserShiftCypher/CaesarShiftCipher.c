/*******************************************************************************
 * Programmer: Alexander Lao                                                   *
 * Class: CptS 122; Lab Section 2                                              *
 * Programming Assignment: CaesarShiftCipher PA #1							   *
 * Date: 09/04/15                                                              *
 *                                                                             *
 * Description: This program performs a Caesar shift on a character array.     *												               
 ******************************************************************************/

#include "CaesarShiftCipher.h"

/*************************************************************
 * Function: caesar_shift_cipher                             *
 * Date Created: 09/03/15                                    *
 * Date Last Modified: 09/04/15                              *
 * Description: This function performs a Caesar shift on a   *
 *				character array to encrypt it. It can also   *
 *              decrypt a string as long as the shifting     *
 *				integer is known.                            *
 * Input parameters: char inputString[], int shift           *
 * Returns: An encrypted or decrypted form of inputString.   *
 * Preconditions: N/A                                        *
 * Postconditions: N/A                                       *
 *************************************************************/

void caesar_shift_cipher (char inputString[], int shift)
{
	int i = 0;
	int count = 0;
	char c;

	printf ("Original string: ");

	//convert the inputString to all uppercase by
	//looping through each character in the array
	for (i = 0; i < strlen(inputString); i++)
	{
		c = inputString[i];
		c = toupper(c);
		putchar(c);
		inputString[i] = c;
	}

	//loop through each character and perform the Caesar shift
	for (count = 0; count < (int)strlen(inputString);
		 count++)
	{
		//if the shift is greater than 26
		//or less than -26
		if (shift > 26 || shift < -26)
		{
			//find the modulus of the shift
			//in order to keep it within
			//the range of 0 - 26
			shift = shift % 26;
		}

		//apply the shift
		inputString[count] += shift;
		
		//if the shift goes beyond the letter Z
		//subtract the 26 letters in the alphabet
		//to bring it back to letter A
		if (inputString[count] > 'Z')
			inputString[count] -= 26;

		//if the shift goes before the letter A
		//add the 26 letters in the alphabet
		//to bring it back to letter Z
		else if (inputString[count] < 'A')
				 inputString[count] += 26;
	}
}