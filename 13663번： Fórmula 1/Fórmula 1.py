import sys
def main():
    lines = sys.stdin.read().splitlines()
    idx = 0
    while idx < len(lines):
        G_P = lines[idx].strip().split()
        G, P = int(G_P[0]), int(G_P[1])
        if G == 0 and P == 0:
            break
        idx += 1
        races = []
        for _ in range(G):
            race = list(map(int, lines[idx].strip().split()))
            races.append(race)
            idx += 1
        S = int(lines[idx].strip())
        idx += 1
        scoring_systems = []
        for _ in range(S):
            parts = list(map(int, lines[idx].strip().split()))
            K, points = parts[0], parts[1:]
            scoring_systems.append((K, points))
            idx += 1
        for system in scoring_systems:
            K, points = system
            total = [0] * P
            for race in races:
                for pilot in range(P):
                    pos = race[pilot]
                    if pos <= K:
                        total[pilot] += points[pos - 1]
            max_points = max(total)
            champions = [str(i + 1) for i, t in enumerate(total) if t == max_points]
            print(' '.join(champions))
    return
    
if __name__ == '__main__':
    main()