import sys

def main():
    K_L = sys.stdin.readline().split()
    K = int(K_L[0])
    L = int(K_L[1])

    clicks = [sys.stdin.readline().strip() for _ in range(L)]
    seen = set()
    queue = []

    for click in reversed(clicks):
        if click not in seen:
            queue.append(click)
            seen.add(click)

    queue.reverse()

    registered = queue[:K]
    for student in registered:
        print(student)

if __name__ == '__main__':
    main()