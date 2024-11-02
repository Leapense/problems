//=====================================================================
//   28619번:    Производство роботов                   
//   @date:   2024-11-02              
//   @link:   https://www.acmicpc.net/problem/28619  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin >> n;

    vector<long long> a(n);
    long long base_t = 0;

    vector<vector<int>> buckets(100);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        base_t += a[i] / 100;
        long long r = a[i] % 100;
        buckets[r].push_back(i + 1);
    }

    long long t = base_t;

    vector<pair<int, int>> pairs;

    int l = 0, r = 99;

    while (l < r) {
        while (l < r && buckets[l].empty()) l++;
        while (l < r && buckets[r].empty()) r--;
        if (l >= r) break;
        if (l + r >= 100) {
            long long min_count = min((long long)buckets[l].size(), (long long) buckets[r].size());
            for (int i = 0; i < min_count; i++) {
                pairs.emplace_back(make_pair(buckets[l].back(), buckets[r].back()));
                buckets[l].pop_back();
                buckets[r].pop_back();
            }

            t += min_count;
        } else {
            l++;
        }
    }

    for (int r_val = 0; r_val < 100; r_val++) {
        if (r_val * 2 >= 100) {
            while (buckets[r_val].size() >= 2) {
                int x = buckets[r_val].back(); buckets[r_val].pop_back();
                int y = buckets[r_val].back(); buckets[r_val].pop_back();
                pairs.emplace_back(make_pair(x, y));
                t += 1;
            }
        }
    }

    cout << t << "\n";
    cout << pairs.size() << "\n";
    for (auto &[x,y]: pairs) {
        cout << x << " " << y << "\n";
    }

    return 0;
}