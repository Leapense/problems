import sys

def main():
    input = sys.stdin.read
    data = input().split()
    N = int(data[0])
    total_players = 1 << N
    D = int(data[1])
    other_scores = list(map(int, data[2:]))
    count = sum(1 for s in other_scores if s <= D)
    print("YES" if count >= N else "NO")

if __name__ == '__main__':
    main()