class CommonAnagrams:
    def __init__(self):
        pass

    def solve(self):
        import sys
        from collections import defaultdict

        T = int(sys.stdin.readline())
        for tc in range(1, T + 1):
            L = int(sys.stdin.readline())
            A = sys.stdin.readline().strip()
            B = sys.stdin.readline().strip()
            b_signatures = defaultdict(set)
            for i in range(L):
                count = [0] * 26
                for j in range(i, L):
                    count[ord(B[j]) - 65] += 1
                    b_signatures[j - i + 1].add(tuple(count))
            count_ans = 0
            for i in range(L):
                count_a = [0] * 26
                for j in range(i, L):
                    count_a[ord(A[j])-65] += 1
                    if tuple(count_a) in b_signatures[j - i + 1]:
                        count_ans += 1
            print(f"Case #{tc}: {count_ans}")
CommonAnagrams().solve()
