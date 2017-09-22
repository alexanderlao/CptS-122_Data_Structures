/*******************************************************************************
 * Programmer: Alexander Lao                                                   *
 * Class: CptS 122; Lab Section 2                                              *
 * Programming Assignment: Data Analysis in Binary Search Trees                *
 * Date: 11/20/2015                                                            *
 *                                                                             *
 * Description: This application analyzes trends seen in a binary search tree. *                                               
 ******************************************************************************/

#ifndef DATA_ANALYSIS_H
#define DATA_ANALYSIS_H

#include <iostream>
#include <string>
#include <fstream>

#include "BST.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;

class DataAnalysis
{
	public:
		// default constructor
		DataAnalysis ();

		// destructor
		~DataAnalysis ();

		void runAnalysis ();

	private:
		BST mTreeSold;
		BST mTreePurchased;
		ifstream mCsvStream;

		void openFile ();
		void splitFile (int &fileUnits, string &fileType, string &fileTransaction);
		void loopFile ();
		void compare (int &newUnits, string &newType, string &newTransaction);
		void printTrends ();
};

#endif