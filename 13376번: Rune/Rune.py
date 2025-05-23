def calculate_power(rune: str) -> int:
    vowels = set("aeiou")
    power = 0
    prev_vowel = False
    for char in rune:
        if char in vowels:
            if not prev_vowel:
                power += 1
                prev_vowel = True
        else:
            prev_vowel = False
    return power

def solve():
    import sys
    input = sys.stdin.readline
    L = int(input().strip())
    results = []

    for _ in range(L):
        data = input().split()
        N = int(data[0])
        runes = data[1:]
        runes_with_power = [(rune, calculate_power(rune)) for rune in runes]
        runes_with_power.sort(key=lambda x: (-x[1], x[0]))
        sorted_runes = [rune for rune, _ in runes_with_power]
        results.append(" ".join(sorted_runes))

    print("\n".join(results))

if __name__ == "__main__":
    solve()