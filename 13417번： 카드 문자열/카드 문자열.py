import sys

def main():
    T = int(sys.stdin.readline())
    for _ in range(T):
        line = ''
        while line.strip() == '':
            line = sys.stdin.readline()
        N = int(line.strip())
        cards = []
        while len(cards) < N:
            line = sys.stdin.readline()
            if not line:
                break
            parts = line.strip().split()
            cards.extend(parts)
        cards = cards[:N]
        S = []
        for c in cards:
            if not S:
                S.append(c)
            else:
                if (c, *S) < (*S, c):
                    S.insert(0, c)
                else:
                    S.append(c)

        print(''.join(S))

if __name__ == '__main__':
    main()