#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> prefix(N + 1, 0);
    int totalYes = 0;

    for (int i = 1; i <= N; i++) {
        int X, Y;
        cin >> X >> Y;

        bool voteYes = false;
        if (Y == 0) {
            voteYes = true;
        } else if (Y == X + 1) {
            voteYes = false;
        } else {
            int leftIndex = i - X - 1;
            int countYes = prefix[i - 1] - (leftIndex >= 0 ? prefix[leftIndex] : 0);
            voteYes = (countYes >= Y);
        }

        totalYes += voteYes ? 1 : 0;
        prefix[i] = totalYes;
    }

    cout << totalYes << "\n";
    return 0;
}
