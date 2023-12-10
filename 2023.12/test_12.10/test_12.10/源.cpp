#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

struct person
{
    string name;
    int income;
};

struct Greater
{
    bool operator()(person x, person y)
    {
        if (x.income == y.income)
            return x.name < y.name;
        return x.income > y.income;
    }
};
int main() 
{
    priority_queue<person, vector<person>, Greater> pq;
    fstream file; 
    file.open("phonebook100000.txt", ios::in);
    //file.open("phonebook100000 - ¸±±¾.txt", ios::in);
    string info;
    string name, income_;
    int income;
    while (!file.eof())
    {
        file >> info;
        int pos = (int)info.find(',');
        name = info.substr(0, pos);
        income_ = info.substr(pos + 1);
        income = stoi(income_);
        if (pq.size() < 500)
        {
            pq.push(person({ name, income }));
        }
        else if (pq.size() == 500)
        {
            if (income > pq.top().income)
            {
                pq.pop();
                pq.push(person({ name, income }));
            }
            else if (income == pq.top().income && name < pq.top().name)
            {
                pq.pop();
                pq.push(person({ name, income }));
            }
        }
    }

    while (!pq.empty())
    {
        cout << pq.top().name << " " << pq.top().income << endl;
        pq.pop();
    }

    return 0;
}
