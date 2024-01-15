#include <iostream>
#include <vector>
#include <functional>

using namespace std;

typedef int T;

bool is_heap(const vector<T>& A, size_t first, size_t last, function<bool(T, T)> comp)
{
    for (int i = (int)first; i <= last; i++)
    {
        int parent = i;
        int lchild = 2 * parent + 1;
        if (lchild > last)
            break;
        if (!comp(A[lchild], A[parent]))
            return false;
        if (lchild + 1 > last)
            break;
        if (!comp(A[lchild + 1], A[parent]))
            return false;
    }
    return true;
}


int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int flag = is_heap(v, 0, n - 1, greater<T>());
    if (flag)
        cout << "Ð¡¶Ñ" << endl;
    else
        cout << "´ó¶Ñ" << endl;


    return 0;
}