import sys

def find_hyper_pyramid(m: int):
    MAX_N = 54
    for n in range(3, MAX_N + 1):
        total = 0
        s = 1
        power = n - 1
        while True:
            total += s ** power
            if total == m:
                return n, s
            if total > m:
                break

            s += 1
    return None

def main() -> None:
    m_str = sys.stdin.readline().strip()
    if not m_str:
        return
    m = int(m_str)
    result = find_hyper_pyramid(m)
    if result is None:
        print("impossible")
    else:
        print(f"{result[0]} {result[1]}")

if __name__ == "__main__":
    main()