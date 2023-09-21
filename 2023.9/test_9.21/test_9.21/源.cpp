#include <iostream>
#include <vector>
using namespace std;
struct Node
{
	string name;
	int final;
	int comment;
	char super;
	char west;
	int essay;
	int bonus;
};

int n;

int main()
{
	cin >> n;
	vector<Node> ret;
	ret.resize(n);
	int maxi = 0;
	int maxx = 0;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> ret[i].name >> ret[i].final >> ret[i].comment >> ret[i].super >> ret[i].west >> ret[i].essay;
		ret[i].bonus = 0;
		if (ret[i].final > 80 && ret[i].essay >= 1)
			ret[i].bonus += 8000;
		if (ret[i].final > 85 && ret[i].comment > 80)
			ret[i].bonus += 4000;
		if (ret[i].final > 90)
			ret[i].bonus += 2000;
		if (ret[i].west == 'Y' && ret[i].final > 85)
			ret[i].bonus += 1000;
		if (ret[i].super == 'Y' && ret[i].comment > 80)
			ret[i].bonus += 850;

		if (ret[i].bonus > maxx)
		{
			maxx = ret[i].bonus;
			maxi = i;
		}
		sum += ret[i].bonus;
	}

	cout << ret[maxi].name << endl << maxx << endl << sum << endl;

	return 0;
}