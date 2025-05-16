import sys
from typing import List, Tuple

MID = {4, 5}
LOW = {0, 1}
HIGH = {8, 9}

def _decode_chirp(samples: List[int], start: int) -> (int, int, int):
    bits = []
    for k in range(8):
        first,second = samples[start + 2 * k], samples[start + 2 * k + 1]
        if first in MID and second in MID:
            bits.append(0)
        elif first in LOW and second in HIGH:
            bits.append(1)
        else:
            raise ValueError("Malformed chirp")
        
    speed = bits[2] | (bits[3] << 1) | (bits[4] << 2)
    incline = bits[5] | (bits[6] << 1) | (bits[7] << 2)
    t = start // 3
    return t, speed, incline

def _process_program(samples: List[int]) -> List[str]:
    out = []
    i, n = 0, len(samples)
    while i + 3 < n:
        if (
            samples[i] in MID and samples[i + 1] in MID and
            samples[i + 2] in LOW and samples[i + 3] in HIGH and
            i + 16 <= n
        ):
            t, spd, inc = _decode_chirp(samples, i)
            out.append(f"{t // 60:02d}:{t % 60:02d} Speed {spd} Inclination {inc}")

            i += 16
        else:
            i += 1
    return out

def solve(text: str) -> str:
    data = list(map(int, text.strip().split()))
    if not data:
        return ""
    p = data[0]
    idx = 1
    prog_no = 1
    lines = []
    for _ in range(p):
        samples = []
        while data[idx] != 10:
            samples.append(data[idx])
            idx += 1
        idx += 1
        lines.append(f"Program {prog_no}")
        lines.extend(_process_program(samples))
        prog_no += 1

    return "\n".join(lines)

if __name__ == "__main__":
    print(solve(sys.stdin.read()))