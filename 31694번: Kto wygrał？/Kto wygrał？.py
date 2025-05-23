# Function to determine the winner
def determine_winner(algosia_scores, bajtek_scores):
    total_algosia = sum(algosia_scores)
    total_bajtek = sum(bajtek_scores)

    if total_algosia > total_bajtek:
        return "Algosia"
    elif total_bajtek > total_algosia:
        return "Bajtek"
    else:
        # Scores are tied, we need to compare individual scores starting from 10 down to 0
        for score in range(10, -1, -1):
            count_algosia = algosia_scores.count(score)
            count_bajtek = bajtek_scores.count(score)
            if count_algosia > count_bajtek:
                return "Algosia"
            elif count_bajtek > count_algosia:
                return "Bajtek"
        return "remis"

# Read input scores
algosia_scores = list(map(int, input().strip().split()))
bajtek_scores = list(map(int, input().strip().split()))

# Determine the winner and print the result
winner = determine_winner(algosia_scores, bajtek_scores)
print(winner)