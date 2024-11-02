#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    int m, a, b;
    cin >> m; // m: 1부터 m까지 정수를 표시할 수 있는 카운터
    cin >> a; // a: 현재 카운터의 숫자
    cin >> b; // b: 목표하는 숫자

    int cnt = 0; // a를 b로 바꾸기 위해 눌러야 하는 버튼의 수

    // 카운터의 버튼을 누르면 수가 1씩 증가하며, m을 넘어서면 1로 돌아간다.
    while (a != b) {
        a++;
        if (a > m) a = 1;
        cnt++;
    }

    cout << cnt << "\n";
    return 0;
}