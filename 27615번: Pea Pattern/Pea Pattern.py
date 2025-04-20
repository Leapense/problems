import sys

def pea_pattern_position(n: str, m: str):
    seen = set()
    x = n
    for i in range(1, 101):
        if x == m:
            return i
        if x in seen:
            return "Does not appear"
        seen.add(x)
        cnt = [0] * 10
        for ch in x:
            cnt[ord(ch) - 48] += 1
        nxt = []
        for d in range(10):
            if cnt[d]:
                nxt.append(str(cnt[d]))
                nxt.append(str(d))
        x = "".join(nxt)

    return "I'm bored"

if __name__ == "__main__":
    n, m = sys.stdin.read().split()
    print(pea_pattern_position(n, m))