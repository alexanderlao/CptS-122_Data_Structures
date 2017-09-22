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

#ifndef FITNESS_APP_WRAPPER_H
#define FITNESS_APP_WRAPPER_H

#include <iostream>
#include <string>

#include "DietPlan.h"
#include "ExercisePlan.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class FitnessAppWrapper
{
	private:
		int mNumberDietPlans;
		int mNumberExercisePlans;

		DietPlan dietPlans[7];
		ExercisePlan exercisePlans[7];

	public:
		// default constructor
		FitnessAppWrapper ();

		// copy constructor
		FitnessAppWrapper (FitnessAppWrapper &copy);

		// destructor
		~FitnessAppWrapper ();

		// getters
		int getNumberDietPlans ();
		int getNumberExercisePlans ();

		// setters
		void setNumberDietPlans (int newNumberDietPlans);
		void setNumberExercisePlans (int newNumberExercisePlans);

		int mainMenuChoice ();
		int subMenu ();
		void mainMenu ();
		void addPlan ();
		int searchPlanName (); 
		void deletePlan ();
		void modifyPlan ();
		void displayPlan ();
};

#endif