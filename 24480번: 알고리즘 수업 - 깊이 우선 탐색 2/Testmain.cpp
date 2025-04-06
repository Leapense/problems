#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include "gtest/gtest.h"

using namespace std;

int N, M, R;
vector<vector<int>> graph;
vector<int> visitOrder;
int order;

// DFS 함수 (내림차순 인접 리스트 방문)
void dfs(int node) {
    visitOrder[node] = order++;
    for (int next : graph[node]) {
        if (visitOrder[next] == 0) {
            dfs(next);
        }
    }
}

// 문제 해결 함수
void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M >> R;
    graph.clear();
    visitOrder.clear();
    order = 1;
    
    graph.resize(N + 1);
    visitOrder.resize(N + 1, 0);
    
    // 그래프 정보 입력 받기 (무방향)
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    // 각 인접 리스트를 내림차순으로 정렬
    for (int i = 1; i <= N; i++) {
        sort(graph[i].rbegin(), graph[i].rend());
    }
    
    dfs(R);
    
    // 각 정점의 방문 순서 출력
    for (int i = 1; i <= N; i++) {
        cout << visitOrder[i] << "\n";
    }
}

// GTest를 활용한 테스트 케이스
TEST(DFSTest, SampleInputTest) {
    string input = "5 5 1\n1 4\n1 2\n2 3\n2 4\n3 4\n";
    string expectedOutput = "1\n4\n3\n2\n0\n";

    streambuf* origCin = cin.rdbuf();
    streambuf* origCout = cout.rdbuf();
    
    istringstream iss(input);
    ostringstream oss;
    cin.rdbuf(iss.rdbuf());
    cout.rdbuf(oss.rdbuf());
    
    solve();
    
    cin.rdbuf(origCin);
    cout.rdbuf(origCout);
    
    // 디버깅용: 캡처한 출력을 출력
    cout << "캡처한 출력:\n" << oss.str() << "\n";
    
    EXPECT_EQ(oss.str(), expectedOutput);
}

// 추가 테스트 케이스를 원한다면 아래에 더 작성할 수 있습니다.
TEST(DFSTest, DisconnectedGraphTest) {
    // 정점 6개, 간선 3개, 시작 정점 1인 경우
    // 정점 4, 5, 6은 연결되어 있지 않으면 방문 순서는 0으로 출력되어야 함.
    string input = "6 3 1\n1 2\n2 3\n1 3\n";
    // DFS: 1에서 시작, 내림차순이므로 3 -> 2 순으로 방문
    // 1: 1, 3: 2, 2: 3, 4,5,6: 0
    string expectedOutput = "1\n3\n2\n0\n0\n0\n";
    
    streambuf* origCin = cin.rdbuf();
    streambuf* origCout = cout.rdbuf();
    
    istringstream iss(input);
    ostringstream oss;
    cin.rdbuf(iss.rdbuf());
    cout.rdbuf(oss.rdbuf());
    
    solve();
    
    cin.rdbuf(origCin);
    cout.rdbuf(origCout);
    
    EXPECT_EQ(oss.str(), expectedOutput);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
