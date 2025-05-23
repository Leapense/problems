#include <iostream>
#include <vector>
#include <string>
#include "main.h"

using namespace std;

#ifndef UNIT_TESTS
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];

    // 남은 줄바꿈 처리 후 평문 읽기
    cin.ignore();
    std::string plaintext;
    getline(cin, plaintext);

    std::string ciphertext = HillCipher::encrypt(matrix, plaintext);
    cout << ciphertext << "\n";

    return 0;
}
#endif