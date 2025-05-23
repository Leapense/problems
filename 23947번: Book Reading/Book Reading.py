import sys
import math

class BookReading:
    def solve(self):
        from math import isqrt
        input = sys.stdin.read().split()
        ptr = 0
        T = int(input[ptr])
        ptr += 1

        for tc in range(1, T+1):
            N = int(input[ptr])
            M = int(input[ptr+1])
            Q = int(input[ptr+2])
            ptr += 3
            P_j = list(map(int, input[ptr:ptr+M]))
            ptr += M
            R_i = list(map(int, input[ptr:ptr+Q]))
            ptr += Q

            torn_count = {}
            for Pi in P_j:
                limit = isqrt(Pi)
                for d in range(1, limit + 1):
                    if Pi % d == 0:
                        torn_count[d] = torn_count.get(d, 0) + 1
                        q = Pi // d
                        if q != d:
                            torn_count[q] = torn_count.get(q, 0) + 1
            total = 0
            for R in R_i:
                total += (N // R) - torn_count.get(R, 0)
            print(f"Case #{tc}: {total}")

if __name__ == "__main__":
    BookReading().solve()