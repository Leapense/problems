import sys
from typing import List

def main():
    inp = sys.stdin.readline
    N = int(inp())
    A_orig = list(map(int, inp().split()))
    M = int(inp())
    for _ in range(M):
        L, R = map(int, inp().split())
        A = A_orig[:]
        positions: List[int] = [i for i, position in enumerate(A) if L <= position <= R]
        people = list(range(L, R + 1))
        
        positions.sort()
        people.sort()

        for pos, person in zip(positions, people):
            A[pos] = person
        print(*A)

if __name__ == "__main__":
    main()