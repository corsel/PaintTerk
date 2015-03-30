#include <iostream>
#include <freeglut.h>

#include "GlutFunctions.h"

int screenWidth = 800, screenHeight = 600;

int main(int argc, char **argv)
{
	init(&argc, argv);
	Cursor *instance = Cursor::getInstance();
	Buffer *testBuffer = new Buffer(150, 100);
	testBuffer->bufferWhiteFill();

	//Button testButton(Rectangle(-0.1f, 0.0f, -0.1f, 0.0f));
	//Button testButton2(Rectangle(0.6f, 0.7f, 0.8f, 0.9f));
	//Button testButton3(Rectangle(-0.3f, -0.2f, -0.1f, 0.4f));
	Cursor::getInstance()->brushSize = 2;
	std::cout << "test: " << PaintMath<float>::maximum(1.2f, 1.7f) << std::endl;

	glutMainLoop();

	return 0;
}
