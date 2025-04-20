#include <bits/stdc++.h>
using namespace std;

vector<string> simpleSolitaire(const vector<string> &deck)
{
    struct Card
    {
        char r, s;
    };
    vector<Card> pile;
    pile.reserve(52);

    for (auto &code : deck)
    {
        pile.push_back({code[0], code[1]});
        bool removed;
        do
        {
            removed = false;
            // rank-match removals
            for (int i = int(pile.size()) - 1; i >= 3; --i)
            {
                if (pile[i].r == pile[i - 3].r)
                {
                    pile.erase(pile.begin() + (i - 3), pile.begin() + (i + 1));
                    removed = true;
                    break;
                }
            }
            if (removed)
                continue;
            // suit-match removals
            for (int i = int(pile.size()) - 1; i >= 3; --i)
            {
                if (pile[i].s == pile[i - 3].s)
                {
                    pile.erase(pile.begin() + i);
                    pile.erase(pile.begin() + (i - 3));
                    removed = true;
                    break;
                }
            }
        } while (removed);
    }

    vector<string> result;
    result.reserve(pile.size());
    for (auto &c : pile)
    {
        result.push_back(string{c.r, c.s});
    }
    return result;
}

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> deck(52);
    for (int i = 0; i < 52; i++)
        cin >> deck[i];

    auto survivors = simpleSolitaire(deck);
    cout << survivors.size();
    for (auto &code : survivors)
    {
        cout << ' ' << code;
    }
    cout << "\n";
    return 0;
}
#endif