#include <iostream>
#include <vector>
using namespace std;

/*
10
john M
belle F
elsa F
tom M
smith M
hannah F
viola F
rock M
hugo M
jaden M
16
*/


void pairing_situation(vector<pair<string, char>> m, vector<pair<string, char>> f, int songs)
{
	int i = 0, j = 0;
	while (songs--)
	{
		cout << m[i].first << " " << m[i].second << "和" << f[j].first << " " << f[j].second << "配对" << endl;
		i++;
		i %= m.size();
		j++;
		j %= f.size();
	}
}

void situation_in_k(string m, string f, vector<pair<string, char>> male, vector<pair<string, char>> female)
{
	int i = 0, j = 0;
	int k = 2;
	int cnt = 0;
	while (k--)
	{
		while (1)
		{
			cnt++;
			
			if (male[i].first == m && female[j].first == f)
			{
				cout << m << "和" << f << "在第" << cnt << "曲配对" << endl;
				i++; i %= male.size();
				j++; j %= female.size();
				break;
			}
			i++; i %= male.size();
			j++; j %= female.size();
		}
	}
}

int main()
{
	int num;
	cin >> num;

	int songs = 0;

	vector<pair<string, char>> male;
	vector<pair<string, char>> female;

	
	while (num--)
	{
		pair<string, char> ret;
		cin >> ret.first >> ret.second;
		if (ret.second == 'M')
			male.push_back(ret);
		else
			female.push_back(ret);
	}

	//cin >> songs;

	//pairing_situation(male, female, songs);

	

	situation_in_k("john", "belle", male, female);

	return 0;
}