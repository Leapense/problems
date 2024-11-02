#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;
    
    string S;
    cin >> S;

    for (int q = 0; q < Q; q++) {
        int type, l, r;
        cin >> type >> l >> r;

        if (type == 1) {
            if (l < 1) l = 1;
            if (r > N) r = N;

            string sub = S.substr(l - 1, r - l + 1);
            if (sub.empty()) {
                cout << 0 << "\n";
                continue;
            }

            int count = 1;

            for (int i = 1; i < sub.size(); i++) {
                if (sub[i] != sub[i - 1]) {
                    count++;
                }
            }

            cout << count << "\n";
        }
        else if (type == 2) {
            for (int i = l - 1; i < r; i++) {
                if (S[i] == 'Z') S[i] = 'A';
                else S[i]++;
            }
        }
    }
    return 0;
}