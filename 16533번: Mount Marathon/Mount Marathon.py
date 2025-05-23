def mount_marathon(N, cards):
    score = 0
    for i in range(N - 1):
        if cards[i] < cards[i + 1]:
            score += 1

    return score + 1

# Reading the input
N = int(input())
cards = list(map(int, input().split()))

# Calculating and printing the result
result = mount_marathon(N, cards)
print(result)