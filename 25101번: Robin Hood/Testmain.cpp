#include <iostream>
#include <sstream>
#include <queue>
#include <vector>
#ifdef UNIT_TEST
#include <gtest/gtest.h>
#endif

using namespace std;

// Candidate 구조체: 각 대상의 현재 재산과 원래 인덱스를 저장
struct Candidate {
    long long wealth;
    int index;
};

// 사용자 정의 비교 함수: 우선순위 큐에서 재산이 큰 순으로, 재산이 같다면 인덱스가 작은 순으로 정렬
struct Compare {
    bool operator()(const Candidate &a, const Candidate &b) const {
        if (a.wealth == b.wealth)
            return a.index > b.index;  // 인덱스가 작은 것이 우선
        return a.wealth < b.wealth;      // 재산이 큰 것이 우선
    }
};

// solve 함수: 입력 스트림 in에서 데이터를 읽어 결과를 출력 스트림 out에 출력
void solve(istream &in, ostream &out) {
    int N, K;
    in >> N >> K;
    
    vector<long long> wealths(N);
    for (int i = 0; i < N; i++) {
        in >> wealths[i];
    }
    
    // 우선순위 큐에 도둑질 가능한 후보(현재 재산이 100 초과)를 삽입
    priority_queue<Candidate, vector<Candidate>, Compare> pq;
    for (int i = 0; i < N; i++) {
        if (wealths[i] > 100) {
            pq.push({wealths[i], i});
        }
    }
    
    // K번의 도둑질 시뮬레이션
    for (int i = 0; i < K; i++) {
        // 도둑질 가능한 대상이 없으면 impossible 출력 후 종료
        if (pq.empty()) {
            out << "impossible";
            return;
        }
        Candidate current = pq.top();
        pq.pop();
        
        // 100 단위로 도둑질 진행
        wealths[current.index] -= 100;
        
        // 도둑질 후 금액이 100 초과이면 다시 후보로 삽입
        if (wealths[current.index] > 100) {
            pq.push({wealths[current.index], current.index});
        }
    }
    
    // 최종 결과를 입력 순서대로 출력
    for (int i = 0; i < N; i++) {
        out << wealths[i];
        if (i < N - 1)
            out << " ";
    }
}

#ifndef UNIT_TEST
// 일반 실행 시 표준 입출력을 사용하는 main 함수
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve(cin, cout);
    
    return 0;
}
#else
// Google Test를 사용하는 경우, 테스트 케이스들을 작성합니다.

TEST(RobinHoodTest, SampleTest1) {
    // Sample Input 1:
    // 4 2
    // 100 120 250 13
    // Sample Output 1: 100 120 50 13
    string input = "4 2\n100 120 250 13\n";
    string expected_output = "100 120 50 13";
    stringstream ss(input), out;
    
    solve(ss, out);
    
    EXPECT_EQ(out.str(), expected_output);
}

TEST(RobinHoodTest, SampleTest2) {
    // Sample Input 2:
    // 4 4
    // 100 120 250 13
    // Sample Output 2: impossible
    string input = "4 4\n100 120 250 13\n";
    string expected_output = "impossible";
    stringstream ss(input), out;
    
    solve(ss, out);
    
    EXPECT_EQ(out.str(), expected_output);
}

TEST(RobinHoodTest, SampleTest3) {
    // Sample Input 3:
    // 3 4
    // 200 300 300
    // Sample Output 3: 100 100 200
    string input = "3 4\n200 300 300\n";
    string expected_output = "100 100 200";
    stringstream ss(input), out;
    
    solve(ss, out);
    
    EXPECT_EQ(out.str(), expected_output);
}

// Google Test의 main 함수
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif

