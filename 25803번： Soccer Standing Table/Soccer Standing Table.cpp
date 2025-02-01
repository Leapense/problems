#include <bits/stdc++.h>
using namespace std;

class Solve
{
public:
    void run()
    {
        vector<int> v(5);
        for (int i = 0; i < 5; i++)
            cin >> v[i];
        sort(v.begin(), v.end());

        do
        {
            int MP = v[0], W = v[1], D = v[2], L = v[3], Pts = v[4];
            if (MP == W + D + L && Pts == 3 * W + D)
            {
                cout << MP << " " << W << " " << D << " " << L << " " << Pts << endl;
                break;
            }
        } while (next_permutation(v.begin(), v.end()));
    }
};

int main()
{
    Solve s;
    s.run();
    return 0;
}