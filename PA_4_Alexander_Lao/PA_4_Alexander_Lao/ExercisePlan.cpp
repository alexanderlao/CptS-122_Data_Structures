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

#include "ExercisePlan.h"

///////////////////////////////////////////////////////////////////////
/// ExercisePlan ()
/// \pre    
/// \post   
/// \param  (newGoalSteps, newTotalSteps, newPlanName, newDate)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

// parameterized constructor for the ExercisePlan class
ExercisePlan::ExercisePlan (int newGoalSteps, int newTotalSteps,
							string newPlanName, string newDate)
{
	this -> mGoalSteps = newGoalSteps;
	this -> mTotalSteps = newTotalSteps;
	this -> mPlanName = newPlanName;
	this -> mDate = newDate;
}

///////////////////////////////////////////////////////////////////////
/// ExercisePlan (ExercisePlan &)
/// \pre    
/// \post   
/// \param  (ExercisePlan &copy)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

// copy constructor for the ExercisePlan class
ExercisePlan::ExercisePlan (ExercisePlan &copy)
{
	mGoalSteps = copy.mGoalSteps;
	mTotalSteps = copy.mTotalSteps;
	mPlanName = copy.mPlanName;
	mDate = copy.mDate;
}

///////////////////////////////////////////////////////////////////////
/// ~ExercisePlan ()
/// \pre    
/// \post   
/// \param  
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

// destructor for the ExercisePlan class
ExercisePlan::~ExercisePlan ()
{
	// do something
	/*cout << "We are in the ExercisePlan destructor!" << endl;
	cout << endl;*/
}

///////////////////////////////////////////////////////////////////////
/// create()
/// \pre    
/// \post   
/// \param  
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

// write the create function for the ExercisePlan class
void ExercisePlan::create ()
{
	// initialize variables
	int userGoalSteps;
	int userTotalSteps;
	string userPlanName;
	string userDate;

	// prompt the user to enter values for the Exercise Plan
	cout << "Please enter a plan name: ";
	cin.clear ();
	cin.sync ();
	cin >> userPlanName;

	cout << "Please enter today's date (MM/DD/YYYY): ";
	cin.clear ();
	cin.sync ();
	cin >> userDate;

	cout << "Please enter your goal number of steps: ";
	cin >> userGoalSteps;

	cout << "Please enter the number of steps you've taken today: ";
	cin >> userTotalSteps;

	cout << endl;
}

///////////////////////////////////////////////////////////////////////
/// edit ()
/// \pre    
/// \post   
/// \param  (ExercisePlan userExercisePlan)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

// write the edit function for the ExercisePlan class
void ExercisePlan::edit (ExercisePlan userExercisePlan)
{
	// initializing local variables
	int userChoice;
	string newPlanName;
	int newGoalSteps;
	int newTotalSteps;
	string newDate;

	// prompt the user to choose which field they want to edit
	cout << "What would you like to edit?" << endl;
	cout << "1. Plan name" << endl;
	cout << "2. Goal steps" << endl;
	cout << "3. Total steps" << endl;
	cout << "4. Date created" << endl;
	cout << "Enter an option (1 - 4): " << endl;

	cin >> userChoice;

	if (userChoice == 1)
	{
		// prompt the user for a new plan name
		cout << "Please enter a new plan name: " << endl;
		cin >> newPlanName;

		// set the new plan name
		userExercisePlan.setPlanName (newPlanName);
	}
	else if (userChoice == 2)
	{
		// prompt the user to enter a new step goal
		cout << "Please enter a new calorie goal: " << endl;
		cin >> newGoalSteps;

		// set the new step goal
		userExercisePlan.setGoalSteps (newGoalSteps);
	}
	else if (userChoice == 3)
	{
		// prompt the user to enter a new total number of steps
		cout << "Please enter a new total number of calories: " << endl;
		cin >> newTotalSteps;

		// set the new total number of steps
		userExercisePlan.setTotalSteps (newTotalSteps);
	}
	else if (userChoice == 4)
	{
		// prompt the user to enter a new created date
		cout << "Please enter a new created date (MM/DD/YYYY): " << endl;
		cin >> newDate;

		// set the new created date
		userExercisePlan.setDate (newDate);
	}
	else
	{
		cout << "Please enter a valid option." << endl;
	}
}

///////////////////////////////////////////////////////////////////////
/// update ()
/// \pre    
/// \post   
/// \param  (ExercisePlan userExercisePlan)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

// write the update function for the ExercisePlan class
void ExercisePlan::update (ExercisePlan userExercisePlan)
{
	// initializing local variables
	int userSteps;
	int currentTotalSteps;

	// prompt the user to ask how many steps they traveled
	cout << "How many steps did you travel?" << endl;
	cin >> userSteps;

	// store the current total steps in currentTotalSteps
	currentTotalSteps = userExercisePlan.getTotalSteps ();

	// add the user's steps to the currentTotalSteps
	currentTotalSteps += userSteps;

	// set the total steps to the new currentTotalSteps
	userExercisePlan.setTotalSteps (currentTotalSteps);

	// print out an update message
	cout << "Total steps updated!" << endl;
	cout << endl;
}

///////////////////////////////////////////////////////////////////////
/// deleteExercisePlan ()
/// \pre    
/// \post   
/// \param  (ExercisePlan userExercisePlan)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

void ExercisePlan::deleteExercisePlan (ExercisePlan userExercisePlan)
{
	delete (&userExercisePlan);
}

///////////////////////////////////////////////////////////////////////
/// printExercisePlan ()
/// \pre    
/// \post   
/// \param 
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

void ExercisePlan::printExercisePlan ()
{
	cout << "Plan name: " << mPlanName << endl;
	cout << "Date created: " << mDate << endl;
	cout << "Goal steps: " << mGoalSteps << endl;
	cout << "Total steps: " << mTotalSteps << endl;
	cout << endl;
}

///////////////////////////////////////////////////////////////////////
/// getGoalSteps ()
/// \pre    
/// \post   
/// \param
/// \return int mGoalSteps
/// \throw  
///////////////////////////////////////////////////////////////////////

// getter functions for the ExercisePlan class
int ExercisePlan::getGoalSteps ()
{
	return mGoalSteps;
}

///////////////////////////////////////////////////////////////////////
/// getTotalSteps ()
/// \pre    
/// \post   
/// \param
/// \return int mTotalSteps
/// \throw  
///////////////////////////////////////////////////////////////////////

int ExercisePlan::getTotalSteps ()
{
	return mTotalSteps;
}

///////////////////////////////////////////////////////////////////////
/// getPlanName ()
/// \pre    
/// \post   
/// \param
/// \return string mPlanName
/// \throw  
///////////////////////////////////////////////////////////////////////

string ExercisePlan::getPlanName ()
{
	return mPlanName;
}

///////////////////////////////////////////////////////////////////////
/// getDate ()
/// \pre    
/// \post   
/// \param
/// \return string mDate
/// \throw  
///////////////////////////////////////////////////////////////////////

string ExercisePlan::getDate ()
{
	return mDate;
}

///////////////////////////////////////////////////////////////////////
/// setGoalSteps ()
/// \pre    
/// \post   
/// \param (int newGoalSteps)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

// setter functions for the ExercisePlan class
void ExercisePlan::setGoalSteps (int newGoalSteps)
{
	mGoalSteps = newGoalSteps;
}

///////////////////////////////////////////////////////////////////////
/// setTotalSteps ()
/// \pre    
/// \post   
/// \param (int newTotalSteps)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

void ExercisePlan::setTotalSteps (int newTotalSteps)
{
	mTotalSteps = newTotalSteps;
}

///////////////////////////////////////////////////////////////////////
/// setPlanName ()
/// \pre    
/// \post   
/// \param (string newPlanName)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

void ExercisePlan::setPlanName (string newPlanName)
{
	mPlanName = newPlanName;
}

///////////////////////////////////////////////////////////////////////
/// setDate ()
/// \pre    
/// \post   
/// \param (string newDate)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

void ExercisePlan::setDate (string newDate)
{
	mDate = newDate;
}