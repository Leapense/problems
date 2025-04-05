def solve():
    import sys
    input = sys.stdin.readline
    N, K = map(int, input().split())
    r = K - 1
    size = 1 << N
    result = [''] * size

    for c in range(size):
        letter = None
        for i in range(N - 1, -1, -1):
            r_bit = (r >> i) & 1
            c_bit = (c >> i) & 1
            if r_bit == 0:
                letter = 'J' if c_bit == 0 else 'O'
                break
            else:
                if c_bit == 0:
                    letter = 'I'
                    break

        if letter is None:
            letter = 'J'
        result[c] = letter

    sys.stdout.write(''.join(result))

if __name__ == "__main__":
    solve()
