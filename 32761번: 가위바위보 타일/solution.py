import sys

def max_in_window(pos, n):
    best = 0
    l = r = 0
    m = len(pos)
    for start in range(n):
        end = start + n - 1
        while l < m and pos[l] < start:
            l += 1
        while r < m and pos[r] <= end:
            r += 1
        cnt = r - l
        if cnt > best:
            best = cnt
    return best

def solve(n, s):
    s2 = s + s
    conv = {'R' : 0, 'S' : 1, 'P' : 2}
    best_total = 0
    for shift in range(3):
        pos = []
        expect = shift
        for i, ch in enumerate(s2):
            if conv[ch] == expect:
                pos.append(i)
                expect = (expect + 1) % 3
        best_total = max(best_total, max_in_window(pos, n))
    best_total = best_total // 3 * 3
    return str(n - best_total)

if __name__ == "__main__":
    n = int(sys.stdin.readline().strip())
    s = sys.stdin.readline().strip()
    print(solve(n, s))