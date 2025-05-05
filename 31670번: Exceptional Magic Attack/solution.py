import sys

def min_energy(N, R):
    if N == 0:
        return 0
    
    dp0, dp1 = 0, R[0]
    for i in range(1, N):
        new0 = dp1
        new1 = min(dp0, dp1) + R[i]
        dp0, dp1 = new0, new1
    return min(dp0, dp1)

def main() -> None:
    data = sys.stdin.buffer.read().split()
    N = int(data[0])
    R = list(map(int, data[1:1+N]))
    print(min_energy(N, R))

if __name__ == "__main__":
    main()