from collections import deque
import sys

def main():
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    k = int(data[1])

    tree = [[] for _ in range(n)]
    index = 2

    for _ in range(n - 1):
        p = int(data[index])
        c = int(data[index + 1])
        tree[p].append(c)
        index += 2

    apples = list(map(int, data[index : index + n]))
    count = 0
    dq = deque([(0,0)])
    while dq:
        node, dist = dq.popleft()
        if dist <= k:
            count += apples[node]
            if dist < k:
                for child in tree[node]:
                    dq.append((child, dist + 1))
    sys.stdout.write(str(count))

if __name__ == "__main__":
    main()