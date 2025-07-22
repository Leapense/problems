#include <iostream>

using namespace std;

int main()
{
    long long parrots;
    long long monkeys;

    if (!(cin >> parrots >> monkeys)) {
        return 0;
    }

    const long long minParrots = parrots / (monkeys + static_cast<long long>(1));
    const long long maxParrots = parrots / monkeys;
    cout << minParrots << '\n' << maxParrots << '\n';
    return 0;
}