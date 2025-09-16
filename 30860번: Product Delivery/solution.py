import sys

def solve():
    data = sys.stdin.buffer
    n_line = data.readline().split()
    while not n_line:
        n_line = data.readline().split()
    n = int(n_line[0])

    segments = 0
    cur_max = None

    for _ in range(n):
        l_str, m_str = data.readline().split()
        l = int(l_str)
        m = int(m_str)
        if cur_max is None:
            segments = 1
            cur_max = l
        else:
            nm = cur_max if cur_max > l else l
            if nm <= m:
                cur_max = nm
            else:
                segments += 1
                cur_max = l
    print(segments)

if __name__ == "__main__":
    solve()