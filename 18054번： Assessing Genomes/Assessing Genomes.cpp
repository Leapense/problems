#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int getRepetitionScore(const std::string& s) {
    int len = s.length();
    for (int u_len = 1; u_len <= len; ++u_len) {
        if (len % u_len != 0) continue;
        std::string u = s.substr(0, u_len);
        bool match = true;
        for (int i = u_len; i < len; i += u_len) {
            if (s.substr(i, u_len) != u) {
                match = false;
                break;
            }
        }

        if (match) return u_len;
    }

    return len;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::vector<std::string> virus(n);
    std::vector<std::string> antivirus(n);

    for (auto &s : virus) std::cin >> s;
    for (auto &s : antivirus) std::cin >> s;

    std::vector<int> virus_scores(n);
    std::vector<int> antivirus_scores(n);

    for (int i = 0; i < n; ++i) {
        virus_scores[i] = getRepetitionScore(virus[i]);
        antivirus_scores[i] = getRepetitionScore(antivirus[i]);
    }

    std::sort(virus_scores.begin(), virus_scores.end());
    std::sort(antivirus_scores.begin(), antivirus_scores.end());

    long long total_damage = 0;

    for (int i = 0; i < n; ++i) {
        long long diff = (long long) (virus_scores[i] - antivirus_scores[i]);
        total_damage += diff * diff;
    }

    std::cout << total_damage << std::endl;

    return 0;
}