def find_parallel_fifths(N, K, notes):
    parallel_fifths = []

    for i in range(N - 1):
        for s in range(K):
            for t in range(s + 1, K):
                current_distance = notes[i][s] - notes[i][t]
                next_distance = notes[i + 1][s] - notes[i + 1][t]

                if current_distance % 12 == 7 and next_distance % 12 == 7:
                    if notes[i][s] != notes[i + 1][s] and notes[i][t] != notes[i + 1][t]:
                        parallel_fifths.append((i + 1, s + 1, t + 1))
    if parallel_fifths:
        return sorted(parallel_fifths)
    else:
        return "POLE"
    
N, K = map(int, input().split())
notes = [list(map(int, input().split())) for _ in range(N)]

result = find_parallel_fifths(N, K, notes)

if result == "POLE":
    print(result)
else:
    for i, s, t in result:
        print(f"{i} {s} {t}")