#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <float.h>
#include <stdexcept>
using namespace std;

namespace ariel
{
    class Point
    {
    private:
        double x;
        double y;

    public:
        Point();
        Point(double, double);
        double distance(Point &);
        virtual string print();
        static Point moveTowards(Point &, Point &, double);
        double getX()
        {
            return this->x;
        }
        double getY()
        {
            return this->y;
        }
    };
}
