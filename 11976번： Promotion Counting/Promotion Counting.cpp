#include <iostream>
using namespace std;

int division[4][2], ans[3];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    for (int i = 0; i < 4; i++)
    {
        cin >> division[i][0] >> division[i][1];
    }

    for (int i = 4; i >= 1; i--)
    {
        ans[i-1] = division[i][1] - division[i][0];
        division[i-1][0] -= ans[i-1];
    }

    for(int i = 0; i < 3; i++)
    {
        cout << ans[i] << "\n";
    }

    return 0;
}