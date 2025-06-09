import sys

def parse_pattern(pattern: str, length: int) -> list[set[str]]:
    allowed: list[set[str]] = []
    i = 0
    while i < len(pattern):
        if pattern[i] == '(':
            i += 1
            group = set()
            while i < len(pattern) and pattern[i] != ')':
                group.add(pattern[i])
                i += 1

            i += 1
            allowed.append(group)
        else:
            allowed.append({pattern[i]})
            i += 1

    if len(allowed) != length:
        raise ValueError(
            f"Parsed pattern length {len(allowed)} != expected {length}"
        )
    return allowed

def count_matches(words: list[str], allowed: list[set[str]]) -> int:
    match_count = 0
    length = len(allowed)

    for word in words:
        if len(word) != length:
            continue

        for idx, char in enumerate(word):
            if char not in allowed[idx]:
                break
        else:
            match_count += 1

    return match_count

def main() -> None:
    first_line = sys.stdin.readline().split()
    if len(first_line) != 3:
        print("Invalid input header", file=sys.stderr)
        return

    L, D, N = map(int, first_line)
    words = [sys.stdin.readline().strip() for _ in range(D)]
    for case_num in range(1, N + 1):
        pattern = sys.stdin.readline().strip()
        allowed_sets = parse_pattern(pattern, L)
        matches = count_matches(words, allowed_sets)
        print(f"Case #{case_num}: {matches}")

if __name__ == "__main__":
    main()