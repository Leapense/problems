import sys

def main():
    N, M = map(int, sys.stdin.readline().split())
    files = []

    for _ in range(N):
        full_name = sys.stdin.readline().strip()
        filename, extension = full_name.split('.')
        files.append((filename, extension, full_name))
    recognized = set()
    for _ in range(M):
        ext = sys.stdin.readline().strip()
        recognized.add(ext)

    files.sort(key=lambda x: (x[0], 0 if x[1] in recognized else 1, x[1]))
    for file in files:
        print(file[2])

if __name__ == "__main__":
    main()