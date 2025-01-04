#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;

    long long A = 0, total_wrong = 0;
    unordered_map<string, pair<int, bool>> users;

    while (N--) {
        long long judge_num;
        string user_id;
        int result;
        long long memory, time, language, code_length;

        cin >> judge_num >> user_id >> result >> memory >> time >> language >> code_length;
        if (user_id == "megalusion") continue;
        auto it = users.find(user_id);
        if (it == users.end()) {
            users[user_id] = {0, false};
            it = users.find(user_id);
        }

        if(!it->second.second) {
            if (result == 4) {
                A += 1;
                total_wrong += it->second.first;
                it->second.second = true;
            } else {
                it->second.first += 1;
            }
        }
    }

    if (A == 0) {
        cout << fixed << 0;
    } else {
        double rate = (double)A / (A + total_wrong) * 100.0;
        cout << fixed << setprecision(20) << rate;
    }

    return 0;
}