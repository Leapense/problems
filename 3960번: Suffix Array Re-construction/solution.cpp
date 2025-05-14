#include <iostream>
#include <vector>
#include <string>
#include <numeric>

const char UNKNOWN_CHAR = 0;

std::vector<char> g_result_chars;
std::vector<bool> g_conflicting;
bool g_overall_impossible;
int g_L;

void add_char_at_idx(int char_idx, char c) {
    if (g_overall_impossible) return;

    if (char_idx < 0 || char_idx >= g_L) {
        g_overall_impossible = true;
        return;
    }

    if (g_conflicting[char_idx]) {
        return;
    }

    if (g_result_chars[char_idx] == UNKNOWN_CHAR) {
        g_result_chars[char_idx] = c;
    } else if (g_result_chars[char_idx] != c) {
        g_conflicting[char_idx] = true;
    }
}

void solve_test_case()
{
    int s_count;
    std::cin >> g_L >> s_count;

    g_result_chars.assign(g_L, UNKNOWN_CHAR);
    g_conflicting.assign(g_L, false);
    g_overall_impossible = false;

    for (int i = 0; i < s_count; ++i) {
        int p_orig;
        std::string suf_str;
        std::cin >> p_orig >> suf_str;

        if (g_overall_impossible) {
            continue;
        }

        int start_idx = p_orig - 1;
        size_t star_pos = suf_str.find('*');
        if (star_pos == std::string::npos) {
            if (static_cast<size_t>(start_idx) + suf_str.length() > static_cast<size_t>(g_L)) {
                g_overall_impossible = true;
                continue;
            }
            for (size_t k = 0; k < suf_str.length(); ++k) {
                int current_s_idx = start_idx + static_cast<int>(k);
                add_char_at_idx(current_s_idx, suf_str[k]);
            }
        } else {
            if (static_cast<size_t>(start_idx) + star_pos > static_cast<size_t>(g_L)) {
                g_overall_impossible = true;
                continue;
            }

            for (size_t k = 0; k < star_pos; ++k) {
                int current_s_idx = start_idx + static_cast<int>(k);
                add_char_at_idx(current_s_idx, suf_str[k]);
            }

            if (g_overall_impossible) continue;

            size_t len_suffix_part_after_star = suf_str.length() - (star_pos + 1);

            if (len_suffix_part_after_star > static_cast<size_t>(g_L)) {
                g_overall_impossible = true;
                continue;
            }

            int first_idx_after_prefix = start_idx + static_cast<int>(star_pos);
            int first_idx_of_suffix_part = g_L - static_cast<int>(len_suffix_part_after_star);

            if (first_idx_after_prefix > first_idx_of_suffix_part) {
                g_overall_impossible = true;
                continue;
            }

            for (size_t k = 0; k < len_suffix_part_after_star; ++k) {
                char char_from_suf = suf_str[star_pos + 1 + k];
                int current_s_idx = first_idx_of_suffix_part + static_cast<int>(k);
                add_char_at_idx(current_s_idx, char_from_suf);
            }
        }
    }

    if (g_overall_impossible) {
        std::cout << "IMPOSSIBLE\n";
        return;
    }

    std::string final_s_str = "";
    final_s_str.reserve(g_L);

    for (int i = 0; i < g_L; ++i) {
        if (g_conflicting[i]) {
            g_overall_impossible = true;

            break;
        }
        if (g_result_chars[i] == UNKNOWN_CHAR) {
            g_overall_impossible = true;
            break;
        }

        final_s_str += g_result_chars[i];
    }

    if (g_overall_impossible) {
        std::cout << "IMPOSSIBLE\n";
    } else {
        std::cout << final_s_str << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        solve_test_case();
    }

    return 0;
}