#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <string>
#include <gtest/gtest.h>

using namespace std;

constexpr double EPS = 1e-6;

struct Point {
    double x, y;
};

// 부동소수점 비교 함수
bool isEqual(double a, double b) {
    return fabs(a - b) <= EPS;
}

// 두 점 사이의 거리 계산 함수
double distance(const Point& a, const Point& b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

// 두 벡터의 내적 계산 함수
double dotProduct(const Point& a, const Point& b) {
    return a.x * b.x + a.y * b.y;
}

// 문제 해결 로직을 구현한 함수
// 입력 스트림과 출력 스트림을 받아 처리할 수 있도록 함
void solve(istream &in, ostream &out) {
    int testCases;
    in >> testCases;
    
    for (int t = 1; t <= testCases; t++){
        int p;
        in >> p;
        vector<Point> points(p);
        for (int i = 0; i < p; i++){
            in >> points[i].x >> points[i].y;
        }
        
        int count = 0;
        // 모든 두 점 A, B에 대하여 진행 (중복 방지를 위해 i < j)
        for (int i = 0; i < p; i++){
            for (int j = i + 1; j < p; j++){
                // A와 B의 중점
                Point mid = {(points[i].x + points[j].x) / 2.0, (points[i].y + points[j].y) / 2.0};
                
                // 중점이 실제 입력 점 목록에 존재하는지 확인
                int mIndex = -1;
                for (int k = 0; k < p; k++){
                    if (isEqual(points[k].x, mid.x) && isEqual(points[k].y, mid.y)){
                        mIndex = k;
                        break;
                    }
                }
                if (mIndex == -1) continue;
                
                double AB = distance(points[i], points[j]);
                
                // 후보 C를 검색 (A, B, M와 인덱스가 겹치면 안 됨)
                for (int c = 0; c < p; c++){
                    if (c == i || c == j || c == mIndex)
                        continue;
                    
                    double MC = distance(points[c], points[mIndex]);
                    if (!isEqual(MC, AB))
                        continue;
                    
                    // 벡터 (A - M)와 (C - M)의 내적 확인 (90도이면 0)
                    Point vecAM = {points[i].x - points[mIndex].x, points[i].y - points[mIndex].y};
                    Point vecCM = {points[c].x - points[mIndex].x, points[c].y - points[mIndex].y};
                    
                    if (!isEqual(dotProduct(vecAM, vecCM), 0.0))
                        continue;
                    
                    // 조건을 모두 만족한 경우 T 모양을 형성하는 네 점
                    count++;
                }
            }
        }
        
        out << "Set #" << t << ": " << count << "\n\n";
    }
}

// main() 함수: gtest를 사용하는 경우 테스트 실행, 그렇지 않은 경우 표준 입력/출력 사용
#ifndef UNITTEST
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve(cin, cout);
    return 0;
}
#endif

// gtest 단위 테스트 코드 (컴파일 시 -DUNITTEST 플래그를 정의하면 실행됨)
#ifdef UNITTEST

// 샘플 입력 및 출력 검증 테스트
TEST(DotTheIsAndCrossTheTsTest, SampleTestCases) {
    {
        // 첫 번째 샘플 테스트 케이스
        string input = R"(2
5
5.0 2.0
3.0 6.0
5.0 6.0
7.0 6.0
5.0 10.0
4
-3.0 6.0
0.0 6.0
3.0 6.0
0.0 12.0
)";
        // 예상 출력 문자열 (빈 줄 포함)
        string expected_output = R"(Set #1: 2

Set #2: 1

)";
        stringstream in(input);
        stringstream out;
        solve(in, out);
        EXPECT_EQ(out.str(), expected_output);
    }
    
    // 추가적인 케이스를 원한다면 이와 같은 방식으로 테스트를 작성할 수 있음.
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif