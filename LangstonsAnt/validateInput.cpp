#include "validateInput.hpp"

/*************************************************************
 * Description: This function takes in a string and then checks
 * each character within the string to see if it is in the range
 * 0 to 9. If it is, it returns true. If it is not, it exits the
 * while loop and returns false.
 *************************************************************/
bool checkStringToInt(string stringIn)
{
	for (char c : stringIn)
	{
		int asciiValue = int(c);
		if (asciiValue < 48 || asciiValue > 57)
		{
			return false;
		}
	}
	return true;
}
