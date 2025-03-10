#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, v, d, t;
    cin >> n >> v >> d >> t;
    vector<int> speed(n, 0);
    vector<int> pos(n, 0);

    for (int i = 0; i < n; i++)
    {
        pos[i] = -i * d;
    }
    speed[0] = v;
    bool collision = false;

    for (int interval = 0; interval < t; interval++)
    {
        for (int i = 0; i < n; i++)
        {
            pos[i] += speed[i] * 5;
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (pos[i] - pos[i + 1] <= 0)
            {
                collision = true;
                break;
            }
        }

        if (collision)
            break;
        vector<int> newSpeed = speed;
        int gap = pos[0] - pos[1];
        if (gap < 80)
            newSpeed[0] = speed[0] + 5;
        else if (gap > 100)
            newSpeed[0] = max(speed[0] - 5, 0);
        for (int i = 1; i < n; i++)
        {
            gap = pos[i - 1] - pos[i];
            if (gap < 80)
                newSpeed[i] = max(speed[i] - 5, 0);
            else if (gap > 100)
                newSpeed[i] = speed[i] + 5;
        }
        speed = newSpeed;
    }

    cout << (collision ? -1 : pos[0]);
    return 0;
}