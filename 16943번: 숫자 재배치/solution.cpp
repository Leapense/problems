#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    if (n > m) {
        cout << "-1";
        return 0;
    }
    sort(a.begin(), a.end(), greater<char>());
    if (n < m) {
        if (a[0] == '0') cout << "-1";
        else cout << a;
        return 0;
    }
    if (a[0] != '0' && a < b) {
        cout << a;
        return 0;
    }

    while (prev_permutation(a.begin(), a.end())) {
        if (a[0] == '0') continue;
        if (a < b) {
            cout << a;
            return 0;
        }
    }
    cout << "-1";
    return 0;
}