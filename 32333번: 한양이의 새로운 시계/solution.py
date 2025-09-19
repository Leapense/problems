import sys

def fmt_time(t: int) -> str:
    return f"{t // 60:02d}:{t % 60:02d}"

ANIMALS = [
        "rat", "cow", "tiger", "rabbit", "dragon",
        "snake", "horse", "sheep", "monkey", "chicken",
        "dog", "pig", "lion", "giraffe", "cat"
]

SEG = 96

def animals_covered(start: int, end: int) -> str:
    s_idx = start // SEG
    e_idx = (end - 1) // SEG
    idxs = list(range(s_idx, e_idx + 1))
    if end % SEG == 0 and end <= 1439:
        idxs.append(end // SEG)
    return " ".join(ANIMALS[i] for i in idxs)

readline = sys.stdin.buffer.readline

N_line = readline()
while N_line.strip() == b"":
    N_line = readline()

N = int(N_line)

buckets = [[] for _ in range(1440)]

for _ in range(N):
    line = readline()
    while line.strip() == b"":
        line = readline()
    h, m, d = map(int, line.split())
    r = h * 60 + m
    buckets[r].append(d)

for r in range(1440):
    if buckets[r]:
        buckets[r].sort()

pos = [0] * 1440

p = 0
while p < 1440 and not buckets[p]:
    p += 1

cur = 0
finished = 0
out_lines = []

while p < 1440 and cur < 1440:
    if cur < p:
        cur = p
        if cur >= 1440:
            break

    d = buckets[p][pos[p]]
    pos[p] += 1

    start = cur
    end = start + d
    if end <= 1439:
        out_lines.append(animals_covered(start, end))
        out_lines.append(f"{fmt_time(start)} {fmt_time(end)}")
        finished += 1

    cur = end

    if pos[p] >= len(buckets[p]):
        p += 1
        while p < 1440 and not buckets[p]:
            p += 1

if finished < N:
    out_lines.append(str(N - finished))

sys.stdout.write("\n".join(out_lines))
