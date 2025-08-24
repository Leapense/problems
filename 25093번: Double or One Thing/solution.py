def solve(s):
    n = len(s)
    result = []

    for i in range(n):
        result.append(s[i])
        if i < n - 1:
            j = i + 1
            while j < n and s[j] == s[i]:
                j += 1
            if j < n and s[i] < s[j]:
                result.append(s[i])
    return ''.join(result)

T = int(input())
for case_num in range(1, T + 1):
    S = input().strip()
    result = solve(S)
    print(f"Case #{case_num}: {result}")