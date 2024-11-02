def find_t(n, k):
    if k == 1:
        if n == 1:
            return 0
        else:
            return -1
    if (n - 1) % (k - 1) == 0:
        t = (n - 1) // (k - 1)
        return t
    else:
        return -1

# Input reading
n, k = map(int, input().split())

# Output the result
print(find_t(n, k))