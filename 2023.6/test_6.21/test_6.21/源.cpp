#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_ID = 200000;
vector<int> seqs[MAX_ID + 1];

int main() {
    int n;
    cin >> n;

    string cmd;
    while (n--) {
        cin >> cmd;

        if (cmd == "new") {
            int id;
            cin >> id;
            if (id < 0)
                continue;
            seqs[id].clear();
        }

        else if (cmd == "add") {
            int id, num;
            cin >> id >> num;
            seqs[id].push_back(num);
        }

        else if (cmd == "merge") {
            int id1, id2;
            cin >> id1 >> id2;
            seqs[id1].insert(seqs[id1].end(), seqs[id2].begin(), seqs[id2].end());
            seqs[id2].clear();
        }

        else if (cmd == "unique") {
            int id;
            cin >> id;
            sort(seqs[id].begin(), seqs[id].end());
            auto it = unique(seqs[id].begin(), seqs[id].end());
            seqs[id].erase(it, seqs[id].end());
        }

        else if (cmd == "out") {
            int id;
            cin >> id;
            sort(seqs[id].begin(), seqs[id].end());
            for (int i : seqs[id])
            {
                cout << i << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}
