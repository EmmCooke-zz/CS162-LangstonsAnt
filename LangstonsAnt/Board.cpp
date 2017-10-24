/*************************************************
* Author: Emmet Cooke
* Date: 10/5/2017
* Description: This file has the definitions for the Board class.
* The board class includes a array of pointers to Squares, which
* these functions deal with.
*************************************************/
#include "Board.hpp"
#include <iostream>

/*************************************************
* Description: Constructor for the Board class. Uses the input values
* to generate the width of the board and then uses two for loops to
* create new Squares within them.
*************************************************/
Board::Board(int columnsIn, int rowsIn)
{
	setColumns(columnsIn);
	setRows(rowsIn);

	gameBoard = new Square*[getRows()];

	for (int i = 0; i < getRows(); i++)
	{
		gameBoard[i] = new Square[getColumns()];
	}
}

/*************************************************
* Description: Destructor for the Board class. This function goes through
* the board and frees the memory allocated in the constructor.
*************************************************/
Board::~Board()
{
	for (int i = 0; i < getRows(); i++)
	{
		delete[] gameBoard[i];
	}
	delete[] gameBoard;
}
