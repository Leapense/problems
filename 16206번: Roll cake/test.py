import random
import time
import matplotlib.pyplot as plt
import matplotx
from typing import List, Tuple

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

def generate_case(n: int) -> Tuple[List[int], int]:
    cakes = [random.randint(1, 100) for _ in range(n)]
    m = n
    return cakes, m

def measure_runtime(ns):
    runtimes = []
    for n in ns:
        cakes, m = generate_case(n)
        start = time.perf_counter()
        max_ten_pieces(cakes, m)
        runtimes.append(time.perf_counter() - start)
    return runtimes

def main():
    ns = [2 ** k for k in range(6, 15)]
    runtimes = measure_runtime(ns)

    plt.style.use(matplotx.styles.onedark)
    plt.figure()
    plt.plot(ns, runtimes, marker='o', linestyle='-')
    plt.xlabel("n (number of cakes)")
    plt.ylabel("runtime (seconds)")
    plt.title("Empirical runtime of max_ten_pieces")
    plt.xscale('log', base=2)
    plt.yscale('log')
    plt.grid(True, which="both", ls=":")
    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    main()