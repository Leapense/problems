#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int r, c;
        cin >> r >> c;

        int x = r - 1, y = c - 1;
        int nim = x ^ y;

        if (nim == 0)
        {
            cout << "dohoon\n";
        }
        else
        {
            cout << "jinseo\n";

            int new_r = r, new_c = c;

            if ((x ^ nim) < x)
            {
                new_r = (x ^ nim) + 1;
            }
            else
            {
                new_c = (y ^ nim) + 1;
            }

            cout << new_r << " " << new_c << "\n";
        }
    }

    return 0;
}