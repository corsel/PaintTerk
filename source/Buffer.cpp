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
	ZoneContainer::getInstance()->appendMouseZone(new BufferMouseZone(Rectangle(-0.8f, 0.8f, -0.8f, 0.8f), this));
	RenderableContainer::getInstance()->appendRenderable(new PixelMatrix(this));
	std::srand(std::time(0)); //Debug
}
void Buffer::paintPixel(CoordinateInteger argCoordinate, Color argColor)
{
	CoordinateFloat temp = convertScreenIntToScreenFloat(argCoordinate);
	CoordinateInteger tempIndex = convertScreenIntToBufferInt(argCoordinate, canvasOffset, canvasSize);
	//std::cout << "Buffer::paintPixel x: " << tempIndex.x << "\ty: " << tempIndex.y << std::endl;
	if (tempIndex.x > -1.0f && tempIndex.y > -1.0f)
	{
		buffer[tempIndex.x][tempIndex.y] = Color(1.0f, 0.0f, 0.0f);
		for (int i = 0; i < Cursor::getInstance()->brushSize; i++)
		{
			for (int j = 0; j < Cursor::getInstance()->brushSize; j++)
			{
				CoordinateInteger indexBrushSize;
            indexBrushSize.x =  tempIndex.x + i;/*PaintMath<int>::clamp(tempIndex.x + i * ((i%2 == 0) ? 1 : -1), 0, canvasSize.x);*/
            indexBrushSize.y = tempIndex.y + j;/*PaintMath<int>::clamp(tempIndex.y + j * ((j%2 == 0) ? 1 : -1), 0, canvasSize.y);*/
            buffer[indexBrushSize.x][indexBrushSize.y] = Color(1.0f, 0.0f, 0.0f);
			}
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
