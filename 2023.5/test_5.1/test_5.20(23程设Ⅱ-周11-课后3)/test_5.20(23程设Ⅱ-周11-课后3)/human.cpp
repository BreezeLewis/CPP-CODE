#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "creature.h"
#include "human.h"
using namespace std;
Human::Human(const char* _languages, const char* _sound, int _age)
    :Creature(_sound, _age)
{
    //char* s = new char[strlen(_languages) + 1];
    char* s = new char[10000];
    strcpy(s, _languages);
    languages = s;
}
Human::Human(const char* _languages, const Creature& _creature)
    : Creature(_creature)
{
    strcpy(languages, _languages);
}
Human::Human(const Human& other)
    : Creature("null", other.getAge())
{
    //char* s = new char[strlen(other.languages) + 1];
    char* s = new char[10000];
    strcpy(s, other.languages);
    languages = s;
}
Human::~Human()
{
    delete[] languages;
}
Human& Human::operator=(const Human& other)
{
    if (this != &other)
    {
        strcpy(languages, other.languages);
        //age = other.getAge();
    }
    return *this;
}

//print out info: "Human with age speak languages"
void Human::say()const
{
    printf("Human with %d speak %s\n", getAge(), languages);
}

//add new_language to the end of languages, split by ','
void Human::studyLanguage(const char* new_language)
{
    strcat(languages, ",");
    strcat(languages, new_language);
}
//friend std::ostream& operator<<(std::ostream& os, const People& _people);