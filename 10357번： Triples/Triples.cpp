#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    cin >> m >> n;

    long long trival = (long long)(n - 1) * (m + 1);
    long long pythagorean = 0;
    for (int x = 1; x <= m; x++)
    {
        for (int y = x; y <= m; y++)
        {
            int sum = x * x + y * y;
            int z = static_cast<int>(sqrt(sum));
            if (z * z == sum && z >= y && z <= m)
                pythagorean++;
        }
    }

    cout << trival + pythagorean << "\n";

    return 0;
}