#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
int total;
long long dp[50][50][50];
bool visited[50][50][50];

vector<int> pills;

bool isAllowed(int mealIndex, int pillType) {
    int time = mealIndex % 3;
    if (time == 0 || time == 2) return (pillType == 0 || pillType == 2);
    return (pillType == 1);
}

long long solveDP(int l, int r, int i) {
    if (i == total) return 1;
    if (visited[l][r][i]) return dp[l][r][i];
    
    long long ways = 0;
    if (l == r) {
        if (isAllowed(i, pills[l])) {
            ways = solveDP(l + 1, r, i + 1);
        }
    } else {
        if (isAllowed(i, pills[l])) {
            ways += solveDP(l, r - 1, i + 1);
        }
    }

    dp[l][r][i] = ways;
    visited[l][r][i] = true;

    return ways;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    total = 3 * N;
    pills.resize(total);

    for (int i = 0; i < N; i++) {
        pills[3 * i] = 0;
        pills[3 * i + 1] = 1;
        pills[3 * i + 2] = 2;
    }

    cout << solveDP(0, total - 1, 0) << "\n";
    return 0;
}
