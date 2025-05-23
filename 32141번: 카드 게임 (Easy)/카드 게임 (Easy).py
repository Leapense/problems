def main():
    N, H = map(int, input().split())
    cards = list(map(int, input().split()))

    total_damage = 0
    cards_used = 0
    for i in range(N):
        total_damage += cards[i]
        cards_used += 1
        if total_damage >= H:
            print(cards_used)
            return

    print(-1)


if __name__ == "__main__":
    main()