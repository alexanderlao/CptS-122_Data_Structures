#include "TestDigitalMusicManager.h"

//void testMakeRecord (void)
//{
//	Record *pMem = NULL;
//
//	struct record newRecord;
//
//	strcpy(newRecord.artist, "Katy Perry");
//	strcpy(newRecord.album, "Prism");
//	strcpy(newRecord.songTitle, "Birthday");
//	strcpy(newRecord.genre, "Disco");
//	newRecord.songLength.songLengthMinutes = 3;
//	newRecord.songLength.songLengthSeconds = 35;
//	newRecord.timesPlayed = 42;
//	newRecord.rating = 5;
//
//	pMem = makeRecord (newRecord);
//
//	if (pMem != NULL)
//	{
//		printf ("Data was successfully allocated!\n");
//	}
//	else
//	{
//		printf ("Data was not successfully allocated!\n");
//	}
//
//	displayRecord (pMem);
//}

void testLoadRecord (void)
{
	FILE *pFile = NULL;
	Record *pList = NULL;

	pFile = fopen ("MySong.txt", "r");

	if (pFile == NULL)
	{
		printf ("File cannot be opened!\n");
	}
	else
	{
		loadRecord (&pList, pFile);
		displayRecord(pList);
	}
}

//void testStoreRecord (void)
//{
//	FILE *pFile = NULL;
//	Record *pList = NULL;
//
//	pFile = fopen ("MySong.txt", "w+");
//
//	storeRecord (&pList, pFile);
//	displayRecord(pList);
//}

//void testInsertRecord (void)
//{
//	struct record newRecord;
//
//	Record *pTemp = NULL;
//	Record *pList = NULL;
//
//	insertRecord (&pTemp);
//
//	displayRecord(pList);
//}