/*******************************************************************************
 * Programmer: Alexander Lao                                                   *
 * Class: CptS 122; Lab Section 2                                              *
 * Programming Assignment: CaesarShiftCipher PA #1							   *
 * Date: 09/04/15                                                              *
 *                                                                             *
 * Description: This program performs a Caesar shift on a character array.     *												               
 ******************************************************************************/

#ifndef CAESAR_SHIFT_CIPHER_H
#define CAESAR_SHIFT_CIPHER_H

#include <stdio.h> // printf (), scanf ()
#include <stdlib.h> // malloc (), realloc (), free ()
#include <string.h> //strlen ()
#include <ctype.h> //toupper ()

void caesar_shift_cipher (char inputString[], int shift);

#endif