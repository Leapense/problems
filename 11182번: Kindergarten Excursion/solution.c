#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>

#define MAX_LEN 1000005U

int main(void)
{
    static char buffer[MAX_LEN];
    if (scanf("%1000004s", buffer) != 1) {
        return EXIT_FAILURE;
    }

    uint64_t countOnes = 0U;
    uint64_t countTwos = 0U;
    uint64_t inversionCount = 0U;

    for (size_t i = 0U; buffer[i] != '\0'; ++i) {
        char ch = buffer[i];
        if (ch == '0') {
            inversionCount += countOnes;
            inversionCount += countTwos;
        } else if (ch == '1') {
            inversionCount += countTwos;
            ++countOnes;
        } else if (ch == '2') {
            ++countTwos;
        } else {

        }
    }

    printf("%" PRIu64 "\n", inversionCount);
    return EXIT_SUCCESS;
}