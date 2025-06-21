#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

const int MAX_N = 500;
const int MAX_M = 50;

vector<string> spotty(MAX_N);
vector<string> plain(MAX_N);

bool is_valid(int a, int b, int c, int N, int M) {
    unordered_set<string> spotty_combinations;
    for (int i = 0; i < N; i++) {
        string combination = string() + spotty[i][a] + spotty[i][b] + spotty[i][c];
        spotty_combinations.insert(combination);
    }
    
    for (int i = 0; i < N; i++) {
        string combination = string() + plain[i][a] + plain[i][b] + plain[i][c];
        if (spotty_combinations.find(combination) != spotty_combinations.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        cin >> spotty[i];
    }
    
    for (int i = 0; i < N; i++) {
        cin >> plain[i];
    }
    
    int count = 0;
    for (int a = 0; a < M; a++) {
        for (int b = a + 1; b < M; b++) {
            for (int c = b + 1; c < M; c++) {
                if (is_valid(a, b, c, N, M)) {
                    count++;
                }
            }
        }
    }
    
    cout << count << endl;
    return 0;
}
