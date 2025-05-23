#include <iostream>
#include <vector>
#include <unordered_map>
#include <ios>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--)
    {
        int n;
        unsigned int x;

        std::cin >> n >> x;

        std::vector<unsigned int> v(n);
        std::unordered_map<unsigned int, int> freq;

        long long count = 0;

        for (int i = 0; i < n; ++i)
        {
            std::cin >> v[i];

            unsigned int target = x ^ v[i];

            auto it = freq.find(target);
            if (it != freq.end())
            {
                count += it->second;
            }

            freq[v[i]]++;
        }

        std::cout << count << "\n";
    }

    return 0;
}