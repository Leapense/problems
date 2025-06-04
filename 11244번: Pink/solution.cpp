#include <bits/stdc++.h>
using namespace std;

static const uint64_t KNUTH_CONST = 2654435761ull;

// 'p','i','n','k','h','a','r','e' → 0..7 매핑
static const array<uint8_t, 256> charMap = []() {
    array<uint8_t, 256> m{};
    m.fill(UINT8_MAX);
    m['p'] = 0; m['i'] = 1; m['n'] = 2; m['k'] = 3;
    m['h'] = 4; m['a'] = 5; m['r'] = 6; m['e'] = 7;
    return m;
}();

// 문자열 s[0..9] → 10문자 코드(30비트) 직접 계산
static inline uint32_t encodeDirect(const string &s)
{
    uint32_t code = 0u;
    for (int i = 0; i < 10; i++) {
        code = (code << 3) | charMap[(uint8_t)s[i]];
    }
    return code;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) {
        return 0;
    }
    while (T--) {
        int Q;
        cin >> Q;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // 예상 키 개수 약 50만 건 → reserve로 미리 버킷 확보
        unordered_map<uint32_t, int> mp;
        mp.reserve(600000);

        string line;
        for (int qi = 0; qi < Q; qi++) {
            getline(cin, line);
            int len = static_cast<int>(line.size());

            if (len == 44) {
                // ============================
                // 1) 토끼 추가 (염색체 길이 44)
                // ============================
                vector<uint32_t> codes;
                codes.reserve(35);

                // 첫 10문자 직접 인코딩
                uint32_t key = encodeDirect(line);
                codes.push_back(key);

                // 롤링 해시: 8^9 = 1<<27
                const uint32_t POWER_8_9 = 1u << 27;
                for (int i = 1; i < 35; i++) {
                    uint8_t out_v = charMap[(uint8_t)line[i - 1]];
                    uint8_t in_v  = charMap[(uint8_t)line[i + 9]];

                    // 불필요한 마스킹 제거
                    key = ((key - ((uint32_t)out_v << 27)) << 3) | in_v;
                    codes.push_back(key);
                }

                // 로컬 중복 제거: 정렬 후 unique
                sort(codes.begin(), codes.end());
                codes.erase(unique(codes.begin(), codes.end()), codes.end());

                // 전역 해시맵에 반영
                for (uint32_t c : codes) {
                    auto it = mp.find(c);
                    if (it == mp.end()) {
                        mp.insert({c, 1});
                    } else {
                        it->second++;
                    }
                }
            }
            else if (len == 10) {
                // ============================
                // 2) 조회 명령 (길이 10)
                // ============================
                uint32_t code = encodeDirect(line);
                auto itr = mp.find(code);
                int cnt = (itr == mp.end() ? 0 : itr->second);

                if (cnt == 0) {
                    cout << "not exist\n";
                }
                else if (cnt == 1) {
                    cout << "unique\n";
                }
                else {
                    cout << "duplicate\n";
                }
            }
            else {
                // 길이가 10 또는 44가 아닌 경우 → 무시
            }
        }
    }

    return 0;
}