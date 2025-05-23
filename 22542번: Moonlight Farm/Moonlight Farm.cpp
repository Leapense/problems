#include <bits/stdc++.h>
using namespace std;

struct Crop {
    string name;
    double efficiency;
};

int main() {
    int N;
    while (cin >> N && N != 0) {
        vector<Crop> crops;
        for (int i = 0; i < N; i++) {
            string Li;
            int Pi, Ai, Bi, Ci, Di, Ei, Fi, Si, Mi;
            cin >> Li >> Pi >> Ai >> Bi >> Ci >> Di >> Ei >> Fi >> Si >> Mi;

            long long total_revenue = (long long)Fi * Si * Mi - Pi;
            long long total_time = Ai + Bi + Ci + Di + Ei + (Mi - 1) * (Di + Ei);
            double efficiency = (double)total_revenue / total_time;
            crops.push_back(Crop{Li, efficiency});
        }
        sort(crops.begin(), crops.end(), [&](const Crop &a, const Crop &b) -> bool {
            if (abs(a.efficiency - b.efficiency) > 1e-9) {
                return a.efficiency > b.efficiency;
            }
            return a.name < b.name;
        });
        for (auto &c : crops) cout << c.name << "\n";
        cout << "#\n";
    }

    return 0;
}