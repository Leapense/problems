#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 100;

/* 전역 변수 선언 */
static int N;
static vector<int> adj[MAX_N + 1];

/* 1번에서 도달 가능한 정점 여부 */
static array<bool, MAX_N + 1> reachable{};

/* DFS 사이클 검사용 상태 배열: 0=미방문, 1=탐색 중, 2=탐색 완료 */
static array<int, MAX_N + 1> status{};

/**
 * DFS를 통해 정점 u로부터 adj를 타고 도달 가능한 모든 정점을
 * reachable[] 배열에 표시한다.
 */
static void dfs_mark_reachable(int u) {
    if (u < 1 || u > N || reachable[u]) {
        return;
    }
    reachable[u] = true;
    for (int v : adj[u]) {
        if (!reachable[v]) {
            dfs_mark_reachable(v);
        }
    }
}

/**
 * R 위에서만 사이클 존재 여부를 DFS로 판정한다.
 * status[u] == 1 상태의 정점으로 다시 들어오는 간선이 발견되면 사이클이다.
 */
static bool dfs_cycle_detect(int u) {
    status[u] = 1;  // 탐색 중
    for (int v : adj[u]) {
        if (!reachable[v]) {
            // 1번에서 도달 불가능한 정점은 건너뛴다
            continue;
        }
        if (status[v] == 0) {
            // 아직 방문하지 않은 정점이면 재귀 탐색
            if (dfs_cycle_detect(v)) {
                return true;
            }
        }
        else if (status[v] == 1) {
            // 탐색 중인 정점으로 간선을 다시 만난 경우 -> 사이클
            return true;
        }
        // status[v] == 2(탐색 완료)인 경우는 무시
    }
    status[u] = 2;  // 탐색 완료
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /* 1. 입력: N (교차로 개수) */
    if (!(cin >> N)) {
        return EXIT_FAILURE;
    }
    if (N < 1 || N > MAX_N) {
        return EXIT_FAILURE;
    }

    /* 2. 인접 리스트 초기화 */
    for (int i = 1; i <= N; i++) {
        adj[i].clear();
    }

    /* 3. 1번부터 N-1번까지 각 교차로의 outgoing 간선 정보 입력 */
    for (int u = 1; u <= N - 1; u++) {
        int M;
        cin >> M;
        if (M < 0 || M > N) {
            return EXIT_FAILURE;
        }
        for (int i = 0; i < M; i++) {
            int v;
            cin >> v;
            if (v < 1 || v > N) {
                return EXIT_FAILURE;
            }
            adj[u].push_back(v);
        }
    }
    // N번 교차로는 대피소: outgoing edges 없음

    /* 4. 1번에서 도달 가능한 정점 집합 R 구하기 */
    reachable.fill(false);
    dfs_mark_reachable(1);

    /* 5. R 위에서 사이클 탐색 */
    status.fill(0);
    for (int u = 1; u <= N; u++) {
        if (reachable[u] && status[u] == 0) {
            if (dfs_cycle_detect(u)) {
                cout << "CYCLE\n";
                return EXIT_SUCCESS;
            }
        }
    }

    /* 6. 사이클이 없으면 NO CYCLE */
    cout << "NO CYCLE\n";
    return EXIT_SUCCESS;
}