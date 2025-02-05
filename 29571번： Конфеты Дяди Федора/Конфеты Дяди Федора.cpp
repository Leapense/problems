#include <iostream>
#include <set>

using namespace std;

long long pyramid_candies(int h)
{
    if (h < 0)
        return 0;
    return (long long)h * (h + 1) * (h + 2) / 6;
}

int main()
{
    int n;
    cin >> n;

    if (n == 0)
    {
        cout << "YES" << endl;
        return 0;
    }

    set<int> possible_sums;
    for (int h = 2; h <= 2000; ++h)
    {
        for (int r = 1; r < h; ++r)
        {
            long long sum = pyramid_candies(h) - pyramid_candies(r);
            if (sum <= 1000000000)
            {
                possible_sums.insert(sum);
            }
            else
            {
                break; // Sum will only increase for larger r or h, so no need to continue for this h.
            }
        }
    }

    if (possible_sums.count(n))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}