import sys

def main():
    n = int(sys.stdin.readline())
    arr = list(map(int, sys.stdin.readline().split()))
    total = sum(arr)
    q = int(sys.stdin.readline())
    shift = 0
    for _ in range(q):
        parts = sys.stdin.readline().split()
        if parts[0] == '2':
            k = int(parts[1])
            shift = (shift + k) % n
            print(total)
        else:
            i = int(parts[1])
            x = int(parts[2])
            original_idx = (i - 1 - shift) % n
            old_val = arr[original_idx]
            total += x - old_val
            arr[original_idx] = x
            print(total)

if __name__ == "__main__":
    main()