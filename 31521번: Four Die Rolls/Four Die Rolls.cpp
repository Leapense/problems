#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    int n;
    cin >> n;

    vector<int> rolls(n);
    for (auto &x : rolls) cin >> x;

    unordered_set<int> s;

    bool unique = true;

    for (auto x : rolls) {
        if (s.find(x) != s.end()) {
            unique = false;
            break;
        }
        s.insert(x);
    }

    long long ashley = 0;
    if (unique) {
        long long temp = 1;
        for (int i = 0; i < 4 - n; i++) {
            temp *= (6 - n - i);
        }
        ashley = temp;
    }

    long long total = 1;
    for (int i = 0; i < 4 - n; i++) {
        total *= 6;
    }

    long long brandon = total - ashley;

    cout << ashley << " " << brandon << "\n";

    return 0;
}