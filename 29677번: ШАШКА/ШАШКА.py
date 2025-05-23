import sys
import math

def main():
    lines = sys.stdin.read().splitlines()
    idx = 0

    n = int(lines[idx])
    idx += 1

    players = {}
    surnames = []

    for _ in range(n):
        parts = lines[idx].split()
        rating = int(parts[0])
        surname = ' '.join(parts[1:])
        
        players[surname] = rating
        surnames.append(surname)
        idx += 1

    if idx < len(lines):
        m = int(lines[idx])
        idx += 1
    else:
        m = 0

    for _ in range(m):
        parts = lines[idx].split()
        surname1, surname2, x = parts[0], parts[1], int(parts[2])

        idx += 1

        RA = players[surname1]; RB = players[surname2]

        # EA sports
        EA = 1 / (1 + math.pow(10, (RB - RA) / 400))
        EB = 1 - EA

        if x == 1:
            SA = 1.0; SB = 0.0
        elif x == 2:
            SA = 0.0; SB = 1.0
        else:
            SA = 0.5; SB = 0.5

        newRA = math.floor(RA + 15 * (SA - EA))
        newRB = math.floor(RB + 15 * (SB - EB))

        newRA = max(newRA, 0); newRB = max(newRB, 0)

        players[surname1] = newRA; players[surname2] = newRB

    player_list = []

    for surname in players:
        player_list.append((players[surname], surname))

    player_list.sort(key=lambda x: (-x[0], x[1]))

    for rating, surname in player_list:
        print(rating, surname)

if __name__ == '__main__':
    main()

