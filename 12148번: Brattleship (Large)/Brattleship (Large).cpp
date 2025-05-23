#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        int R, C, W;
        cin >> R >> C >> W;

        int base = R * (C / W);
        int extra = (C % W == 0) ? (W - 1) : W;
        cout << "Case #" << t << ": " << base + extra << "\n";
    }

    return 0;
}