#include <iostream>

int main() {
    int x, y, d;
    std::cin >> x >> y;
    std::cin >> d;

    // Преобразуваме обиколката в сантиметри
    int P_cm = 100 * x + y;

    // Намираме по-малката страна b в сантиметри
    int b = (P_cm - 2 * d) / 4;

    // Намираме по-голямата страна a в сантиметри
    int a = b + d;

    // Преобразуваме в метри и сантиметри
    int a_meters = a / 100;
    int a_centimeters = a % 100;
    int b_meters = b / 100;
    int b_centimeters = b % 100;

    // Извеждаме резултата
    std::cout << a_meters << " " << a_centimeters << std::endl;
    std::cout << b_meters << " " << b_centimeters << std::endl;

    return 0;
}