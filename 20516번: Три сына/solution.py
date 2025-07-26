def main() -> None:
    import sys
    n = int(sys.stdin.readline().strip())
    q, r = divmod(n, 3)
    if r == 0:
        a, b, c = q - 1, q, q + 1
    elif r == 1:
        a, b, c = q - 1, q, q + 2
    else:
        a, b, c = q - 1, q + 1, q + 2
    print(a, b, c)

if __name__ == "__main__":
    main()