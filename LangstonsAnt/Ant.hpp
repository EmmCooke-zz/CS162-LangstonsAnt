/*************************************************
* Author: Emmet Cooke
* Date: 10/5/2017
* Description: This is Ant header file. Most of the functions here
* have in-line definitions, but the constructor, printGameBoard(),
* and runAnt() can be found in Ant.cpp.
*************************************************/
#ifndef ANT_HPP
#define ANT_HPP

#include "Board.hpp"
// Used for the direction of the ant
enum direction {up, right, down, left};

class Ant :
	public Board
{
private:
	direction currentDirection = up;
	int steps;
	int startingRow;
	int startingColumn;
	
public:
	Ant(int columnsIn, int rowsIn, int startingColumnIn,
		int startingRowIn, int numSteps);
	~Ant();

	void printGameBoard() override;	// overridden from the Board class
	void runAnt();

	// Getters
	direction getDirection() const { return currentDirection; }
	int getSteps() const { return steps; }
	
	// Setters
	void setStartingRow(int startingRowIn)
	{ startingRow = startingRowIn; }
	void setStartingColumn(int startingColumnIn)
	{ startingColumn = startingColumnIn; }
	void setDirection(direction directionIn)
	{ currentDirection = directionIn; }
};

#endif
