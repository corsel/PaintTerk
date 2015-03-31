#ifndef BUFFER_H_INCLUDED
#define BUFFER_H_INCLUDED

#include <iostream> //Debug
#include <cstdlib> //Debug
#include <ctime> //Debug
#include <freeglut.h>
#include "Utils.h"
#include "MouseZone.h"
#include "Renderable.h"


extern int screenWidth, screenHeight;

class Buffer
{
private:
	Color **buffer;
	CoordinateInteger canvasSize;
	CoordinateFloat pixelSize;
	CoordinateFloat canvasOffset;

public:
	Buffer(int argWidth, int argHeight);
	void paintPixel(CoordinateInteger argCoordinate, Color argColor);
	void paintPixelWithBufferCoordinates(CoordinateInteger argCoordinate, Color argColor);
	CoordinateInteger getCanvasSize(void);
	CoordinateFloat getCanvasOffset(void);
	CoordinateFloat getPixelSize(void);
	Color getColor(int argX, int argY);
	//Debug
	void bufferRandomFill(void);
	void bufferWhiteFill(void);
};

#endif //BUFFER_H_INCLUDED

