def max_pleasure(n, k, a):
    current_pleasure = a[:]
    consecutive_play = [0] * n
    total_pleasure = 0
    previous_song = -1

    for _ in range(k):
        max_pleasure = -1
        chosen_song = -1

        for i in range(n):
            if i != previous_song and current_pleasure[i] > max_pleasure:
                max_pleasure = current_pleasure[i]
                chosen_song = i

        if chosen_song == -1:
            chosen_song = previous_song
            max_pleasure = current_pleasure[chosen_song]

        total_pleasure += max_pleasure
        consecutive_play[chosen_song] += 1
        current_pleasure[chosen_song] = max(a[chosen_song] - consecutive_play[chosen_song], 0)
        previous_song = chosen_song

    return total_pleasure

n, k = map(int, input().split())
a = list(map(int, input().split()))

print(max_pleasure(n, k, a))