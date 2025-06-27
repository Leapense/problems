import sys

sys.setrecursionlimit(2000)

def solve():
    N, P = map(int, input().split())
    groups = list(map(int, input().split()))

    counts = [0] * P
    for g in groups:
        counts[g % P] += 1

    if P == 2:
        return solve_p2(counts)
    if P == 3:
        return solve_p3(counts)
    return solve_p4(counts)

def solve_p2(counts):
    return counts[0] + (counts[1] + 1) // 2

def solve_p3(counts):
    memo = {}
    c1, c2 = counts[1], counts[2]

    def run_dp(c1, c2, rem):
        state = (c1, c2, rem)
        if state in memo:
            return memo[state]
        if c1 == 0 and c2 == 0:
            return 0
        
        future_outcomes = []
        if c1 > 0:
            future_outcomes.append(run_dp(c1 - 1, c2, (rem + 1) % 3))
        if c2 > 0:
            future_outcomes.append(run_dp(c1, c2 - 1, (rem + 2) % 3))

        best_future = max(future_outcomes)

        is_fresh = 1 if rem == 0 else 0 

        result = is_fresh + best_future
        memo[state] = result
        return result
    
    additional_fresh = 0
    if c1 > 0 or c2 > 0:
        additional_fresh = run_dp(c1, c2, 0)

    return counts[0] + additional_fresh

def solve_p4(counts):
    memo = {}
    ans = counts[0]
    pairs_1_3 = min(counts[1], counts[3])
    ans += pairs_1_3
    pairs_2_2 = counts[2] // 2

    ans += pairs_2_2
    c1 = counts[1] - pairs_1_3
    c2 = counts[2] % 2
    c3 = counts[3] - pairs_1_3

    def run_dp(c1, c2, c3, rem):
        state = (c1, c2, c3, rem)
        if state in memo:
            return memo[state]
        if c1 == 0 and c2 == 0 and c3 == 0:
            return 0
        
        future_outcomes = []
        if c1 > 0:
            future_outcomes.append(run_dp(c1 - 1, c2, c3, (rem + 1) % 4))
        if c2 > 0:
            future_outcomes.append(run_dp(c1, c2 - 1, c3, (rem + 2) % 4))
        if c3 > 0:
            future_outcomes.append(run_dp(c1, c2, c3 - 1, (rem + 3) % 4))

        best_future = max(future_outcomes)
        is_fresh = 1 if rem == 0 else 0

        result = is_fresh + best_future
        memo[state] = result
        return result
    
    if c1 > 0 or c2 > 0 or c3 > 0:
        ans += run_dp(c1, c2, c3, 0)

    return ans

if __name__ == "__main__":
    T = int(input())
    for i in range(1, T + 1):
        result = solve()
        print(f"Case #{i}: {result}")