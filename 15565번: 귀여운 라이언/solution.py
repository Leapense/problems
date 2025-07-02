import sys

def find_min_window_size(n: int, k: int, dolls: list[int]) -> int:
    left = 0
    ryan_count = 0
    best = n + 1

    for right, value in enumerate(dolls):
        if value == 1:
            ryan_count += 1

        while ryan_count >= k:
            current_size = right - left + 1
            if current_size < best:
                best = current_size

            if dolls[left] == 1:
                ryan_count -= 1
            left += 1

    return -1 if best == n + 1 else best

def main() -> None:
    input_data = sys.stdin.read().split()
    n, k = map(int, input_data[:2])
    dolls = list(map(int, input_data[2:2 + n]))
    result = find_min_window_size(n, k, dolls)
    print(result)

if __name__ == "__main__":
    main()
