def main():
    import sys
    input = sys.stdin.readline

    n = int(input().strip())
    piles = list(map(int, input().split()))
    odd_count = sum(1 for a in piles if a % 2 == 1)

    if odd_count % 2 == 1:
        normal_winner = "Misha"
    else:
        normal_winner = "Gleb"

    all_ones = all(a == 1 for a in piles)

    if all_ones:
        if n % 2 == 0:
            misere_winner = "Misha"
        else:
            misere_winner = "Gleb"
    else:
        if odd_count % 2 == 0:
            misere_winner = "Misha"
        else:
            misere_winner = "Gleb"

    sys.stdout.write(normal_winner + "\n")
    sys.stdout.write(misere_winner + "\n")

if __name__ == "__main__":
    main()