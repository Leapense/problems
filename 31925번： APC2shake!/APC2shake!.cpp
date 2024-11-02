#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Participant {
    string name;
    string enrollment;
    string icpc_status;
    int S;
    int A;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<Participant> participants(N);

    for (int i = 0; i < N; i++) {
        cin >> participants[i].name >> participants[i].enrollment >> participants[i].icpc_status >> participants[i].S >> participants[i].A;
    }

    vector<Participant> eligible;

    for (int i = 0; i < N; i++) {
        if (participants[i].enrollment == "jaehak" and participants[i].icpc_status == "notyet" && (participants[i].S == -1 or participants[i].S > 3)) {
            eligible.push_back(participants[i]);
        }
    }

    sort(eligible.begin(), eligible.end(), [&](const Participant &a, const Participant &b) -> bool {
        return a.A < b.A;
    });
    
    int M = min((int)eligible.size(), 10);

    vector<string> selected_names;


    for (int i = 0; i < M; i++) {
        selected_names.push_back(eligible[i].name);
    }

    sort(selected_names.begin(), selected_names.end());

    cout << M << "\n";

    for (int i = 0; i < M; i++) {
        cout << selected_names[i] << "\n";
    }

    return 0;
}