#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> restrictions(M);
    for (auto &[a, b] : restrictions)
    {
        cin >> a >> b;
        --a;
        --b;
    }

    int total = 0;

    for (int mask = 0; mask < (1 << N); ++mask)
    {
        bool valid = true;
        for (const auto &[a, b] : restrictions)
        {
            if ((mask & (1 << a)) && (mask & (1 << b)))
            {
                valid = false;
                break;
            }
        }

        total += valid;
    }

    cout << total << "\n";

    return 0;
}