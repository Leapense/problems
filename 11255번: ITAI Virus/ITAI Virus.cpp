#include <iostream>
#include <vector>

// Function to read input for a single test case
void readInput(int& N, int& M, int& K, std::vector<std::vector<int>>& adjacency, std::vector<int>& initialCities) {
    std::cin >> N >> M >> K;
    adjacency.resize(N + 1);
    for (int i = 0; i < M; ++i) {
        int A, B;
        std::cin >> A >> B;
        adjacency[A].push_back(B);
        adjacency[B].push_back(A);
    }
    initialCities.resize(K);
    for (int i = 0; i < K; ++i) {
        std::cin >> initialCities[i];
    }
}

// Function to spread the virus
void spreadVirus(const std::vector<std::vector<int>>& adjacency, const std::vector<int>& initialCities, std::vector<bool>& virus) {
    for (const auto& city : initialCities) {
        virus[city] = true;
        for (const auto& neighbor : adjacency[city]) {
            virus[neighbor] = true;
        }
    }
}

// Function to count infected cities
int countInfectedCities(const std::vector<bool>& virus) {
    int count = 0;
    for (int i = 1; i < virus.size(); ++i) {
        if (virus[i]) {
            count++;
        }
    }
    return count;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin >> T;
    while (T--) {
        int N, M, K;
        std::vector<std::vector<int>> adjacency;
        std::vector<int> initialCities;
        readInput(N, M, K, adjacency, initialCities);

        std::vector<bool> virus(N + 1, false);
        spreadVirus(adjacency, initialCities, virus);

        int infectedCount = countInfectedCities(virus);
        std::cout << infectedCount << "\n";
    }

    return 0;
}