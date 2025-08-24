#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

uint64_t factorial[27];

void computeFactorials(void) {
    factorial[0] = 1;
    for (int i = 1; i <= 26; i++) {
        factorial[i] = factorial[i - 1] * i;
    }
}

uint64_t getLexicographicRank(const char* word, int n) {
    uint64_t rank = 0;
    int used[26] = {0};

    for (int i = 0; i < n; i++) {
        int currentChar = word[i] - 'a';
        int smallerCount = 0;
        for (int j = 0; j < currentChar; j++) {
            if (!used[j]) {
                smallerCount++;
            }
        }
        rank += smallerCount * factorial[n - i - 1];
        used[currentChar] = 1;
    }
    return rank;
}

int main(void)
{
    int n;
    char wordA[27], wordB[27];

    scanf("%d", &n);
    scanf("%s", wordA);
    scanf("%s", wordB);

    computeFactorials();
    uint64_t rankA = getLexicographicRank(wordA, n);
    uint64_t rankB = getLexicographicRank(wordB, n);

    uint64_t distance = (rankA > rankB) ? (rankA - rankB) : (rankB - rankA);
    printf("%llu\n", (unsigned long long)distance);

    return 0;
}