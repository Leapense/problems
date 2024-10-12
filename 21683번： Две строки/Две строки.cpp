#include <bits/stdc++.h>
using namespace std;

bool isValidNumber(const string& str) {
    if (str[0] == '0' && str.length() > 1) return false;
    return true;
}

unordered_set<long long> generateCyclicPermutations(const string &str) {
    int len = str.length();
    unordered_set<long long> numbers;

    for (int i = 0; i < len; ++i) {
        string perm = str.substr(i) + str.substr(0, i);
        if (isValidNumber(perm)) {
            if (perm.length() < 19) {
                numbers.insert(stoll(perm));
            }
        }
    }

    return numbers;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    string s, t;
    cin >> s;
    cin >> t;

    unordered_set<long long> numS = generateCyclicPermutations(s);
    unordered_set<long long> numT = generateCyclicPermutations(t);

    long long maxDifference = 0;
    for (long long num : numS) {
        for (long long num2 : numT) {
            maxDifference = max(maxDifference, num - num2);
        }
    }

    cout << maxDifference << "\n";

    return 0;
}