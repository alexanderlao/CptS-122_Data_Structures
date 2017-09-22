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

/*************************************************************
 * Function: makeRecord ()                                   *
 * Date Created: 9/08/2015                                   *
 * Date Last Modified: 9/09/2015                             *
 * Description: This function creates a record node.         *                                 
 * Input parameters: An record struct.                       *
 * Returns: A pointer to the record struct.                  *
 * Preconditions: None.                                      *
 * Postconditions: None.                                     *
 *************************************************************/

Record * makeRecord (Record newRecord)
{
	Record *pMem = NULL;

	// allocate memory for the record node
	pMem = (Record *) malloc (sizeof (Record));

	// copy the attributes to pMem
	strncpy (pMem -> artist, newRecord.artist, 100);
	strncpy (pMem -> album, newRecord.album, 100);
	strncpy (pMem -> songTitle, newRecord.songTitle, 100);
	strncpy (pMem -> genre, newRecord.genre, 100);
	pMem -> songLength.songLengthMinutes = newRecord.songLength.songLengthMinutes;
	pMem -> songLength.songLengthSeconds = newRecord.songLength.songLengthSeconds;
	pMem -> timesPlayed = newRecord.timesPlayed;
	pMem -> rating = newRecord.rating;

	// set the linked-list pointers to null
	pMem -> pNext = NULL;
	pMem -> pPrev = NULL;
	                      
	return pMem;
}

/*************************************************************
 * Function: loadRecord ()                                   *
 * Date Created: 9/13/2015                                   *
 * Date Last Modified: 9/15/2015                             *
 * Description: This function reads record nodes from a file *
 *			     and places them into the doubly linked-list.*                                 
 * Input parameters: A double pointer to the linked-list and *
 *					 a pointer to the file.                  *
 * Returns: Nothing.                                         *
 * Preconditions: The file exists and the list is not empty. *
 * Postconditions: None.                                     *
 *************************************************************/

Record * loadRecord (Record **pList, FILE *pFile)
{
	struct record newRecord;

	Record *pMem = NULL;

	pFile = fopen ("MySong.txt", "r+");

	while (!feof (pFile))
	{
		// read the attributes from the file and
		// store them in temporary variables
		fgets (newRecord.artist, 100, pFile);
		fgets (newRecord.album, 100, pFile);
		fgets (newRecord.songTitle, 100, pFile);
		fgets (newRecord.genre, 100, pFile);
	
		fscanf (pFile, "%d", &newRecord.songLength.songLengthMinutes);
		fscanf (pFile, "%d", &newRecord.songLength.songLengthSeconds);
		fscanf (pFile, "%d", &newRecord.timesPlayed);
		fscanf (pFile, "%d", &newRecord.rating);

		fgetc (pFile);

		// create a record node using the temporary variables
		pMem = makeRecord (newRecord);

		// place the newly made record into 
		// the front of the linked list
		if (*pList != NULL)
		{
			(*pList) -> pPrev = pMem;
		}
		
		pMem -> pNext = *pList;
		*pList = pMem;

		printf ("Record successfully loaded!");
		printf ("\n");
	}
}

/*************************************************************
 * Function: storeRecord ()                                  *
 * Date Created: 9/15/2015                                   *
 * Date Last Modified: 9/20/2015                             *
 * Description: This function writes records from a linked-  *
 *				list into a file.                            *                                 
 * Input parameters: A double pointer to the linked-list and *
 *					 a pointer to the file.                  *
 * Returns: Nothing.                                         *
 * Preconditions: The list is not empty and the file exists. *
 * Postconditions: None.                                     *
 * NOTE: This function worked in my test function, but it is *
 *	     now not working when I call it from main.           *
 *************************************************************/

Record * storeRecord (Record **pList, FILE *pFile)
{
	struct record newRecord;

	// initialize a temporary record node that stores
	// the fields of the record
	Record *pTemp = NULL;

	pFile = fopen ("MySong.txt", "w+");

	// make the record and store it in pTemp
	pTemp = *pList;

	while (pTemp != NULL)
	{
		// read the attributes from the linked list and
		// store them in the file
		fputs (pTemp -> artist, pFile);
		fputs ("\n", pFile);

		fputs (pTemp -> album, pFile);
		fputs ("\n", pFile);

		fputs (pTemp -> songTitle, pFile);
		fputs ("\n", pFile);

		fputs (pTemp -> genre, pFile);
		fputs ("\n", pFile);
	
		fprintf (pFile, "%d", pTemp -> songLength.songLengthMinutes);
		fputs ("\n", pFile);

		fprintf (pFile, "%d", pTemp -> songLength.songLengthSeconds);
		fputs ("\n", pFile);

		fprintf (pFile, "%d", pTemp -> timesPlayed);
		fputs ("\n", pFile);

		fprintf (pFile, "%d", pTemp -> rating);
		fputs ("\n", pFile);

		// read the next node
		pTemp = pTemp -> pNext;
	}

	free (pTemp);
}

/*************************************************************
 * Function: displayRecord ()                                *
 * Date Created: 9/16/2015                                   *
 * Date Last Modified: 9/16/2015                             *
 * Description: This function recursively prints the         *
 *				contents of the linked-list to the console.  *                                 
 * Input parameters: A pointer to a Record node.             *
 * Returns: Nothing.                                         *
 * Preconditions: None.                                      *
 * Postconditions: None.                                     *
 *************************************************************/

void displayRecord (Record *pCur)
{
	// base case?
	if (pCur == NULL)
	{
		printf ("NULL\n");
		printf ("\n");
	}
	else // recursive step
	{
		printf ("Artist: %s", pCur -> artist);
		printf ("Album: %s", pCur -> album);
		printf ("Song: %s", pCur -> songTitle);
		printf ("Genre: %s", pCur -> genre);
		printf ("Song Length: %d:", pCur -> songLength.songLengthMinutes);
		printf ("%d\n", pCur -> songLength.songLengthSeconds);
		printf ("Times Played: %d\n", pCur -> timesPlayed);
		printf ("Rating: %d\n", pCur -> rating);
		printf ("\n");
		displayRecord (pCur -> pNext);
	}
}

/*************************************************************
 * Function: insertRecord ()                                 *
 * Date Created: 9/18/2015                                   *
 * Date Last Modified: 9/20/2015                             *
 * Description: This function creates a new record node      *
 *				based on user input and inserts it into the  *
 *				linked list.                                 *                                 
 * Input parameters: A double pointer to the linked-list.    *
 * Returns: Nothing.                                         *
 * Preconditions: The list is not empty.                     *
 * Postconditions: None.                                     *
 * NOTE: This function crashes when trying to read in a      *
 *       string.                                             *
 *************************************************************/

Record * insertRecord (Record **pList)
{
	struct record newRecord;

	// initialize a temporary record node that stores
	// the fields of the record
	Record *pTemp = NULL;

	// prompt the user for song attributes
	// and store them in their respective fields
	printf ("Please enter the artist: ");
	scanf ("%s", &pTemp -> artist);
	printf("\n");

	printf ("Please enter the album: ");
	scanf ("%s", &pTemp -> album);
	printf("\n");

	printf ("Please enter the song title: ");
	scanf ("%s", pTemp -> songTitle);
	printf("\n");

	printf ("Please enter the genre: ");
	scanf ("%s", pTemp -> genre);
	printf("\n");

	printf ("Please enter the song length's minutes ");
	printf ("(if a song is 4:65, enter 4): ");
	scanf ("%d", pTemp -> songLength.songLengthMinutes);
	printf("\n");

	printf ("Please enter the song length's seconds ");
	printf ("(if a song is 4:65, enter 65): ");
	scanf ("%d", pTemp -> songLength.songLengthSeconds);
	printf("\n");

	printf ("Please enter the number of times the song has been played: ");
	scanf ("%d", pTemp -> timesPlayed);
	printf("\n");

	printf ("Please enter a rating (1-5): ");
	scanf ("%d", pTemp -> rating);
	printf("\n");

	// store the record node at the front of the list
	// if the list is not empty
	if (*pList != NULL)
	{
		(*pList) -> pPrev = pTemp;
	}
		
	pTemp -> pNext = *pList;
	*pList = pTemp;
}

/*************************************************************
 * Function: deleteRecord ()                                 *
 * Date Created: 9/18/2015                                   *
 * Date Last Modified: 9/20/2015                             *
 * Description: This function deletes a node in the linked   *
                list based on a user-inputted song title.    *                                 
 * Input parameters: A double pointer to the linked-list.    *
 * Returns: Nothing.                                         *
 * Preconditions: The list is not empty.                     *
 * Postconditions: None.                                     *
 * NOTE: This function crashes when trying to read in a      *
 *       string.                                             *
 *************************************************************/

Record * deleteRecord (Record **pList)
{
	Record *pTemp = NULL, *pCur = NULL;

	char * deleteSongTitle[100];

	// prompt the user on which song they would like to delete
	printf ("Please enter the song title of the record you wish to delete: ");
	scanf ("%s", deleteSongTitle);
	printf("\n");

	// set pTemp to the front of the list
	pTemp = *pList;

	while ((pTemp -> pNext) != NULL)
	{
		// check to see if the song title of the current
		// record node matches the one the user wants to delete
		if ((pTemp -> songTitle) == *deleteSongTitle)
		{
			// reassign the pointers
			pTemp -> pNext -> pPrev = pCur -> pPrev;
			pTemp -> pPrev -> pNext = pCur -> pNext;

			free (pTemp);
			break;
		}
		else if ((pTemp -> songTitle) != *deleteSongTitle)
		{
			// traverse to the next node
			pTemp = pTemp -> pNext;
		}
	}
}

/*************************************************************
 * Function: editRecord ()                                   *
 * Date Created: 9/18/2015                                   *
 * Date Last Modified: 9/20/2015                             *
 * Description: This function searches for a record based    *
 *              on any attribute and can then edit any       *
 *				attribute of that record.                    *                                 
 * Input parameters: A double pointer to the linked-list.    *
 * Returns: Nothing.                                         *
 * Preconditions: The list is not empty.                     *
 * Postconditions: None.                                     *
 * NOTE: This function crashes when trying to read in a      *
 *       string.                                             *
 *************************************************************/

Record * editRecord (Record **pList)
{
	Record *pCur = NULL;

	// initialize attribute variables
	char * searchArtist[256];
	char * searchAlbum[256];
	char * searchSongTitle[256];
	char * searchGenre[256];
	int searchSongLengthMinutes = 0;
	int searchSongLengthSeconds = 0;
	int searchTimesPlayed = 0;
	int searchRating = 0;
	int subMenuChoice = 0;

	// print out a sub-menu to prompt the user on how they
    // would like to search
	printf ("Please enter how you would like to search: \n");
	printf ("1. By artist\n");
	printf ("2. By album\n");
	printf ("3. By song title\n");
	printf ("4. By genre\n");
	printf ("5. By song length in minutes\n");
	printf ("6. By song length in seconds\n");
	printf ("7. By times played\n");
	printf ("8. By rating\n");

	// read in the user's choice
	scanf ("%d", &subMenuChoice);

	// perform the appropriate search based on the user's choice
	if (subMenuChoice == 1)
		{
			printf("Please enter an artist: ");
			scanf ("%s", &searchArtist);
			printf("\n");
		}
		else if (subMenuChoice == 2)
		{
			printf("Please enter an album: ");
			scanf ("%s", &searchAlbum);
			printf("\n");
		}
		else if (subMenuChoice == 3)
		{
			printf("Please enter a song title: ");
			scanf ("%s", &searchSongTitle);
			printf("\n");
		}
		else if (subMenuChoice == 4)
		{
			printf("Please enter a genre: ");
			scanf ("%s", &searchGenre);
			printf("\n");
		}
		else if (subMenuChoice == 5)
		{
			printf("Please enter a song length in minutes: ");
			scanf ("%d", &searchSongLengthMinutes);
			printf("\n");
		}
		else if (subMenuChoice == 6)
		{
			printf("Please enter a song length in seconds: ");
			scanf ("%d", &searchSongLengthSeconds);
			printf("\n");
		}
		else if (subMenuChoice == 7)
		{
			printf("Please enter a number of times played: ");
			scanf ("%d", &searchTimesPlayed);
			printf("\n");
		}
		else if (subMenuChoice == 8)
		{
			printf("Please enter a rating: ");
			scanf ("%d", &searchRating);
			printf("\n");
		}
		else
		{
			printf ("Please choose a valid option.\n");
			printf("\n");
		}
}

/*************************************************************
 * Function: sortRecord ()                                   *
 * Date Created: 9/20/2015                                   *
 * Date Last Modified: 9/20/2015                             *
 * Description: This function is supposed to sort the        *
 *				linked-list alphabetically by artist, genre, *
 *				or increasing numeric value by rating.       *                                 
 * Input parameters: A double pointer to the linked-list.    *
 * Returns: Nothing.                                         *
 * Preconditions: The list is not empty.                     *
 * Postconditions: None.                                     *
 * NOTE: This function is incomplete.                        *
 *************************************************************/

Record * sortRecord (Record **pList)
{
	printf ("Sorry, this feature is currently unavailable.\n");
}

/*************************************************************
 * Function: rateRecord ()                                   *
 * Date Created: 9/18/2015                                   *
 * Date Last Modified: 9/20/2015                             *
 * Description: This function searches for a song by song    *
 *				title and allows the user to rate the song.  *                                 
 * Input parameters: A double pointer to the linked-list.    *
 * Returns: Nothing.                                         *
 * Preconditions: The list is not empty.                     *
 * Postconditions: None.                                     *
 * NOTE: This function crashes when trying to read in a      *
 *       string.                                             *
 *************************************************************/

Record * rateRecord (Record **pList)
{
	Record *pCur = NULL;

	char * searchSongTitle[256];
	int newRating = 0;

	printf("Please enter the song you would like to rate: ");
	scanf ("%s", &searchSongTitle);
	printf("\n");

	// set pCur to the front of the list
	pCur = *pList;

	while ((pCur -> pNext) != NULL)
	{
		// check to see if the song title of the current
		// record node matches the one the user wants to rate
		if ((pCur -> songTitle) == *searchSongTitle)
		{
			printf("Please enter a new rating between 1 and 5: ");
			scanf ("%d", newRating);
			printf("\n");

			newRating = pCur -> rating;
			break;
		}
		// if the node doesn't match
		else
		{
			// traverse to the next node
			pCur = pCur -> pNext;
		}
	}
}

/*************************************************************
 * Function: createMenu ()                                   *
 * Date Created: 9/15/2015                                   *
 * Date Last Modified: 9/20/2015                             *
 * Description: This function creates the menu and calls     *
 *              other functions based on a user inputted     *
 *				menu choice.                                 *                                 
 * Input parameters: None.                                   *
 * Returns: Nothing.                                         *
 * Preconditions: None.                                      *
 * Postconditions: None.                                     *
 *************************************************************/

int createMenu (void)
{
	Boolean running = TRUE;
	FILE *pFile = NULL;
	Record *pList = NULL;
	Record *pTemp = NULL;

	int menuChoice;

	while (running)
	{
		// print out the mainn menu
		printf("\nWelcome to the Digital Music Manager!\n");
		printf("Please select an option below. (1 - 9)\n");
		printf("\n");
		printf("1. Load\n");
		printf("2. Store\n");
		printf("3. Display\n");
		printf("4. Insert\n");
		printf("5. Delete\n");
		printf("6. Edit\n");
		printf("7. Sort\n");
		printf("8. Rate\n");
		printf("9. Exit\n");
		printf("\n");

		// prompt the user for a choice and read in that choice
		printf("Your choice: ");
		scanf ("%d", &menuChoice);
		printf("\n");

		// call the appropriate function based on the user's choice
		if (menuChoice == 1)
		{
			loadRecord (&pList, pFile);
		}
		else if (menuChoice == 2)
		{
			storeRecord (&pList, pFile);
		}
		else if (menuChoice == 3)
		{
			displayRecord(pList);
		}
		else if (menuChoice == 4)
		{
			insertRecord (&pTemp);
		}
		else if (menuChoice == 5)
		{
			deleteRecord (&pList);
		}
		else if (menuChoice == 6)
		{
			editRecord (&pList);
		}
		else if (menuChoice == 7)
		{
			sortRecord (&pList);
		}
		else if (menuChoice == 8)
		{
			rateRecord (&pList);
		}
		else if (menuChoice == 9)
		{
			break;
		}
		else
		{
			printf ("Please choose a valid option.\n");
			printf("\n");
		}
	}
}