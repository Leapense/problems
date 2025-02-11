#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 충분히 작은 음의 무한대 값 (문제에 따라 조정)
const long long NEG_INF = -1LL << 60;

// 세그먼트 트리: 구간 [l, r) 내 최댓값을 O(log n)에 구할 수 있음.
struct SegTree
{
    int size;
    vector<long long> tree;

    SegTree(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        tree.assign(2 * size, NEG_INF);
    }

    // pos는 0-indexed, value와 기존 값을 비교하여 최대값 갱신
    void update(int pos, long long value)
    {
        pos += size;
        tree[pos] = max(tree[pos], value);
        for (pos /= 2; pos >= 1; pos /= 2)
        {
            tree[pos] = max(tree[2 * pos], tree[2 * pos + 1]);
        }
    }

    // query: 구간 [l, r) 내 최댓값 반환 (0-indexed)
    long long query(int l, int r)
    {
        long long res = NEG_INF;
        l += size;
        r += size;
        while (l < r)
        {
            if (l & 1)
                res = max(res, tree[l++]);
            if (r & 1)
                res = max(res, tree[--r]);
            l /= 2;
            r /= 2;
        }
        return res;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<long long> wines(N);
    for (int i = 0; i < N; i++)
    {
        cin >> wines[i];
    }

    // dp 배열: j=1일 때, dp[i] = wines[i]
    vector<long long> dp_prev = wines;

    // 좌표 압축: wines의 모든 맛을 정렬하여 중복 제거
    vector<long long> comp = wines;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    int compSize = comp.size();

    // j=2 부터 K까지 DP 전이
    for (int step = 2; step <= K; step++)
    {
        // 두 세그먼트 트리 생성
        SegTree seg1(compSize), seg2(compSize);
        vector<long long> dp_curr(N, NEG_INF);
        int p = 0; // 아직 세그먼트 트리에 업데이트하지 않은 인덱스
        for (int i = 0; i < N; i++)
        {
            // i보다 작은 인덱스들을 세그먼트 트리에 업데이트
            while (p < i)
            {
                int pos = (int)(lower_bound(comp.begin(), comp.end(), wines[p]) - comp.begin());
                seg1.update(pos, dp_prev[p] - wines[p]);
                seg2.update(pos, dp_prev[p]);
                p++;
            }
            int pos = (int)(lower_bound(comp.begin(), comp.end(), wines[i]) - comp.begin());
            // case 1: 이전 맛이 wines[p] < wines[i] 인 경우
            long long candidate1 = wines[i] + seg1.query(0, pos); // [0, pos)
            // case 2: 이전 맛이 wines[p] >= wines[i] 인 경우
            long long candidate2 = seg2.query(pos, compSize); // [pos, compSize)
            dp_curr[i] = max(candidate1, candidate2);
        }
        dp_prev = dp_curr;
    }

    // 최종 답: dp_prev[i] (즉, K번째 선택으로 끝난 경우)들 중 최대값
    long long answer = NEG_INF;
    for (int i = 0; i < N; i++)
    {
        answer = max(answer, dp_prev[i]);
    }
    cout << answer << "\n";
    return 0;
}
