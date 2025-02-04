#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    // 막대기가 7개 미만이면 직사각형을 구성할 수 없음
    if (n < 7)
    {
        cout << 0;
        return 0;
    }

    // 전체 막대기의 길이 합
    long long total = n * (n + 1) / 2;

    int r = n % 4;
    if (r == 0 || r == 3)
        cout << total; // 전체 집합 사용 가능
    else
        cout << total - 1; // 막대기 1 제거하여 사용

    return 0;
}
