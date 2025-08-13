import sys
import argparse
import random
from typing import List, Tuple

def compute_optimal_playlist(songs: List[int]) -> Tuple[List[int], int]:
    n = len(songs)
    if n == 0:
        return [], 0
    max_val = 50
    dp = [[0] * (max_val + 1) for _ in range(n + 1)]
    for i in range(n - 1, -1, -1):
        ai = songs[i]
        for lv in range(max_val + 1):
            skip = dp[i + 1][lv]
            gain = 1 if lv == ai else 0
            take = dp[i + 1][ai] + gain
            dp[i][lv] = take if take > skip else skip
    playlist = []
    lv = 0
    i = 0
    while i < n:
        ai = songs[i]
        skip = dp[i + 1][lv]
        gain = 1 if lv == ai else 0
        take = dp[i + 1][ai] + gain
        if take >= skip:
            playlist.append(ai)
            lv = ai
        i += 1
    k = 0
    for j in range(1, len(playlist)):
        if playlist[j] == playlist[j - 1]:
            k += 1
    return playlist, k

def brute_force_best_k(songs: List[int]) -> int:
    n = len(songs)
    best = 0
    for mask in range(1 << n):
        last = None
        k = 0
        for i in range(n):
            if (mask >> i) & 1:
                ai = songs[i]
                if last is not None and ai == last:
                    k += 1
                last = ai
        if k > best:
            best = k
    return best

def adjacency_count(seq: List[int]) -> int:
    k = 0
    for i in range(1, len(seq)):
        if seq[i] == seq[i - 1]:
            k += 1
    return k

def is_subsequence(source: List[int], target: List[int]) -> bool:
    it = iter(source)
    try:
        for x in target:
            while True:
                v = next(it)
                if v == x:
                    break
        return True
    except StopIteration:
        return False
    
def generate_random_songs(n: int, alphabet_size: int, rng: random.Random) -> List[int]:
    return [rng.randint(1, alphabet_size) for _ in range(n)]

def format_input_lines(songs: List[int]) -> str:
    n = len(songs)
    return f"{n}\n{' '.join(map(str, songs))}\n"

def run_gen(args: argparse.Namespace) -> None:
    rng = random.Random(args.seed)
    n = args.n if args.n is not None else rng.randint(1, 50)
    if n < 1 or n > 50:
        raise ValueError("n은 1 이상 50 이하이어야 합니다.")
    alphabet = args.alphabet if args.alphabet is not None else 1 + int(rng.random() ** 2 * 49)
    if alphabet < 1 or alphabet > 50:
        raise ValueError("alphabet은 1 이상 50 이하이어야 합니다.")
    songs = generate_random_songs(n, alphabet, rng)
    sys.stdout.write(format_input_lines(songs))
    if args.show_answer:
        playlist, k = compute_optimal_playlist(songs)
        m = len(playlist)
        sys.stdout.write(f"{m} {k}\n")
        if m > 0:
            sys.stdout.write(" ".join(map(str, playlist)) + "\n")

def run_fuzz(args: argparse.Namespace) -> None:
    rng = random.Random(args.seed)
    total = args.cases
    if total < 1:
        raise ValueError("cases는 1 이상이어야 합니다.")
    if args.max_n < 1 or args.max_n > 50:
        raise ValueError("max-n은 1 이상 50 이하이어야 합니다.")
    if args.alphabet_min < 1 or args.alphabet_max > 50 or args.alphabet_min > args.alphabet_max:
        raise ValueError("alphabet 범위가 올바르지 않습니다.")
    for t in range(1, total + 1):
        n = rng.randint(1, args.max_n)
        alpha = 1 + int(rng.random() ** 2 * (args.alphabet_max - 1))
        alpha = max(args.alphabet_min, min(alpha, args.alphabet_max))
        songs = generate_random_songs(n, alpha, rng)
        for v in songs:
            if v < 1 or v > 50:
                sys.stderr.write("유효하지 않은 곡 번호가 생성되었습니다.\n")
                sys.exit(1)
        playlist, k = compute_optimal_playlist(songs)
        if not is_subsequence(songs, playlist):
            sys.stderr.write("서브시퀀스 제약 위반\n")
            sys.stderr.write("입력:\n")
            sys.stderr.write(format_input_lines(songs))
            sys.stderr.write("솔버 출력:\n")
            sys.stderr.write(f"{len(playlist)} {k}\n")
            if len(playlist) > 0:
                sys.stderr.write(" ".join(map(str, playlist)) + "\n")
            sys.exit(1)
        if adjacency_count(playlist) != k:
            sys.stderr.write("인접 동일 카운트 불일치\n")
            sys.stderr.write("입력:\n")
            sys.stderr.write(format_input_lines(songs))
            sys.stderr.write("솔버 출력:\n")
            sys.stderr.write(f"{len(playlist)} {k}\n")
            if len(playlist) > 0:
                sys.stderr.write(" ".join(map(str, playlist)) + "\n")
            sys.exit(1)
        best_k = brute_force_best_k(songs)
        if k != best_k:
            sys.stderr.write("브루트포스 최적값과 불일치\n")
            sys.stderr.write("입력:\n")
            sys.stderr.write(format_input_lines(songs))
            sys.stderr.write("솔버 출력:\n")
            sys.stderr.write(f"{len(playlist)} {k}\n")
            if len(playlist) > 0:
                sys.stderr.write(" ".join(map(str, playlist)) + "\n")
            sys.stderr.write(f"브루트포스 최적 k: {best_k}\n")
            sys.exit(1)
    sys.stdout.write(f"OK: {total} cases passed (max_n={args.max_n})\n")

def build_parser() -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    parser.add_argument("--mode", choices=["gen", "fuzz"], default="fuzz")
    parser.add_argument("--seed", type=int, default=None)
    parser.add_argument("--n", type=int, default=None)
    parser.add_argument("--alphabet", type=int, default=None)
    parser.add_argument("--show-answer", action="store_true")
    parser.add_argument("--cases", type=int, default=300)
    parser.add_argument("--max-n", type=int, default=18)
    parser.add_argument("--alphabet-min", type=int, default=1)
    parser.add_argument("--alphabet-max", type=int, default=50)
    return parser.parse_args()

def main() -> None:
    args = build_parser()
    if args.mode == "gen":
        run_gen(args)
    else:
        run_fuzz(args)

if __name__ == "__main__":
    main()