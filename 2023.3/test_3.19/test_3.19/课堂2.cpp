//#include <iostream>
//#include "Person.hpp"
//using namespace std;
////111 2023 3 15
////2077
//void displayPerson(Person& person1, Person& person2)
//{
//    cout << "person1 id: " << person1.getId() << endl;
//    cout << "person1 birthday: ";
//    person1.getBirthDate()->Print();
//    cout << "person2 id: " << person2.getId() << endl;
//    cout << "person2 birth year: ";
//    person2.getBirthDate()->Print();
//}
//
//int main()
//{
//    int id, year, month, day, year2;
//    cin >> id >> year >> month >> day;
//    Person person1(id, year, month, day);
//    cout << "number of Person objects: " << Person::getNumberOfObjects() << endl;
//
//    Person person2(id, year, month, day);
//    cout << "number of Person objects: " << Person::getNumberOfObjects() << endl;
//
//    cout << "After creating person1 and person2" << endl;
//    displayPerson(person1, person2);
//    cout << (person1.getBirthDate() == person2.getBirthDate()) << endl;
//
//    cin >> year2;
//    person2.getBirthDate()->setYear(year2);
//    cout << "After modifying person2's birthDate" << endl;
//    displayPerson(person1, person2);
//
//    Person* p_person3 = &person1;
//    cout << "number of Person objects: " << Person::getNumberOfObjects() << endl;
//    cout << (p_person3->getBirthDate() == person1.getBirthDate()) << endl;
//
//    {
//        Person person5(id, year, month, day);
//        cout << "number of Person objects: " << Person::getNumberOfObjects() << endl;
//    }
//    cout << "number of Person objects: " << Person::getNumberOfObjects() << endl;
//
//
//    p_person3 = NULL;
//    cout << "number of Person objects: " << Person::getNumberOfObjects() << endl;
//
//    return 0;
//}