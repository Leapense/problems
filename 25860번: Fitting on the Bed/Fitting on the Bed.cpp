#include <iostream>
#include <cmath>
#include <numbers>

using namespace std;

constexpr double eps = 1e-9;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L, W, H;
    cin >> L >> W >> H;

    int x, y, a;
    cin >> x >> y >> a;

    double rad = a * std::numbers::pi / 180.0;

    double tailX = x + H * cos(rad);
    double tailY = y + H * sin(rad);

    if (tailX >= -eps && tailX <= W + eps && tailY >= -eps && tailY <= L + eps) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}