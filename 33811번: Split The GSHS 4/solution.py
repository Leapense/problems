import sys

def main() -> None:
    data = sys.stdin.read().strip().split()
    if not data:
        return
    
    n = int(data[0])
    s = data[1]
    if n < 4:
        print(0)
        return
    max_end = max_ans = 0
    for i in range(n - 3):
        sub = s[i:i + 4]
        v = 1 if sub == "SSHS" else -1 if sub == "GSHS" else 0
        max_end = max(0, max_end + v)
        if max_end > max_ans:
            max_ans = max_end
    print(max_ans)

if __name__ == "__main__":
    main()