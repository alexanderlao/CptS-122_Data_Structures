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

#include "FitnessAppWrapper.h"

///////////////////////////////////////////////////////////////////////
/// FitnessAppWrapper ()
/// \pre    
/// \post   
/// \param
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

// write the default constructor
FitnessAppWrapper::FitnessAppWrapper ()
{
	mNumberDietPlans = 0;
	mNumberExercisePlans = 0;
}

///////////////////////////////////////////////////////////////////////
/// FitnessAppWrapper (FitnessAppWrapper &)
/// \pre    
/// \post   
/// \param  (FitnessAppWrapper &copy)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

// write the copy constructor
FitnessAppWrapper::FitnessAppWrapper (FitnessAppWrapper &copy)
{
	mNumberDietPlans = copy.mNumberDietPlans;
	mNumberExercisePlans = copy.mNumberExercisePlans;
}

///////////////////////////////////////////////////////////////////////
/// ~FitnessAppWrapper ()
/// \pre    
/// \post   
/// \param  
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

// write the destructor
FitnessAppWrapper::~FitnessAppWrapper ()
{
	/*cout << "We are in the FitnessAppWrapper destructor!" << endl;
	cout << endl;*/
}

///////////////////////////////////////////////////////////////////////
/// getNumberDietPlans ()
/// \pre    
/// \post   
/// \param
/// \return int mNumberDietPlans
/// \throw  
///////////////////////////////////////////////////////////////////////

// getters
int FitnessAppWrapper::getNumberDietPlans ()
{
	return mNumberDietPlans;
}

///////////////////////////////////////////////////////////////////////
/// getNumberExercisePlans ()
/// \pre    
/// \post   
/// \param
/// \return int mNumberExercisePlans
/// \throw  
///////////////////////////////////////////////////////////////////////

int FitnessAppWrapper::getNumberExercisePlans ()
{
	return mNumberExercisePlans;
}

///////////////////////////////////////////////////////////////////////
/// setNumberDietPlans ()
/// \pre    
/// \post   
/// \param (int newNumberDietPlans)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

// setters
void FitnessAppWrapper::setNumberDietPlans (int newNumberDietPlans)
{
	mNumberDietPlans = newNumberDietPlans;
}

///////////////////////////////////////////////////////////////////////
/// setNumberExercisePlans ()
/// \pre    
/// \post   
/// \param (int newNumberExercisePlans)
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

void FitnessAppWrapper::setNumberExercisePlans (int newNumberExercisePlans)
{
	mNumberExercisePlans = newNumberExercisePlans;
}

///////////////////////////////////////////////////////////////////////
/// mainMenuChoice ()
/// \pre    
/// \post   
/// \param 
/// \return int mainMenuChoice
/// \throw  
///////////////////////////////////////////////////////////////////////

int FitnessAppWrapper::mainMenuChoice ()
{
	int mainMenuChoice;

	cout << "Welcome to the Fitness Plan Application!" << endl;
	cout << "1. Add a plan" << endl;
	cout << "2. Delete a plan" << endl;
	cout << "3. Modify a plan" << endl;
	cout << "4. Display a plan" << endl;
	cout << "5. Exit" << endl;
	cout << "Please choose an option: ";

	cin >> mainMenuChoice;
	cout << endl;

	return mainMenuChoice;
}

///////////////////////////////////////////////////////////////////////
/// subMenu ()
/// \pre    
/// \post   
/// \param 
/// \return int subMenuChoice
/// \throw  
///////////////////////////////////////////////////////////////////////

int FitnessAppWrapper::subMenu ()
{
	int subMenuChoice;

	cout << "Choose a type of plan:" << endl;
	cout << "1. Diet plan" << endl;
	cout << "2. Exercise plan" << endl;
	cout << "Please choose an option: ";
	cin >> subMenuChoice;
	cout << endl;

	return subMenuChoice;
}

///////////////////////////////////////////////////////////////////////
/// mainMenu ()
/// \pre    
/// \post   
/// \param 
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

void FitnessAppWrapper::mainMenu ()
{
	// initialize variables
	int mainChoice;
	bool running = true;
	
	while (running)
	{
		mainChoice = mainMenuChoice ();

		// adding a plan
		if (mainChoice == 1)
		{
			addPlan ();
		}
		// delete a plan
		else if (mainChoice == 2)
		{
			deletePlan ();
		}
		// modify a plan
		else if (mainChoice == 3)
		{
			modifyPlan ();
		}
		// display a plan
		else if (mainChoice == 4)
		{
			displayPlan ();
		}
		// exit
		else if (mainChoice == 5)
		{
			break;
		}
		else
		{
			cout << "Please enter a valid option." << endl;
			cout << endl;
		}
	}
}

///////////////////////////////////////////////////////////////////////
/// addPlan ()
/// \pre    
/// \post   
/// \param 
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

void FitnessAppWrapper::addPlan ()
{
	int subChoice;
	subChoice = subMenu ();

	// diet plan
	if (subChoice == 1)
	{
		// initialize variables
		int userGoalCalories;
		int userTotalCalories;
		char userPlanName[100];
		string userDate;

		// prompt the user to enter values for the DietPlan
		cout << "Please enter a plan name: ";
		cin.clear ();
		cin.sync ();
		cin.getline(userPlanName, sizeof(userPlanName));

		cout << "Please enter today's date (MM/DD/YYYY): ";
		cin.clear ();
		cin.sync ();
		cin >> userDate;

		cout << "Please enter your goal number of calories: ";
		cin >> userGoalCalories;

		cout << "Please enter the number of calories you've eaten today: ";
		cin >> userTotalCalories;
		cout << endl;

		DietPlan newDietPlan (userGoalCalories, userTotalCalories,
							  userPlanName, userDate);

		int counter = 0;

		while (counter < mNumberDietPlans)
		{
			// search for an available spot in the array
			counter ++;
		}

		// if there's no space in the array...
		if (mNumberDietPlans < counter)
		{
			cout << "WARNING: Could not create diet plan!" << endl;
			cout << endl;
		}
		else
		{
			dietPlans[counter].setPlanName (newDietPlan.getPlanName ());
			dietPlans[counter].setDate (newDietPlan.getDate ());
			dietPlans[counter].setGoalCalories (newDietPlan.getGoalCalories ());
			dietPlans[counter].setTotalCalories (newDietPlan.getTotalCalories ());

			cout << "Diet plan added successfully!" << endl;
			cout << endl;

			mNumberDietPlans++;
		}
	}
	// exercise plan
	else if (subChoice == 2)
	{
		// initialize variables
		int userGoalSteps;
		int userTotalSteps;
		char userPlanName[100];
		string userDate;

		// prompt the user to enter values for the Exercise Plan
		cout << "Please enter a plan name: ";
		cin.clear ();
		cin.sync ();
		cin.getline(userPlanName, sizeof(userPlanName));

		cout << "Please enter today's date (MM/DD/YYYY): ";
		cin.clear ();
		cin.sync ();
		cin >> userDate;

		cout << "Please enter your goal number of steps: ";
		cin >> userGoalSteps;

		cout << "Please enter the number of steps you've taken today: ";
		cin >> userTotalSteps;
		cout << endl;

		ExercisePlan newExercisePlan (userGoalSteps, userTotalSteps,
									  userPlanName, userDate);

		int counter = 0;

		while (counter < mNumberExercisePlans)
		{
			// search for an available spot in the array
			counter ++;
		}

		// if there's no space in the array...
		if (mNumberExercisePlans < counter)
		{
			cout << "WARNING: Could not create exercise plan!" << endl;
			cout << endl;
		}
		else
		{
			exercisePlans[counter].setPlanName (newExercisePlan.getPlanName ());
			exercisePlans[counter].setDate (newExercisePlan.getDate ());
			exercisePlans[counter].setGoalSteps (newExercisePlan.getGoalSteps ());
			exercisePlans[counter].setTotalSteps (newExercisePlan.getTotalSteps ());

			cout << "Exercise plan added successfully!" << endl;
			cout << endl;

			mNumberExercisePlans++;
		}
	}
}

///////////////////////////////////////////////////////////////////////
/// searchPlanName ()
/// \pre    
/// \post   
/// \param 
/// \return int index
/// \throw  
///////////////////////////////////////////////////////////////////////

int FitnessAppWrapper::searchPlanName ()
{
	char searchPlanName[100];

	cout << "Please enter a plan name to search for (CASE SENSITIVE): ";
	cin.clear ();
	cin.sync ();
	cin.getline(searchPlanName, sizeof(searchPlanName));
	cout << endl;

	int index;
	
	// search through the diet plans
	for (index = 0; ((index < mNumberDietPlans) && (dietPlans[index].getPlanName () != searchPlanName)); index++)
	{
		// the header of the for loop contains all the neccessary logic
	}

	// search through the exercise plans
	for (index = 0; ((index < mNumberExercisePlans) && (exercisePlans[index].getPlanName () != searchPlanName)); index++)
	{
		// the header of the for loop contains all the neccessary logic
	}

	return index;
}

///////////////////////////////////////////////////////////////////////
/// deletePlan ()
/// \pre    
/// \post   
/// \param 
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

void FitnessAppWrapper::deletePlan ()
{
	int subChoice;
	subChoice = subMenu ();

	// diet plan
	if (subChoice == 1)
	{
		int counter = 0;
		counter = searchPlanName ();

		// "delete" the diet plan by setting 
		// its attributes to zero or the empty string
		dietPlans[counter].setPlanName ("");
		dietPlans[counter].setDate ("");
		dietPlans[counter].setGoalCalories (0);
		dietPlans[counter].setTotalCalories (0);

		cout << "Diet plan deleted!" << endl;
		cout << endl;

		mNumberDietPlans--;
	}
	// exercise plan
	else if (subChoice == 2)
	{
		int counter = 0;
		counter = searchPlanName ();

		// "delete" the exercise plan by setting 
		// its attributes to zero or the empty string
		exercisePlans[counter].setPlanName ("");
		exercisePlans[counter].setDate ("");
		exercisePlans[counter].setGoalSteps (0);
		exercisePlans[counter].setTotalSteps (0);

		cout << "Exercise plan deleted!" << endl;
		cout << endl;

		mNumberExercisePlans--;
	}
}

///////////////////////////////////////////////////////////////////////
/// modifyPlan ()
/// \pre    
/// \post   
/// \param 
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

void FitnessAppWrapper::modifyPlan ()
{
	int subChoice;
	subChoice = subMenu ();

	// diet plan
	if (subChoice == 1)
	{
		int subSubMenuChoice;

		cout << "What would you like to modify?" << endl;
		cout << "1. Edit an attribute of a diet plan" << endl;
		cout << "2. Update a plan's total calories" << endl;
		cout << "Please choose an option: ";
	
		cin >> subSubMenuChoice;
		cout << endl;

		int counter = 0;

		if (subSubMenuChoice == 1)
		{
			counter = searchPlanName ();
			
			// initializing local variables
			int userChoice;
			char newPlanName[100];
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
				cin.clear ();
				cin.sync ();
				cin.getline(newPlanName, sizeof(newPlanName));
				cout << endl;

				// set the new plan name
				dietPlans[counter].setPlanName (newPlanName);
				cout << "Plan name updated!" << endl;
				cout << endl;
			}
			else if (userChoice == 2)
			{
				// prompt the user to enter a new calorie goal
				cout << "Please enter a new calorie goal: ";
				cin >> newGoalCalories;
				cout << endl;

				// set the new calorie goal
				dietPlans[counter].setGoalCalories (newGoalCalories);
				cout << "Calorie goal updated" << endl;
				cout << endl;
			}
			else if (userChoice == 3)
			{
				// prompt the user to enter a new total number of calories
				cout << "Please enter a new total number of calories: ";
				cin >> newTotalCalories;
				cout << endl;

				// set the new total number of calories
				dietPlans[counter].setTotalCalories (newTotalCalories);
				cout << "Total calories updated!" << endl;
				cout << endl;
			}
			else if (userChoice == 4)
			{
				// prompt the user to enter a new created date
				cout << "Please enter a new created date (MM/DD/YYYY): ";
				cin >> newDate;
				cout << endl;

				// set the new created date
				dietPlans[counter].setDate (newDate);
				cout << "Date created updated!" << endl;
				cout << endl;
			}
			else
			{
				cout << "Please enter a valid option." << endl;
				cout << endl;
			}
		}
		else if (subSubMenuChoice == 2)
		{
			counter = searchPlanName ();
			
			// initializing local variables
			int userCalories;
			int currentTotalCalories;

			// prompt the user to ask how many calories they ate
			cout << "How many calories did you eat?" << endl;
			cin >> userCalories;
			cout << endl;

			// store the current total calories in currentTotalCalories
			currentTotalCalories = dietPlans[counter].getTotalCalories ();

			// add the user's calories to the currentTotalCalories
			currentTotalCalories += userCalories;

			// set the total calories to the new currentTotalCalories
			dietPlans[counter].setTotalCalories (currentTotalCalories);

			// print out an update message
			cout << "Total calories updated!" << endl;
			cout << endl;
		}
	}
	else if (subChoice == 2)
	{
		int subSubMenuChoice;

		cout << "What would you like to modify?" << endl;
		cout << "1. Edit an attribute of an exercise plan" << endl;
		cout << "2. Update a plan's total steps" << endl;
		cout << "Please choose an option: ";
	
		cin >> subSubMenuChoice;
		cout << endl;

		int counter = 0;

		if (subSubMenuChoice == 1)
		{
			counter = searchPlanName ();
			
			// initializing local variables
			int userChoice;
			char newPlanName[100];
			int newGoalSteps;
			int newTotalSteps;
			string newDate;

			// prompt the user to choose which field they want to edit
			cout << "What would you like to edit?" << endl;
			cout << "1. Plan name" << endl;
			cout << "2. Goal steps" << endl;
			cout << "3. Total steps" << endl;
			cout << "4. Date created" << endl;
			cout << "Please choose an option: ";

			cin >> userChoice;

			if (userChoice == 1)
			{
				// prompt the user for a new plan name
				cout << "Please enter a new plan name: ";
				cin.clear ();
				cin.sync ();
				cin.getline(newPlanName, sizeof(newPlanName));

				// set the new plan name
				exercisePlans[counter].setPlanName (newPlanName);
				cout << "Plan name updated!" << endl;
				cout << endl;
			}
			else if (userChoice == 2)
			{
				// prompt the user to enter a new step goal
				cout << "Please enter a new step goal: ";
				cin >> newGoalSteps;

				// set the new step goal
				exercisePlans[counter].setGoalSteps (newGoalSteps);
				cout << "Step goal updated!" << endl;
				cout << endl;
			}
			else if (userChoice == 3)
			{
				// prompt the user to enter a new total number of steps
				cout << "Please enter a new total number of steps: ";
				cin >> newTotalSteps;

				// set the new total number of steps
				exercisePlans[counter].setTotalSteps (newTotalSteps);
				cout << "Total steps updated!" << endl;
				cout << endl;
			}
			else if (userChoice == 4)
			{
				// prompt the user to enter a new created date
				cout << "Please enter a new created date (MM/DD/YYYY): ";
				cin >> newDate;

				// set the new created date
				exercisePlans[counter].setDate (newDate);
				cout << "Date created!" << endl;
				cout << endl;
			}
			else
			{
				cout << "Please enter a valid option." << endl;
			}
		}
		else if (subSubMenuChoice == 2)
		{
			counter = searchPlanName ();
			
			// initializing local variables
			int userSteps;
			int currentTotalSteps;

			// prompt the user to ask how many steps they traveled
			cout << "How many steps did you travel?" << endl;
			cin >> userSteps;
			cout << endl;

			// store the current total steps in currentTotalSteps
			currentTotalSteps = exercisePlans[counter].getTotalSteps ();

			// add the user's steps to the currentTotalSteps
			currentTotalSteps += userSteps;

			// set the total steps to the new currentTotalSteps
			exercisePlans[counter].setTotalSteps (currentTotalSteps);

			// print out an update message
			cout << "Total steps updated!" << endl;
			cout << endl;
		}
	}
}

///////////////////////////////////////////////////////////////////////
/// displayPlan ()
/// \pre    
/// \post   
/// \param 
/// \return
/// \throw  
///////////////////////////////////////////////////////////////////////

void FitnessAppWrapper::displayPlan ()
{
	int subChoice;
	subChoice = subMenu ();

	// diet plan
	if (subChoice == 1)
	{
		char searchPlanName[100];

		cout << "Please enter a plan name to search for (CASE SENSITIVE): ";
		cin.clear ();
		cin.sync ();
		cin.getline(searchPlanName, sizeof(searchPlanName));
		cout << endl;

		int index;
	
		// search through the diet plans
		for (index = 0; ((index < mNumberDietPlans) && (dietPlans[index].getPlanName () != searchPlanName)); index++)
		{
			// the header of the for loop contains all the neccessary logic
		}

		if (index <= mNumberDietPlans) // we found the account
		{
			dietPlans[index].printDietPlan ();
		}
		else
		{
			cout << "WARNING: Diet plan does not exist!" << endl;
			cout << endl;
		}
	}
	// exercise plan
	else if (subChoice == 2)
	{
		char searchPlanName[100];

		cout << "Please enter a plan name to search for (CASE SENSITIVE): ";
		cin.clear ();
		cin.sync ();
		cin.getline(searchPlanName, sizeof(searchPlanName));
		cout << endl;

		int index;
	
		// search through the exercise plans
		for (index = 0; ((index < mNumberExercisePlans) && (exercisePlans[index].getPlanName () != searchPlanName)); index++)
		{
			// the header of the for loop contains all the neccessary logic
		}

		if (index <= mNumberExercisePlans) // we found the account
		{
			exercisePlans[index].printExercisePlan ();
		}
		else
		{
			cout << "WARNING: Exercise plan does not exist!" << endl;
			cout << endl;
		}
	}
}