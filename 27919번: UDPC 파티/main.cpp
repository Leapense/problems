#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string votes;
    std::cin >> votes;

    int64_t yooni_count = 0, abstain_count = 0, dalgu_count = 0, phoenix_count = 0;
    for (char vote : votes) {
        switch (vote) {
            case 'U': ++yooni_count; break;
            case 'C': ++abstain_count; break;
            case 'D': ++dalgu_count; break;
            case 'P': ++phoenix_count; break;
        }
    }

    int64_t yooni_max = yooni_count + abstain_count;
    int64_t dalgu_phoenix_max = dalgu_count + phoenix_count;

    std::vector<char> winners;
    if (yooni_max > dalgu_phoenix_max) {
        winners.push_back('U');
    }
    if (dalgu_phoenix_max > yooni_max) {
        winners.push_back('D');
        winners.push_back('P');
    }

    if (winners.empty()) {
        std::cout << "C\n";
    } else {
        for (char winner : winners) {
            std::cout << winner;
        }
        std::cout << '\n';
    }

    return 0;
}