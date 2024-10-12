#include <iostream>
#include <map>
#include <string>

int main()
{
    int N;
    std::cin >> N;
    std::cin.ignore();

    std::map<char, int> frequency;
    std::string line;

    for (int i = 0; i < N; ++i) {
        std::getline(std::cin, line);
        for (char c : line) {
            if (c != ' ') {
                frequency[c]++;
            }
        }
    }

    for (const auto& pair : frequency) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    return 0;
}