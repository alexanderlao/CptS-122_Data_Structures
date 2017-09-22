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

#ifndef MAZE_SOLVER_H
#define MAZE_SOLVER_H

#include <stdio.h> // printf (), scanf ()
#include <stdlib.h> // malloc (), realloc (), free ()

void maze_creator (char maze[8][8]);

void maze_solver (char maze[8][8], int horizontalMove, int verticalMove);

#endif
