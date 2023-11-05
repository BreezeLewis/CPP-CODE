//ѧ�ţ�21310386 ������¬����
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
		std::cout << "�� " << s << " Ӣ��!	";
	}
	void shout()
	{
		std::cout << "������������" << _name << "(���� " << _age << ")" << endl;
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
		std::cout << "��Ծ " << s << " Ӣ��!	";
	}
	void shout()
	{
		std::cout << "�����ɣ�����" << _name << "(���� " << _age << ")" << endl;
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
		std::cout << "���� " << s << " Ӣ��!	";
	}
	void shout()
	{
		std::cout << "��ౣ�����" << _name << "(���� " << _age << ")" << endl;
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

	Dog dogList[10]; Frog frogList[8]; Bird birdList[12];  // ����԰���� 10ֻ dog, 8ֻ frog��12ֻ bird
	Animal* animalList[10];                                // animal���͵�ָ�����飬���ڴ�������ѡ���Ķ���ĵ�ַ

	///

	int totalnum = Animal::getNum();
	std::cout << endl << "***  ����԰�ﹲ�� " << totalnum << " ֻ����";
	std::cout << "��" << Dog::getNum() << " ��, " << Frog::getNum() << " ����, " << Bird::getNum() << " �� ***\n\n";

	///
	for (int i = 0; i < 10; i++)
	{
		int num = ((rand() ^ 1234567)* 1314) % 30;
		
		if (num < 10)
		{//��
			animalList[i] = &dogList[num];
		}
		else if (num < 18)
		{//����
			animalList[i] = &frogList[num - 10];
		}
		else
		{//��
			animalList[i] = &birdList[num - 18];
		}
	}

	std::cout << "---------------------------------------------" << endl << endl; // ��ǰ 5ֻ������С����ѧϰ
	std::cout << "��ѧϰѧϰ ......" << endl << endl;
	for (int i = 0; i < 5; i++)
	{
		showAnimal(animalList[i]);
		cout << endl;
	}
	for (int i = 5; i < 10; i++)                 // �ú� 5ֻ���������ԣ�Ϊ�˴ﵽ����Ч�����Ƚ����ǵ�����ͳһ��Ϊ animal, �ٿ�ʼ����
		animalList[i]->setName("Animal");
	std::cout << "---------------------------------------------" << endl;
	std::cout << "\n��С�������²£�Ӣ� ......";

	system("pause");
	///
	int score = 0;

	for (int i = 5; i < 10; i++)
	{
		string name;
		showAnimal(animalList[i]);
		std::cout << "	�²�����ʲô���� ����";
		std::cin >> name;
		//std::cout << endl;
		if (strcmp(strstr(typeid(*animalList[i]).name(), name.c_str()), name.c_str()) == 0)
		{

			score += 20;
			std::cout << "�� ����ˣ�" << endl;
		}
		else
			std::cout << "�� ����ˣ�" << endl;
	}

	std::cout << "***  ������յ÷�: " << score << "  ***" << endl;
	return 0;
}
