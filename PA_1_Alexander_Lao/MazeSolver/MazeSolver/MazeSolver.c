/*******************************************************************************
 * Programmer: Alexander Lao                                                   *
 * Class: CptS 122; Lab Section 2                                              *
 * Programming Assignment: MazeSolver PA #1									   *
 * Date: 09/04/15                                                              *
 *                                                                             *
 * Description: This program creates an array that represents a maze and finds *
 *              a solution to the maze if one exists.                          *
 *                                                                             *																			   
 * Note: This program is incomplete.                                           *														               
 ******************************************************************************/

#include "MazeSolver.h"

/*************************************************************
 * Function: maze_creator                                    *
 * Date Created: 09/02/15                                    *
 * Date Last Modified: 09/04/15                              *
 * Description: This function creates an 8 by 8 array that   *
				represents a maze.                           *
 * Input parameters: char maze[8][8]                         *
 * Returns: The char maze array                              *
 * Preconditions: N/A                                        *
 * Postconditions: N/A                                       *
 *************************************************************/

//write the function that creates the maze
void maze_creator (char maze[8][8])
{
	int x;
	int y;

	//loop through each index of the array
	//and randomly place an "X" for a blocked path
	for (x = 0; x < 8; x++)
	{
		for (y = 0; y < 8; y++)
		{
			//do not place an X at the starting postion [0][1]
			if (rand () % 4 == 0 && !maze[0][1])
			{
				maze[x][y] = 'X';
			}
			else
			{
				maze[x][y] = ' ';
			}
		} 
	}
}

/*************************************************************
 * Function: maze_solver                                     *
 * Date Created: 09/02/15                                    *
 * Date Last Modified: 09/04/15                              *
 * Description: This function is supposed to determine if a  *
 *				path in the maze array exists and print out  *
 *				the path.									 *
 * Input parameters: char maze[8][8], int horizontalMove,    * 
 *					 int verticalMove                        *
 * Returns: A possible path to the char maze array           *
 * Preconditions: [0][1] in the array must be open.          *
 * Postconditions: N/A                                       *
 *************************************************************/

//write the function that solves the maze
void maze_solver (char maze[8][8], int horizontalMove, int verticalMove)
{
	//base case: if maze[7][7] is blocked, the maze is unsolvable
	if (maze[7][7] = 'X')
	{
		printf ("There is no path in the maze.");
		return;
	}
	else
	{
		printf ("There is a path in the maze!/n");
		printf ("Calculating possible path.../n");
	}
}
