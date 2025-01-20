def get_max_k(p, a, b):
    max_k = 0
    k = 1
    while True:
        power = p ** k
        if power > b:
            break
        if b // power - (a - 1) // power >= 1:
            max_k = k
        k += 1
    return max_k

a, b = map(int, input().split())
k2 = get_max_k(2, a, b)
k5 = get_max_k(5, a, b)
print(min(k2, k5))