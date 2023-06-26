#include <iostream>
#include <string>

using namespace std;

template <typename T, int N>
void print(T(&arr)[N]) 
{
    int x = 10;
    cout << "(T&)[" << N << "]\n";
}

template <typename T, int N>
void print(T(*arr)[N]) {
    cout << "(T*)[" << N << "]\n";
}

template <typename T>
void print(T* arr, int N) {
    cout << "T*" << "\n";
}

int main()
{
    int intArr[6] = { 1, 2, 3, 4, 5, 6 };
    double dblArr[4] = { 1.2, 2.3, 3.4, 4.5 };

    print(intArr);
    print(dblArr);
    print(&intArr);
    print(intArr, 6);

    return 0;
}