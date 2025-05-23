n = int(input())
result = []
seen = set()
for _ in range(n):
    word = input().strip()
    key = ''.join(sorted(word))
    if key not in seen:
        seen.add(key)
        result.append(word)
print('\n'.join(result))