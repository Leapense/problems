#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> alice(n);
    set<int> aliceSet;

    for (int i = 0; i < n; ++i)
    {
        cin >> alice[i];
        aliceSet.insert(alice[i]);
    }

    vector<int> bob;
    for (int card = 1; card <= 2 * n; ++card)
    {
        if (aliceSet.find(card) == aliceSet.end())
        {
            bob.push_back(card);
        }
    }

    sort(alice.begin(), alice.end());
    sort(bob.begin(), bob.end());

    int aliceWinsMax = 0;
    int j = 0;
    for (int i = 0; i < n && j < n; ++i)
    {
        if (alice[j] > bob[i])
        {
            aliceWinsMax++;
            j++;
        }
        else
        {
            while (j < n && alice[j] <= bob[i])
            {
                j++;
            }
            if (j < n)
            {
                aliceWinsMax++;
                j++;
            }
        }
    }

    int bobWinsMax = 0;
    j = 0;
    for (int i = 0; i < n && j < n; ++i)
    {
        if (bob[j] > alice[i])
        {
            bobWinsMax++;
            j++;
        }
        else
        {
            while (j < n && bob[j] <= alice[i])
            {
                j++;
            }

            if (j < n)
            {
                bobWinsMax++;
                j++;
            }
        }
    }

    int aliceWinsMin = n - bobWinsMax;

    cout << aliceWinsMin << " " << aliceWinsMax << "\n";

    return 0;
}