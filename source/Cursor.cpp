#include "Cursor.h"

Cursor *Cursor::instance = 0; //static
Cursor::Cursor()
	:state(Cursor::RELEASED), brushSize(1) {}
Cursor* Cursor::getInstance() //static
{
	if (instance == 0)
		instance = new Cursor();
	return instance;
}
void Cursor::setCoordinate(CoordinateInteger argCoord) {mouseCoordinate = argCoord;}
CoordinateInteger Cursor::getScreenIntCoordinate() {return mouseCoordinate;}
CoordinateFloat Cursor::getScreenFloatCoordinate() {return convertScreenIntToScreenFloat(mouseCoordinate);}
