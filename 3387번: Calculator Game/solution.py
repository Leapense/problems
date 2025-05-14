import sys

def solve():
    k_str = sys.stdin.readline()
    if not k_str:
        return
    
    k = int(k_str)

    if k % 2 == 0 and k % 5 == 0:
        sys.stdout.write("Impossible\n")
        return
    
    if k % 25 == 0:
        sys.stdout.write("Impossible\n")
        return
    
    if k % 16 == 0:
        sys.stdout.write("Impossible\n")
        return
    
    L_MAX = 2500

    rep_unit = 0
    for length in range(1, L_MAX + 1):
        rep_unit = rep_unit * 10 + 1

        for digit_val in range(1, 10):
            current_repdigit = digit_val * rep_unit

            if current_repdigit % k == 0:
                sys.stdout.write(f"{digit_val} {length}\n")
                return
            
    sys.stdout.write("Impossible\n")

if __name__ == "__main__":
    solve()