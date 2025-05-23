#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    vector<int> people, hamburgers;

    for (int i = 0; i < N; i++) {
        if (S[i] == 'P') people.push_back(i + 1);
        else if (S[i] == 'H') hamburgers.push_back(i + 1);
    }

    int i = 0, j = 0, count = 0;

    while (i < people.size() && j < hamburgers.size()) {
        if (abs(people[i] - hamburgers[j]) <= K) {
            count++;
            i++;
            j++;
        }
        else if (hamburgers[j] < people[i] - K) {
            j++;
        } else {
            i++;
        }
    }
    cout << count << endl;

    return 0;
}