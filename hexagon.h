#pragma once
#include "shape.h"
#include "point.h"
using namespace std;

class Hexagon: public Shape
{
  public:
    Hexagon(Point top, Point cent, RGB color);
	  void Move(Point point);
	  void RotateAroundPoint(Point point, double angle);
	  void Scale(double k);
	  void SetColor(RGB NColor);
	  RGB GetColor();
	  void Print(ostream& outstream);
    friend ostream& operator << (ostream& output, Shape& object);

  private:
    Point Tops[6];
};
