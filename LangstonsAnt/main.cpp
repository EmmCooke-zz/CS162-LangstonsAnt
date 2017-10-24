/*************************************************
 * Program Name: Langston's Ant
 * Author: Emmet Cooke
 * Date: 10/5/2017
 * Description: This program runs Langston's Ant. Initially the user
 * is prompted whether they wish to run the program, then they are
 * asked if they would like the ant to start from a random location.
 * If so, the starting position is randomized and the board width,
 * height, and number of steps are prompted from the user.
 *************************************************/
#include <iostream>
#include "Menu.hpp"
#include "validateInput.hpp"
#include "Ant.hpp"
using std::cout;
using std::cin;
using std::endl;

#include <ctime>

int main()
{
	cout << "EC: This program does the extra credit by asking if the user "
		<< "would like to start in a random position." << endl << endl;
	// Menu options
	Menu antMenu(2);
	string validMenuChoice;
	antMenu.setOption(0, "Start Langston's Ant Simulation");
	antMenu.setOption(1, "Quit");
	antMenu.printOptions();

	// Checks if the menu choice is valid
	getline(cin, validMenuChoice);
	while (!checkStringToInt(validMenuChoice))
	{
		cout << "Please choose a valid option." << endl;
		getline(cin, validMenuChoice);
	}
	int menuChoice = stoi(validMenuChoice);

	if(menuChoice == 1)
	{
		string randomChoice, validInput;
		int numRows, numColumns, numSteps, startingPosRow, startingPosColumn;
		// For the random locations
		srand(static_cast<unsigned int>(time(0)));

		// Ask if they want a random starting position
		cout << "Would you like the ant to start in a random position (y/n)? ";
		getline(cin, randomChoice);

		if (randomChoice == "y")
		{	// Run random ant
			// Check if rows is valid and enters it
			do
			{
				cout << "Please enter a valid number for row: ";
				getline(cin, validInput);
				while (!checkStringToInt(validInput))
				{
					cout << "Please enter a valid number for row: ";
					getline(cin, validInput);
				}
				numRows = stoi(validInput);
			} while (numRows <= 0);

			// Check if columns is valid and enter it
			do
			{
				cout << "Please enter a valid number for column: ";
				getline(cin, validInput);
				while (!checkStringToInt(validInput))
				{
					cout << "Please enter a valid number for column: ";
					getline(cin, validInput);
				}
				numColumns = stoi(validInput);
			} while (numColumns <= 0);

			// Check if steps is valid and enter it
			do
			{
				cout << "Please enter a valid number for steps: ";
				getline(cin, validInput);
				while (!checkStringToInt(validInput))
				{
					cout << "Please enter a valid number for steps: ";
					getline(cin, validInput);
				}
				numSteps = stoi(validInput);
			} while (numSteps <= -1);
			
			// Random position
			startingPosRow = rand() % numRows;
			startingPosColumn = rand() % numColumns;

			Ant randomAnt(numColumns, numRows, startingPosColumn,
				startingPosRow, numSteps);
			randomAnt.runAnt();
			
		}
		else
		{	// Run normal ant
			// Check if rows is valid and enters it
			do
			{
				cout << "Please enter a valid number for row: ";
				getline(cin, validInput);
				while (!checkStringToInt(validInput))
				{
					cout << "Please enter a valid number for row: ";
					getline(cin, validInput);
				}
				numRows = stoi(validInput);
			} while (numRows <= 0);

			// Check if columns is valid and enter it
			do
			{
				cout << "Please enter a valid number for column: ";
				getline(cin, validInput);
				while (!checkStringToInt(validInput))
				{
					cout << "Please enter a valid number for column: ";
					getline(cin, validInput);
				}
				numColumns = stoi(validInput);
			} while (numColumns <= 0);

			// Check if steps is valid and enter it
			do
			{
				cout << "Please enter a valid number for steps: ";
				getline(cin, validInput);
				while (!checkStringToInt(validInput))
				{
					cout << "Please enter a valid number for steps: ";
					getline(cin, validInput);
				}
				numSteps = stoi(validInput);
			} while (numSteps <= -1);

			// Check if starting pos is valid and enter it
			do
			{
				cout << "Please enter a valid number for starting row";
				cout << " (0 - " << numRows - 1 << "): ";
				getline(cin, validInput);
				while (!checkStringToInt(validInput))
				{
					cout << "Please enter a valid number for starting row";
					cout << " (0 - " << numRows - 1 << "): ";
					getline(cin, validInput);
				}
				startingPosRow = stoi(validInput);
			} while (startingPosRow < 0 || startingPosRow > numRows - 1);


			// Check if starting col is valid and enter it
			do
			{
				cout << "Please enter a valid number for starting column";
				cout << " (0 - " << numColumns - 1 << "): ";
				getline(cin, validInput);
				while (!checkStringToInt(validInput))
				{
					cout << "Please enter a valid number for starting column";
					cout << " (0 - " << numColumns - 1 << "): ";
					getline(cin, validInput);
				}
				startingPosColumn = stoi(validInput);
			} while (startingPosColumn < 0 || startingPosColumn > numColumns - 1);

			Ant normalAnt(numColumns, numRows, startingPosColumn,
				startingPosRow, numSteps);
			normalAnt.runAnt();
		}
	}

	return 0;
}
