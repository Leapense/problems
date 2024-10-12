#include <bits/stdc++.h>

using namespace std;

int main()
{
    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;

        vector<int> heights(N);
        for (int i = 0; i < N; i++) {
            cin >> heights[i];
        }

        sort(heights.begin(), heights.end(), greater<int>());

        multiset<int> stacks;

        for (int height : heights) {
            auto it = stacks.upper_bound(height);
            if (it != stacks.end()) {
                stacks.erase(it);
            }
            stacks.insert(height);
        }
        cout << stacks.size() << "\n";
    }

    return 0;
}