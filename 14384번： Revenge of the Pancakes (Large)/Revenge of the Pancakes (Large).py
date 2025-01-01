T = int(input())
for tc in range(1, T + 1):
    S = input().strip()
    flips = 0
    for i in range(1, len(S)):
        if S[i] != S[i - 1]:
            flips += 1
    if S[-1] == '-':
        flips += 1
    print(f"Case #{tc}: {flips}")