MAX_N = 11234

def main():
    notes = [0] * MAX_N

    while True:
        try:
            n = int(input())
        except EOFError:
            break

        notes = list(map(int, input().split()))
        avg = sum(notes)

        if avg % n != 0:
            res = -1
        else:
            avg //= n
            res = 1
            for note in notes:
                if note < avg:
                    res += avg - note

        print(res)

if __name__ == '__main__':
    main()