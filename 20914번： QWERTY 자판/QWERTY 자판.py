from collections import deque

graph = {
    'Q': {'W','A'},
    'W': {'Q','E','A','S'},
    'E': {'W','R','S','D'},
    'R': {'E','T','D','F'},
    'T': {'R','Y','F','G'},
    'Y': {'T','U','G','H'},
    'U': {'Y','I','H','J'},
    'I': {'U','O','J','K'},
    'O': {'I','P','K','L'},
    'P': {'O','L'},
    'A': {'Q','W','S','Z'},
    'S': {'W','E','D','X','Z','A'},
    'D': {'E','R','F','C','X','S'},
    'F': {'R','T','G','V','C','D'},
    'G': {'T','Y','H','B','V','F'},
    'H': {'Y','U','J','N','B','G'},
    'J': {'U','I','K','M','N','H'},
    'K': {'I','O','L','M','J'},
    'L': {'O','P','K'},
    'Z': {'A','S','X'},
    'X': {'S','D','C','Z'},
    'C': {'D','F','V','X'},
    'V': {'F','G','B','C'},
    'B': {'G','H','N','V'},
    'N': {'H','J','M','B'},
    'M': {'J','K','N'}
}

dist = {k: {} for k in graph}

def bfs(start):
    q = deque([start])
    visited = {start: 0}
    while q:
        cur = q.popleft()
        for nxt in graph[cur]:
            if nxt not in visited:
                visited[nxt] = visited[cur] + 1
                q.append(nxt)
    return visited

for letter in graph:
    dist_map = bfs(letter)
    for k, v in dist_map.items():
        dist[letter][k] = v

def solve():
    import sys

    input = sys.stdin.readline
    T = int(input().strip())

    for _ in range(T):
        s = input().strip()
        time = 0
        time += len(s)
        for i in range(1, len(s)):
            steps = dist[s[i - 1]][s[i]]
            time += steps * 2
        print(time)

solve()