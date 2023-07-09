#include "rational.h"
#include <iostream>

using namespace std;

void show(const vector<rational>& vec) {
    cout << "[ ";
    if (vec.size() > 0) {
        cout << vec[0].to_str();
        for (int i = 1; i < vec.size(); ++i) {
            cout << ", ";
            cout << vec[i].to_str();
        }
    }
    cout << " ]";
}

int main() {
    vector<rational> v1 = { rational{1, 2}, rational{1, 3}, rational{1, 5}, rational{2, 9}, rational{1, 7} };
    vector<rational> v2 = { rational{-1, 2}, rational{-2, 1}, rational{1, 3}, rational{2, 1} };

    sortRational(v1);
    sortRational(v2);

    show(v1);
    cout << "\n";
    show(v2);
}