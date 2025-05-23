def max_painted_spoons(A, B):
    if A == 0 or B == 0:
        return 0
    return (A * B) // (A + B)

A, B = map(int, input().split())
print(max_painted_spoons(A, B))