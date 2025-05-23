#include <iostream>
#include <string>
#include <cstring>  // For memset
#include <cctype>   // For toupper

int score[256];
std::string best;
int ntray, nblanks = 0, bestscore = 0;
int gotlets[256];

void initscore() {
    memset(score, 0, sizeof(score));
    score['#'] = 0;
    score['A'] = score['E'] = score['I'] = score['L'] = score['N'] =
    score['O'] = score['R'] = score['S'] = score['T'] = score['U'] = 1;
    score['D'] = score['G'] = 2;
    score['B'] = score['C'] = score['M'] = score['P'] = 3;
    score['F'] = score['H'] = score['V'] = score['W'] = score['Y'] = 4;
    score['K'] = 5;
    score['J'] = score['X'] = 8;
    score['Q'] = score['Z'] = 10;
}

int main() {
    memset(gotlets, 0, sizeof(gotlets));
    initscore();
    std::cin >> ntray;
    for (int i = 0; i < ntray; i++) {
        std::string in;
        std::cin >> in;
        char c = toupper(in[0]);
        if (c == '#') {
            nblanks++;
        } else {
            gotlets[c]++;
        }
    }
    std::cin.ignore(); // Ignore any remaining newline character

    std::string in;
    while (std::getline(std::cin, in)) {
        if (in.empty()) continue; // Skip empty lines
        int mygotlets[256] = {0};
        int nbad = 0, myscore = 0;
        for (size_t i = 0; i < in.length(); i++) {
            char c = toupper(in[i]);
            if (++mygotlets[c] > gotlets[c]) {
                nbad++;
            } else {
                myscore += score[c];
            }
        }
        if (nbad <= nblanks && myscore > bestscore) {
            best = in;
            bestscore = myscore;
        }
    }
    std::cerr << best << " " << bestscore << std::endl;
    std::cout << best << std::endl;
    return 0;
}
