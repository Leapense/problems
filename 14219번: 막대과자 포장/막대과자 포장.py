def can_fill_box(n, m):
    if (n * m) % 3 == 0:
        return "YES"
    else:
        return "NO"
    
n, m = map(int, input().strip().split())
print(can_fill_box(n, m))