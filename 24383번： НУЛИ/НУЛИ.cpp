#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    string s;
    cin >> s;

    set<int> unique_lengths;
    
    int count = 0;
    for (char c : s) {
        if (c == '0') {
            count++;
        } else {
            if (count > 0) {
                unique_lengths.insert(count);
            }
            count = 0;
        }
    }

    if (count > 0) {
        unique_lengths.insert(count);
    }

    cout << unique_lengths.size() << endl;

    return 0;
}