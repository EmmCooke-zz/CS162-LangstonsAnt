/*************************************************
* Author: Emmet Cooke
* Date: 10/5/2017
* Description: This file has the definitions for the ant class.
* Ant extends the Board class and implements the printGameBoard()
* function from that class.
*************************************************/
#include "Ant.hpp"
#include <iostream>
using std::cout;
using std::endl;

/*************************************************
* Description: Constructor for the Ant class. Takes in five int values for
* the size of the matrix, position of the ant, and number of steps.
* columnsIn and rowsIn are passed to the Board constructor.
*************************************************/
Ant::Ant(int columnsIn, int rowsIn, int startingColumnIn,
	int startingRowIn, int numSteps)
	: Board(columnsIn, rowsIn)
{
	startingColumn = startingColumnIn;
	startingRow = startingRowIn;
	steps = numSteps;
}

/*************************************************
* Description: Ant destructor.
*************************************************/
Ant::~Ant()
{
}

/*************************************************
* Description: Runs the Langston's Ant simulation. Uses multiple pointers
* to keep track of which square the ant has been in, is currently in, and
* will be in by the next step. A while loop serves as the counter while
* currentStep is increased to match the number of steps. When the ant 
* reaches a side of the board, it continues through to the other side.
*************************************************/
void Ant::runAnt()
{
	Square **gameBoard = getGameBoard();
	int currentColumn = startingColumn,
		currentRow = startingRow,
		lastColumn,
		lastRow,
		currentStep = 0;
	
	// For keeping track of the squares around the ant
	Square * lastSquare = gameBoard[currentRow];
	Square * currentSquare = gameBoard[currentRow];
	Square * nextSquare = gameBoard[currentRow];

	// For keeping track of what color those squares are
	Square::color currentColor;
	Square::color nextColor;

	while (currentStep <= getSteps())
	{	// So that lastSquare can hold the previous Square
		lastColumn = currentColumn;
		lastRow = currentRow;		
		lastSquare = gameBoard[lastRow];

		// Places the ant in its correct position
		currentSquare = nextSquare;
		currentColor = lastSquare[lastColumn].getColor();
		currentSquare[currentColumn].setColor(Square::ant);

		// Prints the game board with the ant in the correct spot
		printGameBoard();
		cout << endl;

		// returns the color to the current square
		currentSquare[currentColumn].setColor(currentColor);

		if (getDirection() == up)
		{	// Jumps to the bottom of the board
			if (currentRow == 0)
			{
				nextSquare = gameBoard[getRows() - 1];
				currentRow = getRows() - 1;
			}
			else
			{
				nextSquare = gameBoard[currentRow - 1];
				currentRow--;
			}
			// Checks the next squares color so that
			// the correct direction is set
			nextColor = nextSquare[currentColumn].getColor();

			if (nextColor == Square::white)
			{
				setDirection(right);
			}
			else
			{
				setDirection(left);
			}

			// The previous squares color is changed
			lastSquare[lastColumn].setColor(
				static_cast<Square::color>((currentColor + 1) % 2));
		}

		else if (getDirection() == down)
		{	// Jumps to the top of the board
			if (currentRow == getRows() - 1)
			{
				nextSquare = gameBoard[0];
				currentRow = 0;
			}
			else
			{
				nextSquare = gameBoard[currentRow + 1];
				currentRow++;
			}
			// Checks the next squares color so that
			// the correct direction is set
			nextColor = nextSquare[currentColumn].getColor();

			if (nextColor == Square::white)
			{
				setDirection(left);
			}
			else
			{
				setDirection(right);
			}
			// The previous squares color is changed
			lastSquare[lastColumn].setColor(
				static_cast<Square::color>((currentColor + 1) % 2));
		}

		else if (getDirection() == right)
		{	// Jumps to the left side of the board
			if (currentColumn == getColumns() - 1)
			{
				currentColumn = 0;
			}
			else
			{
				currentColumn++;
			}
			// Checks the next squares color so that
			// the correct direction is set
			nextColor = nextSquare[currentColumn].getColor();

			if (nextColor == Square::white)
			{
				setDirection(down);
			}
			else
			{
				setDirection(up);
			}
			// The previous squares color is changed
			lastSquare[lastColumn].setColor(
				static_cast<Square::color>((currentColor + 1) % 2));
		}

		else if (getDirection() == left)
		{	// Jumps to the right side of the board
			if (currentColumn == 0)
			{
				currentColumn = getColumns() - 1;
			}
			else
			{
				currentColumn--;
			}
			// Checks the next squares color so that
			// the correct direction is set
			nextColor = nextSquare[currentColumn].getColor();

			if (nextColor == Square::white)
			{
				setDirection(up);
			}
			else
			{
				setDirection(down);
			}
			//The previous squares color is changed
			lastSquare[lastColumn].setColor(
				static_cast<Square::color>((currentColor + 1) % 2));
		}
		currentStep++;
	}

}

/*************************************************
* Description: This function prints the game board. It uses two loops to
* go through the board and prints a black space if the square is white,
* a '#' if the square is black, and an '*' if the ant is on the space.
*************************************************/
void Ant::printGameBoard()
{
	Square** gameBoard = getGameBoard();

	for (int i = 0; i < getRows(); i++)
	{
		for (int j = 0; j < getColumns(); j++)
		{
			if (gameBoard[i][j].getColor() == Square::white)
			{
				cout << " ";
			}
			else if (gameBoard[i][j].getColor() == Square::black)
			{
				cout << "#";
			}
			else if (gameBoard[i][j].getColor() == Square::ant)
			{
				cout << "*";
			}
		}
		cout << endl;
	}
}
