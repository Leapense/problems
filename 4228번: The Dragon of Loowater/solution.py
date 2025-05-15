import sys

def main():
    while True:
        line = sys.stdin.readline().split()
        if not line:
            break

        try:
            n, m = int(line[0]), int(line[1])
        except (ValueError, IndexError):
            break

        if n == 0 and m == 0:
            break

        heads = []
        for _ in range(n):
            heads.append(int(sys.stdin.readline()))

        knights = []
        for _ in range(m):
            knights.append(int(sys.stdin.readline()))

        heads.sort()
        knights.sort()

        total_cost = 0
        heads_chopped_count = 0
        head_ptr = 0
        knight_ptr = 0

        while head_ptr < n and knight_ptr < m:
            if knights[knight_ptr] >= heads[head_ptr]:
                total_cost += knights[knight_ptr]
                heads_chopped_count += 1
                head_ptr += 1
                knight_ptr += 1
            else:
                knight_ptr += 1

        if heads_chopped_count == n:
            sys.stdout.write(str(total_cost) + "\n")
        else:
            sys.stdout.write("Loowater is doomed!\n")

if __name__ == "__main__":
    main()