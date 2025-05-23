n, m = map(int, input().split())
a = list(map(int, input().split()))

current_stress = 0
days_with_pain = 0

for stress_change in a:
    current_stress += stress_change
    if current_stress < 0:
        current_stress = 0
    if current_stress >= m:
        days_with_pain += 1

print(days_with_pain)