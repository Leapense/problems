#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    int T, X, Y;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        cin >> X >> Y;
        string result = "";

        if (X > 0)
        {
            for (int i = 0; i < X; i++)
            {
                result += "WE";
            }
        }
        else
        {
            for (int i = 0; i < abs(X); i++)
            {
                result += "EW";
            }
        }
        if (Y > 0)
        {
            for (int i = 0; i < Y; i++)
            {
                result += "SN";
            }
        }
        else
        {
            for (int i = 0; i < abs(Y); i++)
            {
                result += "NS";
            }
        }
        cout << "Case #" << t << ": " << result;
        if (t < T)
            cout << "\n";
    }

    return 0;
}