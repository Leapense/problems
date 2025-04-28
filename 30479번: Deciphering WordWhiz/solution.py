import sys

def compute_feedback(guess: str, secret: str) -> str:
    fb = []
    secret_set = set(secret)
    for g_char, s_char in zip(guess, secret):
        if g_char == s_char:
            fb.append('*')
        elif g_char in secret_set:
            fb.append('!')
        else:
            fb.append('X')
    return ''.join(fb)

def main():
    data = sys.stdin.read().split()
    it = iter(data)
    n = int(next(it))
    words = [next(it) for _ in range(n)]
    secret = words[0]
    g = int(next(it))
    feedbacks = [next(it) for _ in range(g)]

    count = sum(compute_feedback(w, secret) == fb for fb in feedbacks for w in words)
    print(count)
if __name__ == "__main__":
    main()
