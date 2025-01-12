#pragma once
#include <iostream>

using namespace std;

class clsRectangle
{
private:
	double _Width, _Height, _Diagonal = 0;

public:

	clsRectangle(double width , double height)
	{
		_Width = width;
		_Height = height;
	}

	static double calculateRectangleArea(double width, double height)
	{
		return height * width;
	}

	static double calculateRectangleArea(clsRectangle rectangle)
	{
		return calculateRectangleArea(rectangle._Width , rectangle._Height);
	}

	double calculateRectangleArea()
	{
		return calculateRectangleArea(_Width, _Height);
	}

	static double calculateRectangleAreaThroughDiagonal(double height, double diagonal)
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

	double getWidth()
	{
		return _Width;
	}

	double getHeight()
	{
		return _Height;
	}

	double getDiagonal()
	{
		return _Diagonal;
	}

	void setWidth(double width)
	{
		_Width = width;
	}

	void setHeight(double height)
	{
		_Height = height;
	}

	void setDiagonal(double diagonal)
	{
		_Diagonal = diagonal;
	}

	__declspec(property(get = getWidth,		put = setWidth))	double width;
	__declspec(property(get = getHeight,	put = setHeight))	double height;
	__declspec(property(get = getDiagonal,	put = setDiagonal))	double diagonal;
};

