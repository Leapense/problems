#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;
        std::unordered_map<std::string, int> file_map;
        for (int i = 0; i < N; ++i) {
            std::string name;
            int id;
            std::cin >> name >> id;
            if (file_map.find(name) == file_map.end() || id < file_map[name]) {
                file_map[name] = id;
            }
        }
        std::vector<int> result;
        for (const auto& entry : file_map) {
            result.push_back(entry.second);
        }
        std::sort(result.begin(), result.end());
        for (size_t i = 0; i < result.size(); ++i) {
            if (i > 0) std::cout << " ";
            std::cout << result[i];
        }
        std::cout << "\n";
    }
    return 0;
}