#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class MyPoint
{
private:
    double x, y;
public:
    // The no-arg constructor that constructs a point with coordinates(0,0)
    MyPoint()
    {
        x = 0, y = 0;
    }

    MyPoint(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    double getX() const
    {
        return x;
    }
    double getY() const
    {
        return y;
    }

    //display the distance between two points in two-dimensional space.
    double distance(const MyPoint& point)
    {
        return sqrt((x - point.getX()) * (x - point.getX()) + (y - point.getY()) * (y - point.getY()));
    }
};

class ThreeDPoint : public MyPoint
{
private:
    double z;
public:
    // The no-arg constructor that constructs a point with coordinates(0,0,0)  
    ThreeDPoint()
    {
        z = 0;
    }

    ThreeDPoint(double x, double y, double z)
        :MyPoint(x, y)
    {
        this->z = z;
    }
    double getZ() const
    {
        return z;
    }

    //display the distance between two points in Three-dimensional space.
    double distance(const ThreeDPoint& point)
    {
        double x1 = getX();
        double x2 = point.getX();
        double y1 = getY();
        double y2 = point.getY();
        double z1 = getZ();
        double z2 = point.getZ();
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));
    }
};