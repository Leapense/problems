import sys
from typing import List, Tuple

def parse_input() -> List[int]:
    data = sys.stdin.read().strip().split()
    if not data:
        return []
    n = int(data[0])
    songs = list(map(int, data[1:1+n]))
    return songs

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

def solve():
    songs = parse_input()
    playlist, k = compute_optimal_playlist(songs)
    m = len(playlist)
    print(f"{m} {k}")
    if m > 0:
        print(" ".join(map(str, playlist)))

if __name__ == "__main__":
    solve()