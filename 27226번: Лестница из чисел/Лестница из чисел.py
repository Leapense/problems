def generate_ladder(a, b, k):
    result = []

    for i in range(a, b + 1):
        start_num = 1 + (i * (i - 1)) // 2
        line = [start_num + j for j in range(min(i, k))]
        result.append(" ".join(map(str, line)))
    print("\n".join(result))

a = int(input())
b = int(input())
k = int(input())

generate_ladder(a, b, k)