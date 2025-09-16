import sys

def rank_key(s: str):
    def r(ch):
        if '0' <= ch <= '9':
            return ord(ch) - ord('0')
        return 10 + ord(ch) - ord('A')
    return tuple(r(c) for c in s)

def can_reorder(arr):
    target = sorted(arr, key=rank_key)
    stack = []
    idx = 0
    n = len(arr)

    for x in arr:
        while stack and idx < n and stack[-1] == target[idx]:
            stack.pop()
            idx += 1
        if idx < n and x == target[idx]:
            idx += 1
        else:
            stack.append(x)
        
    while stack and idx < n and stack[-1] == target[idx]:
        stack.pop()
        idx += 1
    
    return idx == n

def main():
    data = sys.stdin.read().strip().split()
    t = int(data[0])
    out = []
    p = 1
    for _ in range(t):
        F = int(data[p]); p += 1
        arr = data[p:p+F]; p += F
        out.append("Yes" if can_reorder(arr) else "No")
    print("\n".join(out))

if __name__ == "__main__":
    main()