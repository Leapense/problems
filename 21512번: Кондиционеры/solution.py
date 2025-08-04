import sys

def solve():
    n = int(sys.stdin.readline())
    required_powers = list(map(int, sys.stdin.readline().split()))
    m = int(sys.stdin.readline())

    MAX_POWER = 1000
    infinity = float('inf')
    
    min_cost_for_power = [infinity] * (MAX_POWER + 1)

    for _ in range(m):
        power, cost = map(int, sys.stdin.readline().split())
        if power <= MAX_POWER:
            min_cost_for_power[power] = min(min_cost_for_power[power], cost)

    for i in range(MAX_POWER - 1, 0, -1):
        min_cost_for_power[i] = min(min_cost_for_power[i], min_cost_for_power[i+1])

    total_cost = 0
    for power_needed in required_powers:
        total_cost += min_cost_for_power[power_needed]

    print(total_cost)

solve()