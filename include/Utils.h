#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <iostream> //Debug

extern int screenWidth, screenHeight;

struct Color
{
	float red, green, blue;

	Color();
	Color(float argRed, float argGreen, float argBlue);
	Color operator*(float argMultiplier);
	Color operator+(Color argColor);
};
namespace Paint
{
	struct Rectangle
	{
		float x1, x2;
		float y1, y2;

		Rectangle();
		Rectangle(float argX1, float argX2, float argY1, float argY2);
		Rectangle(float argOffsetX, float argOffsetY, float argPixelWidth, float argPixelHeight, int argIndexX, int argIndexY);
	};
}
struct CoordinateFloat
{
	float x, y;

	CoordinateFloat(void);
	CoordinateFloat(float argX, float argY);
};
struct CoordinateInteger
{
	int x, y;

	CoordinateInteger(void);
	CoordinateInteger(int argX, int argY);
};
CoordinateInteger convertScreenIntToBufferInt(CoordinateInteger argScreenCoordinate, CoordinateFloat argCanvasOffset, CoordinateInteger argCanvasSize);
CoordinateFloat convertScreenIntToScreenFloat(CoordinateInteger argCoordinate);
CoordinateInteger convertScreenFloatToBufferInt(CoordinateFloat argCoordinate, CoordinateFloat argCanvasOffset, CoordinateInteger argCanvasSize);
template <typename T>
class PaintMath
{
public:
	static T maximum(T arg1, T arg2)
	{
		return arg1 > arg2 ? arg1 : arg2;
	}
	static T minimum(T arg1, T arg2)
	{
		return arg1 < arg2 ? arg1 : arg2;
	}
	static T clamp(T argValue, T argUpperBound, T argLowerBound)
	{
		return argValue < argUpperBound ? (argValue > argLowerBound ? argValue : argLowerBound) : argUpperBound;
	}
	static void swap(T &arg1, T &arg2)
	{
		T temp;
		temp = arg1;
		arg1 = arg2;
		arg2 = temp;
	}
};
#endif //UTILS_H_INCLUDED
