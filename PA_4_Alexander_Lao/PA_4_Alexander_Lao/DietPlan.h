/*******************************************************************************
 * Programmer: Alexander Lao                                                   *
 * Class: CptS 122; Lab Section 2                                              *
 * Programming Assignment: Basic Fitness Application                           *
 * Date: 10/09/2015                                                            *
 *                                                                             *
 * Description: This application stores basic diet and fitness plans.          * 
 *                                                                             *
 * Note: This program was heavily adapted from Andrew S. O'Fallon's            *
 *		 BankApplication program.                                              *
 ******************************************************************************/

#ifndef DIET_PLAN_H
#define DIET_PLAN_H

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class DietPlan
{
	private:
		int mGoalCalories;
		int mTotalCalories;
		string mPlanName;
		string mDate;

	public:
		// parameterized constructor with default values
		DietPlan (int newGoalCalories = 0, int newTotalCalories = 0,
				  string newPlanName = "", string newDate = "");

		// copy contructor (match name of class, same type of class we're defining)
		// invoked when passing-by-value
		DietPlan (DietPlan &copy); // passing-by-reference

		// destructor - implicitly invoked when an object
		// goes out of scope
		~DietPlan ();

		// initialize the create function
		void create ();

		// initialize the edit function
		void edit (DietPlan userDietPlan);

		// initialize the update function
		void update (DietPlan userDietPlan);

		// initialize the delete function
		void deleteDietPlan (DietPlan userDietPlan);

		// initialize the print function
		void printDietPlan ();

		// getters/accessors - access private data members
		int getGoalCalories ();
		int getTotalCalories ();
		string getPlanName ();
		string getDate ();

		// setters/mutators - modify private data members
		void setGoalCalories (int newGoalCalories);
		void setTotalCalories (int newTotalCalories);
		void setPlanName (string newPlanName);
		void setDate (string newDate);
};

#endif