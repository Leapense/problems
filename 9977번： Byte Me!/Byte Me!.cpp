#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>
#include <bitset>

using namespace std;

int binToInt(const string &s)
{
    return stoi(s, nullptr, 2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    while (getline(cin, line))
    {
        if (line == "ENDOFINPUT")
            break;
        if (line.substr(0, 5) == "START")
        {
            istringstream iss(line);
            string start;
            int nPlayers;
            iss >> start >> nPlayers;
            string dealerLine;
            getline(cin, dealerLine);
            istringstream dealerStream(dealerLine);
            string dealerCard1, dealerCard2;
            dealerStream >> dealerCard1 >> dealerCard2;
            int dealerTotal = binToInt(dealerCard1) + binToInt(dealerCard2);

            string playerLine;
            getline(cin, playerLine);
            vector<int> playerTotals;
            if (nPlayers > 0)
            {
                istringstream playerStream(playerLine);
                for (int i = 0; i < nPlayers; i++)
                {
                    string card;
                    playerStream >> card;
                    int total = binToInt(card) + 255;
                    playerTotals.push_back(total);
                }
            }

            int maxPlayerTotal = 0;
            for (auto t : playerTotals)
            {
                if (t > maxPlayerTotal)
                    maxPlayerTotal = t;
            }

            string byteLine;
            getline(cin, byteLine);
            istringstream byteStream(byteLine);

            vector<int> byteHits;
            for (int i = 0; i < 4; i++)
            {
                string s;
                byteStream >> s;
                byteHits.push_back(binToInt(s));
            }

            string nibbleLine;
            getline(cin, nibbleLine);
            istringstream nibbleStream(nibbleLine);
            vector<int> nibbleHits;
            for (int i = 0; i < 4; i++)
            {
                string s;
                nibbleStream >> s;
                nibbleHits.push_back(binToInt(s));
            }
            getline(cin, line);
            vector<string> actions;

            int hitCount = 0, byteIndex = 0, nibbleIndex = 0;
            bool bust = false;
            while (hitCount < 4 && dealerTotal <= 510)
            {
                bool rule1 = (dealerTotal >= maxPlayerTotal);
                if (rule1)
                    break;
                if (dealerTotal < 382)
                {
                    if (byteIndex < (int)byteHits.size())
                    {
                        dealerTotal += byteHits[byteIndex++];
                        actions.push_back("Byte me!");
                        hitCount++;
                    }
                    else
                        break;
                }
                else if (dealerTotal <= 500)
                {
                    if (nibbleIndex < (int)nibbleHits.size())
                    {
                        dealerTotal += nibbleHits[nibbleIndex++];
                        actions.push_back("Nibble me!");
                        hitCount++;
                    }
                    else
                        break;
                }
                else
                {
                    break;
                }

                if (dealerTotal > 510)
                {
                    bust = true;
                    break;
                }
            }

            cout << "HAND " << nPlayers << "\n";
            for (auto &act : actions)
            {
                cout << act << "\n";
            }

            if (bust)
            {
                cout << "Bust!" << "\n";
            }
            else
            {
                if (dealerTotal >= maxPlayerTotal)
                    cout << "Win!" << "\n";
                else
                    cout << "Lose!" << "\n";
            }
        }
    }

    return 0;
}