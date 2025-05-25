#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> digits(5);
    for (auto &d : digits) {
        cin >> d;
    }

    sort(digits.begin(), digits.end());
    vector<int> V;
    do {
        if (digits[0] == 0) {
            continue;
        }

        int num = 0;
        for (int d : digits) {
            num = num * 10 + d;
        }

        V.push_back(num);
    } while (next_permutation(digits.begin(), digits.end()));

    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());

    unordered_map<int, int> idx;
    idx.reserve(V.size() * 2);

    for (int i = 0; i < (int)V.size(); ++i) {
        idx[V[i]] = i;
    }

    long long count = 0;
    int N = V.size();
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            for (int k = j + 1; k < N; ++k) {
                int sum = V[i] + V[j] + V[k];
                auto it = idx.find(sum);
                if (it != idx.end() && it -> second > k) {
                    ++count;
                }
            }
        }
    }

    cout << count << "\n";
    return 0;
}