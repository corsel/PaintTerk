#ifndef CURSOR_H_INCLUDED
#define CURSOR_H_INCLUDED

#include "Utils.h"

extern int screenWidth, screenHeight;

class Cursor //Singleton
{
private:
	static Cursor *instance;
	CoordinateInteger mouseCoordinate;

	Cursor(void);

public:
	enum State { CLICKED, RELEASED }state, rightClickState;
	enum Tool { BRUSH, LINESTRIP }tool;
	static float brushSize;
	static Color color;
	static float alpha;

	static Cursor* getInstance(void);
	void setCoordinate(CoordinateInteger argCoord);
	CoordinateInteger getScreenIntCoordinate(void);
	CoordinateFloat getScreenFloatCoordinate(void);
};


#endif //CURSOR_H_INCLUDED
