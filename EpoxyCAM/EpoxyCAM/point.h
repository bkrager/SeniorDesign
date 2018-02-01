#ifndef POINT_H
#define POINT_H


class point
{
public:
    point();
    double getX();
    double getY();
    double set(double X, double Y);
private:
    double x;
    double y;
};

#endif // POINT_H
