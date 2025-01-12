#pragma once
#include <iostream>

using namespace std;

class clsTriangle
{
private:
	float _Height = 0.0f, _Base = 0.0f, _Ribs[3] = { 0.0f, 0.0f, 0.0f };

	static bool IsValidTriangle(float side1, float side2, float side3)  {

		return (side1 > 0 && side2 > 0 && side3 > 0) &&
			(side1 + side2 > side3) &&
			(side1 + side3 > side2) &&
			(side2 + side3 > side1);
	}

public:
	clsTriangle(float height, float base)
	{
		if (height <= 0 || base <= 0) {
			throw std::invalid_argument("Height and base must be positive values.");
		}

		_Height = height;
		_Base = base;
	}

	clsTriangle(float side1, float side2, float side3)
	{
		if (!IsValidTriangle(side1, side2, side3)) 
			throw std::invalid_argument("The given sides do not form a valid triangle.");

		_Ribs[0] = side1;
		_Ribs[1] = side2;
		_Ribs[2] = side3;
	}

	static float calculateTriangleArea(float height, float base)
	{
		if (height > 0 && base > 0) {

			return (base / 2) * height;
		}
		throw logic_error("Area cannot be calculated without height and base.");
	}

	static float calculateTriangleArea(clsTriangle triangle)
	{
		return calculateTriangleArea(triangle._Height, triangle._Base);
	}

	float calculateTriangleArea()
	{
		return calculateTriangleArea(_Height, _Base);
	}

	static float CalculateCircleAreaCircleDescribedAroundArbitraryTriangle(float ribs[3])
	{
		if (ribs == nullptr) {
			throw std::invalid_argument("Ribs pointer is null.");
		}

		if (!clsTriangle::IsValidTriangle(ribs[0] , ribs[1] , ribs[2]))
		{
			throw std::invalid_argument("The provided sides do not form a valid triangle.");
		}

		double perimeter = (ribs[0] + ribs[1] + ribs[2]) / 2;

		double numerator = ribs[0] * ribs[1] * ribs[2];

		double denominator = 4.0 * sqrt(perimeter * (perimeter - ribs[0]) * 
				(perimeter - ribs[1]) * (perimeter - ribs[2]));

		if (denominator == 0) {
			throw std::runtime_error("Denominator is zero, cannot calculate circumcircle area.");
		}

		double radius = numerator / denominator;
		double result = clsCircle::PI * radius * radius;

		return (float)result;
	}

	static float CalculateCircleAreaCircleDescribedAroundArbitraryTriangle(clsTriangle& triangle)
	{
		float sides[3] = { triangle.GetRibs(0), triangle.GetRibs(1), triangle.GetRibs(2) };
		return CalculateCircleAreaCircleDescribedAroundArbitraryTriangle(sides);
	}

	float CalculateCircleAreaCircleDescribedAroundArbitraryTriangle()
	{
		return CalculateCircleAreaCircleDescribedAroundArbitraryTriangle(_Ribs);
	}

	static float CalculateCircleAreaInscribedInIsoscelesTriangle(float height, float base)
	{
		return clsCircle::PI * (pow(base, 2) / 4) *
			(((2 * height) - base) / ((2 * height) + base));
	}

	static float CalculateCircleAreaInscribedInIsoscelesTriangle(clsTriangle& triangle)
	{
		return CalculateCircleAreaInscribedInIsoscelesTriangle(triangle._Height, triangle._Base); 
	}

	float CalculateCircleAreaInscribedInIsoscelesTriangle()
	{
		return CalculateCircleAreaInscribedInIsoscelesTriangle(_Height, _Base);
	}

	float getBase()
	{
		return _Base;
	}

	float getHeight()
	{
		return _Height;
	}

	float GetRibs(int index)  {
		if (index < 0 || index >= 3) {
			throw std::out_of_range("Index out of bounds.");
		}
		return _Ribs[index];
	}

	void setBase(float Base)
	{
		_Base = Base;
	}

	void setHeight(float height)
	{
		_Height = height;
	}

	__declspec(property(get = getHeight, put = setHeight))	float height;
	__declspec(property(get = getTriangleRule, put = setTriangleRule))	float Base;
};

