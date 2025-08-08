#include <bits/stdc++.h>
using namespace std;

static inline bool isLetter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

static inline char shiftChar(char c, int s) {
    if (c >= 'A' && c <= 'Z') {
        int idx = c - 'A';
        idx = (idx - s) % 26;
        if (idx < 0) idx += 26;
        return static_cast<char>('A' + idx);
    }
    if (c >= 'a' && c <= 'z') {
        int idx = c - 'a';
        idx = (idx - s) % 26;
        if (idx < 0) idx += 26;
        return static_cast<char>('a' + idx);
    }
    return c;
}

static string decrypt(const string& cipher, int s) {
    string out(cipher.size(), '\0');
    for (size_t i = 0; i < cipher.size(); ++i) out[i] = shiftChar(cipher[i], s);
    return out;
}

struct Score {
    int matchCount;
    int threatCount;
    int totalWords;
};

static Score evaluate(const string& plain, const unordered_set<string>& good, const unordered_set<string>& bad) {
    int total = 0;
    int matches = 0;
    int threats = 0;
    size_t i = 0;
    while (i < plain.size()) {
        if (isLetter(plain[i])) {
            size_t j = i;
            while (j < plain.size() && isLetter(plain[j])) ++j;
            size_t len = j - i;
            if (len >= 1 && len <= 20) {
                string word = plain.substr(i, len);
                for (char& ch : word) ch = static_cast<char>(tolower(static_cast<unsigned char>(ch)));
                bool inBad = bad.find(word) != bad.end();
                bool inGood = good.find(word) != good.end();
                if (inBad || inGood) ++matches;
                if (inBad) ++threats;
                ++total;
            }
            i = j;
        } else {
            ++i;
        }
    }
    return {matches, threats, total};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    if (!getline(cin, line)) return 0;
    int C = stoi(line);
    for (int tc = 0; tc < C; ++tc) {
        getline(cin, line);
        int G = stoi(line);
        unordered_set<string> good;
        good.reserve(static_cast<size_t>(G) * 2);
        for (int i = 0; i < G; ++i) {
            string w;
            getline(cin, w);
            good.insert(w);
        }
        getline(cin, line);
        int B = stoi(line);
        unordered_set<string> bad;
        bad.reserve(static_cast<size_t>(B) * 2);
        for (int i = 0; i < B; ++i) {
            string w;
            getline(cin, w);
            bad.insert(w);
        }
        string cipher;
        getline(cin, cipher);

        int bestMatch = -1;
        int bestThreat = 0;
        int bestTotal = 0;
        int bestShift = -1;
        int ties = 0;
        string bestPlain;

        for (int s = 0; s < 26; ++s) {
            string plain = decrypt(cipher, s);
            Score sc = evaluate(plain, good, bad);
            if (sc.matchCount > bestMatch) {
                bestMatch = sc.matchCount;
                bestThreat = sc.threatCount;
                bestTotal = sc.totalWords;
                bestShift = s;
                bestPlain = move(plain);
                ties = 1;
            } else if (sc.matchCount == bestMatch) {
                ++ties;
            }
        }

        if (ties != 1) {
            cout << "Unable to decipher\n";
        } else {
            cout << bestPlain << "\n";
            int M = 0;
            int T = 0;
            if (bestTotal > 0) {
                M = (bestMatch * 100 + bestTotal / 2) / bestTotal;
                T = (bestThreat * 100 + bestTotal / 2) / bestTotal;
            }
            cout << "Shift: " << bestShift << ", Match: " << M << "%, Threat: " << T << "%\n";
        }
    }
    return 0;
}