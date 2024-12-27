#include <bits/stdc++.h>
using namespace std;

int P, C;
int S[10];
vector<vector<int>> subsets;
int bestAns;

void backtrack(int idx, int current, int sLeft[]) {
    if (idx == (int)subsets.size()) {
        bestAns = max(bestAns, current);
        return;
    }
    int sumLeft = 0;
    for (int i = 0; i < P; i++) sumLeft += sLeft[i];
    if (current + sumLeft / C <= bestAns) return;
    int mn = INT_MAX;
    for (int i : subsets[idx]) mn = min(mn, sLeft[i]);
    for (int x = mn; x >= 0; x--) {
        for (int i : subsets[idx]) sLeft[i] -= x;
        backtrack(idx + 1, current + x, sLeft);
        for (int i : subsets[idx]) sLeft[i] += x;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for(int tc=1; tc<=T; tc++){
        cin >> P >> C;
        for(int i=0; i<P; i++) cin >> S[i];
        subsets.clear();
        for(int mask=0; mask<(1<<P); mask++){
            int c = __builtin_popcount(mask);
            if(c == C) {
                vector<int> sub;
                for(int i=0; i<P; i++){
                    if(mask & (1<<i)) sub.push_back(i);
                }
                subsets.push_back(sub);
            }
        }
        bestAns = 0;
        backtrack(0, 0, S);
        cout << "Case #" << tc << ": " << bestAns << "\n";
    }
    return 0;
}