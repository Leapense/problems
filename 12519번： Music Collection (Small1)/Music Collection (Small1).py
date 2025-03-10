def solve():
    import sys
    input_data = sys.stdin.read().splitlines()
    t = int(input_data[0])
    index = 1
    outputs = []
    for case in range(1, t + 1):
        n = int(input_data[index])
        index += 1
        songs = [input_data[index + i] for i in range(n)]
        index += n
        songs_lower = [song.lower() for song in songs]
        res = []
        for i in range(n):
            if n == 1:
                res.append('""')
                continue
            found = None
            song_lower = songs_lower[i]
            L = len(song_lower)
            for length in range(1, L + 1):
                candidates = set()
                for start in range(L - length + 1):
                    cand = song_lower[start:start + length]
                    candidates.add(cand)
                valid_candidates = []
                for cand in candidates:
                    valid = True
                    for j in range(n):
                        if j == i: continue
                        if cand in songs_lower[j]:
                            valid = False
                            break
                    if valid:
                        valid_candidates.append(cand)
                if valid_candidates:
                    best = min(valid_candidates)
                    # 출력 시 알파벳은 대문자로 변환 (공백과 하이픈은 그대로)
                    best_out = "".join(ch.upper() if ch.isalpha() else ch for ch in best)
                    found = best_out
                    break
            if found is None:
                res.append(":(")
            else:
                res.append('"' + found + '"')
        outputs.append("Case #{}:".format(case))
        outputs.extend(res)
    sys.stdout.write("\n".join(outputs))

if __name__ == '__main__':
    solve()
