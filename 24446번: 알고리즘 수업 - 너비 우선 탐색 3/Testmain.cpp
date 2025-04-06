#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <gtest/gtest.h>

using namespace std;

// BFS 문제 해결 함수
// 입력 스트림에서 데이터를 읽어, 출력 스트림에 결과를 출력하는 함수
void solve(istream &in, ostream &out) {
    int N, M, R;
    in >> N >> M >> R;
    
    // 인접 리스트 구성 (정점 번호 1부터 시작)
    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; i++){
        int u, v;
        in >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    // 각 정점의 인접 리스트를 내림차순 정렬
    for (int i = 1; i <= N; i++){
        sort(graph[i].rbegin(), graph[i].rend());
    }
    
    // 각 정점의 깊이를 저장하는 배열 (-1: 미방문)
    vector<int> depth(N + 1, -1);
    
    // BFS 구현
    queue<int> q;
    depth[R] = 0;
    q.push(R);
    
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (int nxt : graph[cur]){
            if (depth[nxt] == -1){
                depth[nxt] = depth[cur] + 1;
                q.push(nxt);
            }
        }
    }
    
    // 결과 출력
    for (int i = 1; i <= N; i++){
        out << depth[i] << "\n";
    }
}

// Google Test를 활용한 단위 테스트
TEST(BFSTest, SampleTest) {
    // 샘플 입력
    string input = R"(5 5 1
1 4
1 2
2 3
2 4
3 4
)";
    // 예상되는 출력 결과
    string expected_output = R"(0
1
2
1
-1
)";
    stringstream in(input);
    stringstream out;
    
    solve(in, out);
    
    string result = out.str();
    // 결과가 예상과 동일한지 확인 (일치하지 않을 경우 상세 로그 출력)
    EXPECT_EQ(result, expected_output) << "출력 결과가 예상과 다릅니다.\n"
                                         << "입력:\n" << input << "\n"
                                         << "예상 출력:\n" << expected_output << "\n"
                                         << "실제 출력:\n" << result << "\n";
}

// 수정된 테스트 케이스: 단순 연결 그래프
TEST(BFSTest, SimpleGraphTest) {
    // 정점 4개, 간선 3개, 시작정점 2
    string input = R"(4 3 2
1 2
2 3
3 4
)";
    // 정점 1은 정점 2와 연결되어 있으므로, BFS 결과는
    // 정점 1: 깊이 1, 정점 2: 깊이 0, 정점 3: 깊이 1, 정점 4: 깊이 2
    string expected_output = R"(1
0
1
2
)";
    stringstream in(input);
    stringstream out;
    
    solve(in, out);
    
    string result = out.str();
    EXPECT_EQ(result, expected_output) << "SimpleGraphTest 실패: 입력:\n" << input 
                                         << "\n예상 출력:\n" << expected_output 
                                         << "\n실제 출력:\n" << result << "\n";
}

// 추가 테스트 케이스 예시 2: 분리된 그래프 (방문 불가능한 정점 존재)
TEST(BFSTest, DisconnectedGraphTest) {
    // 정점 6개, 간선 3개, 시작정점 1
    string input = R"(6 3 1
1 2
2 3
4 5
)";
    // 정점 4, 5, 6는 시작정점 1과 연결되어 있지 않으므로 깊이는 -1로 출력되어야 한다.
    string expected_output = R"(0
1
2
-1
-1
-1
)";
    stringstream in(input);
    stringstream out;
    
    solve(in, out);
    
    string result = out.str();
    EXPECT_EQ(result, expected_output) << "DisconnectedGraphTest 실패: 입력:\n" << input 
                                         << "\n예상 출력:\n" << expected_output 
                                         << "\n실제 출력:\n" << result << "\n";
}

// 메인 함수: Google Test 실행
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
