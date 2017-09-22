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

#include "DigitalMusicManager.h"
#include "TestDigitalMusicManager.h"

int main (void)
{
	//testMakeRecord ();
	testLoadRecord ();
	//testStoreRecord ();
	//testInsertRecord ();

	createMenu ();
}
