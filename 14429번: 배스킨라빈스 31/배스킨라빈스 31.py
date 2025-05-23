def find_shortest_game(n, games):
    index = 0
    len = 987654321
    for i in range(n):
        j, m = games[i]
        nextLen = ((j - 1) // (m + 1) + 1) * 2
        if nextLen < len:
            len = nextLen
            index = i + 1
        
    print(index, len)

n = int(input())
games = []
for i in range(n):
    games.append(list(map(int, input().split())))

find_shortest_game(n, games)