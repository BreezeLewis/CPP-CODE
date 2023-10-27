#include <iostream>

using namespace std;


class Products
{
public:
	static double sum;//总销售款
	static double discount;//折扣
	static int n;//销售总件数
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
		cout << "总销售量：" << n << "件，" << "平均单价：" << average() << "元" << endl;
	}

private:
	double _price;//产品单价
	int _quantity;//销货件数
	int _num;//销货员号
};
double Products::sum = 0;
double Products::discount = 0.98;
int Products::n = 0;

int main()
{


	return 0;
}