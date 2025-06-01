from typing import List

def totients_upto(n: int) -> List[int]:
    phi = list(range(n + 1))
    for p in range(2, n + 1):
        if phi[p] == p:
            for multiple in range(p, n + 1, p):
                phi[multiple] -= phi[multiple] // p
    
    return phi

def count_visible_seats(d1: int, d2: int) -> int:
    phi = totients_upto(d2)
    visible = 0
    for d in range(1, d2 + 1):
        first = (d1 + d - 1) // d
        last = d2 // d
        if first <= last:
            visible += phi[d]

    return visible

def main() -> None:
    d1, d2 = map(int, input().split())
    print(count_visible_seats(d1, d2))

if __name__ == "__main__":
    main()