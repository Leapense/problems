#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

class StringCombinations
{
private:
    std::string X, Y, Z;
    int k;
    std::set<std::string> result;

    void generateCombinations(const std::string &s, int index, std::string current, std::set<std::string> &combinations)
    {
        if (current.size() == k)
        {
            combinations.insert(current);
            return;
        }
        for (int i = index; i < s.size(); i++)
        {
            generateCombinations(s, i + 1, current + s[i], combinations);
        }
    }

public:
    StringCombinations(const std::string &x, const std::string &y, const std::string &z, int k_val) : X(x), Y(y), Z(z), k(k_val) {}

    void findCommonCombinations()
    {
        std::set<std::string> cx, cy, cz;
        generateCombinations(X, 0, "", cx);
        generateCombinations(Y, 0, "", cy);
        generateCombinations(Z, 0, "", cz);

        std::set<std::string> all;
        std::set<std::string> duplicates;

        for (const auto &str : cx)
        {
            if (!all.insert(str).second)
                duplicates.insert(str);
        }

        for (const auto &str : cy)
        {
            if (!all.insert(str).second)
                duplicates.insert(str);
        }

        for (const auto &str : cz)
        {
            if (!all.insert(str).second)
                duplicates.insert(str);
        }

        std::vector<std::string> sorted_result(duplicates.begin(), duplicates.end());
        std::sort(sorted_result.begin(), sorted_result.end());

        if (sorted_result.empty())
        {
            std::cout << "-1\n";
        }
        else
        {
            for (const auto &str : sorted_result)
            {
                std::cout << str << "\n";
            }
        }
    }
};

int main()
{
    std::string X, Y, Z;
    int k;
    std::cin >> X >> Y >> Z >> k;
    StringCombinations sc(X, Y, Z, k);
    sc.findCommonCombinations();
    return 0;
}