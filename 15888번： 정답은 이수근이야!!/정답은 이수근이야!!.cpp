#include <iostream>
#include <cmath>

using namespace std;

bool isPowerOfTwo(int x)
{
    if (x < 2)
        return false;
    while (x % 2 == 0)
        x /= 2;
    return x == 1;
}

int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    int D = B * B - 4 * A * C;

    if (D <= 0)
    {
        cout << "둘다틀렸근";
        return 0;
    }

    int sqrtD = (int)sqrt(D);

    if (sqrtD * sqrtD != D)
    {
        cout << "둘다틀렸근";
        return 0;
    }

    int denom = 2 * A;

    if ((-B + sqrtD) % denom != 0 || (-B - sqrtD) % denom != 0)
    {
        cout << "둘다틀렸근";
        return 0;
    }

    int root1 = (-B + sqrtD) / denom;
    int root2 = (-B - sqrtD) / denom;

    if (isPowerOfTwo(root1) && isPowerOfTwo(root2))
    {
        cout << "이수근";
    }
    else
    {
        cout << "정수근";
    }

    return 0;
}