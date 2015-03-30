#ifndef WIDGET_H_INCLUDED
#define WIDGET_H_INCLUDED

#include "MouseZone.h"
#include "Renderable.h"

/*
class Widget //abstract
{
protected:
	int layer;
public:
	virtual void
};
*/

class Button
{
private:
	RectangularMouseZone *mouseZone;
	Box *box;

public:
	Button(Rectangle argRectangle);
};

#endif //WIDGET_H_INCLUDED
