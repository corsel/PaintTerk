#ifndef WIDGET_H_INCLUDED
#define WIDGET_H_INCLUDED

#include "MouseZone.h"
#include "Renderable.h"

class Box; //forward declaration
class RectangularMouseZone; //forward declaration

class Widget //abstract
{
protected:
	int layer;

public:
	virtual void clickCallback(CoordinateInteger argCoordinate);
};

class Button : public Widget
{
private:
	RectangularMouseZone *mouseZone;
	Box *box;
	void(*clickTask)(void);
	bool clicked;
	bool sticky;

public:
	Button(Paint::Rectangle argRectangle, bool argSticky = false, void(*argClickTask)(void) = 0);
	void clickCallback(CoordinateInteger argCoordinate = CoordinateInteger(0, 0)); //virtual implementation
	void setTask(void(*argClickTask)(void));
};

class Slider : public Widget
{
private:
	RectangularMouseZone *mouseZone;
	Box *line, *slider;
	bool clicked;
	Color color;
	bool horizontal;
	float value;
	float *bindedVariable;

public:
	Slider(Paint::Rectangle argRectangle, float *argBindedVariable = 0, bool argIsHorizontal = true, Color argColor = Color());
	void clickCallback(CoordinateInteger argCoordinate = CoordinateInteger(0, 0)); //virtual implementation
	void bindVariable(float *argBindedVariable);
};

namespace ButtonTask
{
	void toggleLineStripState(void);
};

#endif //WIDGET_H_INCLUDED
