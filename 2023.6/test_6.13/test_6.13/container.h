class Container //声明抽象类
{
public:
    Container()
    {

    }
    Container(double radius) //抽象类的构造函数
    {
        this->radius = radius;
    }
    virtual double calSurfaceArea() = 0; //纯虚函数
    virtual double calVolume() = 0; //纯虚函数
protected:
    double radius;
};

class Cube :public Container
{
public:
    double a;
    Cube(double a)
    {
        this->a = a;
    }
    double calSurfaceArea()
    {
        return 6 * a * a;
    }
    double calVolume()
    {
        return a * a * a;
    }
};

class Sphere :public Container
{
public:
    double r;
    Sphere(double radius)
    {
        r = radius;
    }
    double calSurfaceArea()
    {
        return 4 * 3.1415926 * r * r;
    }
    double calVolume()
    {
        return (4 / 3.0) * 3.1415926 * r * r * r;
    }
};

class Cylinder :public Container
{
public:
    double r;
    double h;
    Cylinder(double radius, double height)
    {
        r = radius;
        h = height;
    }
    double calSurfaceArea()
    {
        return 2 * 3.1415926 * r * h + 3.1415926 * r * r * 2;
    }
    double calVolume()
    {
        return 3.1415926 * r * r * h;
    }
};