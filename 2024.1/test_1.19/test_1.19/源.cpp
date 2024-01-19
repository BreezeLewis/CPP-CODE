#include <iostream>
using namespace std;

int main()
{
	/*double w;
	cin >> w;

	double sum = 0;

	if (w <= 20)
		sum = 1.68 * w;
	else
		sum = 1.98 * w;

	printf("%.2lf\n", sum);*/

	/*double maxx, a, b, c;

	cin >> a;
	maxx = a;
	cin >> b >> c;
	maxx = b > maxx ? b : maxx;
	maxx = c > maxx ? c : maxx;

	cout << maxx << endl;*/

	/*int num;
	cin >> num;
	switch (num)
	{
	case 1:
		cout << "Monday";
		break;
	case 2:
		cout << "Tuesday";
		break;
	case 3:
		cout << "Wednesday";
		break;
	case 4:
		cout << "Thursday";
		break;
	case 5:
		cout << "Friday";
		break;
	case 6:
		cout << "Saturday";
		break;
	case 7:
		cout << "Sunday";
		break;
	default:
		cout << "input error!";
		break;
	}*/

	double a, b;
	char op;
	cin >> a >> b >> op;

	switch (op)
	{
	case '+':
		cout << a + b;
		break;
	case '-':
		cout << a - b;
		break;
	case '*':
		cout << a * b;
		break;
	case '/':
	{
		if (b == 0)
			cout << "Divided by zero!";
		else
			cout << a / b;
		break;
	}
	default:
		cout << "Invalid operator!";
		break;
	}
	

	return 0;
}