#include <iostream>
#include <set>
#include <vector>

class CardMultiplier
{
private:
    int n;
    std::set<int> results;
    std::vector<int> numbers;

    void generateProducts(int depth, int product)
    {
        if (depth == n)
        {
            results.insert(product);
            return;
        }

        for (int num : numbers)
        {
            generateProducts(depth + 1, product * num);
        }
    }

public:
    CardMultiplier(int num) : n(num), numbers({1, 2, 3, 4, 5, 6, 7, 8, 9}) {}

    int countUniqueProducts()
    {
        generateProducts(0, 1);
        return results.size();
    }
};

int main()
{
    int n;
    std::cin >> n;
    CardMultiplier solver(n);

    std::cout << solver.countUniqueProducts() << std::endl;

    return 0;
}