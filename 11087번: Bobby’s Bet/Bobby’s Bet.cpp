#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    while (N--)
    {
        int R, S, X, Y, W;
        cin >> R >> S >> X >> Y >> W;
        double p = double(S - R + 1) / S;
        double winProb = 0.0;
        for (int k = X; k <= Y; k++)
        {
            double comb = 1.0;
            for (int i = 1; i <= k; i++)
            {
                comb *= double(Y - i + 1) / i;
            }

            winProb += comb * pow(p, k) * pow(1 - p, Y - k);
        }

        cout << (winProb * W > 1.0 ? "yes" : "no") << "\n";
    }

    return 0;
}