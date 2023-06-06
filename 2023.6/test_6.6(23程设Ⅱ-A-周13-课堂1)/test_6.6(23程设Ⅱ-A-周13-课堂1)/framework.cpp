#include"source.h"

int main() {
    Animal a;
    Animal* p;
    Dog d;
    Cat c;

    p = &a;
    p->speak();

    p = &d;
    p->speak();

    p = &c;
    p->speak();

    return 0;
}