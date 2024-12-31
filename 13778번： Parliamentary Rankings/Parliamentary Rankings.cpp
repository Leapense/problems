#include <bits/stdc++.h>
using namespace std;

struct MP {
    string name;
    int score;
} mp_info[121];

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int I;
        cin >> I;

        string name;
        getline(cin, name);

        if (!name.empty() && name[0] == ' ') name = name.substr(1);
        mp_info[I].name = name;
        mp_info[I].score = 0;
    }

    int A;
    cin >> A;

    while (A--) {
        int I;
        char code;
        cin >> I >> code;
        int points = 0;

        switch(code) {
            case 'S' : points = 10; break;
            case 'Q' : points = 5; break;
            case 'A' : points = 7; break;
            case 'L' : points = -8; break;
            case 'F' : points = 4; break;
            case 'D' : points = -5; break;
            case 'E' : points = -10; break;
        }
        mp_info[I].score += points;
    }

    vector<pair<int, string>> mps;
    for (int I = 1; I <= 120; I++) {
        if (!mp_info[I].name.empty()) {
            mps.emplace_back(make_pair(I, mp_info[I].name));
        }
    }

    int max_score = INT32_MIN, min_score = INT32_MAX;
    for (auto &[I, name] : mps) {
        if (mp_info[I].score > max_score) max_score = mp_info[I].score;
        if (mp_info[I].score < min_score) min_score = mp_info[I].score;
    }

    vector<pair<int, string>> best, worst;
    for (auto &[I, name] : mps) {
        if (mp_info[I].score == max_score) best.emplace_back(make_pair(I, name));
        if (mp_info[I].score == min_score) worst.emplace_back(make_pair(I, name));
    }

    sort(best.begin(), best.end());
    sort(worst.begin(), worst.end());
    cout << max_score;
    for (auto &[I, name] : best) cout << " " << name;
    cout << endl << min_score;
    for (auto &[I, name] : worst) cout << " " << name;
    return 0;
}