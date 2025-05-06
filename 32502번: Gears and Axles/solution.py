import sys
import math
from collections import defaultdict

def main():
    inp = sys.stdin.readline
    n = int(inp())
    groups = defaultdict(list)
    for _ in range(n):
        s, c = map(int, inp().split())
        groups[s].append(c)
    
    total_log = 0.0

    for c_list in groups.values():
        cnt = len(c_list)
        if cnt < 2:
            continue
        c_list.sort()
        half = cnt // 2
        for k in range(half):
            a = c_list[cnt - 1 - k]
            b = c_list[k]
            total_log += math.log(a) - math.log(b)

    sys.stdout.write(f"{total_log:.16f}")

if __name__ == "__main__":
    main()