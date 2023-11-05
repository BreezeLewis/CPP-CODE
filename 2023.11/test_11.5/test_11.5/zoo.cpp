//学号：21310386 姓名：卢昀生
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

class Animal
{
public:
	Animal(string name = "Animal", int age = 0):_name(name)
	{
		_age = (rand() ^ 12138 * 131452) % 10 + 1;
		animalNum++;
	}
	virtual void move() = 0;
	virtual void shout() = 0;
	string getName() { return _name; }
	void setName(string s) { _name = s; }
	int getAge() { return _age; };
	static int getNum() { return animalNum; }
protected:
	string _name;
	static int animalNum;
	int _age;
};
int Animal::animalNum = 0;

class Dog :public Animal
{
public:
	Dog(string name = "Dog") :Animal(name)
	{
		dogNum++;
	}
	void move()
	{
		double s = 5 + 0.1 * _age;
		std::cout << "跑 " << s << " 英尺!	";
	}
	void shout()
	{
		std::cout << "汪汪汪，它是" << _name << "(年龄 " << _age << ")" << endl;
	}
	static int getNum()
	{
		return dogNum;
	}
protected:
	static int dogNum;
};
int Dog::dogNum = 0;

class Frog :public Animal
{
public:
	Frog(string name = "Frog") :Animal(name)
	{
		frogNum++;
	}
	void move()
	{
		double s = 1 + 0.1 * _age;
		std::cout << "跳跃 " << s << " 英尺!	";
	}
	void shout()
	{
		std::cout << "呱呱呱，它是" << _name << "(年龄 " << _age << ")" << endl;
	}
	static int getNum()
	{
		return frogNum;
	}
protected:
	static int frogNum;
};
int Frog::frogNum = 0;

class Bird :public Animal
{
public:
	Bird(string name = "Bird") :Animal(name)
	{
		birdNum++;
	}
	void move()
	{
		double s = 10 + 0.1 * _age;
		std::cout << "飞行 " << s << " 英尺!	";
	}
	void shout()
	{
		std::cout << "啾啾啾，它是" << _name << "(年龄 " << _age << ")" << endl;
	}
	static int getNum()
	{
		return birdNum;
	}
protected:
	static int birdNum;
};
int Bird::birdNum = 0;

void showAnimal(Animal* animal)
{
	animal->move();
	animal->shout();
}

int main()
{
	srand((unsigned int)time(0));

	Dog dogList[10]; Frog frogList[8]; Bird birdList[12];  // 动物园中有 10只 dog, 8只 frog，12只 bird
	Animal* animalList[10];                                // animal类型的指针数组，用于存放随机挑选出的动物的地址

	///

	int totalnum = Animal::getNum();
	std::cout << endl << "***  动物园里共有 " << totalnum << " 只动物";
	std::cout << "（" << Dog::getNum() << " 狗, " << Frog::getNum() << " 青蛙, " << Bird::getNum() << " 鸟） ***\n\n";

	///
	for (int i = 0; i < 10; i++)
	{
		int num = ((rand() ^ 1234567)* 1314) % 30;
		
		if (num < 10)
		{//狗
			animalList[i] = &dogList[num];
		}
		else if (num < 18)
		{//青蛙
			animalList[i] = &frogList[num - 10];
		}
		else
		{//鸟
			animalList[i] = &birdList[num - 18];
		}
	}

	std::cout << "---------------------------------------------" << endl << endl; // 用前 5只动物让小朋友学习
	std::cout << "先学习学习 ......" << endl << endl;
	for (int i = 0; i < 5; i++)
	{
		showAnimal(animalList[i]);
		cout << endl;
	}
	for (int i = 5; i < 10; i++)                 // 用后 5只动物来测试，为了达到测试效果，先将他们的名字统一改为 animal, 再开始测试
		animalList[i]->setName("Animal");
	std::cout << "---------------------------------------------" << endl;
	std::cout << "\n让小朋友来猜猜（英语） ......";

	system("pause");
	///
	int score = 0;

	for (int i = 5; i < 10; i++)
	{
		string name;
		showAnimal(animalList[i]);
		std::cout << "	猜猜它是什么动物 ？：";
		std::cin >> name;
		//std::cout << endl;
		if (strcmp(strstr(typeid(*animalList[i]).name(), name.c_str()), name.c_str()) == 0)
		{

			score += 20;
			std::cout << "√ 答对了！" << endl;
		}
		else
			std::cout << "× 答错了！" << endl;
	}

	std::cout << "***  你的最终得分: " << score << "  ***" << endl;
	return 0;
}
