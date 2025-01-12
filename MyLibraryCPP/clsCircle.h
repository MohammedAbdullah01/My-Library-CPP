#pragma once
#include <iostream>
#include <stdexcept> 
#include "clsTriangle.h"

using namespace std;

class clsCircle
{
private:
	float  _Radius, _Diameter, _LengthPerimeter = 0;

public:
	static constexpr double PI = 3.14159;
	clsCircle(float  Radius, float  Diameter ,float lengthPerimeter)
	{
		_Radius = Radius;
		_Diameter = Diameter;
		_LengthPerimeter = lengthPerimeter;
	}

	float  getRadius()
	{
		return _Radius;
	}

	float  getDiameter()
	{
		return _Diameter;
	}

	void setRadius(float  radius)
	{
		_Radius = radius;
	}

	void setDiameter(float  diameter)
	{
		_Diameter = diameter;
	}

	static float CalculateCircleAreaByRadius(float radius)
	{
		return (PI * pow(radius, 2));
	}

	static float CalculateCircleAreaByRadius(clsCircle circle)
	{
		return CalculateCircleAreaByRadius(circle.radius);
	}

	float CalculateCircleAreaByRadius()
	{
		return CalculateCircleAreaByRadius(_Radius);
	}

	static float CalculateAreaCircleFullDiameter(float diameter)
	{
		return PI * pow(diameter, 2) / 4;
	}

	static float CalculateAreaCircleFullDiameter(clsCircle circle)
	{
		return CalculateAreaCircleFullDiameter(circle.diameter);
	}

	float CalculateAreaCircleFullDiameter()
	{
		return CalculateAreaCircleFullDiameter(_Diameter);
	}

	static float CalculateCircleAreaAlongCircumference(float lengthPerimeter)
	{
		return pow(lengthPerimeter, 2) / (PI * 4);
	}

	static float CalculateCircleAreaAlongCircumference(clsCircle circle)
	{
		return CalculateCircleAreaAlongCircumference(circle._LengthPerimeter);
	}

	float CalculateCircleAreaAlongCircumference()
	{
		return CalculateCircleAreaAlongCircumference(_LengthPerimeter);
	}

	__declspec(property(get = getRadius,	put = setRadius))	float  radius;
	__declspec(property(get = getDiameter,	put = setDiameter))	float  diameter;
};

