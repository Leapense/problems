import sys

def process_distribution() -> None:
    buffer = sys.stdin.buffer
    n, q = map(int, buffer.readline().split())
    occupied = [False] * (n + 1)
    output_lines = []
    for _ in range(q):
        desire = int(buffer.readline())
        node = desire
        blocked = 0
        while node > 1:
            if occupied[node]:
                blocked = node
            node //= 2

        output_lines.append(str(blocked))
        if blocked == 0:
            occupied[desire] = True

    sys.stdout.write("\n".join(output_lines))

if __name__ == '__main__':
    process_distribution()