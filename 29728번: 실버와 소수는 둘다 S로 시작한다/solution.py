import sys, math

n = int(sys.stdin.readline())

# --- 소수 테이블 ---
prime = [True]*(n+1)
if n >= 0:
    prime[0] = False
if n >= 1:
    prime[1] = False
limit = int(math.isqrt(n))
for i in range(2, limit+1):
    if prime[i]:
        for j in range(i*i, n+1, i):
            prime[j] = False

# --- 시뮬레이션(문자 수만 추적) ---
length = 0
cntB = 0
cntS = 0
first = last = None

for i in range(1, n+1):
    if prime[i]:                     # 소수 차례
        if length and last == 'B':   # B → S 치환
            cntB -= 1
            cntS += 1
            last = 'S'
            if length == 1:          # 길이 1이면 first 도 동일 문자
                first = 'S'
        # S 하나 추가
        if length == 0:
            first = last = 'S'
        else:
            last = 'S'
        cntS += 1
        length += 1
        # 뒤집기 ⇒ first, last swap
        if length > 1:
            first, last = last, first
    else:                            # 소수가 아님
        if length == 0:
            first = last = 'B'
        else:
            last = 'B'
        cntB += 1
        length += 1

print(cntB, cntS)