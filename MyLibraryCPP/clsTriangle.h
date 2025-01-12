#pragma once
#include <stdexcept>
#include <cmath>
#include <array>
#include "clsCircle.h"

using namespace std;

class clsTriangle
{
private:
	double _Height = 0.0f, _Base = 0.0f, _Ribs[3] = { 0.0f, 0.0f, 0.0f };

	static bool IsValidTriangle(double side1, double side2, double side3)  {

		return (side1 > 0 && side2 > 0 && side3 > 0) &&
			(side1 + side2 > side3) &&
			(side1 + side3 > side2) &&
			(side2 + side3 > side1);
	}

public:
	clsTriangle(double height, double base)
	{
		if (height <= 0 || base <= 0) {
			throw std::invalid_argument("Height and base must be positive values.");
		}

		_Height = height;
		_Base = base;
	}

	clsTriangle(double side1, double side2, double side3)
	{
		if (!IsValidTriangle(side1, side2, side3)) 
			throw std::invalid_argument("The given sides do not form a valid triangle.");

		_Ribs[0] = side1;
		_Ribs[1] = side2;
		_Ribs[2] = side3;
	}

	static double calculateTriangleArea(double height, double base)
	{
		if (height > 0 && base > 0) {

			return (base / 2) * height;
		}
		throw logic_error("Area cannot be calculated without height and base.");
	}

	static double calculateTriangleArea(clsTriangle triangle)
	{
		return calculateTriangleArea(triangle._Height, triangle._Base);
	}

	double calculateTriangleArea()
	{
		return calculateTriangleArea(_Height, _Base);
	}

	static double CalculateCircleAreaCircleDescribedAroundArbitraryTriangle(double ribs[3])
	{
		if (ribs == nullptr) {
			throw invalid_argument("Ribs pointer is null.");
		}

		if (!IsValidTriangle(ribs[0] , ribs[1] , ribs[2]))
		{
			throw invalid_argument("The provided sides do not form a valid triangle.");
		}

		double perimeter = (ribs[0] + ribs[1] + ribs[2]) / 2;

		double numerator = ribs[0] * ribs[1] * ribs[2];

		double denominator = 4.0 * sqrt(perimeter * (perimeter - ribs[0]) * 
				(perimeter - ribs[1]) * (perimeter - ribs[2]));

		if (denominator == 0) {
			throw runtime_error("Denominator is zero, cannot calculate circumcircle area.");
		}

		double radius = numerator / denominator;
		double result = clsCircle::PI * radius * radius;

		return result;
	}

	static double CalculateCircleAreaCircleDescribedAroundArbitraryTriangle(clsTriangle& triangle)
	{
		double sides[3] = { triangle.GetRibs(0), triangle.GetRibs(1), triangle.GetRibs(2) };
		return CalculateCircleAreaCircleDescribedAroundArbitraryTriangle(sides);
	}

	double CalculateCircleAreaCircleDescribedAroundArbitraryTriangle()
	{
		return CalculateCircleAreaCircleDescribedAroundArbitraryTriangle(_Ribs);
	}

	static double CalculateCircleAreaInscribedInIsoscelesTriangle(double height, double base)
	{
		return clsCircle::PI * (pow(base, 2) / 4) *
			(((2 * height) - base) / ((2 * height) + base));
	}

	static double CalculateCircleAreaInscribedInIsoscelesTriangle(clsTriangle& triangle)
	{
		return CalculateCircleAreaInscribedInIsoscelesTriangle(triangle._Height, triangle._Base); 
	}

	double CalculateCircleAreaInscribedInIsoscelesTriangle()
	{
		return CalculateCircleAreaInscribedInIsoscelesTriangle(_Height, _Base);
	}

	double getBase()
	{
		return _Base;
	}

	double getHeight()
	{
		return _Height;
	}

	double GetRibs(int index)  {
		if (index < 0 || index >= 3) {
			throw std::out_of_range("Index out of bounds.");
		}
		return _Ribs[index];
	}

	void setBase(double Base)
	{
		_Base = Base;
	}

	void setHeight(double height)
	{
		_Height = height;
	}

	__declspec(property(get = getHeight, put = setHeight))	double height;
	__declspec(property(get = getTriangleRule, put = setTriangleRule))	double Base;
};

