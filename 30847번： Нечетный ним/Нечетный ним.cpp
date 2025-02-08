#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    // 홀수 돌 더미의 개수를 센다.
    int oddCount = 0;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        if (a % 2 == 1)
            oddCount++;
    }

    // [일반 님]
    // 미샤(첫 번째 플레이어)는 홀수 돌 더미의 개수가 홀수일 때 승리
    if (oddCount % 2 == 1)
        cout << "Misha" << "\n";
    else
        cout << "Gleb" << "\n";

    // [미저 님]
    // 미샤는 홀수 돌 더미의 개수가 짝수일 때 승리
    if (oddCount % 2 == 0)
        cout << "Misha" << "\n";
    else
        cout << "Gleb" << "\n";

    return 0;
}