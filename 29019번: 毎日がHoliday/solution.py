import sys

def min_initial_asset(y: int, c: int, r: int) -> int:
    a = 100 + r
    b = 100
    need = 0
    for _ in range(y):
        need = c + (need * b + a - 1) // a
    return need

def main():
    data = sys.stdin.read().strip().split()
    it = iter(data)
    out_lines = []
    for y_str, c_str, r_str in zip(it, it, it):
        y, c, r = int(y_str), int(c_str), int(r_str)
        if y == 0 and c == 0 and r == 0:
            break
        out_lines.append(str(min_initial_asset(y, c, r)))
    print("\n".join(out_lines))

if __name__ == "__main__":
    main()