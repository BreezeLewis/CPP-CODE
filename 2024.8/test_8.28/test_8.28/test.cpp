#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n), B(n), C(n);
    unordered_map<int, vector<int>> indexMapA;

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        indexMapA[A[i]].push_back(i);
    }

    for (int i = 0; i < n; ++i) {
        cin >> B[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> C[i];
    }

    long long count = 0; 


    for (int j = 0; j < n; ++j) {
        int indexB = C[j] - 1;
        if (indexB >= 0 && indexB < n) {
            int valueBCJ = B[indexB];
            if (indexMapA.count(valueBCJ)) {
                count += indexMapA[valueBCJ].size();
            }
        }
    }

    cout << count << endl;

    return 0;
}
