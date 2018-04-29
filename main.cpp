#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "point.h"
#include "square.h"
#include "hexagon.h"
#include "parallelogram.h"

using namespace std;

int main()
{
	struct RGB red = { 255,0,0 };
	struct RGB green = { 0,192,0 };
	struct RGB blue = { 0,32,255 };
	double rad = 90 * (M_PI / 180);

	//ШЕСТИУГОЛЬНИК
  Point topH (6,6);
  Point centH (6,3);
	Hexagon hex(topH, centH , red);
	cout << hex << endl;
	cout << "Color setting..." << endl;
	hex.SetColor(red);
	cout << "Moving..." << endl;
  Point movH (4, 0);
	hex.Move(movH);
	cout << hex << endl;
	cout << "Scaling..." << endl;
	hex.Scale(1.5);
	cout << hex << endl;
	cout << "Rotation..." << endl;
  Point rotAroundH(4,0);
	hex.RotateAroundPoint(rotAroundH, 1.5708);
	cout << hex << endl;

  //КВАДРАТ
  Point topS (4,9);
  Point centS (4,6);
  Square sqr(topS, centS , blue);
  cout << sqr << endl;
  cout << "Color setting..." << endl;
  sqr.SetColor(red);
  cout << "Moving..." << endl;
  Point movS (4, 0);
  sqr.Move(movS);
  cout << sqr << endl;
  cout << "Scaling..." << endl;
  sqr.Scale(3);
  cout << sqr << endl;
  cout << "Rotation..." << endl;
  Point rotAroundS(4,0);
  sqr.RotateAroundPoint(rotAroundS, 1.5708);
  cout << sqr << endl;

  //ПАРАЛЛЕЛОГРАММ
  Point point1 (2,2);
  Point point2 (6,2);
  Point point3 (8,4);
  Point point4 (4,4);
  Parallelogram prg(point1, point2, point3, point4, blue);
  cout << prg << endl;
  cout << "Color setting..." << endl;
  prg.SetColor(red);
  cout << "Moving..." << endl;
  Point movP (4, 0);
  prg.Move(movP);
  cout << prg << endl;
  cout << "Scaling..." << endl;
  prg.Scale(3);
  cout << prg << endl;
  cout << "Rotation..." << endl;
  Point rotAroundP(4,0);
  prg.RotateAroundPoint(rotAroundP, 1.5708);
  cout << prg << endl;

  return 0;
}
