#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        int N;
        cin >> N;
        vector<int> pancakes(N);
        for (int i = 0; i < N; i++)
        {
            cin >> pancakes[i];
        }

        int left = 0, right = N - 1;
        int countPay = 0;
        int currentMax = 0;

        while (left <= right)
        {
            if (pancakes[left] <= pancakes[right]) {
                if (pancakes[left] >= currentMax) {
                    currentMax = pancakes[left];
                    countPay++;
                }
                left++;
            } else {
                if (pancakes[right] >= currentMax) {
                    currentMax = pancakes[right];
                    countPay++;
                }
                right--;
            }
        }

        cout << "Case #" << t << ": " << countPay << "\n";
    }
    return 0;
}
