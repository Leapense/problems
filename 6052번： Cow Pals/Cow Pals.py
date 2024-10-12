S = int(input())

N = 20000
spd = [0] * (N + 1)

# 각 수의 약수의 합(자기 자신 제외)을 계산
for i in range(1, N // 2 + 1):
    for j in range(2 * i, N + 1, i):
        spd[j] += i

# S부터 시작하여 superpal을 찾음
for n in range(S, N + 1):
    m = spd[n]
    if m != n and m <= N:
        s = spd[m]
        if s == n:
            print(f"{n} {m}")
            break
