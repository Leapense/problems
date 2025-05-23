#include <bits/stdc++.h>
using namespace std;

string findLongestCommonSubstring(string a, string b) {
    vector<int> countA(26,0);
    vector<int> countB(26,0);

    for (char c : a) {
        countA[c-'a']++;
    }

    for (char c : b) {
        countB[c-'a']++;
    }

    string result;

    for (int i = 0; i < 26; i++) {
        int commonCount = min(countA[i], countB[i]);
        result += string(commonCount, 'a'+i);
    }
    return result;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    string a, b;
    cin >> a >> b;
    cout << findLongestCommonSubstring(a, b) << endl;
    return 0;
}