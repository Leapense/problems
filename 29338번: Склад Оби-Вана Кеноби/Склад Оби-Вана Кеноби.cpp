#include <iostream>
#include <deque>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::deque<int> table;
    std::string operation;
    int x;

    for (int i = 0; i < n; ++i) {
        std::cin >> operation;
        if (operation == "add") {
            std::cin >> x;
            table.push_back(x);
        } else if (operation == "take") {
            if (!table.empty()) {
                table.pop_back();
            }
        } else if (operation == "mum!") {
            int size = table.size();
            if (size >= 2) {
                int mid = size / 2;
                std::deque<int> left_half(table.begin(), table.begin() + mid);
                table.erase(table.begin(), table.begin() + mid);
                table.insert(table.end(), left_half.begin(), left_half.end());
            }
        }
    }

    std::cout << table.size() << "\n";
    for (int num : table) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}
