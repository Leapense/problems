#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        long long x;
        cin >> x;
        vector<long long> leftPan, rightPan;

        if (x == 0)
        {
            cout << "left pan:\n";
            cout << "right pan:\n\n";
            continue;
        }

        long long num = x;
        int power = 0;
        while (num != 0)
        {
            int rem = num % 3;
            num /= 3;
            if (rem == 2)
            {
                rem = -1;
                num++;
            }
            if (rem == 1)
            {
                rightPan.push_back((long long)pow(3, power));
            }
            else if (rem == -1)
            {
                leftPan.push_back((long long)pow(3, power));
            }
            power++;
        }

        sort(leftPan.rbegin(), leftPan.rend());
        sort(rightPan.rbegin(), rightPan.rend());
        cout << "left pan:";

        if (!leftPan.empty())
        {
            cout << " ";
            for (size_t i = 0; i < leftPan.size(); i++)
            {
                cout << leftPan[i];
                if (i != leftPan.size() - 1)
                    cout << " ";
            }
        }

        cout << "\n";
        cout << "right pan:";
        if (!rightPan.empty())
        {
            cout << " ";
            for (size_t i = 0; i < rightPan.size(); i++)
            {
                cout << rightPan[i];
                if (i != rightPan.size() - 1)
                    cout << " ";
            }
        }

        cout << "\n\n";
    }

    return 0;
}