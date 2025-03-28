#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    if (n == 1)
    {
        if (k == 0)
        {
            std::cout << "YES\n.\n";
        }
        else
        {
            std::cout << "NO\n";
        }

        return 0;
    }

    if (n == 2)
    {
        int maxCells = 1;
        if (k > maxCells)
        {
            std::cout << "NO\n";
            return 0;
        }
        std::vector<std::string> grid(2, std::string(2, '.'));
        if (k == 1)
            grid[0][0] = '#';
        std::cout << "YES\n"
                  << grid[0] << "\n"
                  << grid[1] << "\n";
        return 0;
    }

    int maxCells = n * (n - 1);
    if (k > maxCells)
    {
        std::cout << "NO\n";
        return 0;
    }

    std::vector<int> perm(n);

    for (int i = 0; i < n; i++)
        perm[i] = i;

    if (n % 2 == 0)
    {
        std::swap(perm[0], perm[n - 1]);
    }

    std::vector<std::string> grid(n, std::string(n, '#'));
    for (int i = 0; i < n; i++)
    {
        grid[i][perm[i]] = '.';
    }

    int current = maxCells;

    for (int i = 0; i < n && current > k; i++)
    {
        for (int j = 0; j < n && current > k; j++)
        {
            if (grid[i][j] == '#')
            {
                grid[i][j] = '.';
                current--;
            }
        }
    }

    std::cout << "YES\n";
    for (auto &s : grid)
        std::cout << s << "\n";
    return 0;
}