import sys
from typing import List

def max_ten_pieces(cakes: List[int], max_cuts: int) -> int:
    ready = sum(1 for length in cakes if length == 10)
    divisible = [c for c in cakes if c > 10 and c % 10 == 0]
    others = [c for c in cakes if c > 10 and c % 10 != 0]

    divisible.sort()
    pieces = ready
    cuts = max_cuts

    for length in divisible:
        if cuts == 0:
            break
        ten_count = length // 10
        need = ten_count - 1
        if cuts >= need:
            pieces += ten_count
            cuts -= need
        else:
            pieces += cuts
            cuts = 0
            break
    if cuts > 0:
        others.sort()
        for length in others:
            if cuts == 0:
                break
            ten_count = length // 10
            if ten_count == 0:
                continue
            need = ten_count
            if cuts >= need:
                pieces += ten_count
                cuts -= need
            else:
                pieces += cuts
                cuts = 0
                break
    return pieces

def main() -> None:
    raw = list(map(int, sys.stdin.buffer.read().split()))
    n, m = raw[0], raw[1]
    lengths = raw[2:2+n]
    print(max_ten_pieces(lengths, m))

if __name__ == "__main__":
    main()