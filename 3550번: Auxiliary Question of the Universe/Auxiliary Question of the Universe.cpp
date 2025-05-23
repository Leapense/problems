#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

const int mlen = 1000;

char s[mlen + 1];

void go(int l, int r) {
    if (l > r) printf("0");
    else {
        printf("(%c)+", isdigit(s[l]) ? s[l] : '0');
        go(l + 1, r);
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios::failbit);

    cin >> s;
    go(0, strlen(s) - 1);
    return 0;
}