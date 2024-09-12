#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, st;
    cin >> n >> st;

    vector<pair<int, int>> residential_areas(n);
    for (int i = 0; i < n; i++) {
        cin >> residential_areas[i].first >> residential_areas[i].second;
    }

    // Sort residential areas based on their positions
    sort(residential_areas.begin(), residential_areas.end());

    // Initial positions
    int left_bound = st, right_bound = st;
    long long total_distance = 0;

    // Two pointers for left and right directions
    int left_ptr = n - 1, right_ptr = 0;

    while (left_ptr >= 0 || right_ptr < n) {
        if (left_ptr < 0) {
            total_distance += abs(residential_areas[right_ptr].first - st);
            st = residential_areas[right_ptr].first;
            right_ptr++;
        }
        else if (right_ptr >= n) {
            total_distance += abs(residential_areas[left_ptr].first - st);
            st = residential_areas[left_ptr].first;
            left_ptr--;
        }
        else {
            long long left_distance = abs(residential_areas[left_ptr].first - st);
            long long right_distance = abs(residential_areas[right_ptr].first - st);

            if (left_distance <= right_distance) {
                total_distance += left_distance;
                st = residential_areas[left_ptr].first;
                left_ptr--;
            }
            else {
                total_distance += right_distance;
                st = residential_areas[right_ptr].first;
                right_ptr++;
            }
        }
    }

    cout << total_distance << endl;

    return 0;
}
