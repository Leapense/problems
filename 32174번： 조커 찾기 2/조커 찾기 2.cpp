#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int *pos = new int[M + 1];
    pos[0] = 0;

    for (int i = 1; i <= M; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            ll x;
            cin >> x;
            int delta = (int)(x % N);
            pos[i] = (pos[i - 1] + delta) % N;
        }
        else if (op == 2)
        {
            ll y;
            cin >> y;
            int delta = (int)(y % N);
            pos[i] = ((pos[i - 1] - delta) % N + N) % N;
        }
        else if (op == 3)
        {
            int z;
            cin >> z;
            pos[i] = pos[z];
        }

        cout << pos[M] + 1 << "\n";

        delete[] pos;
        return 0;
    }
}