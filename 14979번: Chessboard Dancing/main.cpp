#include <iostream>
using namespace std;

int main()
{
    int S;
    char type;

    while (cin >> S >> type)
    {
        int ans = 0;
        if (type == 'K')
        {
            ans = (S == 1 ? 1 : 4);
        }
        else if (type == 'N')
        {
            ans = (S <= 2 ? 1 : 2);
        }
        else if (type == 'B')
        {
            ans = (S == 1 ? 1 : S);
        }
        else if (type == 'R')
        {
            ans = S;
        }

        cout << ans << "\n";
    }

    return 0;
}