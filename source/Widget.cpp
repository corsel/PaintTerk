#include "Widget.h"

//Widget Class
void Widget::clickCallback(CoordinateInteger argCoordinate) {} //virtual

//Button Class
Button::Button(Paint::Rectangle argRectangle, bool argSticky, void(*argClickTask)(void))
	:clicked(false), sticky(argSticky), clickTask(argClickTask)
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
		if (sticky)
			box->dimmed = !box->dimmed;
		else
			box->dimmed = true;
		if (clickTask != 0) clickTask();
	}
	else if (Cursor::getInstance()->state == Cursor::RELEASED)
	{
		clicked = false;
		if (!sticky)
			box->dimmed = false;
	}
}
void Button::setTask(void(*argClickTask)(void))
{
	clickTask = argClickTask;
}

//Slider Class
Slider::Slider(Paint::Rectangle argRectangle, float *argBindedVariable, bool argIsHorizontal, Color argColor)
	:value(0.0f), horizontal(argIsHorizontal), color(argColor), bindedVariable(argBindedVariable)
{
	mouseZone = new RectangularMouseZone(argRectangle, this);
	ZoneContainer::getInstance()->appendMouseZone(mouseZone);
	if (horizontal)
	{
		slider = new Box(Paint::Rectangle(argRectangle.x1 - 0.03f, argRectangle.x1 + 0.03f, argRectangle.y1, argRectangle.y2), color);
		line = new Box(Paint::Rectangle(argRectangle.x1, argRectangle.x2, (argRectangle.y1 + argRectangle.y2) / 2.0f - 0.005f, (argRectangle.y1 + argRectangle.y2) / 2.0f + 0.005f), Color(0.3f, 0.3f, 0.3f));
	}
	else
	{
		slider = new Box(Paint::Rectangle(argRectangle.x1, argRectangle.x2, argRectangle.y1 - 0.03f, argRectangle.y1 + 0.03f), color);
		line = new Box(Paint::Rectangle((argRectangle.x1 + argRectangle.x2) / 2.0f - 0.005f, (argRectangle.x1 + argRectangle.x2) / 2.0f + 0.005f, argRectangle.y1, argRectangle.y2), Color(0.3f, 0.3f, 0.3f));
	}
	RenderableContainer::getInstance()->appendRenderable(line);
	RenderableContainer::getInstance()->appendRenderable(slider);
}
void Slider::clickCallback(CoordinateInteger argCoordinate) //virtual implementation
{
	CoordinateFloat temp = convertScreenIntToScreenFloat(argCoordinate);
	value = horizontal ? (temp.x - mouseZone->getZone().x1) / (mouseZone->getZone().x2 - mouseZone->getZone().x1) : (temp.y - mouseZone->getZone().y1) / (mouseZone->getZone().y2 - mouseZone->getZone().y1);
	CoordinateFloat sliderOffset;
	if (horizontal)
	{
		sliderOffset.x = value * (mouseZone->getZone().x2 - mouseZone->getZone().x1);
	}
	else
	{
		sliderOffset.y = value * (mouseZone->getZone().y2 - mouseZone->getZone().y1);
	}
	if (Cursor::getInstance()->state == Cursor::CLICKED)
	{
		clicked = true;
		slider->setOffset(sliderOffset);
		slider->dimmed = true;
		if (bindedVariable != 0) *bindedVariable = value;
	}
	else if (Cursor::getInstance()->state == Cursor::RELEASED)
	{
		slider->dimmed = false;
		clicked = false;
	}
}
void Slider::bindVariable(float *argBindedVariable)
{
	bindedVariable = argBindedVariable;
}

//ButtonTask Functions
void ButtonTask::toggleLineStripState()
{
	if (Cursor::getInstance()->tool == Cursor::BRUSH)
		Cursor::getInstance()->tool = Cursor::LINESTRIP;
	else if (Cursor::getInstance()->tool == Cursor::LINESTRIP)
		Cursor::getInstance()->tool = Cursor::BRUSH;
}