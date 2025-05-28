#include <stdio.h>
#include <string.h>

static void swapChars(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

static void reverseSuffix(char *s, int start, int end)
{
    while (start < end)
    {
        swapChars(&s[start], &s[end]);
        ++start;
        --end;
    }
}

static int computeNext(char *s)
{
    int length = (int)strlen(s);
    int pivot = length - 2;

    while (pivot >= 0 && s[pivot] >= s[pivot + 1]) --pivot;
    if (pivot < 0) {
        return 0;
    }

    int successor = length - 1;
    while (s[successor] <= s[pivot])
    {
        --successor;
    }

    swapChars(&s[pivot], &s[successor]);

    reverseSuffix(s, pivot + 1, length - 1);
    return 1;
}

int main(void)
{
    int testCount = 0;
    if (scanf("%d", &testCount) != 1) {
        return 1;
    }
    for (int t = 0; t < testCount; ++t) {
        char word[101] = {0};
        if (scanf("%100s", word) != 1) {
            break;
        }
        if (!computeNext(word)) {

        }
        printf("%s\n", word);
    }

    return 0;
}