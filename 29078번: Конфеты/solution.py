import sys

def main():
    data = sys.stdin.read().split()
    n = int(data[0])
    p = list(map(int, data[1:]))
    left = 0
    count = {}
    best = 0
    for right, x in enumerate(p):
        count[x] = count.get(x, 0) + 1
        while len(count) > 2:
            y = p[left]
            count[y] -= 1
            if count[y] == 0:
                del count[y]
            left += 1
        if len(count) == 2:
            best = max(best, right - left + 1)
    print(best)

if __name__ == "__main__":
    main()