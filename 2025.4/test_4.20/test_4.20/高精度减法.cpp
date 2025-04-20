#include <iostream>
#include <vector>

using namespace std;

bool cmp(string a, string b)
{
    if (a.size() != b.size()) return a.size() >= b.size();
    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i])
            return a[i] > b[i];
    return true;
}

vector<int> sub(vector<int>& A, vector<int>& B)
{
    vector<int> ret;
    int t = 0;
    for (int i = 0; i < A.size(); i++)
    {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        ret.push_back((t + 10) % 10);
        if (t < 0) t = 1;
        else t = 0;
    }

    while (ret.size() > 1 && ret.back() == 0) ret.pop_back();

    return ret;
}

int main()
{
    string a, b;
    cin >> a >> b;
    vector<int> A, B;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    if (cmp(a, b))
    {
        auto C = sub(A, B);
        for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
    }
    else
    {
        auto C = sub(B, A);
        cout << '-';
        for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
    }

    return 0;
}