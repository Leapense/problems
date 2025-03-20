#include <cstdio>
#include <cctype>
#include <cstring>

void fastscan(int &number)
{
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if (c == '-')
    {
        negative = true;
        c = getchar();
    }

    for (; (c > 47 && c < 58); c = getchar())
    {
        number = number * 10 + c - 48;
    }
    if (negative)
        number *= -1;
}

struct Rule
{
    const char *pattern;
    char replacement;
};

int main()
{
    int n;
    fastscan(n);

    Rule rules[] = {
        {"at", '@'},
        {"and", '&'},
        {"one", '1'},
        {"won", '1'},
        {"to", '2'},
        {"too", '2'},
        {"two", '2'},
        {"for", '4'},
        {"four", '4'},
        {"bea", 'b'},
        {"be", 'b'},
        {"bee", 'b'},
        {"sea", 'c'},
        {"see", 'c'},
        {"eye", 'i'},
        {"oh", 'o'},
        {"owe", 'o'},
        {"are", 'r'},
        {"you", 'u'},
        {"why", 'y'}};

    const int numRules = sizeof(rules) / sizeof(rules[0]);

    char line[205];
    char output[500];

    for (int lineIndex = 0; lineIndex < n; ++lineIndex)
    {
        if (fgets(line, sizeof(line), stdin) == nullptr)
        {
            break;
        }

        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n')
        {
            line[len - 1] = '\0';
            --len;
        }

        int outIdx = 0;
        for (int i = 0; i < len;)
        {
            int bestLen = 0;
            char bestReplacement = '\0';
            for (int r = 0; r < numRules; r++)
            {
                int patLen = strlen(rules[r].pattern);
                if (i + patLen <= len)
                {
                    bool match = true;
                    for (int k = 0; k < patLen; k++)
                    {
                        if (tolower(line[i + k]) != rules[r].pattern[k])
                        {
                            match = false;
                            break;
                        }
                    }

                    if (match && patLen > bestLen)
                    {
                        bestLen = patLen;
                        bestReplacement = rules[r].replacement;
                    }
                }
            }

            if (bestLen > 0)
            {
                if (isupper(line[i]) && isalpha(bestReplacement))
                {
                    bestReplacement = toupper(bestReplacement);
                }

                output[outIdx++] = bestReplacement;
                i += bestLen;
            }
            else
            {
                output[outIdx++] = line[i++];
            }
        }

        output[outIdx] = '\0';
        puts(output);
    }

    return 0;
}