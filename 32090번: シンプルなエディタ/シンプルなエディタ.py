def main():
    while True:
        N = int(input())
        if N == 0:
            break

        text = []
        cursor = 0
        for _ in range(N):
            command = input().split()
            if command[0] == "INSERT":
                text.insert(cursor, command[1])
                cursor += 1  # Move cursor one position to the right after insertion
            elif command[0] == "LEFT":
                cursor = max(0, cursor - 1)
            elif command[0] == "RIGHT":
                cursor = min(len(text), cursor + 1)

        print("".join(text))


if __name__ == "__main__":
    main()