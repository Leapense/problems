#include <iostream>
#include <string>
#include <algorithm>

class TypoFixer
{
public:
    TypoFixer(const std::string &s1, const std::string &s2) : S1(s1), S2(s2) {}

    int minKeyPresses()
    {
        int commonLength = longestCommonSuffixPrefix();
        int deleteCount = S1.size() - commonLength;
        int addCount = S2.size() - commonLength;
        return deleteCount + addCount;
    }

private:
    std::string S1, S2;

    int longestCommonSuffixPrefix()
    {
        int len = std::min(S1.size(), S2.size());
        int i = 0;
        while (i < len && S1[i] == S2[i])
        {
            i++;
        }

        return i;
    }
};

int main()
{
    std::string s1, s2;
    std::cin >> s1 >> s2;
    TypoFixer fixer(s1, s2);
    std::cout << fixer.minKeyPresses() << std::endl;

    return 0;
}