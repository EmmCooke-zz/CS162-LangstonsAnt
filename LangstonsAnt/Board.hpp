/*************************************************
* Author: Emmet Cooke
* Date: 10/5/2017
* Description: This is the board class header file. Most functions have
* in-definitions, save for the constructor and destructor.
*************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP
#include "Square.hpp"

#include <string>
using std::string;

class Board
{
private:
	Square** gameBoard;
	int columns;
	int rows;

public:
	Board(int columnsIn, int rowsIn);
	~Board();

	Square** getGameBoard() const { return gameBoard; }

	int getColumns() const { return columns; }
	int getRows() const { return rows; }

	void setColumns(int columnsIn) { columns = columnsIn; }
	void setRows(int rowsIn) { rows = rowsIn; }

	virtual void printGameBoard() = 0;	// Must be overridden by the child class
};

#endif

