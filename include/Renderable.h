#ifndef RENDERABLE_H_INCLUDED
#define RENDERABLE_H_INCLUDED

#include <freeglut.h>
#include "Buffer.h"
#include "Utils.h"

class Buffer; //forward declaration

class Renderable //abstract
{
public:
	virtual void render(void) = 0;
};

class Box : public Renderable
{
private:
	Paint::Rectangle rectangle;
	CoordinateFloat offset;
	Color color;

public:
	bool dimmed;

	Box(void);
	Box(Paint::Rectangle argRectangle, Color argColor = Color(1.0f, 0.1f, 0.1f));
	void setOffset(CoordinateFloat argOffset);
	void setColor(Color argColor);
	void render(void); //virtual implementation
};

class PixelMatrix : public Renderable
{
private:
	Buffer *bindedBuffer;

public:
	PixelMatrix(Buffer *argBindedBuffer);
	void render(void); //virtual implementation
};

class ColorBox : public Renderable
{
private:
	Paint::Rectangle rectangle;

public:
	ColorBox(Paint::Rectangle argRectangle);
	void render(void); //virtual implementation
};

class LineStrip : public Renderable
{
private:
	std::vector<CoordinateFloat> vertexVector;
	Color color;
	Buffer *bindedBuffer;

public:
	LineStrip(Buffer *argBindedBuffer, Color argColor = Color());
	void appendVertex(CoordinateFloat argVertex);
	void rasterize(void);
	void render(void); //virtual implementation
};

class RenderableContainer //singleton
{
private:
	static RenderableContainer *instance;
	std::vector<Renderable*> renderableVector;

	RenderableContainer(void);
public:
	static RenderableContainer *getInstance(void);
	void appendRenderable(Renderable *argRenderable);
	void renderAll(void);
};

#endif //BOX_H_INCLUDED
