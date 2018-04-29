#include "hexagon.h"
#include "point.h"

Hexagon::Hexagon (Point top, Point cent, RGB color)
{
	if (!(top == cent))
	{
		Tops[0] = top;
		Color = color;
		ID = number;
		number++;
		Center = cent;
		name = "Hexagon";
    Point tmp;
		for (int i = 0; i < 5; i++)
		{
			tmp = Tops[i];
			tmp.RotatePoint(Center, 1.0472);
			Tops[i + 1] = tmp;
		}
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

void Hexagon::Move(Point point)
{
	Point difference = point - Center;
	Center = Center + difference;
  for (int i = 0; i < 6; i++)
	{
		Tops[i] = Tops[i] + difference;
	}
}

void Hexagon::RotateAroundPoint(Point point, double angle)
{
	Center.RotatePoint(point, angle);
	for (int i = 0; i < 6; i++)
	{
		Tops[i].RotatePoint(point, angle);
	}
}

void Hexagon::Scale(double k)
{
  for (int i = 0; i < 6; i++)
	{
		Tops[i] = Tops[i] * k;
	}
}

void Hexagon::SetColor(RGB NColor)
{
	Color = NColor;
}

RGB Hexagon::GetColor()
{
	return Color;
}

void Hexagon::Print(ostream & outstream)
{
	outstream << "Name:\t" << name << endl;
	outstream << "ID:\t" << ID << endl;
	outstream << "Center:\t(" << Center.X << "; " << Center.Y << ")" << endl;
	outstream << "Tops:\t";
	for (int i = 0; i < 6; i++)
    cout << "(" << Tops[i].X << "; " << Tops[i].Y << ") ";
	outstream << endl;
	outstream << "Color:\t(" << Color.Red << "; " << Color.Green << "; " << Color.Blue << ")" << endl;
}

ostream & operator << (std::ostream & outstream, Shape & object)
{
	object.Print(outstream);
	return outstream;
}
