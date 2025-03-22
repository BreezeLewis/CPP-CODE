#include <iostream>
#include <vector>

using namespace std;

vector<int> mul(vector<int>& A, vector<int>& B)
{
    vector<int> C(A.size() * B.size() + 1);

    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < B.size(); j++)
        {
            C[i + j] += A[i] * B[j];
            C[i + j + 1] += C[i + j] / 10;
            C[i + j] %= 10;
        }

    while (C.size() > 1 && C.back() == 0) C.pop_back();

    return C;
}

int main()
{
    string a, b;
    vector<int> A, B;

    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    vector<int> C = mul(A, B);

    for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);

    return 0;
}