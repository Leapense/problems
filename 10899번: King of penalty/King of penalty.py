def main():
    import sys

    def solve():
        import sys

        P, N = map(int, sys.stdin.readline().split())
        Ti = list(map(int, sys.stdin.readline().split()))
        Ti_sorted = sorted(Ti)
        prefix_sum = [0] * (N +1)
        for i in range(N):
            prefix_sum[i+1] = prefix_sum[i] + Ti_sorted[i]
            if prefix_sum[i+1] > P -1:
                # No need to compute further, but continue to compute full prefix_sum
                pass

        # Binary search to find maximum K where prefix_sum[K] <= P-1
        left =0
        right =N
        while left < right:
            mid = (left + right +1)//2
            if prefix_sum[mid] <= P -1:
                left =mid
            else:
                right =mid -1
        K=left
        if K ==0:
            print(0,0)
            return
        selected_Ti = Ti_sorted[:K]
        selected_Ti_sorted_desc = sorted(selected_Ti, reverse=True)
        sum_Tj = sum(selected_Ti_sorted_desc)
        S = P - sum_Tj -1
        if S <0:
            S =0
        sum_penalty =0
        for idx in range(K):
            multiplier = K - idx
            sum_penalty += multiplier * selected_Ti_sorted_desc[idx]
        total_penalty = K * S + sum_penalty
        print(K, total_penalty)

    solve()
main()