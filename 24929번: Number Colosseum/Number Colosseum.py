class NumberColosseum:
    def __init__(self):
        self.positives = []
        self.negatives = []

    def process_contestant(self, value):
        current = value
        team = 'positive' if current > 0 else 'negative'
        while True:
            opposing = self.negatives if team == 'positive' else self.positives
            if not opposing:
                break

            opponent = opposing.pop()
            if abs(current) > abs(opponent):
                current += opponent
            elif abs(opponent) > abs(current):
                current += opponent
                team = 'positive' if opponent > 0 else 'negative'
            else:
                current = None
                team = None
                break
        if current is not None and team is not None:
            if team == 'positive':
                self.positives.append(current)
            else:
                self.negatives.append(current)

    def determine_result(self):
        if not self.positives and not self.negatives:
            return ("Tie!", [])
        elif self.positives:
            return ("Positives win!", self.positives)
        else:
            return ("Negatives win!", self.negatives)

n = int(input())
contestants = list(map(int, input().split()))
colosseum = NumberColosseum()
for contestant in contestants:
    colosseum.process_contestant(contestant)

result, remaining = colosseum.determine_result()
print(result)
if remaining:
    print(' '.join(map(str, remaining)))