class CowWordGame:
    def __init__(self):
        import sys
        data = sys.stdin.read().strip().split()
        self.N, self.M = map(int, data[:2])
        self.points = list(map(int, data[2:28]))
        self.letters = data[28:28 + self.N]
        self.words = data[28 + self.N:]
    def solve(self):
        letter_count = [0] * 26
        for letter in self.letters:
            letter_count[ord(letter) - 65] += 1
        max_score = -1
        for word in self.words:
            temp_count = [0] * 26
            score = 0
            valid = True
            for ch in word:
                idx = ord(ch) - 65
                temp_count[idx] += 1
                if temp_count[idx] > letter_count[idx]:
                    valid = False
                    break
                score += self.points[idx]
            if valid and score > max_score:
                max_score = score
        print(max_score)

if __name__ == "__main__":
    game = CowWordGame()
    game.solve()