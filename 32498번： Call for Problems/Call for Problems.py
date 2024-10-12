def count_excluded_problems(n, diff):
    excluded_count = 0

    for d in diff:
        if d % 2 != 0:
            excluded_count += 1

    return excluded_count

n = int(input())
diff = [int(input()) for _ in range(n)]

print(count_excluded_problems(n, diff))