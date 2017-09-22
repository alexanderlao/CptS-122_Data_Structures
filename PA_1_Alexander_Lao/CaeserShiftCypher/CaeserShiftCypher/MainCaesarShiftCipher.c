/*******************************************************************************
 * Programmer: Alexander Lao                                                   *
 * Class: CptS 122; Lab Section 2                                              *
 * Programming Assignment: CaesarShiftCipher PA #1							   *
 * Date: 09/04/15                                                              *
 *                                                                             *
 * Description: This program performs a Caesar shift on a character array.     *												               
 ******************************************************************************/

#include "CaesarShiftCipher.h"

int main (void)
{
	//input a string to encrypt
	char inputString[] = "teSTsTRING";

	//input a shift value of any integer
	int shift = 40;

	//call the function on the string to encrypt it
	caesar_shift_cipher (inputString, -shift);

	//print out the newly encrypted string
	printf ("\nEncrypted string: %s\n", inputString);

	//take the newly incrypted string and decrypt it
	caesar_shift_cipher (inputString, shift);

	//print out the decrypted string
	printf ("\nDecrypted string: %s\n", inputString);
}
