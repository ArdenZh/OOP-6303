#include "parallelogram.h"
#include "point.h"
#include <cmath>

Parallelogram::Parallelogram(Point point1, Point point2, Point point3, Point point4, RGB color)
{
	double k1 = abs((point1.Y - point2.Y) / (point1.X - point2.X));
 	double k2 = abs((point4.Y - point3.Y) / (point4.X - point3.X));
	double k3 = abs((point1.Y - point4.Y) / (point1.X - point4.X));
	double k4 = abs((point3.Y - point2.Y) / (point3.X - point2.X));

	if (!((k1 != k2) || (k3 != k4)))
	{
		Tops[0] = point1;
		Tops[1] = point2;
		Tops[2] = point3;
		Tops[3] = point4;
		Color = color;
		ID = number;
		number++;
		Center.X = (point1.X + point2.X) / 2;
		Center.Y = (point1.Y + point2.Y) / 2 ;
		name = "Parallelogram";
    Point tmp;
	}
	else
	{
		ID = -1;
		for (int i = 0; i < 2; i++)
		{
			Point Nullp(0, 0);
			Tops[0] = Nullp;
			Center = Nullp;
		}
		name = "Error";
	}
}

void Parallelogram::Move(Point point)
{
	Point difference = point - Center;
	Center = Center + difference;
  for (int i = 0; i < 4; i++)
	{
		Tops[i] = Tops[i] + difference;
	}
}

void Parallelogram::RotateAroundPoint(Point point, double angle)
{
	Center.RotatePoint(point, angle);
	for (int i = 0; i < 4; i++)
	{
		Tops[i].RotatePoint(point, angle);
	}
}

void Parallelogram::Scale(double k)
{
  for (int i = 0; i < 4; i++)
	{
		Tops[i] = Tops[i] * k;
	}
}

void Parallelogram::SetColor(RGB NColor)
{
	Color = NColor;
}

RGB Parallelogram::GetColor()
{
	return Color;
}

void Parallelogram::Print(ostream & outstream)
{
	outstream << "Name:\t" << name << endl;
	outstream << "ID:\t" << ID << endl;
	outstream << "Center:\t(" << Center.X << "; " << Center.Y << ")" << endl;
	outstream << "Tops:\t";
	for (int i = 0; i < 4; i++)
    cout << "(" << Tops[i].X << "; " << Tops[i].Y << ") ";
	outstream << endl;
	outstream << "Color:\t(" << Color.Red << "; " << Color.Green << "; " << Color.Blue << ")" << endl;
}
