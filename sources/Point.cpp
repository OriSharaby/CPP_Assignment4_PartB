#include "Point.hpp"
#include <string>

using namespace std;
using namespace ariel;

Point::Point() : x(0), y(0)
{
}

Point::Point(double x, double y) : x(x), y(y)
{
}

double Point::distance(Point &other)
{
    double resX = this->getX() - other.getX();
    double resY = this->getY() - other.getY();
    return sqrt(pow(resX, 2) + pow(resY, 2));
}

string Point::print()
{
    return "(" + to_string(x) + " , " + to_string(y) + ")";
}

Point Point::moveTowards(Point &p1, Point &p2, double distance)
{
    if (distance < 0)
    {
        throw invalid_argument("Distance cannot be negative!");
    }
    else if (distance > p1.distance(p2))
    {
        return Point(p2.getX(), p2.getY());
    }
    double x1 = p1.getX();
    double y1 = p1.getY();
    double x2 = p2.getX();
    double y2 = p2.getY();
    double x3 = x1 + (distance * (x2 - x1) / p1.distance(p2));
    double y3 = y1 + (distance * (y2 - y1) / p1.distance(p2));
    return Point(x3, y3);
}
