#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);

    int n;
    cin >> n;
    string S;
    cin >> S;

    vector<int> Ps;
    vector<int> Cs;

    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'P') Ps.push_back(i);
        else if (S[i] == 'C') Cs.push_back(i);
    }

    int k = min(Ps.size(), Cs.size());

    for (int i = 0; i < k; i++) {
        int p = Ps[i];
        int c = Cs[i];

        char temp = S[p];
        S[p] = S[c];
        S[c] = temp;
    }

    cout << S;
    return 0;
}