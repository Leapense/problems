#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;

struct Move
{
    int player;
    char color;
    int number;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<string> names = {"IGOR", "LEA", "MARINO", "SONJA", "VIKTOR"};
    set<string> playedCards;

    vector<set<char>> prohibited(5);
    vector<pair<int, string>> paradoxes;

    int startIndex = 3;

    for (int round = 1; round <= N; round++)
    {
        vector<string> cards(5);
        for (int i = 0; i < 5; i++)
        {
            cin >> cards[i];
        }

        vector<int> order(5);
        for (int i = 0; i < 5; i++)
        {
            order[i] = (startIndex + i) % 5;
        }

        vector<Move> validMoves;
        char roundColor = '\0';

        for (int j = 0; j < 5; j++)
        {
            int player = order[j];
            string card = cards[j];
            char color = card[0];
            int num = card[1] - '0';
            string cardID = card;

            if (j == 0)
            {
                roundColor = color;
                validMoves.push_back({player, color, num});
                playedCards.insert(cardID);
                continue;
            }

            if (playedCards.count(cardID))
            {
                paradoxes.push_back({round, names[player]});
                continue;
            }

            if (prohibited[player].count(color))
            {
                paradoxes.push_back({round, names[player]});
                continue;
            }

            if (color != roundColor)
            {
                prohibited[player].insert(roundColor);
            }

            validMoves.push_back({player, color, num});
            playedCards.insert(cardID);
        }

        int winner = -1;
        int maxNum = -1;
        bool foundRed = false;

        for (auto &m : validMoves)
        {
            if (m.color == 'C')
            {
                if (!foundRed || m.number > maxNum)
                {
                    foundRed = true;
                    maxNum = m.number;
                    winner = m.player;
                }
            }
        }

        if (!foundRed)
        {
            maxNum = -1;
            for (auto &m : validMoves)
            {
                if (m.color == roundColor && m.number > maxNum)
                {
                    maxNum = m.number;
                    winner = m.player;
                }
            }
        }

        startIndex = winner;
    }

    cout << paradoxes.size() << "\n";
    for (auto &p : paradoxes)
    {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}