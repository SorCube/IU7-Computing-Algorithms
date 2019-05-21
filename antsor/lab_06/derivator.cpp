#include <cmath>

#include "derivator.h"

/////////// private ///////////////////////////////////////////////////////////

double Derivator::difference(const Point& p1, const Point& p2)
{
	return (p1.y - p2.y) / (p1.x - p2.x);
}

double Derivator::raise_exp(const Point& p1, const Point& p2, const Point& p3)
{
	return (-3 * p1.y + 4 * p2.y - p3.y) / (p1.x - p3.x);
}

double Derivator::runge(double left, double right, double r, int p)
{
	return left + (left - right) / pow(r, p - 1);
}

/////////// public ////////////////////////////////////////////////////////////

double Derivator::diff_left(const PointList& plist, size_t i)
{
	return difference(plist[i], plist[i - 1]);
}

double Derivator::diff_right(const PointList& plist, size_t i)
{
	return difference(plist[i + 1], plist[i]);
}

double Derivator::diff_center(const PointList& plist, size_t i)
{
	return difference(plist[i + 1], plist[i - 1]);
}


double Derivator::raise_exp_left(const PointList& plist)
{
	return raise_exp(plist[0], plist[1], plist[2]);
}

double Derivator::raise_exp_right(const PointList& plist)
{
	size_t last = plist.size() - 1;
	return raise_exp(plist[last], plist[last - 1], plist[last - 2]);
}


double Derivator::diff_runge(const PointList& plist, size_t i, int p)
{
	double right1 = difference(plist[i + 1], plist[i]);
	double right2 = difference(plist[i + 2], plist[i]);
	double r = (plist[i + 1].x - plist[i].x)/ (plist[i + 2].x - plist[i].x);
	return runge(right1, right2, r, p);
}

double Derivator::diff_level(const PointList& plist, size_t i)
{
	return plist[i].x;
}



