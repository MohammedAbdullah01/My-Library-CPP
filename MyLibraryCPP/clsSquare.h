#pragma once
#include <iostream>
#include <stdexcept> 

using namespace std;

class clsSquare
{
private:
	float _SquareSide;

public:
	static constexpr double PI = 3.14159;

	clsSquare(float  squareSide)
	{
		_SquareSide = squareSide;
	}

	float  getSquareSide()
	{
		return _SquareSide;
	}

	void setSquareSide(float  squareSide)
	{
		_SquareSide = squareSide;
	}

	static float CalculateCircleAreaInscribedInSquare(float SquareSide)
	{
		return PI * pow(SquareSide, 2) / pow(2, 2);
	}

	static float CalculateCircleAreaInscribedInSquare(clsSquare Square)
	{
		return CalculateCircleAreaInscribedInSquare(Square._SquareSide);
	}

	float CalculateCircleAreaInscribedInSquare()
	{
		return CalculateCircleAreaInscribedInSquare(_SquareSide);
	}

	__declspec(property(get = getRadius, put = setRadius))	float  squareSide;
};
