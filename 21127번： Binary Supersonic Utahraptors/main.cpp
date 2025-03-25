#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    int countYellowAlexey = 0;

    for (int i = 0; i < n; i++)
    {
        int color;
        cin >> color;
        if (color == 0)
            countYellowAlexey++;
    }

    int countRedBoris = 0;

    for (int i = 0; i < m; i++)
    {
        int color;
        cin >> color;
        if (color == 1)
            countRedBoris++;
    }

    for (int i = 0; i < k; i++)
    {
        int s;
        cin >> s;
    }

    int score = abs(countYellowAlexey - countRedBoris);
    cout << score << "\n";

    return 0;
}