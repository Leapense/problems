#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;

    std::vector<long long> distances(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> distances[i];
    }

    long long total_energy = 0;
    int left = 0;

    for (int i = n - 1; i >= left; --i)
    {
        if (distances[i] > 0)
        {
            total_energy += distances[i];
        }

        int j = i - 1;

        while (j >= left && distances[j] >= 1 && distances[j] >= distances[i] - (i - j))
        {
            distances[j] = std::max(0LL, distances[j] - 1);
            j--;
        }

        while (left < n && distances[left] == 0)
        {
            left++;
        }
    }

    std::cout << total_energy << std::endl;

    return 0;
}