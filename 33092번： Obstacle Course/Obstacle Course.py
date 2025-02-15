def solve():
    import sys
    input = sys.stdin.readline

    N = int(input().strip())
    A = list(map(int, input().split()))

    odd_positions = []
    odd_values = []
    for i in range(N):
        if i % 2 == 0:
            odd_positions.append(i)
            odd_values.append(A[i])
    M = len(odd_values)

    max_candidate = 0

    start = 0
    i = 0
    while i < M:
        while i + 1 < M and abs(odd_values[i + 1] - odd_values[i]) in (0, 2):
            i += 1
        
        c = i - start + 1
        left_odd = odd_positions[start]
        right_odd = odd_positions[i]

        candidate = (2 * c - 1)

        if left_odd > 0:
            candidate += 1

        if right_odd < N - 1:
            candidate += 1
        
        max_candidate = max(max_candidate, candidate)
        i += 1
        start = i
    
    max_candidate = max(max_candidate, 2)
    max_candidate = min(max_candidate, N)
    print(max_candidate)

if __name__ == '__main__':
    solve()