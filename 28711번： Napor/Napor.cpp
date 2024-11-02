#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

string removeLeadingZeros(const string& num) {
    int i = 0;
    while (i < num.size() && num[i] == '0') i++;
    if (i == num.size()) return "0";
    return num.substr(i);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<string> numbers;
    string line;

    getline(cin, line);

    for (int i = 0; i < n; ++i) {
        getline(cin, line);

        string current;

        for (char c : line) {
            if (isdigit(c)) {
                current += c;
            } else {
                if (!current.empty()) {
                    string num = removeLeadingZeros(current);
                    numbers.push_back(num);
                    current.clear();
                }
            }
        }

        if (!current.empty()) {
            string num = removeLeadingZeros(current);
            numbers.push_back(num);
        }
    }

    auto compare = [](const string& a, const string& b) -> bool {
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
    };

    sort(numbers.begin(), numbers.end(), compare);

    for (const string& num : numbers) {
        cout << num << "\n";
    }

    return 0;
}