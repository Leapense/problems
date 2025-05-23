#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a1, p1, z1; // Vilius's rocks, papers, scissors
    int a2, p2, z2; // Adomas's rocks, papers, scissors
    
    cin >> a1 >> p1 >> z1;
    cin >> a2 >> p2 >> z2;
    
    // Total number of games
    int total_games = a1 + p1 + z1;
    
    // Maximum score for Vilius
    int max_vilius_score = 0;
    
    // Maximum score calculation
    int win_rock = min(a1, z2);
    int win_scissors = min(z1, p2);
    int win_paper = min(p1, a2);
    
    max_vilius_score = win_rock + win_scissors + win_paper;
    
    // Minimum score for Vilius
    int min_vilius_score = 0;
    
    // Minimum score calculation
    int lose_rock = min(a1, p2);
    int lose_scissors = min(z1, a2);
    int lose_paper = min(p1, z2);
    
    min_vilius_score = -(lose_rock + lose_scissors + lose_paper);
    
    cout << max_vilius_score << endl;
    cout << min_vilius_score << endl;
    
    return 0;
}
