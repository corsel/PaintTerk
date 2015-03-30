#ifndef MOUSEZONE_H_INCLUDED
#define MOUSEZONE_H_INCLUDED

#include <iostream>
#include <vector>
#include "Utils.h"
#include "Cursor.h"
#include "Buffer.h"

extern int screenWidth, screenHeight;
class Buffer;

class MouseZone //abstract
{
protected:
	Rectangle zone;
	int layer;

public:
	MouseZone(Rectangle argZone);
	Rectangle getZone(void);
	virtual void clickCallback(CoordinateInteger argCoordinate = CoordinateInteger()) = 0;
};

class RectangularMouseZone : public MouseZone
{
private:
public:
	RectangularMouseZone(Rectangle argZone);
	void clickCallback(CoordinateInteger argCoordinate = CoordinateInteger()); //virtual implementation
};

class BufferMouseZone : public MouseZone
{
private:
	Buffer *bindedBuffer;
public:
	BufferMouseZone(Rectangle argZone, Buffer *argBindedBuffer = 0);
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
