import sys

def main():
    input = sys.stdin.read().split()
    n = int(input[0])
    k = int(input[1])
    c = int(input[2])

    teams = []
    ptr = 3

    for rank in range(1, n + 1):
        t = int(input[ptr])
        s = int(input[ptr + 1])
        teams.append((rank, t, s))
        ptr += 2

    selected = []
    skipped = []
    school_counts = {}

    for team in teams:
        rank, t, s = team
        if school_counts.get(s, 0) < c:
            selected.append(team)
            school_counts[s] = school_counts.get(s, 0) + 1
        else:
            skipped.append(team)

    if len(selected) < k:
        selected = selected[:k]
        school_counts[s] = school_counts.get(s, 0) + 1
    else:
        skipped.append(team)

    if len(selected) >= k:
        selected = selected[:k]
    else:
        needed = k - len(selected)
        selected += skipped[:needed]

    selected_sorted = sorted(selected, key=lambda x: x[0])

    for team in selected_sorted:
        print(team[1])

if __name__ == '__main__':
    main()