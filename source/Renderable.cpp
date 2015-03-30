#include "Renderable.h"

//Box Class
Box::Box() {}
Box::Box(Rectangle argRectangle, Color argColor)
	:rectangle(argRectangle), color(argColor) {}
void Box::render()
{
	glColor3f(color.red, color.green, color.blue);
   glBegin(GL_QUADS);
   glVertex2f(rectangle.x1, rectangle.y1);
   glVertex2f(rectangle.x1, rectangle.y2);
   glVertex2f(rectangle.x2, rectangle.y2);
   glVertex2f(rectangle.x2, rectangle.y1);
   glEnd();
}

//PixelMatrix Class
PixelMatrix::PixelMatrix(Buffer *argBindedBuffer)
	:bindedBuffer(argBindedBuffer) {}
void PixelMatrix::render()
{
	for (int i = 0; i < bindedBuffer->getCanvasSize().x; i++)
	{
		for(int j = 0; j < bindedBuffer->getCanvasSize().y; j++)
		{
			Color tempColor = bindedBuffer->getColor(i, j);
			Rectangle tempRect(
				bindedBuffer->getCanvasOffset().x,
				bindedBuffer->getCanvasOffset().y,
				bindedBuffer->getPixelSize().x,
				bindedBuffer->getPixelSize().y,
				i, j);
			glColor3f(tempColor.red, tempColor.green, tempColor.blue);
         glBegin(GL_QUADS);
         glVertex2f(tempRect.x1, tempRect.y1);
         glVertex2f(tempRect.x2, tempRect.y1);
         glVertex2f(tempRect.x2, tempRect.y2);
         glVertex2f(tempRect.x1, tempRect.y2);
         glEnd();
		}
	}
}

//RenderableContainer Class
RenderableContainer *RenderableContainer::instance = 0;
RenderableContainer::RenderableContainer() {}
RenderableContainer *RenderableContainer::getInstance()
{
	if (instance == 0)
		instance = new RenderableContainer();
	return instance;
}
void RenderableContainer::appendRenderable(Renderable *argRenderable)
{
	renderableVector.push_back(argRenderable);
}
void RenderableContainer::renderAll()
{
	for (int i = 0; i < renderableVector.size(); i++)
	{
		renderableVector[i]->render();
	}
}
