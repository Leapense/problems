import sys
from collections import deque

def solve():
    data = sys.stdin.read().split()
    n = int(data[0])
    k = int(data[1])
    tree = [[] for _ in range(n)]
    index = 2

    for _ in range(n - 1):
        p = int(data[index])
        c = int(data[index + 1])
        tree[p].append(c)
        index += 2

    apples = list(map(int, data[index:index+n]))

    count = 0
    dq = deque([(0, 0)])
    while dq:
        node, dist = dq.popleft()
        if dist <= k:
            count += apples[node]
            if dist < k:
                for child in tree[node]:
                    dq.append((child, dist + 1))
    sys.stdout.write(str(count))

def run_io_fun(input_data, func):
    backup_stdin = sys.stdin
    backup_stdout = sys.stdout
    sys.stdin = sys.__stdin__ = __import__("io").StringIO(input_data)
    sys.stdout = sys.__stdout__ = __import__("io").StringIO()
    try:
        func()
        return sys.stdout.getvalue()
    finally:
        sys.stdin = backup_stdin
        sys.stdout = backup_stdout

def test_sample1():
    input_data = "8 2\n0 1\n0 2\n1 3\n1 4\n2 5\n2 6\n6 7\n1 0 0 1 0 1 0 1\n"
    output = run_io_fun(input_data, solve)
    assert output.strip() == "3"

def test_no_apples():
    input_data = "5 3\n0 1\n0 2\n1 3\n1 4\n0 0 0 0 0\n"
    output = run_io_fun(input_data, solve)
    assert output.strip() == "0"

def test_all_apples():
    input_data = "5 1\n0 1\n0 2\n1 3\n1 4\n1 1 1 1 1\n"
    output = run_io_fun(input_data, solve)
    # nodes in distance <= 1: node 0, node 1, node 2
    assert output.strip() == "3"

if __name__ == "__main__":
    solve()