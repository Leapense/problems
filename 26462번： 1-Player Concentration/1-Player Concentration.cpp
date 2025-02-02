#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;

    vector<vector<int>> cards(H, vector<int>(W));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> cards[i][j];
        }
    }

    vector<pair<int, int>> order;

    for (int i = 0; i < H; i++)
    {
        if ((i + 1) % 2 == 1)
        {
            for (int j = 0; j < W; j++)
            {
                order.push_back({i, j});
            }
        }
        else
        {
            for (int j = W - 1; j >= 0; j--)
            {
                order.push_back({i, j});
            }
        }
    }
    sort(order.begin(), order.end(), [&](auto &a, auto &b)
         {
        if (a.first != b.first) return a.first < b.first;
        if ((a.first + 1) % 2 == 1) return a.second < b.second;
        return a.second > b.second; });

    vector<vector<bool>> removed(H, vector<bool>(W, false));
    vector<int> knownCount((H * W) / 2 + 1, 0);
    vector<pair<int, int>> knownPos((H * W) / 2 + 1, {-1, -1});

    int totalRemoved = 0;
    int turns = 0;
    int idx = 0;

    auto removePair = [&](int num)
    {
        auto p1 = knownPos[num];
        if (p1.first < 0)
            return false;
        if (removed[p1.first][p1.second])
            return false;
        int countNum = 0;

        for (int r = 0; r < H; r++)
        {
            for (int c = 0; c < W; c++)
            {
                if (!removed[r][c] && cards[r][c] == num)
                {
                    countNum++;
                }
            }
        }

        if (countNum < 2)
            return false;
        int foundCount = 0;
        pair<int, int> posA, posB;

        for (int r = 0; r < H; r++)
        {
            for (int c = 0; c < W; c++)
            {
                if (!removed[r][c] && cards[r][c] == num)
                {
                    if (foundCount == 0)
                        posA = {r, c};
                    else
                        posB = {r, c};
                    foundCount++;
                    if (foundCount == 2)
                        break;
                }
            }

            if (foundCount == 2)
                break;
        }

        removed[posA.first][posA.second] = true;
        removed[posB.first][posB.second] = true;

        totalRemoved += 2;
        knownCount[num] = 0;
        knownPos[num] = {-1, -1};
        turns++;
        return true;
    };

    while (totalRemoved < H * W)
    {
        bool done = false;
        for (int num = 1; num <= (H * W) / 2; num++)
        {
            if (knownCount[num] == 2)
            {
                if (removePair(num))
                {
                    done = true;
                    break;
                }
            }
        }

        if (done)
            continue;

        int firstCardIndex = -1;
        while (firstCardIndex < 0 && idx < (int)order.size())
        {
            auto [r, c] = order[idx++];
            if (!removed[r][c])
            {
                firstCardIndex = (idx - 1);
            }
        }

        if (firstCardIndex < 0)
        {
            for (int num = 1; num <= (H * W) / 2; num++)
            {
                if (knownCount[num] == 2)
                {
                    if (removePair(num))
                    {
                        done = true;
                        break;
                    }
                }
            }
            if (!done)
                turns++;
            continue;
        }

        auto [r1, c1] = order[firstCardIndex];
        int x = cards[r1][c1];
        if (knownCount[x] == 1)
        {
            int pr = knownPos[x].first;
            int pc = knownPos[x].second;
            removed[r1][c1] = true;
            removed[pr][pc] = true;
            totalRemoved += 2;
            knownCount[x] = 0;
            knownPos[x] = {-1, -1};
            turns++;
        }
        else
        {
            if (knownCount[x] == 0)
            {
                knownCount[x] = 1;
                knownPos[x] = {r1, c1};
            }

            int secondCardIndex = -1;
            while (secondCardIndex < 0 && idx < (int)order.size())
            {
                auto [r, c] = order[idx++];
                if (!removed[r][c])
                {
                    secondCardIndex = (idx - 1);
                }
            }

            if (secondCardIndex < 0)
            {
                turns++;
                continue;
            }

            auto [r2, c2] = order[secondCardIndex];
            int y = cards[r2][c2];

            if (x == y)
            {
                removed[r1][c1] = true;
                removed[r2][c2] = true;
                totalRemoved += 2;
                knownCount[x] = 0;
                knownPos[x] = {-1, -1};
            }
            else
            {
                if (knownCount[y] == 0)
                {
                    knownCount[y] = 1;
                    knownPos[y] = {r2, c2};
                }
                else if (knownCount[y] == 1)
                {
                    int pr = knownPos[y].first;
                    int pc = knownPos[y].second;
                    if (!removed[pr][pc])
                    {
                        knownCount[y] = 2;
                    }
                }
            }
            turns++;
        }
    }

    cout << turns << "\n";
    return 0;
}