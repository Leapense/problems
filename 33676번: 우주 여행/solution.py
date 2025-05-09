import sys

def build_path(N, M, L):
    D = (N - 1) + (M - 1)
    if L < D or (L - D) % 2:
        return None
    E = L - D
    path = []

    if E:
        if N > 1:
            path.extend('DU' * (E // 2))
        elif M > 1:
            path.extend('RL' * (E // 2))
        else:
            return None
        
    path.extend('D' * (N - 1))
    path.extend('R' * (M - 1))
    return ''.join(path)

def main():
    data = sys.stdin.read().strip().split()
    if not data:
        return
    
    N, M, K, L = map(int, data[:4])
    res = build_path(N, M, L)
    if res is None:
        print(-1)
    else:
        print(res)

if __name__ == "__main__":
    main()