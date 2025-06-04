#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_Q       15000
#define HSIZE       (1 << 20)         // 1,048,576
#define EMPTY_KEY   UINT32_MAX        // 빈 슬롯 표시 (모든 비트 1)
#define KNUTH_CONST 2654435761u       // Knuth 곱셈 해시 상수

static uint32_t Keys[HSIZE];
static uint32_t Counts[HSIZE];

// 문자열 내 문자 → 3비트 값 매핑 (p,i,n,k,h,a,r,e → 0~7)
static const uint8_t charMap[256] = {
    ['p'] = 0u, ['i'] = 1u, ['n'] = 2u, ['k'] = 3u,
    ['h'] = 4u, ['a'] = 5u, ['r'] = 6u, ['e'] = 7u
};

// 해시 인덱스 계산 (Knuth 곱셈 후 상위 20비트 사용)
static inline uint32_t hashIndex(uint32_t key)
{
    uint64_t prod = (uint64_t)key * KNUTH_CONST;
    return (uint32_t)(prod >> (32 - 20)) & (HSIZE - 1);
}

// 해시테이블 초기화 (모든 슬롯을 EMPTY_KEY로 채워 빈 상태로 만듦)
static void initHashTable(void)
{
    memset(Keys, 0xFF, sizeof(Keys));   // 0xFF..FF = EMPTY_KEY
    memset(Counts, 0x00, sizeof(Counts));
}

// 키 삽입 또는 기존 키의 카운트 증가
static void putIncrement(uint32_t key)
{
    uint32_t idx = hashIndex(key);
    while (Keys[idx] != EMPTY_KEY && Keys[idx] != key) {
        idx = (idx + 1u) & (HSIZE - 1);
    }
    if (Keys[idx] == EMPTY_KEY) {
        Keys[idx] = key;
        Counts[idx] = 1u;
    } else {
        Counts[idx]++;
    }
}

// 키 조회: 존재하면 Count 반환, 없으면 0 반환
static uint32_t getCount(uint32_t key)
{
    uint32_t idx = hashIndex(key);
    while (Keys[idx] != EMPTY_KEY) {
        if (Keys[idx] == key) {
            return Counts[idx];
        }
        idx = (idx + 1u) & (HSIZE - 1);
    }
    return 0u;
}

// 첫 10문자(인덱스 0..9) → 코드(30비트) 직접 계산
static inline uint32_t encodeDirect(const char *s)
{
    uint32_t code = 0u;
    for (int i = 0; i < 10; i++) {
        code = (code << 3) | charMap[(uint8_t)s[i]];
    }
    return code;
}

// qsort 비교 함수 (uint32_t 타입)
static int cmpUint32(const void *a, const void *b)
{
    uint32_t va = *(const uint32_t *)a;
    uint32_t vb = *(const uint32_t *)b;
    if (va < vb) {
        return -1;
    }
    if (va > vb) {
        return 1;
    }
    return 0;
}

int main(void)
{
    int T = 0;
    if (scanf("%d", &T) != 1) {
        return 0;
    }

    for (int tc = 1; tc <= T; tc++) {
        initHashTable();

        int Q = 0;
        if (scanf("%d", &Q) != 1) {
            return 0;
        }
        getchar();  // 남은 개행문자 제거

        char line[48];  // 최대 길이 44 + 널 종료

        for (int qi = 0; qi < Q; qi++) {
            if (fgets(line, sizeof(line), stdin) == NULL) {
                return 0;
            }
            size_t len = strlen(line);
            if (len > 0 && line[len - 1] == '\n') {
                line[len - 1] = '\0';
                len--;
            }

            if (len == 44) {
                // ============================
                // 1) 토끼 추가 (염색체 길이 44)
                // ============================
                uint32_t codes[35];
                // 1. 첫 10문자 인코딩
                uint32_t key = encodeDirect(line);
                codes[0] = key;

                // 2. 롤링 해시: 44자 문자열에서 연속 10자 윈도우를 35회 계산
                //    POWER_8_9 = 8^9 = 1 << 27
                const uint32_t POWER_8_9 = 1u << 27;
                for (int i = 1; i < 35; i++) {
                    uint8_t out_v = charMap[(uint8_t)line[i - 1]];
                    uint8_t in_v  = charMap[(uint8_t)line[i + 9]];

                    // 잘못된 마스킹 제거: 간단히 (old_key - out_v*8^9) * 8 + in_v
                    key = ((key - ((uint32_t)out_v << 27)) << 3) | in_v;
                    codes[i] = key;
                }

                // 3. qsort로 정렬 후 중복 제거
                qsort(codes, 35, sizeof(uint32_t), cmpUint32);
                for (int i = 0; i < 35; i++) {
                    if (i == 0 || codes[i] != codes[i - 1]) {
                        putIncrement(codes[i]);
                    }
                }
            }
            else if (len == 10) {
                // ============================
                // 2) 조회 명령 (길이 10)
                // ============================
                uint32_t code = encodeDirect(line);
                uint32_t cnt  = getCount(code);
                if (cnt == 0u) {
                    puts("not exist");
                }
                else if (cnt == 1u) {
                    puts("unique");
                }
                else {
                    puts("duplicate");
                }
            }
            else {
                // 길이가 10 또는 44가 아닌 경우 → 무시
            }
        }
    }

    return 0;
}