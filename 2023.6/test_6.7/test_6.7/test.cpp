#include "source.h"
int main() {
    Vehicle* vehicle;
    Car car(100);
    Truck truck(200);
    Bus bus(300);

    vehicle = &car;
    vehicle->run();

    vehicle = &truck;
    vehicle->run();

    vehicle = &bus;
    vehicle->run();

    return 0;
}