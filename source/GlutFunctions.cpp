#include "GlutFunctions.h"

void init(int *argc, char **argv)
{
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Paint Terk");

	glutDisplayFunc(&display);
	glutIdleFunc(&idle);
	glutMouseFunc(&mouseClick);
	glutPassiveMotionFunc(&mouseMove);
	glutMotionFunc(&mouseMove);
}

void display()
{
	glClearColor(0.15f, 0.15f, 0.15f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	RenderableContainer::getInstance()->renderAll();

	glutSwapBuffers();
}

void mouseClick(int argButton, int argState, int argX, int argY)
{
	if (argButton == 0)
	{
		if (argState == 1)
			Cursor::getInstance()->state = Cursor::RELEASED;
		else
			Cursor::getInstance()->state = Cursor::CLICKED;
	}
	else if (argButton == 2)
	{
		if (argState == 1)
			Cursor::getInstance()->rightClickState = Cursor::RELEASED;
		else
			Cursor::getInstance()->rightClickState = Cursor::CLICKED;
	}
}

void mouseMove(int argX, int argY)
{
	Cursor::getInstance()->setCoordinate(CoordinateInteger(argX, argY));
}

void idle()
{
	ZoneContainer::getInstance()->checkClick();
	glutPostRedisplay();
}
