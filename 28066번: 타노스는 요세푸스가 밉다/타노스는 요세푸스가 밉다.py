import sys

def main():
    input = sys.stdin.readline
    n, k = map(int, input().split())
    stack = [n]
    while stack[-1] > 1:
        stack.append(max(stack[-1] - (k - 1), 1))
    res = 1
    for i in range(len(stack) - 2, -1, -1):
        n1 = stack[i + 1]
        if res == n1:
            res = 1
        else:
            res = k + res
    print(res)

if __name__ == "__main__":
    main()