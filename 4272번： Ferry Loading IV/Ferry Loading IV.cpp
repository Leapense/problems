#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, m;
        cin >> l >> m;
        l *= 100;
        queue<int> left, right;

        for (int i = 0; i < m; i++)
        {
            int len;
            string bank;
            cin >> len >> bank;
            if (bank == "left")
            {
                left.push(len);
            }
            else
            {
                right.push(len);
            }
        }

        int trips = 0;
        int current = 0;

        while (!left.empty() || !right.empty())
        {
            int load = 0;
            if (current == 0)
            {
                while (!left.empty() && load + left.front() <= l)
                {
                    load += left.front();
                    left.pop();
                }
            }
            else
            {
                while (!right.empty() && load + right.front() <= l)
                {
                    load += right.front();
                    right.pop();
                }
            }
            trips++;
            current = 1 - current;
        }

        cout << trips << endl;
    }

    return 0;
}