import sys

def min_steps_from_1_to_k(k: int) -> int:
    steps = 0
    while k > 1:
        if k % 2 == 0:
            k //= 2
        else:
            k += 1
        steps += 1
    return steps

def solve():
    input_data = sys.stdin.read().strip().split()
    t = int(input_data[0])
    idx = 1
    out_lines = []
    for _ in range(t):
        k = int(input_data[idx]); idx += 1
        out_lines.append(str(min_steps_from_1_to_k(k)))
    print("\n".join(out_lines))

if __name__ == "__main__":
    solve()