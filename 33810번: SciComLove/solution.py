import sys

def count_mismatches(s: str, target: str = "SciComLove") -> int:
    return sum(1 for sc, tc in zip(s, target) if sc != tc)

def main():
    data = sys.stdin.read().strip().split()
    if not data:
        return
    s = data[0]
    if len(s) != len("SciComLove"):
        print("0")
        return
    print(count_mismatches(s))

if __name__ == "__main__":
    main()