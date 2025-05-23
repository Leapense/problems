#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

struct Candidate {
    std::string name;
    std::string party;
    int votes;

    Candidate(const std::string& n, const std::string& p) : name(n), party(p), votes(0) {}
};

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();

    std::vector<Candidate> candidates;
    std::unordered_map<std::string, int> name_to_index;

    for (int i = 0; i < n; ++i) {
        std::string candidate_name;
        std::getline(std::cin, candidate_name);

        std::string party_name;
        std::getline(std::cin, party_name);

        candidates.emplace_back(candidate_name, party_name);
        name_to_index[candidate_name] = i;
    }

    int m;
    std::cin >> m;
    std::cin.ignore();

    for (int i = 0; i < m; ++i) {
        std::string vote_name;
        std::getline(std::cin, vote_name);

        auto it = name_to_index.find(vote_name);
        if (it != name_to_index.end()) {
            candidates[it->second].votes += 1;
        }
    }

    int max_votes = -1;

    for (const auto& candidate : candidates) {
        if (candidate.votes > max_votes) {
            max_votes = candidate.votes;
        }
    }

    int count_max = 0;
    int winner_index = -1;

    for (int i = 0; i < candidates.size(); ++i) {
        if (candidates[i].votes == max_votes) {
            count_max++;
            winner_index = i;
        }
    }

    if (count_max == 1) {
        std::cout << candidates[winner_index].party;
    } else {
        std::cout << "tie" << "\n";
    }

    return 0;
}