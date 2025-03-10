import sys

def main():
    input_data = sys.stdin.read().splitlines()
    codes = {
        "A": ".--",
        "B": "-.",
        "C": "---",
        "D": "..",
        "E": "--..",
        "F": "--.-",
        "G": ".-."
    }
    letters = sorted(codes.keys())
    for line in input_data:
        s = line.strip()
        n = len(s)
        dp = [None] * (n + 1)
        dp[n] = ""
        for i in range(n - 1, -1, -1):
            candidates = []
            for letter in letters:
                code = codes[letter]
                if s.startswith(code, i) and dp[i + len(code)] is not None:
                    candidates.append(letter + dp[i + len(code)])
            if candidates:
                dp[i] = min(candidates)
        if dp[0] is None:
            sys.stdout.write("could not be translated\n")
        else:
            sys.stdout.write(dp[0] + "\n")

if __name__ == "__main__":
    main()