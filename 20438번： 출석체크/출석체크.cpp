#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K, Q, M;
    cin >> N >> K >> Q >> M;

    int total = N + 3;

    vector<bool> sleeping(total, false);
    vector<bool> attended(total, false);

    for (int i = 0; i < K; i++)
    {
        int x;
        cin >> x;
        sleeping[x] = true;
    }

    for (int i = 0; i < Q; i++)
    {
        int x;
        cin >> x;

        if (!sleeping[x])
        {
            attended[x] = true;
        }
    }

    for (int i = 3; i <= N + 2; i++)
    {
        if (attended[i] && !sleeping[i])
        {
            for (int j = 2 * i; j <= N + 2; j += i)
            {
                if (!sleeping[j])
                {
                    attended[j] = true;
                }
            }
        }
    }

    vector<int> prefix(total, 0);
    for (int i = 3; i <= N + 2; i++)
    {
        prefix[i] = prefix[i - 1] + (attended[i] ? 0 : 1);
    }

    while (M--)
    {
        int S, E;
        cin >> S >> E;

        cout << prefix[E] - prefix[S - 1] << "\n";
    }

    return 0;
}