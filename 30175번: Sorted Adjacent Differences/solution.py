import sys

def solve() -> None:
    data = list(map(int, sys.stdin.buffer.read().split()))
    t = data[0]
    idx = 1
    out = []

    for _ in range(t):
        n = data[idx]
        idx += 1
        arr = data[idx:idx + n]
        idx += n
        arr.sort()
        mid = (n - 1) // 2
        res = [arr[mid]]
        l = mid - 1
        r = mid + 1
        while l >= 0 or r < n:
            if r < n:
                res.append(arr[r])
                r += 1
            if l >= 0:
                res.append(arr[l])
                l -= 1
        out.append(' '.join(map(str, res)))
    sys.stdout.write('\n'.join(out))

if __name__ == "__main__":
    solve()