//=====================================================================
//   24371번:    БРОЙ ПОДНИЗОВЕ
//   @date:   2024-10-22
//   @link:   https://www.acmicpc.net/problem/24371
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

struct Key {
    int state;
    bool included_P;
    vector<int> counts;

    bool operator==(const Key &other) const {
        return state == other.state && included_P == other.included_P && counts == other.counts;
    }
};

namespace std {
    template <>
    struct hash<Key> {
        std::size_t operator()(const Key &k) const {
            std::size_t res = k.state;
            res ^= k.included_P ? 123456789 : 987654321;
            for (int count : k.counts) {
                res ^= std::hash<int>()(count) + 0x9e3779b9 + (res << 6) + (res >> 2);
            }
            return res;
        }
    };
}

string S, P;
vector<int> counts_S(26, 0), counts_P(26, 0);
vector<int> letters_in_S;
vector<vector<int>> automaton;

unordered_map<Key, ull> memo;

void build_automaton() {
    int m = P.size();
    automaton.assign(m + 1, vector<int>(26, 0));
    vector<int> fail(m + 1, 0);
    for (int i = 1; i < m; ++i) {
        int j = fail[i];
        while (j > 0 && P[i] != P[j]) j = fail[j];
        if (P[i] == P[j]) ++j;
        fail[i + 1] = j;
    }
    for (int state = 0; state <= m; ++state) {
        for (char c = 'a'; c <= 'z'; ++c) {
            if (state < m && c == P[state]) {
                automaton[state][c - 'a'] = state + 1;
            } else {
                automaton[state][c - 'a'] = automaton[fail[state]][c - 'a'];
            }
        }
    }
}

ull dfs(int state, vector<int> &counts, bool included_P) {
    if (accumulate(counts.begin(), counts.end(), 0) == 0) {
        return included_P ? 1ULL : 0ULL;
    }

    Key key{state, included_P, counts};
    auto it = memo.find(key);
    if (it != memo.end()) {
        return it->second;
    }

    ull res = 0;

    for (int idx : letters_in_S) {
        if (counts[idx] > 0) {
            counts[idx]--;
            int next_state = automaton[state][idx];
            bool next_included_P = included_P || (next_state == P.size());
            res += dfs(next_state, counts, next_included_P);
            counts[idx]++;
        }
    }

    memo[key] = res;
    return res;
}

int main() {
    cin >> S >> P;

    for (char c : S) counts_S[c - 'a']++;
    for (char c : P) counts_P[c - 'a']++;

    for (int i = 0; i < 26; ++i) {
        if (counts_P[i] > counts_S[i]) {
            cout << 0 << endl;
            return 0;
        }
        if (counts_S[i] > 0) {
            letters_in_S.push_back(i);
        }
    }

    build_automaton();

    vector<int> counts = counts_S;
    ull result = dfs(0, counts, false);
    cout << result << endl;

    return 0;
}
