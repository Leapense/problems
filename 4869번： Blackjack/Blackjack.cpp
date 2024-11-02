#include <iostream>
#include <iomanip>
#include <map>
#include <string>
using namespace std;

int cardValue(char card) {
    if (card == 'A') return 11; // Ace as 11 unless adjusted
    if (card == 'K' || card == 'Q' || card == 'J' || card == 'T') return 10;
    return card - '0'; // Convert numeric characters to int values
}

// Evaluates the best score of a two-card hand
int evaluateHand(char c1, char c2) {
    int v1 = cardValue(c1);
    int v2 = cardValue(c2);
    int total = v1 + v2;

    // Adjust if two aces are drawn
    if (c1 == 'A' && c2 == 'A') {
        return 12; // Best score when having two Aces is 12 (11+1)
    }
    // Adjust if an Ace is part of the hand and total exceeds 21
    if (total > 21 && (c1 == 'A' || c2 == 'A')) {
        total -= 10; // Use Ace as 1 instead of 11
    }
    return total;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        string dealerCard, playerCard1, playerCard2;
        cin >> dealerCard >> playerCard1 >> playerCard2;
        
        // Calculate the count of each card in n decks
        map<char, int> deck;
        string cards = "A23456789TJQK";
        for (char c : cards) {
            deck[c] = 4 * n; // 4 of each card per deck
        }
        
        // Remove known cards from the deck
        deck[dealerCard[0]]--;
        deck[playerCard1[0]]--;
        deck[playerCard2[0]]--;
        
        int playerScore = evaluateHand(playerCard1[0], playerCard2[0]);
        int winCount = 0;
        int totalCount = 0;
        
        for (char dcard : cards) {
            if (deck[dcard] > 0) {
                int dealerScore = evaluateHand(dealerCard[0], dcard);
                if (playerScore > dealerScore || dealerScore > 21) {
                    winCount += deck[dcard];
                }
                totalCount += deck[dcard];
            }
        }
        
        double probability = 100.0 * winCount / totalCount;
        cout << fixed << setprecision(3) << probability << "%" << endl;
    }
    return 0;
}