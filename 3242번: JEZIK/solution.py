import sys
from collections import deque

def main():
    lines = []
    for raw in sys.stdin:
        line = raw.rstrip('\n')
        if line.strip() == '.':
            break
        lines.append(line.strip())

    n = len(lines)
    # adjacency list for 1..n
    adj = [[] for _ in range(n+1)]

    for i, line in enumerate(lines, start=1):
        tokens = line.split()
        cmd = tokens[0]
        if cmd == 'RADI':
            # jump to i+1 if within [1..n]
            if 1 <= i+1 <= n:
                adj[i].append(i+1)

        elif cmd == 'IDI':
            # 'IDI a' or 'IDI a ILI b'
            a = int(tokens[1])
            if 1 <= a <= n:
                adj[i].append(a)
            if len(tokens) == 4 and tokens[2] == 'ILI':
                b = int(tokens[3])
                if 1 <= b <= n:
                    adj[i].append(b)

        else:
            # unknown command—ignore
            pass

    # BFS from function 1, if it exists
    visited = [False] * (n+1)
    if n >= 1:
        dq = deque([1])
        visited[1] = True
        while dq:
            u = dq.popleft()
            for v in adj[u]:
                if not visited[v]:
                    visited[v] = True
                    dq.append(v)

    # Count functions never visited
    unreachable = sum(1 for i in range(1, n+1) if not visited[i])
    print(unreachable)


if __name__ == "__main__":
    main()