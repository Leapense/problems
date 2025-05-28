import sys

def min_changes_to_alternate(s: str) -> int:
    ans = 0
    prev = ''
    for ch in s:
        if ch == prev:
            ans += 1
            prev = '?'
        else:
            prev = ch
    return ans

def main():
    data = sys.stdin.read().split()
    n = int(data[0])
    s = data[1].strip()
    if len(s) != n:
        raise ValueError("입력 문자열 길이가 n과 불일치합니다.")
    print(min_changes_to_alternate(s))

if __name__ == "__main__":
    main()