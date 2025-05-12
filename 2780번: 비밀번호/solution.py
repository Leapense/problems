import sys

MOD = 1_234_567

# 0이 7 아래에만 붙어 있는 키패드 인접 정보
ADJ = {
    0: [7],
    1: [2, 4],
    2: [1, 3, 5],
    3: [2, 6],
    4: [1, 5, 7],
    5: [2, 4, 6, 8],
    6: [3, 5, 9],
    7: [4, 8, 0],
    8: [5, 7, 9],
    9: [6, 8],
}

def precompute(max_n):
    """
    max_n까지 dp 테이블을 만들어 반환.
    dp[n][d] = 길이 n 비밀번호에서 마지막 숫자가 d인 경우의 수 (mod MOD)
    """
    dp = [[0]*10 for _ in range(max_n+1)]
    # 길이 1: 한 자리 비밀번호는 0~9 각각 하나
    for d in range(10):
        dp[1][d] = 1

    # 길이 2부터 max_n까지 채우기
    for n in range(2, max_n+1):
        row = dp[n]
        prev = dp[n-1]
        for d in range(10):
            s = 0
            for p in ADJ[d]:
                s += prev[p]
            row[d] = s % MOD
    return dp

def main():
    data = sys.stdin.read().split()
    t = int(data[0])
    Ns = list(map(int, data[1:]))

    if t == 0:
        return

    M = max(Ns)
    dp = precompute(M)

    out = []
    for N in Ns:
        total = sum(dp[N]) % MOD
        out.append(str(total))

    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()