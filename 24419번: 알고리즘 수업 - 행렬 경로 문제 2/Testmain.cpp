#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

const long long MOD = 1000000007;

// 모듈러 거듭제곱 (fast power)
long long modPow(long long a, long long b, long long mod) {
    long long res = 1;
    a %= mod;
    while (b) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

// 모듈러 역원 (페르마의 소정리 이용)
long long modInverse(long long x, long long mod) {
    return modPow(x, mod - 2, mod);
}

// 문제의 풀이 함수: 입력 스트림을 받아 결과 문자열을 리턴
string solve(istream &in) {
    int n;
    in >> n;
    
    // 행렬 입력 (실제 계산에는 값이 영향이 없으므로 단순히 입력만 받음)
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            in >> matrix[i][j];
        }
    }
    
    // 코드1: 재귀호출 기저조건의 실행 횟수 = 조합 C(2n, n) mod MOD
    int maxVal = 2 * n;
    vector<long long> fact(maxVal + 1), invFact(maxVal + 1);
    fact[0] = 1;
    for (int i = 1; i <= maxVal; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[maxVal] = modInverse(fact[maxVal], MOD);
    for (int i = maxVal; i >= 1; i--) {
        invFact[i - 1] = (invFact[i] * i) % MOD;
    }
    long long code1 = (fact[2 * n] * ((invFact[n] * invFact[n]) % MOD)) % MOD;
    
    // 코드2: 동적 프로그래밍 내부의 for문 실행 횟수 = n * n
    long long code2 = (long long)n * n % MOD;
    
    ostringstream oss;
    oss << code1 << " " << code2;
    return oss.str();
}

#ifdef UNIT_TEST
#include <gtest/gtest.h>

TEST(MatrixPathTest, SampleTest1) {
    string input =
        "5\n"
        "1 1 1 1 1\n"
        "2 2 2 2 2\n"
        "3 3 3 3 3\n"
        "4 4 4 4 4\n"
        "5 5 5 5 5\n";
    string expected = "252 25";
    istringstream iss(input);
    string output = solve(iss);
    EXPECT_EQ(output, expected);
}

TEST(MatrixPathTest, SampleTest2) {
    ostringstream oss;
    oss << "20\n";
    oss << "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1\n";
    oss << "2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2\n";
    oss << "3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3\n";
    oss << "4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4\n";
    oss << "5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5\n";
    oss << "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1\n";
    oss << "2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2\n";
    oss << "3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3\n";
    oss << "4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4\n";
    oss << "5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5\n";
    oss << "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1\n";
    oss << "2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2\n";
    oss << "3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3\n";
    oss << "4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4\n";
    oss << "5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5\n";
    oss << "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1\n";
    oss << "2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2\n";
    oss << "3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3\n";
    oss << "4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4\n";
    oss << "5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5\n";
    
    string input = oss.str();
    string expected = "846527861 400";
    istringstream iss(input);
    string output = solve(iss);
    EXPECT_EQ(output, expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#else
// gtest를 사용하지 않을 때는 단순히 표준 입력으로부터 입력받아 결과를 출력합니다.
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout << solve(cin) << "\n";
    return 0;
}
#endif
