import sys

def solve():
    """
    배열과 연산 문제를 이분 매칭으로 해결하는 메인 함수
    """
    try:
        n_str, k_str = sys.stdin.readline().strip().split()
        n, k = int(n_str), int(k_str)
        a = list(map(int, sys.stdin.readline().strip().split()))
    except (IOError, ValueError) as e:
        print(f"입력 처리 중 오류 발생: {e}")
        return
    
    graph = [[] for _ in range(n)]
    for i in range(n):
        for j in range(1, n + 1):
            if j >= a[i] and (j - a[i]) % k == 0:
                graph[i].append(j - 1)

    match = [-1] * n
    match_count = 0
    for i in range(n):
        visited = [False] * n
        if dfs(i, graph, match, visited):
            match_count += 1

    if match_count == n:
        print(1)
    else:
        print(0)

def dfs(u, graph, match, visited):
    """
    DFS를 이용해 u번째 소스 노드에 대한 증가 경로를 찾는다.
    :param u: 현재 매칭을 시도하는 소스 노드 (A 배열의 인덱스)
    :param graph: 이분 그래프의 인접 리스트
    :param match: 현재 매칭 상태를 저장하는 배열
    :param visited: 현재 DFS 탐색에서 방문한 타겟 노드를 기록하는 배열
    :return: 증가 경로를 찾았으면 True, 아니면 False
    """
    for v in graph[u]:
        if not visited[v]:
            visited[v] = True
            if match[v] == -1 or dfs(match[v], graph, match, visited):
                match[v] = u
                return True
    return False

if __name__ == "__main__":
    solve()