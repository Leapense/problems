def max_uospc_count(n, s):
    needed_chars = "uospc"
    char_count = {char: 0 for char in needed_chars}

    for char in s:
        if char in char_count:
            char_count[char] += 1

    max_count = float('inf')
    for char in needed_chars:
        max_count = min(max_count, char_count[char])

    return max_count

n = int(input())
s = input().strip()

print(max_uospc_count(n, s))