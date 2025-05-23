#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // 빠른 입출력 설정
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long k;
    cin >> n >> k;

    // 비용 배열 입력 (long long 사용)
    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    vector<long long> b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }

    // N=0인 경우는 문제 제약 조건상 없지만, 방어적으로 처리 (N>=1)
    if (n == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    // DP 상태 변수 초기화 (이전 단계의 최소 비용)
    long long prev_drag_cost = a[0];  // 0번 구간을 끌었을 때 비용
    long long prev_carry_cost = b[0]; // 0번 구간을 들었을 때 비용

    // DP 계산 (1번 구간부터 N-1번 구간까지)
    for (int i = 1; i < n; ++i)
    {
        // 현재 i번 구간까지의 최소 비용 계산
        long long current_drag_cost = min(prev_drag_cost + a[i], prev_carry_cost + k + a[i]);
        long long current_carry_cost = min(prev_carry_cost + b[i], prev_drag_cost + k + b[i]);

        // 다음 계산을 위해 상태 업데이트
        prev_drag_cost = current_drag_cost;
        prev_carry_cost = current_carry_cost;
    }

    // 최종 결과 출력 (마지막 구간에서 끌거나 든 경우 중 최소값)
    cout << min(prev_drag_cost, prev_carry_cost) << endl;

    return 0;
}