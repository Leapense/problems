#include <iostream>
#include <algorithm>

using namespace std;

const int MAXLINES = 100;
int n;
char t[MAXLINES][2 * MAXLINES];

int largest()
{
    int i, j, h[2 * MAXLINES], best;

    best = 0;
    /* down facing */
    for (i = 0; i < 2 * n - 1; i += 2)
        if (t[0][i] == '-')
            h[i] = best = 1;
        else
            h[i] = 0;
    for (i = 1; i < n; i++)
        for (j = 0; j < 2 * (n - i) - 1; j += 2)
            if (t[i][j] == '-')
            {
                if (t[i - 1][j + 1] == '-')
                    h[j] = 1 + min(h[j], h[j + 2]);
                else
                    h[j] = 1;
                if (h[j] > best)
                    best = h[j];
            }
            else
                h[j] = 0;
    /* up facing */
    for (i = n - 2; i >= 0; i--)
    {
        for (j = 2 * (n - i) - 3; j >= 1; j -= 2)
            if (t[i][j] == '-')
            {
                if (t[i + 1][j - 1] == '-' && j > 1 && j < (2 * (n - i) - 3))
                    h[j] = 1 + min(h[j - 2], h[j]);
                else
                    h[j] = 1;
                if (h[j] > best)
                    best = h[j];
            }
            else
                h[j] = 0;
    }
    return best * best;
}

int main()
{
    int i, caseno = 1;

    while (cin >> n && n != 0)
    {
        for (i = 0; i < n; i++)
            cin >> t[i];
        cout << "Triangle #" << caseno++ << endl;
        cout << "The largest triangle area is " << largest() << "." << endl << endl;
    }
    return 0;
}