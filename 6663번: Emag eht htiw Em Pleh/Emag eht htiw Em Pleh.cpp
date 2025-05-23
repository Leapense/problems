#include <bits/stdc++.h>
using namespace std;

int main()
{
    string white_line, black_line;
    getline(cin, white_line);
    getline(cin, black_line);

    vector<vector<string>> board(8, vector<string>(8, ""));

    auto place_piece = [&](const string& piece_str, bool is_white) {
        string piece;
        string pos;

        if (piece_str.length() == 2) {
            piece = "P";
            pos = piece_str;
        } else {
            piece = piece_str.substr(0, 1);
            pos = piece_str.substr(1);
        }

        if (!is_white) {
            transform(piece.begin(), piece.end(), piece.begin(), ::tolower);
        } else {
            transform(piece.begin(), piece.end(), piece.begin(), ::toupper);
        }

        char file = pos[0];
        int rank = pos[1] - '0';
        int row = 8 - rank;
        int col = file - 'a';
        board[row][col] = piece;
    };

    size_t white_pos = white_line.find(":");
    string white_pieces = white_line.substr(white_pos + 1);

    stringstream ws(white_pieces);
    string piece;

    while(getline(ws, piece, ',')) {
        piece.erase(remove_if(piece.begin(), piece.end(), ::isspace), piece.end());
        place_piece(piece, true);
    }

    size_t black_pos = black_line.find(":");
    string black_pieces = black_line.substr(black_pos + 1);
    stringstream bs(black_pieces);
    while(getline(bs, piece, ',')) {
        piece.erase(remove_if(piece.begin(), piece.end(), ::isspace), piece.end());
        place_piece(piece, false);
    }

    string border = "+---+---+---+---+---+---+---+---+";
    cout << border << "\n";

    for(int r = 0; r < 8; r++) {
        cout << "|";
        for(int c = 0; c < 8; c++) {
            bool is_light = (r + c) % 2 == 0;
            if (board[r][c] == "") {
                if(is_light) {
                    cout << "...";
                } else {
                    cout << ":::";
                }
            } else {
                if (is_light) {
                    cout << "." << board[r][c] << ".";
                } else {
                    cout << ":" << board[r][c] << ":";
                }
            }
            cout << "|";
        }
        cout << "\n" << border << "\n";
    }

    return 0;
}