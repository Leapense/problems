#include <iostream>
#include <vector>

using namespace std;

int a, b, k;
vector<int> remainders;
int total_whole_strips;

bool dfs(int pos, int m, vector<int>& bin_sums) {
    if (pos == remainders.size()) {
        // 모든 남은 길이를 처리했을 때, 각 그룹의 합이 k 이하인지 확인
        for (int sum : bin_sums) {
            if (sum > k)
                return false;
        }
        return true;
    }
    // 남은 길이를 m개의 그룹에 할당하는 모든 가능한 방법을 시도
    for (int i = 0; i < m; ++i) {
        bin_sums[i] += remainders[pos];
        if (bin_sums[i] <= k) {
            if (dfs(pos + 1, m, bin_sums))
                return true;
        }
        bin_sums[i] -= remainders[pos];
    }
    return false;
}

int main() {
    cin >> a >> b >> k;

    vector<int> sides = {a, b, a, b};
    total_whole_strips = 0;

    for (int len : sides) {
        int whole = len / k;
        int rem = len % k;
        total_whole_strips += whole;
        if (rem > 0)
            remainders.push_back(rem);
    }

    int n = remainders.size();
    int min_cut_strips = n; // 최대 잘린 리본의 수는 남은 길이의 수

    for (int m = 1; m <= n; ++m) { // m은 잘린 리본의 수
        vector<int> bin_sums(m, 0);
        if (dfs(0, m, bin_sums)) {
            min_cut_strips = m;
            break;
        }
    }

    int total_strips = total_whole_strips + min_cut_strips;
    cout << total_strips << endl;

    return 0;
}