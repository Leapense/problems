#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n, c;
    cin >> n >> c;

    vector<tuple<int, char, char>> clues;
    for (int i = 0; i < c; i++)
    {
        int type;
        char x, y;
        cin >> type >> x >> y;
        clues.push_back(make_tuple(type, x, y));
    }

    vector<char> acts;
    for (int i = 0; i < n; i++)
    {
        acts.push_back('A' + i);
    }

    int validOrders = 0;

    do
    {
        bool valid = true;

        vector<int> pos(26, -1);
        for (int i = 0; i < n; i++)
        {
            pos[acts[i] - 'A'] = i;
        }

        for (auto &clue : clues)
        {
            int type;
            char x, y;
            tie(type, x, y) = clue;
            int pos_x = pos[x - 'A'];
            int pos_y = pos[y - 'A'];

            if (type == 1)
            {
                if (pos_x >= pos_y)
                {
                    valid = false;
                    break;
                }
            }
            else if (type == 2)
            {
                if (pos_x <= pos_y)
                {
                    valid = false;
                    break;
                }
            }
            else if (type == 3)
            {
                if (abs(pos_x - pos_y) == 1)
                {
                    valid = false;
                    break;
                }
            }
        }

        if (valid)
        {
            validOrders++;
        }
    } while (next_permutation(acts.begin(), acts.end()));

    cout << validOrders << endl;
    return 0;
}