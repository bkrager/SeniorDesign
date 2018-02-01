#include "point.h"

point::point()
{
    x = 0;
    y = 0;
}

double point::getX() { return x; }
double point::getY() { return y; }
double point::set(double X, double Y) { x = X; y = Y; }
