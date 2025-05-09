#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cctype>

namespace
{
    std::string process_single_option_impl(const std::string &original_option, std::set<char> &assigned_shortcuts)
    {
        bool is_start_of_word = true;
        int shortcut_idx_rule1 = -1;
        bool rule1_must_fail_due_to_non_alpha_start = false;

        for (int i = 0; i < static_cast<int>(original_option.length()); ++i)
        {
            if (original_option[i] == ' ')
            {
                is_start_of_word = true;
                continue;
            }

            if (is_start_of_word)
            {
                if (std::isalpha(static_cast<unsigned char>(original_option[i])))
                {
                    char current_char = original_option[i];
                    char lower_char = static_cast<char>(std::tolower(static_cast<unsigned char>(current_char)));

                    if (assigned_shortcuts.find(lower_char) == assigned_shortcuts.end())
                    {
                        shortcut_idx_rule1 = i;
                        break;
                    }
                }
                else
                {
                    rule1_must_fail_due_to_non_alpha_start = true;
                    break;
                }

                is_start_of_word = false;
            }
        }

        if (rule1_must_fail_due_to_non_alpha_start)
        {
            shortcut_idx_rule1 = -1;
        }

        if (shortcut_idx_rule1 != -1)
        {
            char char_to_assign = original_option[shortcut_idx_rule1];
            assigned_shortcuts.insert(static_cast<char>(std::tolower(static_cast<unsigned char>(char_to_assign))));
            return original_option.substr(0, shortcut_idx_rule1) + "[" + std::string(1, char_to_assign) + "]" + original_option.substr(shortcut_idx_rule1 + 1);
        }

        int shortcut_idx_rule2 = -1;
        for (int i = 0; i < static_cast<int>(original_option.length()); ++i)
        {
            char current_char = original_option[i];
            if (current_char == ' ')
            {
                continue;
            }

            if (std::isalpha(static_cast<unsigned char>(current_char)))
            {
                char lower_char = static_cast<char>(std::tolower(static_cast<unsigned char>(current_char)));
                if (assigned_shortcuts.find(lower_char) == assigned_shortcuts.end())
                {
                    shortcut_idx_rule2 = i;
                    break;
                }
            }
        }

        if (shortcut_idx_rule2 != -1)
        {
            char char_to_assign = original_option[shortcut_idx_rule2];
            assigned_shortcuts.insert(static_cast<char>(std::tolower(static_cast<unsigned char>(char_to_assign))));
            return original_option.substr(0, shortcut_idx_rule2) + "[" + std::string(1, char_to_assign) + "]" + original_option.substr(shortcut_idx_rule2 + 1);
        }

        return original_option;
    }
}

std::vector<std::string> solve_all_options(const std::vector<std::string> &options)
{
    std::set<char> assigned_shortcuts;
    std::vector<std::string> results;
    if (!options.empty())
    {
        results.reserve(options.size());
    }
    for (const auto &opt : options)
    {
        results.push_back(process_single_option_impl(opt, assigned_shortcuts));
    }

    return results;
}

#ifndef UNIT_TEST
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<std::string> options(N);
    for (int i = 0; i < N; ++i)
    {
        std::getline(std::cin, options[i]);
    }

    std::vector<std::string> processed_options = solve_all_options(options);

    for (const auto &res_opt : processed_options)
    {
        std::cout << res_opt << "\n";
    }

    return 0;
}
#endif