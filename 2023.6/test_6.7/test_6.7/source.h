#include <iostream>
using namespace std;

class Vehicle
{
public:
    int a;
    Vehicle()
    {

    }
    Vehicle(int x)
    {
        a = x;
    }
    virtual void run()
    {
        printf("Vehicle running %d kilometers.\n", a);
    }
};

class Car :virtual public Vehicle
{
public:
    Car(int x)
        :Vehicle(x)
    {

    }
    void run()
    {
        printf("Car running %d kilometers.\n", a);
    }
};

class Truck :virtual public Vehicle
{
public:
    Truck(int x)
        :Vehicle(x)
    {

    }
    void run()
    {
        printf("Truck running %d kilometers.\n", a);
    }
};

class Bus :public Car, public Truck
{
public:
    int distance;
    Bus(int x)
        :Car(x), Truck(x)
    {
        distance = x;
    }
    void run()
    {
        printf("Bus running %d kilometers.", distance);
    }

};