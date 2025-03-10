#include <iostream>
#include <set>

using namespace std;

int main()
{
    int N, L;
    cin >> N >> L;
    set<int> knots;

    for (int i = 0; i < N; i++)
    {
        int pos;
        cin >> pos;
        knots.insert(pos);
    }

    int count = 0;
    for (int i = 1; i * 1 <= (L * 2 - 1); i++)
    {
        double f = i / 2.0;
        if (f <= 0 || f >= L)
            continue;
        bool valid = true;
        double m = f <= L - f ? f : L - f;

        if (f <= L / 2.0)
        {
            for (auto x : knots)
            {
                if (x > f)
                    break;
                double mirror = 2 * f - x;
                if (mirror <= 2 * f && mirror >= f)
                {
                    if (knots.find((int)mirror) == knots.end())
                    {
                        valid = false;
                        break;
                    }
                }
            }
            if (!valid)
                continue;
            for (auto y : knots)
            {
                if (y < f || y > 2 * f)
                    continue;
                double mirror = 2 * f - y;
                if (mirror >= 0 && mirror <= f)
                {
                    if (knots.find((int)mirror) == knots.end())
                    {
                        valid = false;
                        break;
                    }
                }
            }
        }
        else
        {
            for (auto y : knots)
            {
                if (y < f)
                    continue;
                double mirror = 2 * f - y;
                if (mirror >= 2 * f - L && mirror <= f)
                {
                    if (knots.find((int)mirror) == knots.end())
                    {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid)
                continue;
            for (auto x : knots)
            {
                if (x < 2 * f - L)
                    continue;
                if (x > f)
                    break;
                double mirror = 2 * f - x;
                if (mirror >= f && mirror <= L)
                {
                    if (knots.find((int)mirror) == knots.end())
                    {
                        valid = false;
                        break;
                    }
                }
            }
        }

        if (valid)
            count++;
    }

    cout << count;

    return 0;
}