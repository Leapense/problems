#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> parse_pattern(const std::string& pattern, int L) {
    std::vector<std::string> possible_letters;
    int i = 0;
    int n = pattern.size();

    while (i < n && (int)possible_letters.size() < L) {
        if (pattern[i] == '(') {
            i++;
            std::string letters;
            while (i < n && pattern[i] != ')') {
                letters += pattern[i];
                i++;
            }
            i++;
            possible_letters.push_back(letters);
        } else {
            possible_letters.push_back(std::string(1, pattern[i]));
            i++;
        }
    }

    return possible_letters;
}

bool matches(const std::string& word, const std::vector<std::string>& pattern_letters, int L) {
    for (int i = 0; i < L; ++i) {
        if (pattern_letters[i].find(word[i]) == std::string::npos) {
            return false;
        }
    }

    return true;
}

int main() {
    int L, D, N;
    std::cin >> L >> D >> N;

    std::vector<std::string> words;
    words.reserve(D);

    for (int i = 0; i < D; ++i) {
        std::string word;
        std::cin >> word;
        words.push_back(word);
    }

    std::cin.ignore(1000, '\n');

    std::vector<std::string> patterns;

    patterns.reserve(N);
    for (int i = 0; i < N; ++i) {
        std::string pattern;
        std::getline(std::cin, pattern);
        patterns.push_back(pattern);
    }

    for (int i = 0; i < N; ++i) {
        const std::string& pattern = patterns[i];
        std::vector<std::string> pattern_letters = parse_pattern(pattern, L);

        int count = 0;
        for (const auto& word : words) {
            if (matches(word, pattern_letters, L)) {
                count++;
            }
        }

        std::cout << "Case #" << (i + 1) << ": " << count << "\n";
    }

    return 0;
}