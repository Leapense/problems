#include <iostream>
#include <iomanip>
#include <cmath>

double calculateFuel(double D, double tankCapacity) {
    if (D <= 100.0 * tankCapacity) {
        // 연료를 운반할 필요가 없음
        return D / 100.0;
    } else {
        // 추가 연료를 운반해야 함
        double extraFuelNeeded = D / 100.0 - tankCapacity;
        // 연료를 운반하는 데 소비되는 연료 계산
        double fuelSpentCarrying = extraFuelNeeded * 2;
        return D / 100.0 + fuelSpentCarrying;
    }
}

int main() {
    double A;
    std::cin >> A;

    double left = 0.0, right = 200.0; // 최대 이동 거리는 200km를 넘지 않음
    double mid, fuelNeeded;
    double epsilon = 1e-8;

    while (right - left > epsilon) {
        mid = (left + right) / 2.0;
        fuelNeeded = calculateFuel(mid, 1.0);
        if (fuelNeeded <= A) {
            left = mid;
        } else {
            right = mid;
        }
    }

    std::cout << std::fixed << std::setprecision(10) << left << std::endl;

    return 0;
}
