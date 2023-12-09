#include <iostream>
#include <queue>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Greater
{
	bool operator()(pair<string, int> x, pair<string, int> y)
	{
		return x.second > y.second;
	}
};

int main()
{
	int person = 0, maxp = 0, minp = 0, minpp = 0x3f3f3f3f;
	double avgp = 0;
	priority_queue<pair<string, int>, vector<pair<string, int>>, Greater> pq;
	fstream file;
	//file.open("bids - 副本.txt", ios::in);
	file.open("bids.txt", ios::in);
	pair<string, int> myp;
	file >> myp.first >> myp.second;
	//avgp += myp.second;
	minpp = myp.second;
	//pq.push(myp);
	//cout << myp.first << " " << myp.second << endl;
	while (!file.eof())
	{
		avgp += myp.second;
		if (pq.size() < 10)
		{
			pq.push(myp);
		}
		else if(pq.size() == 10)
		{
			if (myp.second > pq.top().second)
			{
				pq.pop(), pq.push(myp);
			}
		}
		file >> myp.first >> myp.second;
		person++;
		
		minpp = min(minpp, myp.second);
	}
	minp = pq.top().second;
	while (!pq.empty())
	{
		if (pq.size() == 1)
		{
			maxp = pq.top().second;
		}
		cout << pq.top().first << " " << pq.top().second << endl;
		pq.pop();
	}

	avgp /= person;
	cout << "最高成交价：" << maxp << endl;
	cout << "最低成交价：" << minp << endl;
	printf("平均成交价：%.1lf\n", avgp);
	cout << "竞价总人数：" << person << endl;
	cout << "最低竞价：" << minpp << endl;

	file.close();

	return 0;
}

