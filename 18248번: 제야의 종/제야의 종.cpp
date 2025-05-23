#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<bitset<128>> v(N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int a;
            cin >> a;
            if (a)
                v[i].set(j);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            bitset<128> diff1 = v[i] & ~v[j];
            bitset<128> diff2 = v[j] & ~v[i];
            if (diff1.any() && diff2.any())
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}