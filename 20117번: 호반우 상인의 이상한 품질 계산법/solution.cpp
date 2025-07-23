#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    if (!(std::cin >> n)) {
        return 0;
    }

    std::vector<int> a(n);
    for (int &v : a) {
        std::cin >> v;
    }

    std::sort(a.begin(), a.end());

    long long revenue = 0;
    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        revenue += 2LL * a[j];
        ++i;
        --j;
    }
    if (i == j)
    {
        revenue += a[i];
    }

    std::cout << revenue << '\n';
    return 0;
}