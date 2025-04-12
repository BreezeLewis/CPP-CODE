#include <iostream>
using namespace std;

// 基类
class Animal {
protected:
    string name;
public:
    Animal(const string& n = "") : name(n) {
        cout << "Animal 构造函数被调用" << endl;
    }

    virtual void eat() {
        cout << name << " 正在吃东西" << endl;
    }

    virtual ~Animal() {
        cout << "Animal 析构函数被调用" << endl;
    }
};

// 使用虚继承的派生类
class Mammal : virtual public Animal {
public:
    Mammal(const string& n = "") : Animal(n) {
        cout << "Mammal 构造函数被调用" << endl;
    }

    virtual void breathe() {
        cout << name << " 是哺乳动物，用肺呼吸" << endl;
    }

    virtual ~Mammal() {
        cout << "Mammal 析构函数被调用" << endl;
    }
};

// 另一个使用虚继承的派生类
class WingedAnimal : virtual public Animal {
public:
    WingedAnimal(const string& n = "") : Animal(n) {
        cout << "WingedAnimal 构造函数被调用" << endl;
    }

    virtual void flap() {
        cout << name << " 正在拍打翅膀" << endl;
    }

    virtual ~WingedAnimal() {
        cout << "WingedAnimal 析构函数被调用" << endl;
    }
};

// 多重继承类 - 没有使用虚继承会导致两个Animal实例
class Bat : public Mammal, public WingedAnimal {
public:
    // 注意：这里必须显式调用Animal的构造函数
    Bat(const string& n = "") : Animal(n), Mammal(n), WingedAnimal(n) {
        cout << "Bat 构造函数被调用" << endl;
    }

    void eat() override {
        cout << name << " 吃昆虫" << endl;
    }

    virtual ~Bat() {
        cout << "Bat 析构函数被调用" << endl;
    }
};

int main() {
    cout << "创建一个蝙蝠对象:" << endl;
    Bat bat("小蝙蝠");
    cout << endl;

    cout << "调用方法:" << endl;
    bat.eat();       // 来自Animal，被Bat重写
    bat.breathe();   // 来自Mammal
    bat.flap();      // 来自WingedAnimal

    // 展示单一的Animal实例
    Animal& a1 = static_cast<Mammal&>(bat);
    Animal& a2 = static_cast<WingedAnimal&>(bat);

    cout << endl;
    cout << "地址比较:" << endl;
    cout << "蝙蝠作为哺乳动物的Animal地址: " << &a1 << endl;
    cout << "蝙蝠作为有翼动物的Animal地址: " << &a2 << endl;

    if (&a1 == &a2) {
        cout << "地址相同 - 证明只有一个Animal实例!" << endl;
    }
    else {
        cout << "地址不同 - 有两个Animal实例!" << endl;
    }

    cout << endl;
    cout << "析构过程:" << endl;
    return 0;
}