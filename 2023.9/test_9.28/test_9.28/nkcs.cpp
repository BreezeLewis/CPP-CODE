#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int cube = n * n * n;
	
	for (int i = 1; i < cube; i += 2)
	{
		vector<int> ans;
		int sum = 0;
		for (int j = i; j < cube; j += 2)
		{
			sum += j;
			ans.push_back(j);
			if (sum == cube)
			{
				cout << n << " * " << n << " * " << n << " = ";
				cout << cube << " = ";
				for (int k = 0; k < ans.size(); k++)
				{
					if (k == 0)
					{
						cout << ans[k];
					}
					else
					{
						cout << " + " << ans[k];
					}
				}
				cout << endl;
				return 0;
			}
			else if (sum > cube)
			{
				break;
			}
		}
	}
	return 0;
}