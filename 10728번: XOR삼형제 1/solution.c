#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

static const int POW2_LIST[] = {1, 2, 4, 8, 16, 32, 64};
static const int POW2_COUNT = sizeof(POW2_LIST) / sizeof(POW2_LIST[0]);

static int find_highest_power_index(int n)
{
    int left = 0;
    int right = POW2_COUNT - 1;
    int bestIndex = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (POW2_LIST[mid] <= n)
        {
            bestIndex = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return bestIndex;
}

int main(void)
{
    int testCaseCount = 0;

    if (scanf("%d", &testCaseCount) != 1) {
        return EXIT_FAILURE;
    }

    for (int tc = 0; tc < testCaseCount; ++tc) {
        int n = 0;
        if (scanf("%d", &n) != 1) {
            return EXIT_FAILURE;
        }

        if (n == 1) {
            printf("1\n1\n");
            continue;
        }
        
        if (n == 2) {
            printf("2\n1 2\n");
            continue;
        }

        int idxBig = find_highest_power_index(n);
        int idxSmall = idxBig - 1;

        int bitBig = POW2_LIST[idxBig];
        int bitSmall = POW2_LIST[idxSmall];

        int forbiddenValue = bitBig | bitSmall;

        int maxAllowed = (n < (forbiddenValue - 1) ? n : (forbiddenValue - 1));
        int minAllowed = bitSmall;

        int resultLength = maxAllowed - minAllowed + 1;
        if (resultLength < 0) {
            resultLength = 0;
        }

        printf("%d\n", resultLength);

        for (int val = minAllowed; val <= maxAllowed; ++val) {
            if (val == maxAllowed) {
                printf("%d\n", val);
            } else {
                printf("%d ", val);
            }
        }
    }

    return EXIT_SUCCESS;
}