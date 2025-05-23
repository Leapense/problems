#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

struct Command {
    long long exec_time;
    string action;
};

long long time_to_millis(const string& time_str) {
    int hours = stoi(time_str.substr(0,2));
    int minutes = stoi(time_str.substr(3,2));
    return static_cast<long long>(hours) * 60 * 1000 + static_cast<long long>(minutes) * 1000;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int N;
    cin >> N;

    vector<Command> commands;
    commands.reserve(N);

    for (int i = 0; i < N; ++i) {
        string ts, device, cmd;
        cin >> ts >> device >> cmd;

        long long timestamp = stoll(ts);

        if (device == "mobile") {
            timestamp += 100;
        }

        commands.push_back(Command{timestamp, cmd});
    }
    
    sort(commands.begin(), commands.end(), [&](const Command &a, const Command &b) -> bool {
        return a.exec_time < b.exec_time;
    });

    bool is_playing = false;
    long long last_play_time = 0;
    long long total_play_time = 0;

    for (auto &cmd : commands) {
        if (cmd.action == "play") {
            if (!is_playing) {
                is_playing = true;
                last_play_time = cmd.exec_time;
            }
        } else if (cmd.action == "paus") {
            if (is_playing) {
                total_play_time += (cmd.exec_time - last_play_time);
                is_playing = false;
            }
        }
    }

    cout << total_play_time << "\n";

    return 0;
}