from sys import stdin

MOD: int = 1_000_000_007

# Correct adjacency list (undirected, 0-based vertices)
ADJ: tuple[tuple[int, ...], ...] = (
    (1, 2),            # 0  Information Science
    (0, 2, 3),         # 1
    (0, 1, 3, 4),      # 2
    (1, 2, 4, 5),      # 3
    (2, 3, 5, 7),      # 4
    (3, 4, 6),         # 5
    (5, 7),            # 6
    (4, 6),            # 7
)

def count_walks(length: int) -> int:
    """Return the number of valid walks of exactly `length` minutes."""
    cur: list[int] = [0] * 8
    cur[0] = 1  # t = 0, at building 0

    for _ in range(length):
        nxt: list[int] = [0] * 8
        for v, ways in enumerate(cur):
            if ways == 0:
                continue
            for u in ADJ[v]:
                nxt[u] = (nxt[u] + ways) % MOD
        cur = nxt

    return cur[0]

def main() -> None:
    raw: str | None = stdin.readline()
    if raw is None:
        return
    d: int = int(raw.strip())
    print(count_walks(d))

if __name__ == "__main__":
    main()