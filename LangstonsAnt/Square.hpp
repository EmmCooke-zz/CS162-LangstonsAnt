/*************************************************
* Author: Emmet Cooke
* Date: 10/5/2017
* Description: This is the Square class header file.
*************************************************/
#ifndef SQUARE_HPP
#define SQUARE_HPP

class Square
{
public:
	enum color {white, black, ant};	// Used for the ant class

private: 
	color currentColor;

public:
	Square() { setColor(white); }
	~Square();

	color getColor() const { return currentColor; }

	void setColor(color colorIn) { currentColor = colorIn; }
};

#endif
