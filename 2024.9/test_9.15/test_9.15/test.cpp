#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Event {
    int index;
    string type;
    Event(int idx, string t) : index(idx), type(t) {}
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> sequence(n);
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }

    vector<string> states(m);
    for (int i = 0; i < m; ++i) {
        cin >> states[i];
    }

    vector<Event> events;
    for (int i = 0; i < n; ++i) {
        events.emplace_back(sequence[i], "ON");
        events.emplace_back(sequence[i], "OFF");
    }

    int last_event_index = -1;
    vector<bool> previous_state(33, false);

    for (int t = 0; t < m; ++t) {
        vector<bool> current_state(33);
        for (int i = 0; i < 33; ++i) {
            current_state[i] = states[t][i] == '1';
        }

        bool event_found = false;

        for (int offset = 1; offset <= 3; ++offset) {
            int event_index = last_event_index + offset;
            if (event_index >= events.size()) {
                break;
            }

            Event event = events[event_index];
            if (event.type == "ON" && !previous_state[event.index - 1] && current_state[event.index - 1]) {
                last_event_index = event_index;
                event_found = true;
                break;
            }
            else if (event.type == "OFF" && previous_state[event.index - 1] && !current_state[event.index - 1]) {
                last_event_index = event_index;
                event_found = true;
                break;
            }
        }

        if (!event_found) {
            cout << "INITIAL" << endl;
        }
        else {
            cout << last_event_index + 1 << " " << events[last_event_index].type << endl;
        }

        previous_state = current_state;
    }

    return 0;
}
