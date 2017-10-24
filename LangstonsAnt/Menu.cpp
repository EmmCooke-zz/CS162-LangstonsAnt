/*************************************************
* Author: Emmet Cooke
* Description: This is the Menu class. A menu object must be initialized
* with the number of options you want before options can be added. 
*************************************************/
#include "Menu.hpp"
#include <iostream>

/*************************************************
* Description: Takes in an int that is used to set the number of
* options given in the menu.
*************************************************/
Menu::Menu(int numOptions)
{
	setPrompt("");
	setMenuSize(numOptions);
	options = new string[getMenuSize()];
}

/*************************************************
* Description: Takes in a string that is set to the menu prompt.
* Takes in an int that is used to set the number of options given
* in the menu.
*************************************************/
Menu::Menu(string promptIn, int numOptions)
{
	setPrompt(promptIn);
	setMenuSize(numOptions);
	options = new string[getMenuSize()];
}

/*************************************************
* Description: Places the input string within the dynamically allocated
* string array at the input int location. If the int is larger than the
* array, nothing happens.
*************************************************/
void Menu::setOption(int optionNumber, string optionIn) const
{
	if (optionNumber < getMenuSize())
	{
		options[optionNumber] = optionIn;
	}
}

/*************************************************
* Description: The prompt is printed.
*************************************************/
void Menu::printPrompt() const
{
	std::cout << getPrompt() << std::endl;
}

/*************************************************
* Description: The options are printed with numbers in
* front of them. 
*************************************************/
void Menu::printOptions() const
{
	for (int i = 0; i < getMenuSize(); i++)
	{
		if (options[i] != "")
		{
			std::cout << i + 1 << ". ";
			std::cout << options[i] << std::endl;
		}
		
	}
}
