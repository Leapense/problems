def main():
    import sys
    sys.setrecursionlimit(10000)

    from sys import stdin

    initial_players = list(map(int, stdin.readline().split()))
    sorted_winners = list(map(int, stdin.readline().split()))
    sorted_winners_sorted = sorted(sorted_winners)

    def assign_match(i, match_winners, remaining_winners):
        if i == 7:
            return match_winners.copy()
        
        if i < 4:
            p1, p2 = initial_players[2 * i], initial_players[2 * i + 1]
        elif i == 4:
            p1, p2 = match_winners[0], match_winners[1]
        elif i == 5:
            p1, p2 = match_winners[2], match_winners[3]
        elif i == 6:
            p1, p2 = match_winners[4], match_winners[5]

        possible_winners = []

        if p1 in remaining_winners:
            possible_winners.append(p1)
        if p2 in remaining_winners:
            if p2 != p1 or remaining_winners.count(p2) > 1:
                possible_winners.append(p2)

        for w in possible_winners:
            match_winners[i] = w
            new_remaining = remaining_winners.copy()
            new_remaining.remove(w)

            result = assign_match(i + 1, match_winners, new_remaining)
            if result is not None:
                return result
        return None
    
    match_winners = [None] * 7
    result = assign_match(0, match_winners, sorted_winners.copy())

    if result:
        print(result[6])
        print(result[4], result[5])
        print(result[0], result[1], result[2], result[3])
    else:
        pass

if __name__ == '__main__':
    main()