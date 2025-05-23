def kylskapstransport(pa, ka, pb, kb, n):
    min_cost = float('inf')
    best_a = 0
    best_b = 0

    for a_turer in range((n // ka) + 1):
        kylskap_efter_a = n - a_turer * ka
        if kylskap_efter_a < 0:
            kylskap_efter_a = 0

        b_turer = (kylskap_efter_a + kb - 1) // kb
        total_cost = a_turer * pa + b_turer * pb
    
        if total_cost < min_cost:
            min_cost = total_cost
            best_a = a_turer
            best_b = b_turer

    print(best_a, best_b, min_cost)

pa, ka, pb, kb, n = map(int, input().split())
kylskapstransport(pa, ka, pb, kb, n)

