def can_collect_all(T, balloons, winds, Q):
    total_cost = 0
    for P, orig_h in balloons:
        best = float('inf')
        for j, V in enumerate(winds):
            # Check if balloon is collected at time T with wind V.
            if P == 0:
                best = min(best, abs(orig_h - j))
            elif V == 0:
                continue
            elif P < 0:
                if V > 0 and P + T * V >= 0:
                    best = min(best, abs(orig_h - j))
            elif P > 0:
                if V < 0 and P + T * V <= 0:
                    best = min(best, abs(orig_h - j))
        if best == float('inf'):
            return False
        total_cost += best
        if total_cost > Q:
            return False
    return True

def solve_case():
    import sys
    data = sys.stdin.read().strip().split()
    if not data: 
        return
    t = int(data[0])
    index = 1
    results = []
    for case in range(1, t+1):
        N = int(data[index]); index+=1
        M = int(data[index]); index+=1
        Q_energy = int(data[index]); index+=1
        winds = list(map(int, data[index:index+M])); index += M
        balloons = []
        for _ in range(N):
            P = int(data[index]); H = int(data[index+1]); index += 2
            balloons.append((P, H))
        low, high = 0, 1000
        answer = -1
        while low <= high:
            mid = (low+high)//2
            if can_collect_all(mid, balloons, winds, Q_energy):
                answer = mid
                high = mid - 1
            else:
                low = mid + 1
        if answer == -1:
            results.append(f"Case #{case}: IMPOSSIBLE")
        else:
            results.append(f"Case #{case}: {answer}")
    sys.stdout.write("\n".join(results))

if __name__ == '__main__':
    solve_case()
