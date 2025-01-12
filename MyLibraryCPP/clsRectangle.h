#pragma once
#include <iostream>

using namespace std;

class clsRectangle
{
private:
	float _Width, _Height, _Diagonal = 0;

public:

	clsRectangle(float width , float height)
	{
		_Width = width;
		_Height = height;
	}

	static float calculateRectangleArea(float width, float height)
	{
		return height * width;
	}

	static float calculateRectangleArea(clsRectangle rectangle)
	{
		return calculateRectangleArea(rectangle._Width , rectangle._Height);
	}

	float calculateRectangleArea()
	{
		return calculateRectangleArea(_Width, _Height);
	}

	static double calculateRectangleAreaThroughDiagonal(float height, float diagonal)
	{
		return (double) height * sqrt(pow(diagonal, 2) - pow(height, 2));
	}

	static double calculateRectangleAreaThroughDiagonal(clsRectangle rectangle)
	{
		return calculateRectangleAreaThroughDiagonal(rectangle.height , rectangle.diagonal);
	}

	double calculateRectangleAreaThroughDiagonal()
	{
		return calculateRectangleAreaThroughDiagonal(height, diagonal);
	}

	float getWidth()
	{
		return _Width;
	}

	float getHeight()
	{
		return _Height;
	}

	float getDiagonal()
	{
		return _Diagonal;
	}

	void setWidth(float width)
	{
		_Width = width;
	}

	void setHeight(float height)
	{
		_Height = height;
	}

	void setDiagonal(float diagonal)
	{
		_Diagonal = diagonal;
	}

	__declspec(property(get = getWidth,		put = setWidth))	short width;
	__declspec(property(get = getHeight,	put = setHeight))	short height;
	__declspec(property(get = getDiagonal,	put = setDiagonal))	short diagonal;
};

