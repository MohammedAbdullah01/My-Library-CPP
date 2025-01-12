#pragma once
#include <iostream>
#include <stdexcept> 

using namespace std;

class clsSquare
{
private:
	double _SquareSide;

public:
	static constexpr double PI = 3.14159;

	clsSquare(double  squareSide)
	{
		_SquareSide = squareSide;
	}

	double  getSquareSide()
	{
		return _SquareSide;
	}

	void setSquareSide(double  squareSide)
	{
		_SquareSide = squareSide;
	}

	static double CalculateCircleAreaInscribedInSquare(double SquareSide)
	{
		return PI * pow(SquareSide, 2) / pow(2, 2);
	}

	static double CalculateCircleAreaInscribedInSquare(clsSquare Square)
	{
		return CalculateCircleAreaInscribedInSquare(Square._SquareSide);
	}

	double CalculateCircleAreaInscribedInSquare()
	{
		return CalculateCircleAreaInscribedInSquare(_SquareSide);
	}

	__declspec(property(get = getRadius, put = setRadius))	double  squareSide;
};
