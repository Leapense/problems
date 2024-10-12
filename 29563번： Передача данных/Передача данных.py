def can_transform_with_one_transposition(s, t):
    if s == t:
        return "YES"
    
    diff_indices = []

    for i in range(len(s)):
        if s[i] != t[i]:
            diff_indices.append(i)

    if len(diff_indices) != 2:
        return "NO"
    
    i, j = diff_indices
    if j != i + 1:
        return "NO"

    if s[i] == t[j] and s[j] == t[i]:
        return "YES"

    return "NO"

s = input().strip()
t = input().strip()

print(can_transform_with_one_transposition(s, t))