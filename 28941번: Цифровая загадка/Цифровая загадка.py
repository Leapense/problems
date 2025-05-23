n, k = map(int, input().split())
nums = list(map(int, input().split()))
increments = []

for num in nums:
    s = str(num)
    length = len(s)
    for i, ch in enumerate(s):
        d = int(ch)
        if d < 9:
            pos = length - i - 1
            inc = (9 - d) * (10 ** pos)
            increments.append(inc)
increments.sort(reverse=True)
result = sum(increments[:k])
print(result)