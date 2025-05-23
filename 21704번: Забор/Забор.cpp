#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

struct Segment
{
    ll l, r;
};

/**
 * @brief Finds the minimum total cost of painting all segments.
 *
 * The function takes a vector of segments and an integer k as input.
 * The segments are sorted in descending order of r, and then the function
 * iterates over the segments and calculates the minimum total cost of
 * painting all segments. The cost is calculated as the sum of the cost of
 * painting each segment, which is 2 * (number of segments in the group *
 * r of the segment + number of segments in the group * cum + k *
 * (sum of g from gmin to gmax)), where gmin and gmax are the minimum and
 * maximum group numbers that include the segment, and cum is the cumulative
 * sum of the segment lengths.
 *
 * @param n the number of segments
 * @param k the number of segments in a group
 * @param segments the vector of segments
 *
 * @return the minimum total cost of painting all segments
 */
ll solve(ll n, int k, const vector<Segment> &segments)
{
    // segments를 r값 기준 내림차순 정렬 (즉, 가장 멀리 있는 판부터)
    vector<Segment> seg = segments;
    sort(seg.begin(), seg.end(), [](const Segment &a, const Segment &b)
         { return a.r > b.r; });

    ll ans = 0;
    ll cum = 0; // 지금까지 처리한(내림차순 순서상의) 칠해야 하는 판 개수

    // 각 구간별로 이 구간에서 몇 개의 그룹(페인트 한 통으로 처리하는 묶음)이 처리되는지 계산
    for (const auto &s : seg)
    {
        ll L = s.r - s.l + 1; // 이 구간의 판 개수
        // 이 구간은 내림차순 순서상 [cum+1, cum+L]번째 판에 해당함.
        // 각 그룹은 target = 1 + g*k (g>=0) 번째 판을 기준으로 한다.
        // 이 구간에 포함되는 그룹 g는
        //    cum+1 <= 1 + g*k <= cum+L  <=>  g*k ∈ [cum, cum+L-1]
        // 따라서 gmin = ceil(cum/k), gmax = floor((cum+L-1)/k)
        ll gmin = (cum + k - 1) / k;
        ll gmax = (cum + L - 1) / k;
        if (gmin > gmax)
        {
            cum += L;
            continue;
        }
        ll count = gmax - gmin + 1;
        // 각 그룹 g에 대해, 선택되는 판의 번호는
        //   pos = s.r - ( (1 + g*k) - cum - 1 ) = s.r - (g*k - cum)
        // 왕복 이동 비용은 2 * pos
        // 따라서 이 구간의 총 비용은
        //   2 * [ count * s.r + count * cum - k * (sum_{g=gmin}^{gmax} g) ]
        ll sumg = (gmin + gmax) * count / 2;
        ans += 2 * (count * s.r + count * cum - k * sumg);
        cum += L;
    }
    return ans;
}

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    int k;
    cin >> n >> k;
    int m;
    cin >> m;
    vector<Segment> segments(m);
    for (int i = 0; i < m; i++)
    {
        cin >> segments[i].l >> segments[i].r;
    }
    cout << solve(n, k, segments);
    return 0;
}
#endif
