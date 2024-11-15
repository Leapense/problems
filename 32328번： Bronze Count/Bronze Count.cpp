#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> scores(N);
    std::set<int> unique_scores;

    for (int i = 0; i < N; ++i) {
        std::cin >> scores[i];
        unique_scores.insert(scores[i]);
    }

    std::vector<int> sorted_scores(unique_scores.begin(), unique_scores.end());
    std::sort(sorted_scores.rbegin(), sorted_scores.rend());

    int bronze_score = sorted_scores[2];
    int count = std::count(scores.begin(), scores.end(), bronze_score);
    std::cout << bronze_score << " " << count << std::endl;

    return 0;
    
}