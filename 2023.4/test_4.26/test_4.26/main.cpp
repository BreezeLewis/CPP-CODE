<<<<<<< HEAD
#include <iostream>
using namespace std;
class student
{
public:
    int id;
    int score;
    student()
    {

    }
    student(int a, int b)
    {
        id = a;
        score = b;
    }
    friend double average(student* p, int count);
};
double average(student* p, int count)
{
    double sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += p[i].score;
    }
    double ans = sum / count;
    return ans;
}
int main()
{
    int id, score;
    student* p = new student[100];
    int count = 0;
    while (cin >> id && id && cin >> score)
    {
        p[count].id = id, p[count++].score = score;
    }
    cout << average(p, count) << endl;
    return 0;
=======
#include <iostream>
using namespace std;
class student
{
public:
    int id;
    int score;
    student()
    {

    }
    student(int a, int b)
    {
        id = a;
        score = b;
    }
    friend double average(student* p, int count);
};
double average(student* p, int count)
{
    double sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += p[i].score;
    }
    double ans = sum / count;
    return ans;
}
int main()
{
    int id, score;
    student* p = new student[100];
    int count = 0;
    while (cin >> id && id && cin >> score)
    {
        p[count].id = id, p[count++].score = score;
    }
    cout << average(p, count) << endl;
    return 0;
>>>>>>> cb73fa683f44cfac30efa94f2b3548a5d45d7a6c
}   