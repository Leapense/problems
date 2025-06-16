import sys

def solve():
    """
    주어진 문자열 s의 '최장 증가 부분 수열(LIS)'를 찾아 문제 해결
    """
    try:
        s = sys.stdin.readline().strip()
        if not s:
            print(26)
            return
    except (IOError, IndexError):
        print(26)
        return
    
    n = len(s)
    dp = [1] * n
    for i in range(1, n):
        for j in range(i):
            if s[j] < s[i]:
                dp[i] = max(dp[i], dp[j] + 1)

    lis_length = max(dp) if dp else 0
    result = 26 - lis_length
    print(result)

if __name__ == "__main__":
    solve()