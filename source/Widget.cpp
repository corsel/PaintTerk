#include "Widget.h"

//Widget Class
void Widget::clickCallback(CoordinateInteger argCoordinate) {} //virtual

//Button Class
Button::Button(Rectangle argRectangle)
	:clicked(false)
{
	mouseZone = new RectangularMouseZone(argRectangle, this);
	ZoneContainer::getInstance()->appendMouseZone(mouseZone);
	box = new Box(argRectangle);
	RenderableContainer::getInstance()->appendRenderable(box);
}
void Button::clickCallback(CoordinateInteger argCoordinate) //virtual implementation
{
	if (Cursor::getInstance()->state == Cursor::CLICKED && clicked == false)
	{
		clicked = true;
		std::cout << "button clicked.\n";
	}
	else if (Cursor::getInstance()->state == Cursor::RELEASED)
	{
		clicked = false;
	}
}

//Slider Class
Slider::Slider(Rectangle argRectangle)
	:value(0.0f)
{
	mouseZone = new RectangularMouseZone(argRectangle, this);
	ZoneContainer::getInstance()->appendMouseZone(mouseZone);
	slider = new Box(Rectangle(argRectangle.x1, argRectangle.x1 + 0.05f, argRectangle.y1, argRectangle.y2));
	line = new Box(Rectangle(argRectangle.x1, argRectangle.x2, (argRectangle.y1 + argRectangle.y2) / 2.0f - 0.005f, (argRectangle.y1 + argRectangle.y2) / 2.0f + 0.005f));
	RenderableContainer::getInstance()->appendRenderable(line);
	RenderableContainer::getInstance()->appendRenderable(slider);
}
void Slider::clickCallback(CoordinateInteger argCoordinate) //virtual implementation
{

}
