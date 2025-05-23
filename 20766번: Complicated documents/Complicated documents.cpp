#pragma GCC optimize ("O3,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    cin.ignore();

    string s;

    while(t--) {
        //string s;
        getline(cin, s);

        for (int i = 0; i < s.length(); i++) {
            if(!(s[i] == ':' || s[i] == '-')) continue;
            if(i+1 < s.length() && s[i+1] != ' ') s.insert(i+1, " ");
            if(i-1 >= 0 && s[i-1] != ' ') s.insert(i, " ");
        }

        cout << s << endl;
    }

    return 0;
}