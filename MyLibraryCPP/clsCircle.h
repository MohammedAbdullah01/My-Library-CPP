#pragma once
#include <iostream>
#include <stdexcept> 

using namespace std;

class clsCircle
{
private:
	double  _Radius, _Diameter, _LengthPerimeter = 0;

public:
	static constexpr double PI = 3.141592653589793;
	clsCircle(double  Radius, double  Diameter ,double lengthPerimeter)
	{
		_Radius = Radius;
		_Diameter = Diameter;
		_LengthPerimeter = lengthPerimeter;
	}

	double  getRadius()
	{
		return _Radius;
	}

	double  getDiameter()
	{
		return _Diameter;
	}

	void setRadius(double  radius)
	{
		_Radius = radius;
	}

	void setDiameter(double  diameter)
	{
		_Diameter = diameter;
	}

	static double CalculateCircleAreaByRadius(double radius)
	{
		return (double)(PI * pow(radius, 2));
	}

	static double CalculateCircleAreaByRadius(clsCircle circle)
	{
		return CalculateCircleAreaByRadius(circle.radius);
	}

	double CalculateCircleAreaByRadius()
	{
		return CalculateCircleAreaByRadius(_Radius);
	}

	static double CalculateAreaCircleFullDiameter(double diameter)
	{
		return PI * pow(diameter, 2) / 4;
	}

	static double CalculateAreaCircleFullDiameter(clsCircle circle)
	{
		return CalculateAreaCircleFullDiameter(circle.diameter);
	}

	double CalculateAreaCircleFullDiameter()
	{
		return CalculateAreaCircleFullDiameter(_Diameter);
	}

	static double CalculateCircleAreaAlongCircumference(double lengthPerimeter)
	{
		return pow(lengthPerimeter, 2) / (PI * 4);
	}

	static double CalculateCircleAreaAlongCircumference(clsCircle circle)
	{
		return CalculateCircleAreaAlongCircumference(circle._LengthPerimeter);
	}

	double CalculateCircleAreaAlongCircumference()
	{
		return CalculateCircleAreaAlongCircumference(_LengthPerimeter);
	}

	__declspec(property(get = getRadius,	put = setRadius))	double  radius;
	__declspec(property(get = getDiameter,	put = setDiameter))	double  diameter;
};

