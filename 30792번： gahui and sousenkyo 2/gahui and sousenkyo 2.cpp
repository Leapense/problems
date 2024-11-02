#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    int gahui_votes;
    std::cin >> gahui_votes;
    
    std::vector<int> votes(n-1);
    for(int i = 0; i < n-1; ++i) {
        std::cin >> votes[i];
    }
    
    // Adding Gahui's votes to the list
    votes.push_back(gahui_votes);
    
    // Sorting the votes in descending order
    std::sort(votes.begin(), votes.end(), std::greater<int>());
    
    // Finding the rank of Gahui's character
    auto it = std::find(votes.begin(), votes.end(), gahui_votes);
    int rank = std::distance(votes.begin(), it) + 1;
    
    std::cout << rank << std::endl;
    
    return 0;
}