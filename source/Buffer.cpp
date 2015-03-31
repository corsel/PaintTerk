#include "Buffer.h"

Buffer::Buffer(int argWidth, int argHeight)
	:canvasSize(CoordinateInteger(argWidth, argHeight))
{
   buffer = new Color*[canvasSize.x];
	for (int i = 0; i < canvasSize.x; i++)
	{
		buffer[i] = new Color[canvasSize.y];
	}
	pixelSize.x = 1.6f / float(canvasSize.x);
	pixelSize.y = 1.6f / float(canvasSize.y);
	canvasOffset = CoordinateFloat(-0.8f, -0.8f);
	ZoneContainer::getInstance()->appendMouseZone(new BufferMouseZone(Paint::Rectangle(-0.8f, 0.8f, -0.8f, 0.8f), this));
	RenderableContainer::getInstance()->appendRenderable(new PixelMatrix(this));
	std::srand(std::time(0)); //Debug
}
void Buffer::paintPixel(CoordinateInteger argCoordinate, Color argColor)
{
	CoordinateFloat temp = convertScreenIntToScreenFloat(argCoordinate);
	CoordinateInteger tempIndex = convertScreenIntToBufferInt(argCoordinate, canvasOffset, canvasSize);
	if (tempIndex.x > -1 && tempIndex.y > -1)
	{
		buffer[tempIndex.x][tempIndex.y] = Cursor::color;
		for (int i = 0; i < int(Cursor::brushSize * 10.0f); i++)
		{
			for (int j = 0; j < int(Cursor::brushSize * 10.0f); j++)
			{
				CoordinateInteger indexBrushSize;
				indexBrushSize.x = PaintMath<int>::clamp(tempIndex.x + i, canvasSize.x - 1, 0);
				indexBrushSize.y = PaintMath<int>::clamp(tempIndex.y + j, canvasSize.y - 1, 0);
				buffer[indexBrushSize.x][indexBrushSize.y] = Cursor::color;
			}
		}
	}
}
void Buffer::paintPixelWithBufferCoordinates(CoordinateInteger argCoordinate, Color argColor)
{
	buffer[argCoordinate.x][argCoordinate.y] = Cursor::color;
	for (int i = 0; i < int(Cursor::brushSize * 10.0f); i++)
	{
		for (int j = 0; j < int(Cursor::brushSize * 10.0f); j++)
		{
			CoordinateInteger indexBrushSize;
			indexBrushSize.x = PaintMath<int>::clamp(argCoordinate.x + i, canvasSize.x - 1, 0);
			indexBrushSize.y = PaintMath<int>::clamp(argCoordinate.y + j, canvasSize.y - 1, 0);
			buffer[indexBrushSize.x][indexBrushSize.y] = Cursor::color;
		}
	}
}
CoordinateInteger Buffer::getCanvasSize() {return canvasSize;}
Color Buffer::getColor(int argX, int argY) {return buffer[argX][argY];}
CoordinateFloat Buffer::getCanvasOffset() {return canvasOffset;}
CoordinateFloat Buffer::getPixelSize() {return pixelSize;}
//Debug
void Buffer::bufferRandomFill()
{
   for (int i = 0; i < canvasSize.x; i++)
   {
		for (int j = 0; j < canvasSize.y; j++)
		{
			buffer[i][j].red = float(std::rand() % 100) / 100.0f;
			buffer[i][j].green = float(std::rand() % 100) / 100.0f;
			buffer[i][j].blue = float(std::rand() % 100) / 100.0f;
		}
   }
}
void Buffer::bufferWhiteFill()
{
	for (int i = 0; i < canvasSize.x; i++)
   {
		for (int j = 0; j < canvasSize.y; j++)
		{
			buffer[i][j] = Color(1.0f, 1.0f, 1.0f);
		}
   }
}
