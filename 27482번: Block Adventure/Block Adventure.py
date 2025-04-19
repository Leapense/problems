import sys

def can_win(n, m, k, h):
    bag = m
    for i in range(n - 1):
        need = max(0, h[i + 1] - k)
        if h[i] >= need:
            bag += h[i] - need
        else:
            diff = need - h[i]
            if bag < diff:
                return False
            bag -= diff

    return True

def main():
    data = list(map(int, sys.stdin.buffer.read().split()))
    t = data[0]
    pos = 1
    out = []

    for _ in range(t):
        n, m, k = data[pos:pos+3]
        pos += 3
        h = data[pos:pos+n]
        pos += n
        out.append("YES" if can_win(n, m, k, h) else "NO")
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()