#include <bits/stdc++.h>
using namespace std;

struct Train {
    string id;
    int t;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    int M;
    long long N;

    cin >> T >> M >> N;

    vector<Train> trains;

    for (int i = 0; i < T; i++) {
        string id;
        cin >> id;

        while (true) {
            int t;
            cin >> t;

            if (t == -1) break;
            trains.push_back(Train { id, t });
        }
    }

    int num_trains = trains.size();

    int max_key = (num_trains + 1) * 60;
    vector<long long> state_map(max_key + 1, 0);
    vector<int> last_train_at_step;
    last_train_at_step.push_back(-1);

    long long step = 1;
    long long arrival_time = M;
    int prev_train = -1;

    while (step <= N) {
        int time_mod60 = arrival_time % 60;
        int key;

        if (prev_train == -1) {
            key = 0;
        } else {
            key = (prev_train + 1) * 60 + time_mod60;
        }

        if (state_map[key] > 0) {
            long long first_step = state_map[key];
            long long cycle_length = step - first_step;
            long long steps_left = N - first_step + 1;
            long long cycles_to_skip = steps_left / cycle_length;
            long long steps_remaining = steps_left % cycle_length;

            if (steps_remaining == 0) {
                int last_train = last_train_at_step[first_step + cycle_length - 1];
                cout << trains[last_train].id;

                return 0;
            } else {
                int last_train = last_train_at_step[first_step + steps_remaining - 1];
                cout << trains[last_train].id;

                return 0;
            }
        } else {
            state_map[key] = step;
            long long stationk = step - 1;
            long long min_departure_time = LLONG_MAX;
            int chosen_train = -1;

            for (int ti = 0; ti < num_trains; ti++) {
                if (ti == prev_train) continue;
                int t = trains[ti].t;
                long long base_time = t + stationk * 60;

                if (arrival_time <= base_time) {

                }

                long long diff = arrival_time - base_time;
                long long m;

                if (diff > 0) {
                    m = (diff + 59) / 60;
                } else {
                    m = 0;
                }

                long long departure_time = base_time + m * 60;
                if (departure_time < min_departure_time) {
                    min_departure_time = departure_time;
                    chosen_train = ti;
                }
            }

            last_train_at_step.push_back(chosen_train);

            arrival_time = min_departure_time + 60;
            prev_train = chosen_train;
            step += 1;
        }
    }

    cout << trains[last_train_at_step[N]].id;

    return 0;
}