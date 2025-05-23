def main():
    import sys
    input = sys.stdin.readline
    n = int(input())
    laws = []

    for _ in range(n):
        parts = input().split()
        if parts[0] == "declare":
            laws.append(("declare", None))
        else:
            laws.append(("cancel", int(parts[1]) - 1))
    active = [False] * n
    cancelled = [False] * n
    for i in range(n - 1, -1, -1):
        if not cancelled[i]:
            active[i] = True
            if laws[i][0] == "cancel":
                cancelled[laws[i][1]] = True

    active_indices = [str(i + 1) for i in range(n) if active[i]]
    sys.stdout.write(str(len(active_indices)) + "\n")
    sys.stdout.write(" ".join(active_indices))

if __name__ == "__main__":
    main()