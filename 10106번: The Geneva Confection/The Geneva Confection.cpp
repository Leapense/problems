#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;

    while (T--) 
    {
        int N;
        cin >> N;
        vector<int> cars(N);
        for (int &x : cars) cin >> x;
        int expected = 1;

        vector<int> stack;
        for (int i = N - 1; i >= 0; i--) {
            if (cars[i] == expected) {
                expected++;
                while(!stack.empty() && stack.back() == expected) {
                    stack.pop_back();
                    expected++;
                }
            }
            else
            {
                stack.push_back(cars[i]);
            }
        }
        while(!stack.empty() && stack.back() == expected) {
            stack.pop_back();
            expected++;
        }

        if (expected == N + 1) cout << "Y\n";
        else cout << "N\n";
    }

    return 0;
}