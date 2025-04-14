#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

string getKey(const string &word) {
    int len = word.size();
    if (len <= 2) return word;
    string mid = word.substr(1, len - 2);
    sort(mid.begin(), mid.end());
    return word.front() + mid + word.back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    unordered_map<string, string> dict;
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        string key = getKey(word);
        dict[key] = word;
    }

    int M;
    cin >> M;

    vector<string> result;
    result.reserve(M);

    for (int i = 0; i < M; i++) {
        string scrambled;
        cin >> scrambled;
        string key = getKey(scrambled);
        result.push_back(dict[key]);
    }

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i < result.size() - 1 ? " " : "\n");
    }

    return 0;
}