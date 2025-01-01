T = int(input())
for tc in range(1, T + 1):
    N = int(input())
    from collections import defaultdict
    count = defaultdict(int)
    for _ in range(2 * N - 1):
        lst = list(map(int, input().split()))
        for num in lst:
            count[num] += 1
    missing = sorted([num for num, cnt in count.items() if cnt % 2 == 1])
    print(f"Case #{tc}: {' '.join(map(str, missing))}")