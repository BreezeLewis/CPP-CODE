#include <iostream>
#include <string>
#include "mystack.h"
mystack::mystack()
{

}
void mystack::push(int x)
{
    if (q1.empty())
        q2.push(x);
    else
        q1.push(x);
}
int mystack::pop()
{
    if (empty())
        return -1;
    int res = top();
    if (!q1.empty())
    {
        for (int i = 0, n = q1.size() - 1; i < n; i++)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
    }
    else
    {
        for (int i = 0, n = q2.size() - 1; i < n; i++)
        {
            q1.push(q2.front());
            q2.pop();
        }
        q2.pop();
    }

    return res;
}
int mystack::top()
{
    if (empty()) return -1;

    int res = -1;
    if (!q1.empty())
    {
        res = q1.back();
    }
    else
    {
        res = q2.back();
    }

    return res;
}
bool mystack::empty()
{
    return q1.empty() && q2.empty();
}
