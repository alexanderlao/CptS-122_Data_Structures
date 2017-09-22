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

#include "DietPlan.h"

///////////////////////////////////////////////////////////////////////
/// DietPlan ()
/// \pre    
/// \post   
/// \param  (newGoalCaloires, newTotalCalories, newPlanName, newDate)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

// parameterized constructor function for the DietPlan class
DietPlan::DietPlan (int newGoalCalories, int newTotalCalories,
					string newPlanName, string newDate)
{
	this -> mGoalCalories = newGoalCalories;
	this -> mTotalCalories = newTotalCalories;
	this -> mPlanName = newPlanName;
	this -> mDate = newDate;
}

///////////////////////////////////////////////////////////////////////
/// DietPlan (DietPlan &)
/// \pre    
/// \post   
/// \param  (DietPlan &copy)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

// copy contructor function for the DietPlan class
DietPlan::DietPlan (DietPlan &copy)
{
	mGoalCalories = copy.mGoalCalories;
	mTotalCalories = copy.mTotalCalories;
	mPlanName = copy.mPlanName;
	mDate = copy.mDate;
}

///////////////////////////////////////////////////////////////////////
/// ~DietPlan ()
/// \pre    
/// \post   
/// \param  
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

// destructor function for the DietPlan class
DietPlan::~DietPlan ()
{
	// do something
	/*cout << "We are in the DietPlan destructor!" << endl;
	cout << endl;*/
}

///////////////////////////////////////////////////////////////////////
/// create ()
/// \pre    
/// \post   
/// \param  
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

// write the create () function for the DietPlan class
void DietPlan::create ()
{
	// initialize variables
	int userGoalCalories;
	int userTotalCalories;
	string userPlanName;
	string userDate;

	// prompt the user to enter values for the DietPlan
	cout << "Please enter a plan name: ";
	cin.clear ();
	cin.sync ();
	cin >> userPlanName;

	cout << "Please enter today's date (MM/DD/YYYY): ";
	cin.clear ();
	cin.sync ();
	cin >> userDate;

	cout << "Please enter your goal number of calories: ";
	cin >> userGoalCalories;

	cout << "Please enter the number of calories you've eaten today: ";
	cin >> userTotalCalories;

	cout << endl;

	DietPlan * newDietPlan = new DietPlan (userGoalCalories, userTotalCalories, userPlanName, userDate);
}

///////////////////////////////////////////////////////////////////////
/// edit ()
/// \pre    
/// \post   
/// \param  (DietPlan userDietPlan)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

// write the edit () function for the DietPlan class
void DietPlan::edit (DietPlan userDietPlan)
{
	// initializing local variables
	int userChoice;
	string newPlanName;
	int newGoalCalories;
	int newTotalCalories;
	string newDate;

	// prompt the user to choose which field they want to edit
	cout << "What would you like to edit?" << endl;
	cout << "1. Plan name" << endl;
	cout << "2. Goal calories" << endl;
	cout << "3. Total calories" << endl;
	cout << "4. Date created" << endl;
	cout << "Please choose an option: ";

	cin >> userChoice;

	if (userChoice == 1)
	{
		// prompt the user for a new plan name
		cout << "Please enter a new plan name: ";
		cin >> newPlanName;

		// set the new plan name
		userDietPlan.setPlanName (newPlanName);
	}
	else if (userChoice == 2)
	{
		// prompt the user to enter a new calorie goal
		cout << "Please enter a new calorie goal: ";
		cin >> newGoalCalories;

		// set the new calorie goal
		userDietPlan.setGoalCalories (newGoalCalories);
	}
	else if (userChoice == 3)
	{
		// prompt the user to enter a new total number of calories
		cout << "Please enter a new total number of calories: ";
		cin >> newTotalCalories;

		// set the new total number of calories
		userDietPlan.setTotalCalories (newTotalCalories);
	}
	else if (userChoice == 4)
	{
		// prompt the user to enter a new created date
		cout << "Please enter a new created date (MM/DD/YYYY): ";
		cin >> newDate;

		// set the new created date
		userDietPlan.setDate (newDate);
	}
	else
	{
		cout << "Please enter a valid option." << endl;
		cout << endl;
	}
}

///////////////////////////////////////////////////////////////////////
/// update ()
/// \pre    
/// \post   
/// \param  (DietPlan userDietPlan)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

// write the update function for the DietPlan class
void DietPlan::update (DietPlan userDietPlan)
{
	// initializing local variables
	int userCalories;
	int currentTotalCalories;

	// prompt the user to ask how many calories they ate
	cout << "How many calories did you eat?" << endl;
	cin >> userCalories;

	// store the current total calories in currentTotalCalories
	currentTotalCalories = userDietPlan.getTotalCalories ();

	// add the user's calories to the currentTotalCalories
	currentTotalCalories += userCalories;

	// set the total calories to the new currentTotalCalories
	userDietPlan.setTotalCalories (currentTotalCalories);

	// print out an update message
	cout << "Total calories updated!" << endl;
	cout << endl;
}

///////////////////////////////////////////////////////////////////////
/// deleteDietPlan ()
/// \pre    
/// \post   
/// \param  (DietPlan userDietPlan)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

// write the delete function for the DietPlan class
void DietPlan::deleteDietPlan (DietPlan userDietPlan)
{
	delete (&userDietPlan);
}

///////////////////////////////////////////////////////////////////////
/// printDietPlan ()
/// \pre    
/// \post   
/// \param 
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

// write the print function for the DietPlan class
void DietPlan::printDietPlan ()
{
	cout << "Plan name: " << mPlanName << endl;
	cout << "Date created: " << mDate << endl;
	cout << "Goal calories: " << mGoalCalories << endl;
	cout << "Total calories: " << mTotalCalories << endl;
	cout << endl;
}

///////////////////////////////////////////////////////////////////////
/// getGoalCalories ()
/// \pre    
/// \post   
/// \param
/// \return int mGoalCalories
/// \throw  
///////////////////////////////////////////////////////////////////////

// getter functions for the DietPlan class
int DietPlan::getGoalCalories ()
{
	return mGoalCalories;
}

///////////////////////////////////////////////////////////////////////
/// getTotalCalories ()
/// \pre    
/// \post   
/// \param
/// \return mTotalCalories
/// \throw  
///////////////////////////////////////////////////////////////////////

int DietPlan::getTotalCalories ()
{
	return mTotalCalories;
}

///////////////////////////////////////////////////////////////////////
/// getPlanName ()
/// \pre    
/// \post   
/// \param
/// \return string mPlanName
/// \throw  
///////////////////////////////////////////////////////////////////////

string DietPlan::getPlanName ()
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

string DietPlan::getDate ()
{
	return mDate;
}

///////////////////////////////////////////////////////////////////////
/// setGoalCalories ()
/// \pre    
/// \post   
/// \param (int newGoalCalories)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

// setter functions for the DietPlan class
void DietPlan::setGoalCalories (int newGoalCalories)
{
	mGoalCalories = newGoalCalories;
}

///////////////////////////////////////////////////////////////////////
/// setTotalCalories ()
/// \pre    
/// \post   
/// \param (int newTotalCalories)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

void DietPlan::setTotalCalories (int newTotalCalories)
{
	mTotalCalories = newTotalCalories;
}

///////////////////////////////////////////////////////////////////////
/// setPlanName ()
/// \pre    
/// \post   
/// \param (string newPlanName)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

void DietPlan::setPlanName (string newPlanName)
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

void DietPlan::setDate (string newDate)
{
	mDate = newDate;
}