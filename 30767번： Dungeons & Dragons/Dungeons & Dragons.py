def count_critical_hits(n, a, b, c, d):
    if a + c > n or b + d < n:
        return 0
    
    min_first_die = max(a, n - d)
    max_first_die = min(b, n - c)

    if min_first_die <= max_first_die:
        count = max_first_die - min_first_die + 1
    else:
        count = 0

    return count

n = int(input())
a = int(input())
b = int(input())
c = int(input())
d = int(input())

print(count_critical_hits(n, a, b, c, d))