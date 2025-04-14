#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int commonPrefixLength(const string &a, const string &b) {
    int len = 0;
    int minSize = min(a.size(), b.size());
    while (len < minSize && a[len] == b[len]) {
        len++;
    }
    return len;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l;
    cin >> n >> l;

    vector<string> aliases(n);
    for (int i = 0; i < n; i++) {
        cin >> aliases[i];
    }

    sort(aliases.begin(), aliases.end());

    long long totalCharacters = 0;

    for (int i = 0; i < n; i++) {
        int requiredPrefix = 0;

        if (i > 0) {
            requiredPrefix = max(requiredPrefix, commonPrefixLength(aliases[i], aliases[i - 1]) + 1);
        }

        if (i < n - 1) {
            requiredPrefix = max(requiredPrefix, commonPrefixLength(aliases[i], aliases[i + 1]) + 1);
        }

        if (requiredPrefix > l) {
            requiredPrefix = l;
        }

        totalCharacters += requiredPrefix;
    }
    cout << totalCharacters << "\n";
    return 0;
}