import sys

def count_subarrays_positive(arr: list[int], target: int) -> int:
    left = 0
    current_sum = 0
    count = 0
    for value in arr:
        current_sum += value
        while current_sum > target and left < len(arr):
            current_sum -= arr[left]
            left += 1
        if current_sum == target:
            count += 1
            current_sum -= arr[left]
            left += 1
    return count

def main() -> None:
    data = list(map(int, sys.stdin.buffer.read().split()))
    it = iter(data)
    rows = next(it, None)
    if rows is None:
        return
    cols = next(it)
    grid = [[0] * cols for _ in range(rows)]
    for i in range(rows):
        row = grid[i]
        for j in range(cols):
            row[j] = next(it)
    target = 10
    total = 0
    if rows <= cols:
        for top in range(rows):
            band = [0] * cols
            for bottom in range(top, rows):
                row_bottom = grid[bottom]
                for j in range(cols):
                    band[j] += row_bottom[j]
                total += count_subarrays_positive(band, target)
    else:
        for left in range(cols):
            band = [0] * rows
            for right in range(left, cols):
                for i in range(rows):
                    band[i] += grid[i][right]
                total += count_subarrays_positive(band, target)
    print(total)

if __name__ == "__main__":
    main()