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
	bool clicked;

public:
	Button(Rectangle argRectangle);
	void clickCallback(CoordinateInteger argCoordinate = CoordinateInteger(0, 0)); //virtual implementation
};

class Slider : public Widget
{
private:
	RectangularMouseZone *mouseZone;
	Box *line, *slider;
	bool clicked;
	float value;

public:
	Slider(Rectangle argRectangle);
	void clickCallback(CoordinateInteger argCoordinate = CoordinateInteger(0, 0)); //virtual implementation
};

#endif //WIDGET_H_INCLUDED
