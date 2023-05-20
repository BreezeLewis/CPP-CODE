#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "creature.h"
using namespace std;
Creature::Creature(const char* _sound, int _age)
{
    char* s = new char[strlen(_sound) + 1];
    strcpy(s, _sound);
    sound = s;
    age = _age;
}
Creature::Creature(const Creature& other)
{
    strcpy(sound, other.sound);
    age = other.age;
}
Creature::~Creature()
{
    delete[] sound;
}
Creature& Creature::operator=(const Creature& other)
{
    if (this != &other)
    {
        strcpy(sound, other.sound);
        age = other.age;
    }
    return *this;
}

//print out info: "Creature with age say sound"
void Creature::say()const
{
    printf("Creature with %d say %s\n", age, sound);
}

int Creature::getAge()const
{
    return age;
}
//friend std::ostream& operator<<(std::ostream& os, const Animal& _animal);