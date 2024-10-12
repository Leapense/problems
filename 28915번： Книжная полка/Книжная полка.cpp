#include <iostream>
#include <cmath>

int main()
{
    double h, r, t;
    std::cin >> h >> r;

    int f = int(sqrt(h * h * 0.75));
    
    std::cout << ((int(r) % f) ? 1 : 0) + int(r) / f - 1 << std::endl;

    return 0;
}