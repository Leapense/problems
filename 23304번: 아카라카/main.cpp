#include <iostream>
#include <string>

using namespace std;

bool isAkaraka(const string& s, int left, int right) {
    int l = left, r = right;
    while (l < r) {
        if (s[l] != s[r]) return false;
        ++l; --r;
    }

    int len = right - left + 1;
    if (len <= 1) return true;

    int mid = len / 2;
    return isAkaraka(s, left, left + mid - 1) && isAkaraka(s, right - mid + 1, right);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    if (isAkaraka(s, 0, s.size() - 1)) {
        cout << "AKARAKA\n";
    } else {
        cout << "IPSELENTI\n";
    }

    return 0;
}
