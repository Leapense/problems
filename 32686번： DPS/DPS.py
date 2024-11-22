import sys

def casting_time(t, R, A, P):
    if t < R:
        return 0
    t_prime = t - R
    k_cycles = t_prime // P
    rem = t_prime % P
    additional = min(rem, A)
    return k_cycles * A + additional

def main():
    input = sys.stdin.read
    data = input().split()

    idx = 0
    N = int(data[idx]); idx +=1
    S = int(data[idx]); idx +=1
    E = int(data[idx]); idx +=1

    total_damage = 0.0

    for _ in range(N):
        R = int(data[idx]); idx += 1
        A = int(data[idx]); idx += 1
        D = int(data[idx]); idx += 1

        if D == 0:
            continue

        P = R + A

        t_E = casting_time(E, R, A, P)
        t_S = casting_time(S, R, A, P)

        total_casting_time = t_E - t_S
        if total_casting_time <= 0:
            continue

        damage = D * (total_casting_time) / A
        total_damage += damage

    DPS = total_damage / (E - S)

    print("{0:.10f}".format(DPS).rstrip('0').rstrip('.') if '.' in "{0:.10f}".format(DPS) else "{0:.10f}".format(DPS))

if __name__ == '__main__':
    main()