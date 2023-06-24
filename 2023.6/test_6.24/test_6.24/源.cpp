#include <iostream>
#include <string>

using namespace std;

template <typename T>
void demoPrint(const T v1, const T v2)
{
    cout << "the first version of demoPrint()" << endl;
    cout << "the arguments: " << v1 << " " << v2 << endl;
}


void demoPrint(const double v1, const double v2)
{
    cout << "the nonfunctional template version of demoPrint()" << endl;
    cout << "the arguments: " << v1 << " " << v2 << endl;
}

int main()
{

    int iv1 = 3, iv2 = 5;
    double dv1 = 2.8, dv2 = 8.5;

    demoPrint(iv1, dv2);
    return 0;
}