#include "Renderable.h"

//Box Class
Box::Box() {}
Box::Box(Paint::Rectangle argRectangle, Color argColor)
	:rectangle(argRectangle), color(argColor), offset(CoordinateFloat(0.0f, 0.0f)), dimmed(false) {}
void Box::setOffset(CoordinateFloat argOffset)
{
	offset = argOffset;
}
void Box::setColor(Color argColor)
{
	color = argColor;
}
void Box::render()
{
	glColor3f(color.red * (dimmed ? 0.5f : 1.0f), color.green * (dimmed ? 0.5f : 1.0f), color.blue * (dimmed ? 0.5f : 1.0f));
	glBegin(GL_QUADS);
	glVertex2f(rectangle.x1 + offset.x, rectangle.y1 + offset.y);
	glVertex2f(rectangle.x1 + offset.x, rectangle.y2 + offset.y);
	glVertex2f(rectangle.x2 + offset.x, rectangle.y2 + offset.y);
	glVertex2f(rectangle.x2 + offset.x, rectangle.y1 + offset.y);
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
			Paint::Rectangle tempRect(
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

//ColorBox Class
ColorBox::ColorBox(Paint::Rectangle argRectangle)
	:rectangle(argRectangle)
{
	RenderableContainer::getInstance()->appendRenderable(this);
}
void ColorBox::render()
{
	glBegin(GL_QUADS);
	glColor3f(Cursor::color.red, Cursor::color.green, Cursor::color.blue);
	glVertex2f(rectangle.x1, rectangle.y1);
	glVertex2f(rectangle.x2, rectangle.y1);
	glVertex2f(rectangle.x2, rectangle.y2);
	glVertex2f(rectangle.x1, rectangle.y2);
	glEnd();
}

//LineStrip Class
LineStrip::LineStrip(Buffer *argBindedBuffer, Color argColor)
	:bindedBuffer(argBindedBuffer), color(argColor) 
{
	RenderableContainer::getInstance()->appendRenderable(this);
}
void LineStrip::appendVertex(CoordinateFloat argVertex)
{
	vertexVector.push_back(argVertex);
}
void LineStrip::rasterize()
{
	bindedBuffer = 0;
	vertexVector.clear();
}
void LineStrip::render()
{
	if (vertexVector.size() < 2) return;
	glColor3f(color.red, color.green, color.blue);
	for (int i = 0; i < vertexVector.size() - 1; i++)
	{
		glBegin(GL_LINES);
		glVertex2f(vertexVector[i].x, vertexVector[i].y);
		glVertex2f(vertexVector[i+1].x, vertexVector[i+1].y);
		glEnd();
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
	if (argRenderable != 0)
		renderableVector.push_back(argRenderable);
}
void RenderableContainer::renderAll()
{
	for (int i = 0; i < renderableVector.size(); i++)
	{
		renderableVector[i]->render();
	}
}
