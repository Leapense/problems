#include <bits/stdc++.h>
using namespace std;

struct Entry {
    char type;
    int X;
};

struct FriendData {
    queue<int> received_times;
    int sum_wait_time;
    bool invalid;
    FriendData() : sum_wait_time(0), invalid(false) {}
};

int main() {
    int M;
    cin >> M;
    vector<Entry> entries(M);
    for (int i = 0; i < M; i++) {
        char type;
        int X;
        cin >> type >> X;
        entries[i] = Entry{type, X};
    }

    map<int, FriendData> friends_map;

    int last_non_w_entry_time = 0;
    bool first_non_w_entry = true;

    int pending_wait = 0;
    int current_time = 0;

    for (int i = 0; i < M; i++) {
        char type = entries[i].type;
        int X = entries[i].X;
        if (type == 'W') {
            pending_wait = X;
        } else {
            if (first_non_w_entry) {
                current_time = 0;
                first_non_w_entry = false;
            } else {
                if (pending_wait > 0) {
                    current_time = last_non_w_entry_time + pending_wait;
                } else {
                    current_time = last_non_w_entry_time + 1;
                }
            }

            if (type == 'R') {
                friends_map[X].received_times.push(current_time);
            } else if (type == 'S') {
                if(friends_map.find(X) != friends_map.end() && !friends_map[X].received_times.empty()){
                    int recv_time = friends_map[X].received_times.front();
                    friends_map[X].received_times.pop();
                    friends_map[X].sum_wait_time += (current_time - recv_time);
                }
                else{
                    friends_map[X].invalid = true;
                }
            }

            last_non_w_entry_time = current_time;
            pending_wait = 0;
        }
    }
    for (auto &p : friends_map) {
        int X = p.first;
        FriendData &fd = p.second;
        if (fd.invalid || !fd.received_times.empty()) {
            cout << X << " -1\n";
        } else {
            cout << X << " " << fd.sum_wait_time << "\n";
        }
    }

    return 0;
}