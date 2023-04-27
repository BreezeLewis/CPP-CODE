#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

class FriendsFinder3
{
public:
    string s[10];
    string ss[10][10];
    FriendsFinder3()
    {

    }
    FriendsFinder3(string persons[10], string friends[10][10])
    {
        for (int i = 0; i < 10; i++)
            s[i] = persons[i];
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                ss[i][j] = friends[i][j];
    }
    void operator()()
    {
        string s_array[100];
        int count[100] = { 0 };
        //for (int i = 0; i < 100; i++) count[i] = 1;
        int len = 0;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
            {
                int flag = 0;
                for (int k = 0; k < len; k++)
                    if (s_array[k] == ss[i][j])
                    {
                        count[k]++, flag = 1;
                        break;
                    }
                if (flag == 0)
                    s_array[len++] = ss[i][j], count[len - 1]++;
            }

        string ans[100];
        int ansLen = 0;
        for (int i = 0; i < len; i++)
        {
            if (count[i] == 1)
                ans[ansLen++] = s_array[i];
        }

        //sort(ans[0], ans[ansLen - 1]);
        for (int i = 0; i < ansLen; i++)
            for (int j = 0; j < ansLen; j++)
                if (ans[i] < ans[j])
                    swap(ans[i], ans[j]);


        for (int i = 0; i < ansLen; i++)
            cout << ans[i] << " ";
    }
};