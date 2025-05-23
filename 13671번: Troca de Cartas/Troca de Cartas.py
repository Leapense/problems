def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    idx = 0
    while idx < len(data):
        A = int(data[idx])
        B = int(data[idx + 1])
        idx += 2
        if A == 0 and B == 0:
            break
        A_cards = []
        for _ in range(A):
            if idx >= len(data):
                break
            A_cards.append(int(data[idx]))
            idx += 1
        B_cards = []
        for _ in range(B):
            if idx >= len(data):
                break
            B_cards.append(int(data[idx]))
            idx += 1
        
        set_A = set(A_cards)
        set_B = set(B_cards)

        A_diff = set_A - set_B
        B_diff = set_B - set_A

        N = min(len(A_diff), len(B_diff))
        print(N)

if __name__ == '__main__':
    main()