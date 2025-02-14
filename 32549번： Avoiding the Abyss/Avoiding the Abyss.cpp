#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x_s, y_s, x_t, y_t, x_p, y_p;
    cin >> x_s >> y_s;
    cin >> x_t >> y_t;
    cin >> x_p >> y_p;

    const int M = 1000000000; // 안전한 극한 좌표

    // 시작점의 안전 출구 A 결정
    int A_x, A_y;
    if (x_s != x_p)
    {
        if (x_s < x_p)
            A_x = -M;
        else
            A_x = M;
        A_y = y_s;
    }
    else
    {
        A_x = x_s;
        if (y_s < y_p)
            A_y = -M;
        else
            A_y = M;
    }

    // 도착점의 안전 입구 B 결정
    int B_x, B_y;
    if (x_t != x_p)
    {
        if (x_t < x_p)
            B_x = -M;
        else
            B_x = M;
        B_y = y_t;
    }
    else
    {
        B_x = x_t;
        if (y_t < y_p)
            B_y = -M;
        else
            B_y = M;
    }

    // 교차점 C: A의 x좌표와 B의 y좌표
    int C_x = A_x, C_y = B_y;

    // 중간 점은 A, C, B 총 3개
    cout << 3 << "\n";
    cout << A_x << " " << A_y << "\n";
    cout << C_x << " " << C_y << "\n";
    cout << B_x << " " << B_y << "\n";

    return 0;
}