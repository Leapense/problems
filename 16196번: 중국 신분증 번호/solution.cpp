#include <bits/stdc++.h>
using namespace std;

static constexpr int weights[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};

static bool leap(int y) { return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0); }

int main() {
    string id; if (!(cin >> id)) return 0;
    int n; cin >> n;
    unordered_set<int> regions;
    regions.reserve(n * 2);
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        regions.insert(stoi(s));
    }

    if (id.size() != 18) { cout << 'I'; return 0; }
    for (int i = 0; i < 17; ++i) if (!isdigit(id[i])) { cout << 'I'; return 0; }
    if (!(isdigit(id[17]) || id[17] == 'X')) { cout << 'I'; return 0; }

    int region = stoi(id.substr(0, 6));
    if (!regions.contains(region)) { cout << 'I'; return 0; }

    int year = stoi(id.substr(6, 4));
    int month = stoi(id.substr(10, 2));
    int day = stoi(id.substr(12, 2));
    array<int,12> dim{31,28,31,30,31,30,31,31,30,31,30,31};
    if (leap(year)) dim[1] = 29;
    bool date_ok = year >= 1900 && year <= 2011 && month >= 1 && month <= 12 && day >= 1 && day <= dim[month - 1];
    if (!(date_ok && (year < 2011 || month < 12 || (month == 12 && day <= 31)))) { cout << 'I'; return 0; }

    if (id.substr(14,3) == "000") { cout << 'I'; return 0; }
    bool male = (id[16] - '0') & 1;

    int sum = 0;
    for (int i = 0; i < 17; ++i) sum = (sum + (id[i] - '0') * weights[i]) % 11;
    int x = (1 - sum + 11) % 11;
    char expect = x == 10 ? 'X' : static_cast<char>('0' + x);
    if (expect != id[17]) { cout << 'I'; return 0; }

    cout << (male ? 'M' : 'F');
    return 0;
}