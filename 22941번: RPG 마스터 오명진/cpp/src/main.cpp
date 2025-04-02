#include "main.h"
#include <cstdint>
#include <cmath>

int64_t ceilDiv(int64_t a, int64_t b) {
    return (a + b - 1) / b;
}

void solve(std::istream& in, std::ostream& out) {
    int64_t H, A, D, B;
    in >> H >> A >> D >> B;

    int64_t P, S;
    in >> P >> S;

    int64_t rounds_no_skill = ceilDiv(D, A);

    int64_t r_min = ceilDiv(D - P, A);
    int64_t r_max = (D - 1) / A;

    int64_t total_rounds;
    if (r_min <= r_max) 
    {
        int64_t r_skill = r_min;
        if (rounds_no_skill < r_skill) {
            total_rounds = rounds_no_skill;
        } else {
            int64_t remaining_HP = D - r_skill * A + S;
            int64_t additional_rounds = ceilDiv(remaining_HP, A);
            total_rounds = r_skill + additional_rounds;
        }
    } else {
        total_rounds = rounds_no_skill;
    }

    if (H > (total_rounds - 1) * B) out << "Victory!";
    else out << "gg";
}

#ifndef UNIT_TESTS
int main() {
    solve(std::cin, std::cout);
    return 0;
}
#endif
