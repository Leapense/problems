n = int(input())

for _ in range(n):
    s = input().strip()
    transitions = 0
    length = len(s)

    for i in range(length):
        if s[i] != s[(i+1) % length]:
            transitions += 1
    print(transitions // 2 - 1)