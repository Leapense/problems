#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    int N, M;
    cin >> N >> M;

    unordered_map<string, vector<string>> noteMap;

    for (int i = 0; i < N; ++i) {
        int T;
        string S;
        string a1, a2, a3, a4, a5, a6, a7;
        cin >> T >> S >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7;
        string key = a1 + a2 + a3;
        noteMap[key].push_back(S);
    }

    for (int i = 0; i < M; ++i) {
        string b1, b2, b3;
        cin >> b1 >> b2 >> b3;
        string query = b1 + b2 + b3;

        if (noteMap.find(query) == noteMap.end()) {
            cout << "!\n";
        } else {
            int size = noteMap[query].size();
            if (size == 1) {
                cout << noteMap[query][0] << "\n";
            } else {
                cout << "?\n";
            }
        }
    }
    return 0;
}