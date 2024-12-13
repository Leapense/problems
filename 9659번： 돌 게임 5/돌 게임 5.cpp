#include <iostream>

int main()
{
    long long n;
    std::cin >> n;

    if (n % 2 == 0 && n % 4 != 0) {
        std::cout << "CY" << std::endl;
    } else {
        std::cout << "SK" << std::endl;
    }

    return 0;
}