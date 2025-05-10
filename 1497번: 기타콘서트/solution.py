import sys

def min_guitars_needed(N: int, M: int, raw: list[str]) -> int:
    masks = []
    for line in raw:
        name, yn = line.split()
        bitmask = 0
        for idx, ch in enumerate(yn):
            if ch == 'Y':
                bitmask |= 1 << idx
        masks.append(bitmask)

    best_songs = -1
    best_guitar_cnt = 10 ** 9

    full_subsets = 1 << N
    for subset in range(1, full_subsets):
        union_mask = 0
        cnt = 0
        for g in range(N):
            if subset & (1 << g):
                cnt += 1
                union_mask |= masks[g]
        covered = union_mask.bit_count()
        if covered > best_songs or (covered == best_songs and cnt < best_guitar_cnt):
            best_songs = covered
            best_guitar_cnt = cnt
    if best_songs == 0:
        return -1
    return best_guitar_cnt

def main() -> None:
    data = sys.stdin.read().strip().splitlines()
    if not data:
        return
    N, M = map(int, data[0].split())
    answer = min_guitars_needed(N, M, data[1:])
    print(answer)

if __name__ == "__main__":
    main()