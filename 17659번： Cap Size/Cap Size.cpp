#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;

    for (int ds = 1; ds <= K; ds++)
    {
        int n, t;
        cin >> n >> t;

        vector<int> sizes(n);
        for (int i = 0; i < n; i++)
        {
            cin >> sizes[i];
        }

        int lb = -1, ub = 1001;

        bool inconsistent = false;
        int perfectFit = -1;

        for (int i = 0; i < t; i++)
        {
            int capSize, feedback;
            cin >> capSize >> feedback;
            if (feedback == 1)
            {
                lb = max(lb, capSize);
                if (perfectFit != -1 && perfectFit <= capSize)
                {
                    inconsistent = true;
                }
            }
            else if (feedback == -1)
            {
                ub = min(ub, capSize);
                if (perfectFit != -1 && perfectFit >= capSize)
                {
                    inconsistent = true;
                }
            }
            else if (feedback == 0)
            {
                if (perfectFit == -1)
                {
                    perfectFit = capSize;
                }
                else if (perfectFit != capSize)
                {
                    inconsistent = true;
                }
            }
        }

        if (perfectFit != -1)
        {
            if (perfectFit <= lb || perfectFit >= ub)
            {
                inconsistent = true;
            }
        }
        else
        {
            if (lb >= ub)
            {
                inconsistent = true;
            }
        }

        cout << "Data Set " << ds << ":\n";

        if (inconsistent)
        {
            cout << "Inconsistent feedback\n\n";
        }
        else
        {
            if (perfectFit != -1)
            {
                cout << "1\n\n";
            }
            else
            {
                auto lower_it = std::upper_bound(sizes.begin(), sizes.end(), lb);
                auto upper_it = std::lower_bound(sizes.begin(), sizes.end(), ub);

                int count = distance(lower_it, upper_it);
                cout << count << "\n\n";
            }
        }
    }

    return 0;
}