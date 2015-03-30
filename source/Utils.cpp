#include "Utils.h"

//Color Struct
Color::Color() {}
Color::Color(float argRed, float argGreen, float argBlue)
	:red(argRed), green(argGreen), blue(argBlue) {}

//Rectangle Struct
Rectangle::Rectangle() {}
Rectangle::Rectangle(float argX1, float argX2, float argY1, float argY2)
	:x1(argX1), x2(argX2), y1(argY1), y2(argY2) {}
Rectangle::Rectangle(float argOffsetX, float argOffsetY, float argPixelWidth, float argPixelHeight, int argIndexX, int argIndexY)
{
	x1 = argOffsetX + (argIndexX - 0.5f) * argPixelWidth;
	x2 = argOffsetX + (argIndexX + 0.5f) * argPixelWidth;
	y1 = argOffsetY + (argIndexY - 0.5f) * argPixelHeight;
	y2 = argOffsetY + (argIndexY + 0.5f) * argPixelHeight;
}

//CoordinateFloat Struct
CoordinateFloat::CoordinateFloat() {}
CoordinateFloat::CoordinateFloat(float argX, float argY)
	:x(argX), y(argY) {}

//CoordinateInteger Struct
CoordinateInteger::CoordinateInteger() {}
CoordinateInteger::CoordinateInteger(int argX, int argY)
	:x(argX), y(argY) {}

//Global Functions
CoordinateInteger convertScreenIntToBufferInt(CoordinateInteger argScreenCoordinate, CoordinateFloat argCanvasOffset, CoordinateInteger argCanvasSize)
{
	CoordinateFloat temp = convertScreenIntToScreenFloat(argScreenCoordinate);
	if ((temp.x < 0 ? temp.x : -temp.x) < argCanvasOffset.x ||
		(temp.y < 0 ? temp.y : -temp.y) < argCanvasOffset.y)
		return CoordinateInteger(-1, -1);
	CoordinateInteger returnCoord;
	returnCoord.x = -argCanvasSize.x / 2.0f / argCanvasOffset.x * temp.x + argCanvasSize.x / 2.0f;
	returnCoord.y = -argCanvasSize.y / 2.0f / argCanvasOffset.y * temp.y + argCanvasSize.y / 2.0f;
	return returnCoord;
}
CoordinateFloat convertScreenIntToScreenFloat(CoordinateInteger argCoordinate)
{
	CoordinateFloat returnCoord;
	returnCoord.x = -1.0f + argCoordinate.x * 2.0f / (float)screenWidth;
	returnCoord.y = 1.0f - argCoordinate.y * 2.0f / (float)screenHeight;
	return returnCoord;
}
template <typename T>
T maximum(T arg1, T arg2)
{
	return (arg1 > arg2 ? arg1 : arg2);
}
template <typename T>
T minimum(T arg1, T arg2)
{
	return (arg1 < arg2 ? arg1 : arg2);
}
