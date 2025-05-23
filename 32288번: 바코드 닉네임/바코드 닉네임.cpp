#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    cin.ignore();

    string S;
    cin >> S;

    for (int i = 0; i < N; i++) {
        if (S[i] == 'l') {
            cout << "L";
        } else if (S[i] == 'I') {
            cout << "i";
        }
    }

    return 0;
}