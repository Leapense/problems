#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int FJ[3], master[3];
    for (int i = 0; i < 3; i++)
        cin >> FJ[i];
    for (int i = 0; i < 3; i++)
        cin >> master[i];
    auto closeEnough = [&](int a, int b) -> bool
    {
        int diff = abs(a - b);
        if (diff > N - diff)
            diff = N - diff;
        return diff <= 2;
    };
    int count = 0;
    for (int a = 1; a <= N; a++)
    {
        for (int b = 1; b <= N; b++)
        {
            for (int c = 1; c <= N; c++)
            {
                bool validFJ = closeEnough(a, FJ[0]) && closeEnough(b, FJ[1]) && closeEnough(c, FJ[2]);
                bool validMaster = closeEnough(a, master[0]) && closeEnough(b, master[1]) && closeEnough(c, master[2]);
                if (validFJ || validMaster)
                    count++;
            }
        }
    }
    cout << count << "\n";
    return 0;
}