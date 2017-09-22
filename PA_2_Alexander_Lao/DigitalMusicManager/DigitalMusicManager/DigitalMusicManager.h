/*******************************************************************************
 * Programmer: Alexander Lao                                                   *
 * Class: CptS 122; Lab Section 2                                              *
 * Programming Assignment: Digital Music Manager                               *
 * Date: 9/20/2015                                                             *
 *                                                                             *
 * Description: This program serves as a digital music manager in the form of  *
 *      		a doubly linked-list. It can perform several different         *
 *				functions on nodes in which nodes represent song records.      *
 *                                                                             *                    
 *                                                                             *
 * Format of record in input file (MySong.txt): Katy Perry (artist, str)       *
 *												Prism      (album, str)        *
 *									            Birthday   (song title, str)   *
 *									            Disco      (genre, str)        *
 *												3     (songLengthMinutes, int) *
 *												35    (songLengthSeconds, int) *
 *												324   (timesPlayed, int)       *
 *												5	  (rating, int)            *
 *                                                                             *                                         
 * Format of output file (MySong.txt): Same as input file.                     *
 *																			   *
 * NOTE: Lung-Chi Lin, Kelsey Cairns, and Andrew O'Fallon helped me on this    *
 *       assignment.                                                           *
 ******************************************************************************/

#ifndef DIGITAL_MUSIC_MANAGER_H
#define DIGITAL_MUSIC_MANAGER_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> // printf (), scanf ()
#include <stdlib.h> // malloc (), realloc (), free ()
#include <string.h> // strcpy ()

typedef enum boolean
{
	FALSE, TRUE
} Boolean;

typedef struct length
{
	int songLengthSeconds;
	int songLengthMinutes;
} Length;

typedef struct record
{
	char artist[100];
	char album[100];
	char songTitle[100];
	char genre[100];
	struct length songLength;
	int timesPlayed;
	int rating;

	// self-referential struct
	struct record *pPrev;
	struct record *pNext;
} Record;

Record * makeRecord (Record newRecord);
Record * loadRecord (Record **pList, FILE *pFile);
Record * storeRecord (Record **pList, FILE *pFile);
Record * insertRecord (Record **pList);
Record * deleteRecord (Record **pList);
Record * editRecord (Record **pList);
Record * sortRecord (Record **pList);
Record * rateRecord (Record **pList);

void displayRecord (Record *pCur);
int createMenu (void);

#endif