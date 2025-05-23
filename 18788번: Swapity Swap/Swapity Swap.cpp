#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long K;
    int A1, A2, B1, B2;

    cin >> N >> K >> A1 >> A2 >> B1 >> B2;

    vector<int> cows(N);
    for (int i = 0; i < N; i++)
    {
        cows[i] = i + 1;
    }

    vector<vector<int>> seen;
    seen.push_back(cows);

    while (true)
    {
        reverse(cows.begin() + A1 - 1, cows.begin() + A2);
        reverse(cows.begin() + B1 - 1, cows.begin() + B2);
        if (cows == seen[0])
            break;
        seen.push_back(cows);
    }

    int cycle = seen.size();

    K %= cycle;
    vector<int> result = seen[K];
    for (auto r : result)
        cout << r << "\n";
    return 0;
}