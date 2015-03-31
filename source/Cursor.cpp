#include "Cursor.h"

Cursor *Cursor::instance = 0; //static
float Cursor::brushSize = 0.1f; //static
float Cursor::alpha = 1.0f; //static
Color Cursor::color = Color(0.0f, 0.0f, 0.0f); //static
Cursor::Cursor()
	:state(Cursor::RELEASED), rightClickState(RELEASED), tool(Cursor::BRUSH) {}
Cursor* Cursor::getInstance() //static
{
	if (instance == 0)
		instance = new Cursor();
	return instance;
}
void Cursor::setCoordinate(CoordinateInteger argCoord) {mouseCoordinate = argCoord;}
CoordinateInteger Cursor::getScreenIntCoordinate() {return mouseCoordinate;}
CoordinateFloat Cursor::getScreenFloatCoordinate() {return convertScreenIntToScreenFloat(mouseCoordinate);}
