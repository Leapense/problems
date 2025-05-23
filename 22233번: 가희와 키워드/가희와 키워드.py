import sys

def main():
    input = sys.stdin.readline

    N, M = map(int, sys.stdin.readline().split())
    notepad = set()
    for _ in range(N):
        keyword = sys.stdin.readline().strip()
        notepad.add(keyword)

    remaining = N
    for _ in range(M):
        line = sys.stdin.readline().strip()
        keywords = line.split(',')
        for kw in keywords:
            if kw in notepad:
                notepad.remove(kw)
                remaining -= 1
        print(remaining)

if __name__ == "__main__":
    main()