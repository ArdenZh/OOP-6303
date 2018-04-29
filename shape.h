#pragma once
#include "point.h"
#include <iostream>
using namespace std;

struct RGB
{
	int Red;
	int Green;
	int Blue;
};

class Shape
{
public:
	Point Center;
	RGB Color;
	int number;
	int ID;
	string name;
	virtual void Move(Point point) = 0;
	virtual void RotateAroundPoint(Point point, double angle) = 0;
	virtual void Scale(double k) = 0;
	virtual void SetColor(RGB NColor) = 0;
	virtual RGB GetColor() = 0;
	virtual void Print(ostream& outstream) = 0;
  friend ostream& operator << (ostream& output, Shape& object);
};
