#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed pvA;
	Fixed pvB;
	Fixed pvC;
	pvA = ((a.getX() - b.getX()) * (point.getY() - b.getY())) - ((point.getX() - b.getX()) * (a.getY() - b.getY()));
	pvB = ((b.getX() - c.getX()) * (point.getY() - c.getY())) - ((point.getX() - c.getX()) * (b.getY() - c.getY()));
	pvC = ((c.getX() - a.getX()) * (point.getY() - a.getY())) - ((point.getX() - a.getX()) * (c.getY() - a.getY()));
	return (pvA < 0 && pvB < 0 && pvC < 0);
}
