#include <iostream>
#include <freeglut.h>

#include "GlutFunctions.h"

int screenWidth = 700, screenHeight = 700;

int main(int argc, char **argv)
{
	init(&argc, argv);
	Cursor *instance = Cursor::getInstance();
	Buffer *testBuffer = new Buffer(100, 100);
	testBuffer->bufferWhiteFill();

	Slider sliderRed(Paint::Rectangle(-0.98f, -0.94f, 0.4f, 0.8f), &Cursor::color.red, false, Color(1.0f, 0.1f, 0.1f));
	Slider sliderGreen(Paint::Rectangle(-0.93f, -0.89f, 0.4f, 0.8f), &Cursor::color.green, false, Color(0.1f, 1.0f, 0.1f));
	Slider sliderBlue(Paint::Rectangle(-0.88f, -0.84f, 0.4f, 0.8f), &Cursor::color.blue, false, Color(0.1f, 0.1f, 1.0f));
	Slider sliderBrushSize(Paint::Rectangle(-0.96f, -0.86f, -0.1f, 0.3f), &Cursor::brushSize, false, Color(0.5f, 0.5f, 0.5f));
	ColorBox colorBox(Paint::Rectangle(-0.96f, -0.86f, 0.85f, 0.95f));
	Button lineStripButton(Paint::Rectangle(-0.98f, -0.84f, -0.3f, -0.2f), true, ButtonTask::toggleLineStripState);
	Cursor::getInstance()->brushSize = 0.1f;

	glutMainLoop();

	return 0;
}
