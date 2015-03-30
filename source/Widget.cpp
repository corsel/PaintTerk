#include "Widget.h"

//Button Class
Button::Button(Rectangle argRectangle)
{
	mouseZone = new RectangularMouseZone(argRectangle);
	ZoneContainer::getInstance()->appendMouseZone(mouseZone);
	box = new Box(argRectangle);
	RenderableContainer::getInstance()->appendRenderable(box);
}
