#include <iostream>
#include <vector>
using namespace std;


int N;
struct Node
{
	string name;
	int Chinese;
	int Math;
	int English;
	int Sum;
};

int main()
{
	cin >> N;
	vector<Node> ret;
	ret.resize(N);
	int maxi = 0;
	int maxx = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> ret[i].name >> ret[i].Chinese >> ret[i].Math >> ret[i].English;
		ret[i].Sum = ret[i].Chinese + ret[i].Math + ret[i].English;
		if (ret[i].Sum > maxx)
		{
			maxx = ret[i].Sum;
			maxi = i;
		}
	}

	cout << ret[maxi].name << " " << ret[maxi].Chinese << " " << ret[maxi].Math << " " << ret[maxi].English << endl;

	return 0;
}