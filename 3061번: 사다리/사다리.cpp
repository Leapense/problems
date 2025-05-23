#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;
        vector<int> ladder(N);
        for (int i = 0; i < N; i++)
        {
            cin >> ladder[i];
        }

        long long inversions = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (ladder[i] > ladder[j])
                {
                    inversions++;
                }
            }
        }

        cout << inversions << "\n";
    }

    return 0;
}