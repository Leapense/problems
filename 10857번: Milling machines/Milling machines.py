import sys

def main():
    input = sys.stdin.read().split()
    it = iter(input)

    try:
        W = int(next(it))
        S = int(next(it))
    except StopIteration:
        W, S = 0, 0
    try:
        X = int(next(it))
        Y = int(next(it))
    except StopIteration:
        X, Y = 0, 0
    workpieces = []
    for _ in range(W):
        wp = []
        for _ in range(X):
            try:
                wp.append(int(next(it)))
            except StopIteration:
                wp.append(0)
        workpieces.append(wp)
    max_si = [0] * X
    for _ in range(S):
        for j in range(X):
            try:
                s = int(next(it))
            except StopIteration:
                s = 0
            if s > max_si[j]:
                max_si[j] = s
    H = [Y - max_si[j] for j in range(X)]
    output = []
    for wp in workpieces:
        rem = []
        for j in range(X):
            rem.append(str(wp[j] if wp[j] < H[j] else H[j]))
        output.append(' '.join(rem))
    print('\n'.join(output))

if __name__ == '__main__':
    main()