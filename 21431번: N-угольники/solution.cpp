#include <iostream>
#include <vector>

int main()
{
    int n;
    long long k;
    if (!(std::cin >> n >> k)) {
        return 0;
    }
    int d = n - 1;
    std::vector<long long> a;
    for (int i = 0; i < d; i++) {
        a.push_back(1);
    }
    while(true) {
        long long sum = 0;
        for (size_t i = a.size() - d; i < a.size(); i++) {
            sum += a[i];
        }
        if (sum > k) {
            break;
        }
        a.push_back(sum);
    }
    std::cout << a.size() << "\n";
    for (size_t i = 0; i < a.size(); i++) {
        std::cout << a[i];
        if (i + 1 < a.size()) {
            std::cout << " ";
        }
    }

    std::cout << "\n";
    return 0;
}