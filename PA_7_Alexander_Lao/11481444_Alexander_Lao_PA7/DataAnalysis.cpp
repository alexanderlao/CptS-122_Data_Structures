/*******************************************************************************
 * Programmer: Alexander Lao                                                   *
 * Class: CptS 122; Lab Section 2                                              *
 * Programming Assignment: Data Analysis in Binary Search Trees                *
 * Date: 11/20/2015                                                            *
 *                                                                             *
 * Description: This application analyzes trends seen in a binary search tree. *                                               
 ******************************************************************************/

#include "DataAnalysis.h"

///////////////////////////////////////////////////////////////////////
/// DataAnalysis ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: does nothing
///////////////////////////////////////////////////////////////////////

// default constructor
DataAnalysis::DataAnalysis ()
{
	// does nothing
}

///////////////////////////////////////////////////////////////////////
/// ~DataAnalysis ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: destructor for a DataAnalysis object; does nothing
///////////////////////////////////////////////////////////////////////

// destructor
DataAnalysis::~DataAnalysis ()
{
	// does nothing
}

///////////////////////////////////////////////////////////////////////
/// openFile ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: opens the csv file
///////////////////////////////////////////////////////////////////////

void DataAnalysis::openFile ()
{
	// open the file
	mCsvStream.open ("data.csv", std::ios::in);
}

///////////////////////////////////////////////////////////////////////
/// splitFile (int &fileUnits, string &fileType, string &fileTransaction)
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: splits the csv file and stores the data in their respective
/// \variables
///////////////////////////////////////////////////////////////////////

void DataAnalysis::splitFile (int &fileUnits, string &fileType, string &fileTransaction)
{
	// create a char array that will store the
	// read in lines
	char field[100];

	// reading in lines and storing them in their respective variables
	mCsvStream.getline (field, 100, ',');
	fileUnits = atoi (field); // converting strings to ints

	mCsvStream.getline (field, 100, ',');
	fileType = field;

	mCsvStream.getline (field, 100, '\n');
	fileTransaction = field;
}

///////////////////////////////////////////////////////////////////////
/// loopFile ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: calls the splitFile () function until the end of the file;
/// \then calls the compare function and the inOrderTraversal () function
///////////////////////////////////////////////////////////////////////

void DataAnalysis::loopFile ()
{
	// accomodating the header of the .csv file
	char record[100];
	mCsvStream.getline (record, 100, '\n'); // reads headers of columns

	while (!mCsvStream.eof ())
	{
		int fileUnits;
		string fileType;
		string fileTransaction;

		splitFile (fileUnits, fileType, fileTransaction);

		// compare the file's attributes and insert them into
		// their respective trees
		compare (fileUnits, fileType, fileTransaction);
	}

	// display the contents of both trees
	cout << "--- Purchased Tree Data ---" << endl;
	mTreePurchased.inOrderTraversal ();

	cout << endl; // blank line for readability

	cout << "--- Sold Tree Data ---" << endl;
	mTreeSold.inOrderTraversal ();

}

///////////////////////////////////////////////////////////////////////
/// compare (int &newUnits, string &newType, string &newTransaction)
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: decides which tree to insert the data into based on the
/// \transaction type
///////////////////////////////////////////////////////////////////////

void DataAnalysis::compare (int &newUnits, string &newType, string &newTransaction)
{
	if (newTransaction == "Purchased")
	{
		mTreePurchased.insert (newType, newUnits);
	}
	else if (newTransaction == "Sold")
	{
		mTreeSold.insert (newType, newUnits);
	}
}

///////////////////////////////////////////////////////////////////////
/// printTrends ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: prints out the least/most purchased and least/most
/// sold items of the purchased tree and sold tree, respectively
///////////////////////////////////////////////////////////////////////

void DataAnalysis::printTrends ()
{
	cout << endl; // blank line for readability

	// print out the data for the purchased tree
	cout << "--- Purchased Tree Data Analysis ---" << endl;
	cout << "Least purchased: " << mTreePurchased.findSmallest ().getData () << ", " 
		 << mTreePurchased.findSmallest ().getUnits () << " units" << endl;

	cout << "Most purchased: " << mTreePurchased.findLargest ().getData () << ", " 
		 << mTreePurchased.findLargest ().getUnits () << " units" << endl;

	cout << endl; // blank line for readability

	// print out the data for the sold tree
	cout << "--- Sold Tree Data Analysis ---" << endl;
	cout << "Least sold: " << mTreeSold.findSmallest ().getData () << ", " 
		 << mTreeSold.findSmallest ().getUnits () << " units" << endl;

	cout << "Most sold: " << mTreeSold.findLargest ().getData () << ", " 
		 << mTreeSold.findLargest ().getUnits () << " units" << endl;

	cout << endl; // blank line for readability
}

///////////////////////////////////////////////////////////////////////
/// runAnalysis ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
/// \description: calls the openFile (), loopFile (), and printTrends () functions
///////////////////////////////////////////////////////////////////////

void DataAnalysis::runAnalysis ()
{
	openFile ();
	loopFile ();
	printTrends ();
}