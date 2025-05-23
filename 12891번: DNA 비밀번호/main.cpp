#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int s, p;
    cin >> s >> p;
    string dna;
    cin >> dna;

    int req[4];
    for (int i = 0; i < 4; i++)
    {
        cin >> req[i];
    }

    int cnt[4] = {0, 0, 0, 0};
    auto idx = [&](char ch) -> int
    {
        if (ch == 'A')
            return 0;
        if (ch == 'C')
            return 1;
        if (ch == 'G')
            return 2;
        return 3;
    };

    for (int i = 0; i < p; i++)
    {
        cnt[idx(dna[i])]++;
    }

    int ans = 0;
    bool valid = true;

    for (int i = 0; i < 4; i++)
    {
        if (cnt[i] < req[i])
        {
            valid = false;
            break;
        }
    }
    if (valid)
        ans++;

    for (int i = p; i < s; i++)
    {
        cnt[idx(dna[i])]++;
        cnt[idx(dna[i - p])]--;
        valid = true;
        for (int j = 0; j < 4; j++)
        {
            if (cnt[j] < req[j])
            {
                valid = false;
                break;
            }
        }

        if (valid)
            ans++;
    }

    cout << ans << "\n";
    return 0;
}