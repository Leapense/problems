def solve():
    import sys
    input = sys.stdin.readline

    S = input().strip()
    n = len(S)

    divisors = []

    i = 1
    while i * i <= n:
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n // i)
        i += 1
    divisors.sort()

    for d in divisors:
        if d == n:
            break
        root = S[:d]
        from collections import Counter
        root_counter = Counter(root)

        piece_count = n // d

        is_multigram = True
        for idx in range(1, piece_count):
            piece = S[idx * d : (idx + 1) * d]
            piece_counter = Counter(piece)
            if piece_counter != root_counter:
                is_multigram = False
                break
        if is_multigram:
            print(root)
            return
        
    print(-1)

solve()