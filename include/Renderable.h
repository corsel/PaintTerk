#ifndef RENDERABLE_H_INCLUDED
#define RENDERABLE_H_INCLUDED

#include <freeglut.h>
#include "Buffer.h"

class Buffer; //forward declaration

class Renderable //abstract
{
public:
	virtual void render(void) = 0;
};

class Box : public Renderable
{
private:
	Rectangle rectangle;
	Color color;

public:
	Box(void);
	Box(Rectangle argRectangle, Color argColor = Color(1.0f, 0.1f, 0.1f));
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
