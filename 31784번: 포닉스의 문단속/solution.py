import sys

def solve():
    input_data = sys.stdin.read().strip().split()
    N = int(input_data[0])
    K = int(input_data[1])
    S = list(input_data[2].strip())

    for i in range(N - 1):
        c = S[i]
        need = (26 - (ord(c) - ord('A'))) % 26
        if need <= K:
            S[i] = 'A'
            K -= need

    add = K % 26
    last_val = (ord(S[-1]) - ord('A') + add) % 26
    S[-1] = chr(ord('A') + last_val)
    print("".join(S))

if __name__ == "__main__":
    solve()