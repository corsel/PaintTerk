#ifndef MOUSEZONE_H_INCLUDED
#define MOUSEZONE_H_INCLUDED

#include <iostream>
#include <vector>
#include "Utils.h"
#include "Cursor.h"
#include "Buffer.h"
#include "Widget.h"

extern int screenWidth, screenHeight;
class Buffer; //forward declaration
class Widget; //forward declaration

class MouseZone //abstract
{
protected:
	Paint::Rectangle zone;
	int layer;

public:
	MouseZone(Paint::Rectangle argZone);
	Paint::Rectangle getZone(void);
	virtual void clickCallback(CoordinateInteger argCoordinate = CoordinateInteger()) = 0;
};

class RectangularMouseZone : public MouseZone
{
private:
	Widget *bindedWidget;
public:
	RectangularMouseZone(Paint::Rectangle argZone, Widget *argBindedWidget = 0);
	void clickCallback(CoordinateInteger argCoordinate = CoordinateInteger()); //virtual implementation
};

class BufferMouseZone : public MouseZone
{
private:
	Buffer *bindedBuffer;
public:
	BufferMouseZone(Paint::Rectangle argZone, Buffer *argBindedBuffer = 0);
	void clickCallback(CoordinateInteger argCoordinate); //virtual implementation
};

class ZoneContainer //singleton
{
private:
	static ZoneContainer *instance;
	std::vector<MouseZone*> zoneVector;

	ZoneContainer(void);
public:
	static ZoneContainer *getInstance(void);
	void appendMouseZone(MouseZone *argZone);
	MouseZone *checkClick(void);
};

#endif //MOUSEZONE_H_INCLUDED
