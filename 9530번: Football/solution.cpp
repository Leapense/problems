#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::sort;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long G;
    cin >> N >> G;

    int winCount = 0;
    int drawCount = 0;
    vector<int> deficits;
    deficits.reserve(N);

    for (int i = 0; i < N; ++i) {
        int S, R;
        cin >> S >> R;
        if (S > R) {
            ++winCount;
        } else if (S == R) {
            ++drawCount;
        } else {
            deficits.push_back(R - S);
        }
    }

    long long points = static_cast<long long>(winCount) * 3 + drawCount;

    long long convertDraws = std::min<long long>(G, drawCount);
    G -= convertDraws;
    points += convertDraws * 2;

    sort(deficits.begin(), deficits.end());

    for (int d : deficits) {
        if (G <= 0) {
            break;
        }

        if (G >= d + 1) {
            G -= d + 1;
            points += 3;
        } else if (G >= d) {
            G -= d;
            points += 1;
        } else {
            break;
        }
    }

    cout << points << "\n";
    return 0;
}