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

#ifndef EXERCISE_PLAN_H
#define EXERCISE_PLAN_H

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class ExercisePlan
{
	private:
		int mGoalSteps;
		int mTotalSteps;
		string mPlanName;
		string mDate;

	public:
		// paramterized constructor with default values
		ExercisePlan (int newGoalSteps = 0, int newTotalSteps = 0,
					  string newPlanName = "", string newDate = "");

		// copy constructor - invoked by passing-by-value
		ExercisePlan (ExercisePlan &copy); // pass-by-value

		// destructor - implicitly invoked when an object goes out of scope
		~ExercisePlan ();

		// initialize the create function
		void create ();

		// initialize the edit function
		void edit (ExercisePlan userExercisePlan);

		// initialize the update function
		void update (ExercisePlan userExercisePlan);

		// initialize the delete function
		void deleteExercisePlan (ExercisePlan userExercisePlan);

		// initialize the print function
		void printExercisePlan ();

		// getters/accessors - access private data members
		int getGoalSteps ();
		int getTotalSteps ();
		string getPlanName ();
		string getDate ();

		// setters/mutators - modify private data members
		void setGoalSteps (int newGoalSteps);
		void setTotalSteps (int newTotalSteps);
		void setPlanName (string newPlanName);
		void setDate (string newDate);
};

#endif