import sys

def main():
    input = sys.stdin.read().split()
    N = int(input[0])
    A = list(map(int, input[1:N+1]))
    zero_prefix = [0] * (N+1)
    for i in range(1, N+1):
        zero_prefix[i] = zero_prefix[i-1] + (1 if A[i-1] == 0 else 0)
    one_suffix = [0] * (N+1)
    for i in range(N-1, -1, -1):
        one_suffix[i] = one_suffix[i+1] + (1 if A[i] == 1 else 0)
    min_toggles = float('inf')
    for r in range(N+1):
        toggles = zero_prefix[r] + one_suffix[r]
        if toggles < min_toggles:
            min_toggles = toggles
    print(min_toggles)

if __name__ == "__main__":
    main()