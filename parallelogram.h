#pragma once
#include "shape.h"
#include "point.h"
using namespace std;

class Parallelogram : public Shape
{
  public:
    Parallelogram(Point point1, Point point2, Point point3, Point point4, RGB color);
	  void Move(Point point);
	  void RotateAroundPoint(Point point, double angle);
	  void Scale(double k);
	  void SetColor(RGB NColor);
	  RGB GetColor();
	  void Print(ostream& outstream);
    friend ostream& operator << (ostream& output, Shape& object);

  private:
    Point Tops[4];
};
