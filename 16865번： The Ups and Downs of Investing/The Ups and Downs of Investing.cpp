#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int s, n, m;

    cin >> s >> n >> m;

    vector<int> prices(s);
    for (int i = 0; i < s; ++i) {
        cin >> prices[i];
    }

    vector<int> inc_before(s, 1), dec_before(s, 1);

    for (int i = 1; i < s; ++i) {
        if (prices[i] > prices[i - 1]) {
            inc_before[i] = inc_before[i - 1] + 1;
        } else {
            inc_before[i] = 1;
        }

        if (prices[i] < prices[i - 1]) {
            dec_before[i] = dec_before[i - 1] + 1;
        } else {
            dec_before[i] = 1;
        }
    }

    vector<int> inc_after(s, 1), dec_after(s, 1);
    for (int i = s - 2; i >= 0; --i) {
        if (prices[i] < prices[i + 1]) {
            inc_after[i] = inc_after[i + 1] + 1;
        } else {
            inc_after[i] = 1;
        }

        if (prices[i] > prices[i + 1]) {
            dec_after[i] = dec_after[i + 1] + 1;
        } else {
            dec_after[i] = 1;
        }
    }

    int peaks = 0, valleys = 0;
    for (int i = 0; i < s; ++i) {
        if (inc_before[i] >= n and dec_after[i] >= n) {
            peaks++;
        }
        if (dec_before[i] >= m and inc_after[i] >= m) {
            valleys++;
        }
    }
    cout << peaks << " " << valleys << "\n";
    return 0;
}