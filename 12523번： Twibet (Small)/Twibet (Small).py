def solve():
    import sys
    input = sys.stdin.readline
    T = int(input().strip())
    results = []

    for t in range(1, T + 1):
        N = int(input().strip())
        follows = list(map(int, input().split()))
        followers = [[] for _ in range(N + 1)]
        for i in range(1, N + 1):
            f = follows[i - 1]
            followers[f].append(i)
        case_result = [f"Case #{t}:"]
        for day in range(1, N+1):
            visited = [False]*(N + 1)
            queue = [day]
            visited[day] = True
            count = 0
            while queue:
                monk = queue.pop(0)
                count += 1
                for fol in followers[monk]:
                    if not visited[fol]:
                        visited[fol] = True
                        queue.append(fol)
            case_result.append(str(count))
        results.append("\n".join(case_result))
    sys.stdout.write("\n".join(results))

if __name__ == "__main__":
    solve()