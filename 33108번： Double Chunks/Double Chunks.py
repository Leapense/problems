def main():
    import sys
    input = sys.stdin.readline

    N = int(input().strip())
    A = list(map(int, input().split()))

    pairs_by_sum = {}

    for i in range(N - 1):
        pair_sum = A[i] + A[i + 1]
        if pair_sum not in pairs_by_sum:
            pairs_by_sum[pair_sum] = []
        pairs_by_sum[pair_sum].append(i)

    def max_pairs(indices):
        count = 0
        last = -2

        for idx in indices:
            if idx >= last + 2:
                count += 1
                last = idx
        return count
    
    answer = 0
    for indices in pairs_by_sum.values():
        answer = max(answer, max_pairs(indices))

    print(answer)

if __name__ == "__main__":
    main()