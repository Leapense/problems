import sys

def prefix_function(s: str):
    n = len(s)
    pi = [0] * n
    j = 0
    for i in range(1, n):
        while j > 0 and s[i] != s[j]:
            j = pi[j - 1]
        if s[i] == s[j]:
            j += 1
            pi[i] = j
    return pi

def main():
    s = sys.stdin.readline().strip()
    n = len(s)

    bal = 0
    K = []
    for i, ch in enumerate(s, 1):
        bal += 1 if ch == '(' else -1
        if i < n and bal == 0:
            K.append(i)

    if not K:
        print("no")
        return
    
    pi = prefix_function(s)
    p = n - pi[-1]
    if n % p != 0:
        p = n

    for k in K:
        if k % p != 0:
            ans = s[k:] + s[:k]
            print(ans)
            return
    print("no")

if __name__ == "__main__":
    main()