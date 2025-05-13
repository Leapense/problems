import sys

def main():
    data = sys.stdin.read().split()
    if not data:
        return
    
    it = iter(data)
    N = int(next(it))
    M = int(next(it))
    max_edges = N * (N - 1) // 2

    adj = [0] * N
    total = 0
    for _ in range(M):
        a = int(next(it)) - 1
        b = int(next(it)) - 1
        mask = 1 << b
        if not (adj[a] & mask):
            adj[a] |= mask
            total += 1
        mask = 1 << a
        if not (adj[b] & mask):
            adj[b] |= mask
    days = []
    while total < max_edges:
        new_edges = []
        for u in range(N):
            au = adj[u]
            for v in range(u + 1, N):
                if not (au >> v) & 1:
                    if (au & adj[v]) != 0:
                        new_edges.append((u, v))

        cnt = len(new_edges)
        if cnt == 0:
            break
        days.append(cnt)
        total += cnt
        for u, v in new_edges:
            adj[u] |= 1 << v
            adj[v] |= 1 << u
    out = []
    out.append(str(len(days)))
    out.extend(str(x) for x in days)
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()