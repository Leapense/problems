#include <iostream>
#include <set>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int A, B;
        cin >> A >> B;
        int count = 0;
        int digits = 0;
        int temp = A;
        while (temp)
        {
            digits++;
            temp /= 10;
        }
        int p = 1;
        for (int i = 1; i < digits; i++)
        {
            p *= 10;
        }
        for (int n = A; n <= B; n++)
        {
            set<int> seen;
            int x = n;
            for (int i = 0; i < digits - 1; i++)
            {
                int last = x % 10;
                x = x / 10 + last * p;
                if (x > n && x <= B)
                {
                    seen.insert(x);
                }
            }
            count += seen.size();
        }
        cout << "Case #" << t << ": " << count << "\n";
    }
    return 0;
}