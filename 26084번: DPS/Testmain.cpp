#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <stdexcept>
#include <gtest/gtest.h>

/**
 * @brief 주어진 첫 글자 빈도수 배열과 팀 이름 S를 바탕으로 가능한 팀 조합 수를 계산합니다.
 *
 * @param s 목표 팀 이름 (3글자)
 * @param counts 각 알파벳 대문자로 시작하는 핸들의 수를 저장한 배열 (크기 26)
 * @return long long 가능한 팀 조합의 수
 */
long long calculate_combinations(const std::string& s, const long long counts[26]) {
    if (s.length() != 3) {
        // 실제 문제 제약 조건 상 항상 3이지만, 방어적으로 코딩
        throw std::invalid_argument("Team name S must have 3 characters.");
    }

    long long result = 0; // 최종 경우의 수 (long long 사용)
    char l1 = s[0];
    char l2 = s[1];
    char l3 = s[2];

    // 알파벳 문자가 아니면 예외 처리 (실제 문제 제약 조건 상 불필요)
    if (l1 < 'A' || l1 > 'Z' || l2 < 'A' || l2 > 'Z' || l3 < 'A' || l3 > 'Z') {
         throw std::invalid_argument("Team name S must consist of uppercase English letters.");
    }

    // 세 글자의 인덱스
    int idx1 = l1 - 'A';
    int idx2 = l2 - 'A';
    int idx3 = l3 - 'A';

    // Case 3: 세 글자가 모두 같은 경우 (e.g., DDD)
    if (l1 == l2 && l2 == l3) {
        long long k = counts[idx1];
        // k명 중에서 3명을 뽑는 조합 (k C 3)
        if (k >= 3) {
            // 순서: k * (k - 1) * (k - 2) / (3 * 2 * 1)
            result = k * (k - 1) / 2 * (k - 2) / 3; // 오버플로우 방지를 위해 나누기를 중간에 배치 고려 가능
                                                    // 여기서는 k가 크지 않다고 가정하고 단순 곱셈 후 나눗셈
                                                    // 더 안전하게: result = k; result = result * (k-1) / 2; result = result * (k-2) / 3;
            // 정확한 계산 및 오버플로우 최소화:
             if (k >= 3) {
                 result = k; // Use temporary variable of sufficient size if needed
                 result = result * (k - 1);
                 result = result / 2;
                 result = result * (k - 2);
                 result = result / 3;
             }
        }
    }
    // Case 2: 두 글자만 같은 경우 (e.g., SGS, DDS, SDD)
    else if (l1 == l2 || l1 == l3 || l2 == l3) {
        int idx_rep, idx_uniq; // 같은 글자 인덱스, 다른 글자 인덱스
        if (l1 == l2) {
            idx_rep = idx1;
            idx_uniq = idx3;
        } else if (l1 == l3) {
            idx_rep = idx1;
            idx_uniq = idx2;
        } else { // l2 == l3
            idx_rep = idx2;
            idx_uniq = idx1;
        }

        long long k = counts[idx_rep];  // 같은 글자로 시작하는 사람 수
        long long m = counts[idx_uniq]; // 다른 글자로 시작하는 사람 수

        // k명 중에서 2명을 뽑고 (k C 2), m명 중에서 1명을 뽑는 조합 (m C 1)
        if (k >= 2 && m >= 1) {
            // 순서: (k * (k-1) / 2) * m
            result = k * (k - 1) / 2 * m;
             // 오버플로우 최소화:
             if (k >= 2 && m >= 1) {
                 result = k;
                 result = result * (k - 1);
                 result = result / 2;
                 result = result * m;
             }
        }
    }
    // Case 1: 세 글자가 모두 다른 경우 (e.g., DPS)
    else {
        long long c1 = counts[idx1];
        long long c2 = counts[idx2];
        long long c3 = counts[idx3];

        // 각 그룹에서 1명씩 뽑는 경우 (c1 C 1 * c2 C 1 * c3 C 1)
        if (c1 >= 1 && c2 >= 1 && c3 >= 1) {
            result = c1 * c2 * c3;
        }
    }
    return result;
}

/**
 * @brief 핸들 목록으로부터 각 첫 글자의 빈도수를 계산합니다.
 * 
 * @param handles 핸들 문자열의 벡터
 * @param counts 결과를 저장할 크기 26의 long long 배열
 */
void generate_counts(const std::vector<std::string>& handles, long long counts[26]) {
    // 배열 초기화
    std::fill(counts, counts + 26, 0LL);
    for (const auto& handle : handles) {
        if (!handle.empty() && handle[0] >= 'A' && handle[0] <= 'Z') {
            counts[handle[0] - 'A']++;
        }
    }
}

TEST(DPSTest, Sample1) {
    std::string s = "DPS";
    std::vector<std::string> handles = {
        "DONGGAS", "PICASSO", "SEMTEO", "DJS", "WBCHO", "RAARARAARA", "WEASEL"
    };
    long long counts[26];
    generate_counts(handles, counts);
    // D: 2, P: 1, S: 1, W: 2, R: 1
    EXPECT_EQ(calculate_combinations(s, counts), 2LL); // 2 * 1 * 1 = 2
}

TEST(DPSTest, Sample2) {
    std::string s = "DDD";
    std::vector<std::string> handles = {
        "DONGGAS", "DJS", "DURAM", "DART"
    };
    long long counts[26];
    generate_counts(handles, counts);
    // D: 4
    EXPECT_EQ(calculate_combinations(s, counts), 4LL); // 4 C 3 = 4 * 3 * 2 / 6 = 4
}

TEST(DPSTest, Sample3) {
    std::string s = "SGS"; // S 두 개, G 한 개 필요
    std::vector<std::string> handles = {
        "GUMGOOD", "SHIFTPSH", "SHANDY", "SANGPIL"
    };
    long long counts[26];
    generate_counts(handles, counts);
    // G: 1, S: 3
    EXPECT_EQ(calculate_combinations(s, counts), 3LL); // (3 C 2) * (1 C 1) = (3 * 2 / 2) * 1 = 3
}

// 추가 테스트 케이스: 조합 불가능 (인원 부족)
TEST(DPSTest, InsufficientMembers) {
    std::string s = "ABC";
    std::vector<std::string> handles = {"APPLE", "BANANA"}; // 2명 뿐
    long long counts[26];
    generate_counts(handles, counts);
    // A: 1, B: 1
    EXPECT_EQ(calculate_combinations(s, counts), 0LL); // A, B는 있지만 C가 없음
}

// 추가 테스트 케이스: 조합 불가능 (필요한 중복 인원 부족)
TEST(DPSTest, InsufficientDuplicates) {
    std::string s = "AAB"; // A 2명, B 1명 필요
    std::vector<std::string> handles = {"APPLE", "BALL", "CAT"};
    long long counts[26];
    generate_counts(handles, counts);
    // A: 1, B: 1, C: 1
    EXPECT_EQ(calculate_combinations(s, counts), 0LL); // A가 1명뿐
}

// 추가 테스트 케이스: 조합 불가능 (필요한 3중 중복 인원 부족)
TEST(DPSTest, InsufficientTriples) {
    std::string s = "CCC"; // C 3명 필요
    std::vector<std::string> handles = {"CAT", "CHERRY", "DOG"};
    long long counts[26];
    generate_counts(handles, counts);
    // C: 2, D: 1
    EXPECT_EQ(calculate_combinations(s, counts), 0LL); // C가 2명뿐
}

// 추가 테스트 케이스: 정확히 필요한 만큼 있는 경우 (중복 포함)
TEST(DPSTest, ExactMatchDuplicates) {
    std::string s = "XXY"; // X 2명, Y 1명 필요
    std::vector<std::string> handles = {"XAVIER", "XENON", "YACHT"};
    long long counts[26];
    generate_counts(handles, counts);
    // X: 2, Y: 1
    EXPECT_EQ(calculate_combinations(s, counts), 1LL); // (2 C 2) * (1 C 1) = 1 * 1 = 1
}

// 추가 테스트 케이스: 정확히 필요한 만큼 있는 경우 (3중 중복)
TEST(DPSTest, ExactMatchTriples) {
    std::string s = "ZZZ"; // Z 3명 필요
    std::vector<std::string> handles = {"ZEBRA", "ZORRO", "ZIPPER"};
    long long counts[26];
    generate_counts(handles, counts);
    // Z: 3
    EXPECT_EQ(calculate_combinations(s, counts), 1LL); // 3 C 3 = 1
}

// 추가 테스트 케이스: 많은 인원수 (Distinct)
TEST(DPSTest, LargeCountsDistinct) {
    std::string s = "LMN";
    std::vector<std::string> handles;
    for(int i=0; i<10; ++i) handles.push_back("LION" + std::to_string(i)); // L: 10
    for(int i=0; i<20; ++i) handles.push_back("MOUSE" + std::to_string(i)); // M: 20
    for(int i=0; i<30; ++i) handles.push_back("NEWT" + std::to_string(i));  // N: 30
    long long counts[26];
    generate_counts(handles, counts);
    EXPECT_EQ(calculate_combinations(s, counts), 6000LL); // 10 * 20 * 30 = 6000
}

// 추가 테스트 케이스: 많은 인원수 (Two Same)
TEST(DPSTest, LargeCountsTwoSame) {
    std::string s = "PQP"; // P 2개, Q 1개 필요
    std::vector<std::string> handles;
    for(int i=0; i<15; ++i) handles.push_back("PANDA" + std::to_string(i)); // P: 15
    for(int i=0; i<25; ++i) handles.push_back("QUAIL" + std::to_string(i)); // Q: 25
    long long counts[26];
    generate_counts(handles, counts);
    // (15 C 2) * (25 C 1) = (15 * 14 / 2) * 25 = 105 * 25 = 2625
    EXPECT_EQ(calculate_combinations(s, counts), 2625LL);
}

// 추가 테스트 케이스: 많은 인원수 (All Same)
TEST(DPSTest, LargeCountsAllSame) {
    std::string s = "RRR"; // R 3개 필요
    std::vector<std::string> handles;
    for(int i=0; i<12; ++i) handles.push_back("RABBIT" + std::to_string(i)); // R: 12
    long long counts[26];
    generate_counts(handles, counts);
    // 12 C 3 = 12 * 11 * 10 / 6 = 2 * 11 * 10 = 220
    EXPECT_EQ(calculate_combinations(s, counts), 220LL);
}

// 추가 테스트 케이스: 중간에 0인 count가 있는 경우
TEST(DPSTest, ZeroCount) {
    std::string s = "EFG";
    std::vector<std::string> handles = {"ELEPHANT", "FISH1", "FISH2"}; // G가 없음
    long long counts[26];
    generate_counts(handles, counts);
    // E: 1, F: 2, G: 0
    EXPECT_EQ(calculate_combinations(s, counts), 0LL); // 1 * 2 * 0 = 0
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}