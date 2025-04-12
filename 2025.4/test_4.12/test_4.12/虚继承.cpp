#include <iostream>
using namespace std;

// ����
class Animal {
protected:
    string name;
public:
    Animal(const string& n = "") : name(n) {
        cout << "Animal ���캯��������" << endl;
    }

    virtual void eat() {
        cout << name << " ���ڳԶ���" << endl;
    }

    virtual ~Animal() {
        cout << "Animal ��������������" << endl;
    }
};

// ʹ����̳е�������
class Mammal : virtual public Animal {
public:
    Mammal(const string& n = "") : Animal(n) {
        cout << "Mammal ���캯��������" << endl;
    }

    virtual void breathe() {
        cout << name << " �ǲ��鶯��÷κ���" << endl;
    }

    virtual ~Mammal() {
        cout << "Mammal ��������������" << endl;
    }
};

// ��һ��ʹ����̳е�������
class WingedAnimal : virtual public Animal {
public:
    WingedAnimal(const string& n = "") : Animal(n) {
        cout << "WingedAnimal ���캯��������" << endl;
    }

    virtual void flap() {
        cout << name << " �����Ĵ���" << endl;
    }

    virtual ~WingedAnimal() {
        cout << "WingedAnimal ��������������" << endl;
    }
};

// ���ؼ̳��� - û��ʹ����̳лᵼ������Animalʵ��
class Bat : public Mammal, public WingedAnimal {
public:
    // ע�⣺���������ʽ����Animal�Ĺ��캯��
    Bat(const string& n = "") : Animal(n), Mammal(n), WingedAnimal(n) {
        cout << "Bat ���캯��������" << endl;
    }

    void eat() override {
        cout << name << " ������" << endl;
    }

    virtual ~Bat() {
        cout << "Bat ��������������" << endl;
    }
};

int main() {
    cout << "����һ���������:" << endl;
    Bat bat("С����");
    cout << endl;

    cout << "���÷���:" << endl;
    bat.eat();       // ����Animal����Bat��д
    bat.breathe();   // ����Mammal
    bat.flap();      // ����WingedAnimal

    // չʾ��һ��Animalʵ��
    Animal& a1 = static_cast<Mammal&>(bat);
    Animal& a2 = static_cast<WingedAnimal&>(bat);

    cout << endl;
    cout << "��ַ�Ƚ�:" << endl;
    cout << "������Ϊ���鶯���Animal��ַ: " << &a1 << endl;
    cout << "������Ϊ�������Animal��ַ: " << &a2 << endl;

    if (&a1 == &a2) {
        cout << "��ַ��ͬ - ֤��ֻ��һ��Animalʵ��!" << endl;
    }
    else {
        cout << "��ַ��ͬ - ������Animalʵ��!" << endl;
    }

    cout << endl;
    cout << "��������:" << endl;
    return 0;
}