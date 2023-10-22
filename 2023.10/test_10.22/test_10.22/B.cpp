//#include <iostream>
//#include <vector>
//#include <queue>
//#include <climits>
//
//using namespace std;
//
//int main() {
//    int T;
//    cin >> T;
//
//    while (T--) {
//        int xi;
//        cin >> xi;
//
//        
//        queue<pair<int, int>> q;  
//        vector<bool> visited(2 * xi + 1, false); 
//        q.push({ 0, 0 });  
//
//        while (!q.empty()) {
//            int city = q.front().first;
//            int distance = q.front().second;
//            q.pop();
//
//            if (city == xi) 
//            {
//                cout << distance << endl;
//                break;
//            }
//
//            if (city + 1 <= 2 * xi && !visited[city + 1]) 
//            {
//                visited[city + 1] = true;
//                q.push({ city + 1, distance + 1 });
//            }
//
//            if (city * 3 <= 2 * xi && !visited[city * 3]) 
//            {
//                visited[city * 3] = true;
//                q.push({ city * 3, distance + 1 });
//            }
//
//            if (city * 4 <= 2 * xi && !visited[city * 4]) 
//            {
//                visited[city * 4] = true;
//                q.push({ city * 4, distance + 1 });
//            }
//        }
//    }
//
//    return 0;
//}

/*
7
0
1
2
3
4
5
6
*/

#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int xi;
        cin >> xi;

        unordered_set<int> visited;
        queue<pair<int, int>> q;
        q.push({ 0, 0 });

        while (!q.empty()) {
            int city = q.front().first;
            int distance = q.front().second;
            q.pop();

            if (city == xi) {
                cout << distance << endl;
                break;
            }

            if (city + 1 <= 2 * xi && visited.find(city + 1) == visited.end()) {
                visited.insert(city + 1);
                q.push({ city + 1, distance + 1 });
            }

            if (city * 3 <= 2 * xi && visited.find(city * 3) == visited.end()) {
                visited.insert(city * 3);
                q.push({ city * 3, distance + 1 });
            }

            if (city * 4 <= 2 * xi && visited.find(city * 4) == visited.end()) {
                visited.insert(city * 4);
                q.push({ city * 4, distance + 1 });
            }
        }
    }

    return 0;
}
