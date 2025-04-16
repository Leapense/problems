#include <iostream>
#include <string>
#include <vector>
#include <stack>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string parentheses_string;
    std::cin >> parentheses_string;

    long long total_distance_sum = 0;

    std::vector<int> node_stack;

    for (int i = 0; i < parentheses_string.length(); ++i) {
        if (parentheses_string[i] == '(') {
            node_stack.push_back(0);
        } else {
            node_stack.pop_back();

            if (parentheses_string[i - 1] == '(') {
                total_distance_sum += node_stack.size();
            } else {

            }
        }
    }
    std::cout << total_distance_sum << std::endl;
    return 0;
}