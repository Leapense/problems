#include <bits/stdc++.h>
using namespace std;

int main()
{
    string input;
    cin >> input;

    int GL = 0, GR = 0;
    int PL = 0, PR = 0;
    bool match_over = false;
    bool server_left = true;

    int last_game_winner = 0;

    for (char c : input) {
        if (match_over) {
            if (c == 'Q') {
                if (GL > GR) {
                    cout << GL << " (winner) - " << GR << "\n";
                } else {
                    cout << GL << " - " << GR << " (winner)\n";
                }
            }
            continue;
        }

        if (c == 'S' or c == 'R') {
            bool point_to_left;

            if (c == 'S') {
                point_to_left = server_left;
            } else {
                point_to_left = !server_left;
            }

            if (point_to_left) {
                PL++;
                server_left = true;
            } else {
                PR++;
                server_left = false;
            }

            bool game_over = false;

            if ((PL >= 5 or PR >= 5) and abs(PL - PR) >= 2) {
                game_over = true;
            }
            if (PL == 10 or PR == 10) {
                game_over = true;
            }

            if (game_over) {
                if (PL > PR) {
                    GL++;
                    last_game_winner = 1;
                } else {
                    GR++;
                    last_game_winner = 2;
                }

                PL = 0;
                PR = 0;

                if (GL == 2 or GR == 2) {
                    match_over = true;
                }

                if(!match_over) {
                    if (last_game_winner == 1) {
                        server_left = true;
                    } else {
                        server_left = false;
                    }
                }
            }
        }
        else if (c == 'Q') {
            if(match_over) {
                if(GL > GR) {
                    cout << GL << " (winner) - " << GR << "\n";
                } else {
                    cout << GL << " - " << GR << " (winner)\n";
                }
            } else {
                string left_part = to_string(GL) + " (" + to_string(PL);
                string right_part = to_string(GR) + " (" + to_string(PR);

                if (server_left) {
                    left_part += "*";
                } else {
                    right_part += "*";
                }

                left_part += ")";
                right_part += ")";

                cout << left_part << " - " << right_part << "\n";
            }
        }
    }

    return 0;
}