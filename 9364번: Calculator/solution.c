#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h> // C23에서는 <bool.h>로 변경될 수 있으나, stdbool.h가 널리 쓰임


typedef struct {
    long long coefficient;
    int exponent;
} TermC;

static TermC parse_term_c(const char* term_str_start, const char* term_str_end);
static long long power_c(int base, int exp);

TermC parse_term_c(const char* term_str_start, const char* term_str_end) {
    long long c = 0;
    int e = 0;
    int sign = 1;
    const char* p = term_str_start;

    if (p >= term_str_end) {
        return (TermC){0LL, 0};
    }

    if (*p == '+') {
        p++;
    } else if (*p == '-') {
        sign = -1;
        p++;
    }

    if (p < term_str_end && *p == 'X') {
        c = 1; // Handles "X", "X^E"
    } else if (p < term_str_end && isdigit((unsigned char)*p)) {
        char* end_ptr = NULL;
        c = strtoll(p, &end_ptr, 10);
        p = end_ptr;
    } else {
        if (p >= term_str_end && (term_str_start[0] == '+' || term_str_start[0] == '-')) {
        }
    }
    c *= sign;

    if (p < term_str_end && *p == 'X') {
        p++; 
        e = 1; 
        if (p < term_str_end && *p == '^') {
            p++; 
            if (p < term_str_end && isdigit((unsigned char)*p)) {
                char* end_ptr = NULL;
                e = (int)strtol(p, &end_ptr, 10);
                // p = end_ptr; // p는 더 이상 사용 안 함
            }
        }
    } else {
        e = 0; // No 'X', so it's a constant term
    }
    return (TermC){c, e};
}

long long power_c(int base, int exp) {
    if (exp == 0) {
        return 1LL;
    }
    if (base == 0) { // 0 to power of (positive exp) is 0
        return 0LL;
    }

    long long result = 1LL;
    long long b_ll = base; // Use long long for base in multiplication
    for (int i = 0; i < exp; ++i) {
        result *= b_ll;
    }
    return result;
}
int main(void) {
    int t;
    if (scanf("%d", &t) != 1) return 1; // Basic error check

    for (int i = 1; i <= t; ++i) {
        int x_val;
        if (scanf("%d", &x_val) != 1) return 1;

        char polynomial_str[256]; // Assuming max length for polynomial string
        if (scanf("%s", polynomial_str) != 1) return 1;

        int total_evaluation = 0;
        const char* ptr = polynomial_str;
        const char* term_start = ptr;

        while (*ptr != '\0') {
            ptr++; 
            if (*ptr == '+' || *ptr == '-' || *ptr == '\0') {
                TermC current_term = parse_term_c(term_start, ptr);
                long long x_pow_e_val = power_c(x_val, current_term.exponent);
                long long c_val_ll = current_term.coefficient;
                long long current_term_value_ll = c_val_ll * x_pow_e_val;
                total_evaluation += (int)current_term_value_ll;
                term_start = ptr;
            }
        }
        printf("Case #%d: %d\n", i, total_evaluation);
    }
    return 0;
}