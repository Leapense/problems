#include <iostream>
#include <cstdint>
#include <cmath>

using namespace std;

int64_t ceilDiv(int64_t a, int64_t b) {
    return (a + b - 1) / b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t H, A, D, B;

    cin >> H >> A >> D >> B;
    int64_t P, S;
    cin >> P >> S;

    int64_t rounds_no_skill = ceilDiv(D, A);
    int64_t r_min = ceilDiv(D - P, A);
    int64_t r_max = (D - 1) / A;

    int64_t total_rounds;

    if (r_min <= r_max) {
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

    if (H > (total_rounds - 1) * B) cout << "Victory!" << "\n";
    else cout << "gg" << "\n";

    return 0;
}
