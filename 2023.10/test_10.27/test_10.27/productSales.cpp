#include <iostream>

using namespace std;


class Products
{
public:
	static double sum;//�����ۿ�
	static double discount;//�ۿ�
	static int n;//�����ܼ���
public:
	Products(int num, int quantity, int price) :_num(num), _quantity(quantity), _price(price)
	{
		n += quantity;
		if (quantity > 10)
			sum += discount * price * quantity;
		else
			sum += price * quantity;
	}

	static double average()
	{
		return sum / n;
	}

	static void display()
	{
		cout << "����������" << n << "����" << "ƽ�����ۣ�" << average() << "Ԫ" << endl;
	}

private:
	double _price;//��Ʒ����
	int _quantity;//��������
	int _num;//����Ա��
};
double Products::sum = 0;
double Products::discount = 0.98;
int Products::n = 0;

int main()
{


	return 0;
}