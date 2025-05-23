#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<unsigned int> prefix(N + 1, 0);
    for (int i = 1; i <= N; ++i)
    {
        unsigned int value;
        cin >> value;
        prefix[i] = prefix[i - 1] ^ value;
    }

    unsigned int result = 0;
    for (int i = 0; i < Q; ++i)
    {
        int s, e;
        cin >> s >> e;

        unsigned int queryXor = prefix[e] ^ prefix[s - 1];
        result ^= queryXor;
    }

    cout << result << "\n";

    return 0;
}