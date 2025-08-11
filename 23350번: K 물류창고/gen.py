#!/usr/bin/env python3
import random

def generate_case():
    N = random.randint(1, 100)
    M = random.randint(1, N)
    ensure_all_priorities = True
    items = []
    if ensure_all_priorities:
        for p in range(1, M + 1):
            w = random.randint(1, 100)
            items.append((p, w))
    
    for _ in range(N - len(items)):
        p = random.randint(1, M)
        w = random.randint(1, 100)
        items.append((p, w))

    random.shuffle(items)

    print(f"{N} {M}")
    for p, w in items:
        print(f"{p} {w}")

if __name__ == "__main__":
    generate_case()