#include <iostream>
#include <stack>
#include <queue>
using namespace std;
//int main()
//{
//    stack<char> S;
//
//    char x, y;
//
//    x = 'n'; y = 'g';
//
//    S.push(x); S.push('i'); S.push(y);
//
//    S.pop(); S.push('r'); S.push('t'); S.push(x);
//
//    S.pop(); S.push('s');
//
//    while (!S.empty())
//
//    {
//
//        x = S.top();
//
//        S.pop();
//
//        cout << x;
//
//    };
//    cout << y;
//}
int main()

{

    queue<char> Q;

    char x, y;

    x = 'n'; y = 'g';

    Q.push(x);   //n
    Q.push('i'); //ni
    Q.push(y);  //nig
    Q.pop();//ig
    Q.push('r');//igr
    Q.push('t'); //igrt
    Q.push(x);//igrtn

    Q.pop();//grtn
    Q.push('s');//grtns

    while (!Q.empty())

    {

        x = Q.front();//g

        Q.pop();

        cout << x;

    };

    cout << y;

    


}