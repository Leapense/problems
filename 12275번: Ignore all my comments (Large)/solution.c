#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t cap = 8192;
    size_t len = 0;
    char *input = malloc(cap);
    if(input == NULL) {
        return 1;
    }

    int ch;
    while ((ch = getchar()) != EOF) {
        if (len + 1 >= cap) {
            cap *= 2;
            char *tmp = realloc(input, cap);
            if (tmp == NULL) {
                free(input);
                return 1;
            }
            input = tmp;
        }
        input[len++] = (char)ch;
    }
    input[len] = '\0';

    char *output = malloc(len + 16);
    if (output == NULL) {
        free(input);
        return 1;
    }

    const char *prefix = "Case #1:\n";
    size_t out_pos = 0;

    for (const char *p = prefix; *p != '\0'; ++p) {
        output[out_pos++] = *p;
    }

    int depth = 0;
    for (size_t i = 0; i < len; ) {
        if (i + 1 < len && input[i] == '/' && input[i + 1] == '*') {
            depth++;
            i += 2;
        } else if (i + 1 < len && input[i] == '*' && input[i + 1] == '/' && depth > 0) {
            depth--;
            i += 2;
        } else {
            if (depth == 0) {
                output[out_pos++] = input[i];
            }
            i++;
        }
    }

    output[out_pos] = '\0';
    fputs(output, stdout);
    free(input);
    free(output);
    return 0;
}
