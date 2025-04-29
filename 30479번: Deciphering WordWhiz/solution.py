import sys

def compute_feedback(secret: str, guess: str) -> str:
    fb_chars = []
    for s_ch, g_ch in zip(secret, guess):
        if g_ch == s_ch:
            fb_chars.append('*')
        elif g_ch in secret:
            fb_chars.append('!')
        else:
            fb_chars.append('X')
    return ''.join(fb_chars)

def solve(stdin: sys.stdin, stdout: sys.stdout) -> None:
    lines = stdin.read().splitlines()
    it = iter(lines)

    try:
        n = int(next(it))
    except StopIteration:
        return
    
    words = [next(it).strip() for _ in range(n)]
    secret = words[0]

    g = int(next(it))
    feedbacks = [next(it).strip() for _ in range(g)]

    for fb in feedbacks:
        cnt = 0
        for w in words:
            if compute_feedback(secret, w) == fb:
                cnt += 1
        print(cnt, file=stdout)

def main() -> None:
    solve(sys.stdin, sys.stdout)

if __name__ == "__main__":
    main()