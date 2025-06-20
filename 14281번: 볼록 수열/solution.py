import sys

def solve():
    """
    블록 수열 문제를 반복적 그리디 접근법으로 해결하는 메인 함수
    """
    try:
        n_str = sys.stdin.readline()
        if not n_str: return

        n = int(n_str)
        if n <= 2:
            sys.stdin.readline()
            print(0)
            return

        a = list(map(int, sys.stdin.readline().strip().split()))
    except (IOError, ValueError) as e:
        print(f"입력 처리 중 오류 발생: {e}")
        return

    total_cost = 0
    x = list(a)

    while True:
        changed = False
        for i in range(1, n - 1):
            if 2 * x[i] > x[i-1] + x[i+1]:
                required_val = (x[i-1] + x[i+1]) // 2
                cost_to_add = x[i] - required_val
                total_cost += cost_to_add
                x[i] = required_val
                changed = True

        if not changed:
            break

    print(total_cost)

if __name__ == "__main__":
    solve()
