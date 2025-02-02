class YachtDiceSolver:
    def __init__(self):
        self.available = input().strip()
        self.fixed_dice = list(map(int, input().split()))

    def solve(self):
        answer = 0
        for d1 in range(1, 7):
            for d2 in range(1, 7):
                dice = self.fixed_dice + [d1, d2]
                freq = [0] * 7
                for val in dice:
                    freq[val] += 1
                total_sum = sum(dice)
                candidate_score = 0

                for i, ch in enumerate(self.available):
                    if ch == 'N':
                        continue

                    if i < 6:
                        score = freq[i + 1] * (i + 1)
                    elif i == 6:
                        score = 0
                        for face in range(1, 7):
                            if freq[face] >= 4:
                                score = max(score, face * 4)
                    elif i == 7:
                        score = 0
                        distinct_faces = sum(1 for x in freq if x > 0)
                        if distinct_faces == 2:
                            if 3 in freq and 2 in freq:
                                score = total_sum
                    elif i == 8:
                        if all(freq[val] == 1 for val in range(1, 6)) and freq[6] == 0:
                            score = 30
                        else:
                            score = 0
                    elif i == 9:
                        if all(freq[val] == 1 for val in range(2, 7)) and freq[1] == 0:
                            score = 30
                        else:
                            score = 0
                    elif i == 10:
                        score = 50 if max(freq) == 5 else 0
                    else:
                        score = total_sum
                    
                    candidate_score = max(candidate_score, score)
                answer = max(answer, candidate_score)
        print(answer)

def main():
    solver = YachtDiceSolver()
    solver.solve()

if __name__ == "__main__":
    main()