#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cstdlib>
#include <charconv>

struct Term {
    long long coefficient{0};
    int exponent{0};
};

static Term parse_term_cpp(const std::string& term_s);
static long long power_cpp(int base, int exp);

Term parse_term_cpp(const std::string& term_s) {
    if (term_s.empty()) return {0LL, 0};
    long long c = 0;
    int e = 0;
    size_t current_pos = 0;
    int sign = 1;

    if (term_s[current_pos] == '+') {
        current_pos++;
    } else if (term_s[current_pos] == '-') {
        sign = -1;
        current_pos++;
    }

    if (current_pos < term_s.length() && term_s[current_pos] == 'X') {
        c = 1;
    } else if (current_pos < term_s.length() && std::isdigit(static_cast<unsigned char>(term_s[current_pos]))) {
        size_t coeff_start = current_pos;
        while (current_pos < term_s.length() && std::isdigit(static_cast<unsigned char>(term_s[current_pos]))) {
            current_pos++;
        }

        c = std::stoll(term_s.substr(coeff_start, current_pos - coeff_start));
    } else {
        if (current_pos >= term_s.length() && (term_s[0] == '+' || term_s[0] == '-')) {

        }
    }
    c *= sign;

    if (current_pos < term_s.length() && term_s[current_pos] == 'X') {
        current_pos++; // Consume 'X'
        e = 1;        // Default exponent for X is 1
        if (current_pos < term_s.length() && term_s[current_pos] == '^') {
            current_pos++; // Consume '^'
            if (current_pos < term_s.length() && std::isdigit(static_cast<unsigned char>(term_s[current_pos]))) {
                size_t exp_start = current_pos;
                while (current_pos < term_s.length() && std::isdigit(static_cast<unsigned char>(term_s[current_pos]))) {
                    current_pos++;
                }
                e = std::stoi(term_s.substr(exp_start, current_pos - exp_start));
            }
        }
    } else {
        // No 'X' found after coefficient part, so it's a constant term
        e = 0;
    }

    return {c, e};
}

long long power_cpp(int base, int exp) {
    if (exp == 0) return 1LL;
    if (base == 0) return 0LL;

    long long result = 1LL;
    long long b_ll = base;
    for (int i = 0; i < exp; ++i) {
        result *= b_ll;
    }

    return result;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        int x_val;
        std::cin >> x_val;
        std::string polynomial_s;
        std::cin >> polynomial_s;

        int total_evaluation = 0;
        size_t start_idx = 0;

        for (size_t k = 0; k <= polynomial_s.length(); ++k) {
            if (k > start_idx && (k == polynomial_s.length() || polynomial_s[k] == '+' || polynomial_s[k] == '-')) {
                std::string term_to_parse = polynomial_s.substr(start_idx, k - start_idx);
                Term current_term = parse_term_cpp(term_to_parse);
                long long x_pow_e_val = power_cpp(x_val, current_term.exponent);
                long long c_val_ll = current_term.coefficient;
                long long current_term_value_ll = c_val_ll * x_pow_e_val;

                total_evaluation += static_cast<int>(current_term_value_ll);
                start_idx = k;
            }
        }

        std::cout << "Case #" << i << ": " << total_evaluation << "\n";
    }

    return 0;
}