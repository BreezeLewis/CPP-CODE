#include <iostream>
using namespace std;

class Vehicle
{
protected:
	double speed = 0;
	double weight = 0;

public:
	
};

class Bicycle : virtual public Vehicle
{
protected:
	double height = 0;
};

class Car : virtual public Vehicle
{
protected:
	int seatnum = 0;
};

class Motocycle : public Bicycle, public Car
{
public:
	void changeSpeed()
	{
		Motocycle::Bicycle::speed = 5;
		Motocycle::Car::speed = 10;
	}
};

int main()
{
	Motocycle moto;
	
	moto.changeSpeed();
	return 0;
}