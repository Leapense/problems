#ifndef MAIN_H
#define MAIN_H

#include <string>
#include <vector>

namespace HillCipher
{
    constexpr int MOD = 37;

    inline int charToInt(char c)
    {
        if (c >= 'A' && c <= 'Z')
            return c - 'A';
        if (c >= '0' && c <= '9')
            return 26 + (c - '0');
        return 36;
    }

    inline char intToChar(int num)
    {
        if (num >= 0 && num <= 25)
            return 'A' + num;
        if (num >= 26 && num <= 35)
            return '0' + (num - 26);
        return ' ';
    }

    inline std::string encrypt(const std::vector<std::vector<int>> &matrix, const std::string &plaintext)
    {
        int n = matrix.size();
        std::vector<int> nums;

        for (char c : plaintext)
        {
            nums.push_back(charToInt(c));
        }

        while (nums.size() % n != 0)
        {
            nums.push_back(36);
        }

        std::string ciphertext;

        for (size_t i = 0; i < nums.size(); i += n)
        {
            std::vector<int> result(n, 0);

            for (int row = 0; row < n; ++row)
            {
                long long sum = 0;

                for (int col = 0; col < n; ++col)
                {
                    sum += static_cast<long long>(matrix[row][col]) * nums[i + col];
                }

                result[row] = sum % MOD;
                if (result[row] < 0)
                    result[row] += MOD;
            }
            for (int val : result)
            {
                ciphertext.push_back(intToChar(val));
            }
        }

        return ciphertext;
    }
}
#endif