import sys

def solve():
    data = sys.stdin.read().strip().split()
    it = iter(data)

    N = int(next(it))
    breeds = " " + next(it).strip()
    E = [0] * (N + 1)
    for i in range(1, N + 1):
        E[i] = int(next(it))
    
    Gidx = [i for i in range(1, N + 1) if breeds[i] == 'G']
    Hidx = [i for i in range(1, N + 1) if breeds[i] == 'H']

    firstG, lastG = min(Gidx), max(Gidx)
    firstH, lastH = min(Hidx), max(Hidx)

    cover_all_G = [False] * (N + 1)
    cover_all_H = [False] * (N + 1)

    for i in Gidx:
        if i <= firstG and E[i] >= lastG:
            cover_all_G[i] = True
    
    for j in Hidx:
        if j <= firstH and E[j] >= lastH:
            cover_all_H[j] = True

    CH_flag = [0] * (N + 1)
    for j in Hidx:
        if cover_all_H[j]:
            CH_flag[j] = 1
    
    prefCH = [0] * (N + 1)
    run = 0
    for i in range(1, N + 1):
        run += CH_flag[i]
        prefCH[i] = run

    diff = [0] * (N + 2)
    for h in Hidx:
        if not cover_all_H[h]:
            L, R = h, E[h]
            if L <= R:
                diff[L] += 1
                if R + 1 <= N:
                    diff[R + 1] -= 1

    covH = [0] * (N + 1)
    run = 0

    for i in range(1, N + 1):
        run += diff[i]
        covH[i] = run

    total = 0

    CH_count = prefCH[N]
    for g in Gidx:
        if cover_all_G[g]:
            total += CH_count + covH[g]

    for g in Gidx:
        if not cover_all_G[g]:
            L, R = g, E[g]
            if L <= R:
                total += prefCH[R] - prefCH[L - 1]
    
    print(total)

if __name__ == "__main__":
    solve()