#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <numeric>

struct Condition
{
    int want_count;
    int dice_result;

    Condition(int w, int r) : want_count(w), dice_result(r) {}
};

using ExpressionAndGroup = std::vector<Condition>;
using ParsedExpressionsContainer = std::vector<ExpressionAndGroup>;

int N_DICE;
int S_SIDES;
ParsedExpressionsContainer ALL_EXPRESSIONS;
long long COUNT_SATISFYING_ROLLS = 0;
std::vector<int> CURRENT_ROLL_CONFIGURATION;

ExpressionAndGroup parse_single_expression_line(const std::string &line_str)
{
    ExpressionAndGroup and_conditions;
    std::string current_condition_str_segment;

    for (size_t i = 0; i < line_str.length(); ++i)
    {
        if (line_str[i] == '+')
        {
            size_t x_pos = current_condition_str_segment.find('x');
            int w = std::stoi(current_condition_str_segment.substr(0, x_pos));
            int r = std::stoi(current_condition_str_segment.substr(x_pos + 1));
            and_conditions.emplace_back(w, r);
            current_condition_str_segment.clear();
        }
        else
        {
            current_condition_str_segment += line_str[i];
        }
    }

    if (!current_condition_str_segment.empty())
    {
        size_t x_pos = current_condition_str_segment.find('x');
        int w = std::stoi(current_condition_str_segment.substr(0, x_pos));
        int r = std::stoi(current_condition_str_segment.substr(x_pos + 1));
        and_conditions.emplace_back(w, r);
    }

    return and_conditions;
}

bool does_roll_satisfy_criteria(const std::vector<int> &roll)
{
    std::vector<int> dice_face_counts(S_SIDES + 1, 0);
    for (int face_value : roll)
    {
        dice_face_counts[face_value]++;
    }

    for (const auto &expression_and_group : ALL_EXPRESSIONS)
    {
        bool current_expression_line_satisfied = true;

        for (const auto &cond : expression_and_group)
        {
            if (cond.dice_result < 1 || cond.dice_result > S_SIDES)
            {
            }
            if (dice_face_counts[cond.dice_result] < cond.want_count)
            {
                current_expression_line_satisfied = false;
                break;
            }
        }

        if (current_expression_line_satisfied)
        {
            return true;
        }
    }

    return false;
}

void generate_all_rolls_recursively(int die_k_index)
{
    if (die_k_index == N_DICE)
    {
        if (does_roll_satisfy_criteria(CURRENT_ROLL_CONFIGURATION))
        {
            COUNT_SATISFYING_ROLLS++;
        }

        return;
    }

    for (int side_value = 1; side_value <= S_SIDES; ++side_value)
    {
        CURRENT_ROLL_CONFIGURATION[die_k_index] = side_value;
        generate_all_rolls_recursively(die_k_index + 1);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int E_expressions;
    std::cin >> N_DICE >> S_SIDES >> E_expressions;

    std::string temp_line_buffer;
    std::getline(std::cin, temp_line_buffer);

    ALL_EXPRESSIONS.resize(E_expressions);
    for (int i = 0; i < E_expressions; ++i)
    {
        std::string expression_line_str;
        std::getline(std::cin, expression_line_str);
        ALL_EXPRESSIONS[i] = parse_single_expression_line(expression_line_str);
    }

    CURRENT_ROLL_CONFIGURATION.resize(N_DICE);
    generate_all_rolls_recursively(0);

    std::cout << COUNT_SATISFYING_ROLLS << "\n";

    return 0;
}