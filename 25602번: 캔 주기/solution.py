import sys
sys.setrecursionlimit(2000)

def solve():
    n, k = map(int, sys.stdin.readline().split())
    initial_can_counts = tuple(map(int, sys.stdin.readline().split()))
    rangi_satisfaction = [list(map(int, sys.stdin.readline().split())) for _ in range(k)]
    merry_satisfaction = [list(map(int, sys.stdin.readline().split())) for _ in range(k)]
    memo = {}
    def find_max_satisfaction(day, can_counts):
        if day == k:
            return 0
        
        state = (day, can_counts)
        if state in memo:
            return memo[state]
        
        max_found_satisfaction = 0

        for rangi_can in range(n):
            for merry_can in range(n):
                if rangi_can == merry_can:
                    if can_counts[rangi_can] >= 2:
                        current_day_satisfaction = rangi_satisfaction[day][rangi_can] + merry_satisfaction[day][merry_can]
                        next_can_counts = list(can_counts)
                        next_can_counts[rangi_can] -= 2
                        future_satisfaction = find_max_satisfaction(day + 1, tuple(next_can_counts))
                        max_found_satisfaction = max(max_found_satisfaction, current_day_satisfaction + future_satisfaction)
                else:
                    if can_counts[rangi_can] >= 1 and can_counts[merry_can] >= 1:
                        current_day_satisfaction = rangi_satisfaction[day][rangi_can] + merry_satisfaction[day][merry_can]
                        next_can_counts = list(can_counts)
                        next_can_counts[rangi_can] -= 1
                        next_can_counts[merry_can] -= 1
                        future_satisfaction = find_max_satisfaction(day + 1, tuple(next_can_counts))
                        max_found_satisfaction = max(max_found_satisfaction, current_day_satisfaction + future_satisfaction)
        memo[state] = max_found_satisfaction
        return max_found_satisfaction
    total_max_satisfaction = find_max_satisfaction(0, initial_can_counts)
    print(total_max_satisfaction)

solve()