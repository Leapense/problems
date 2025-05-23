class UniformMaker:
    def __init__(self, N, M, words):
        self.N = N
        self.M = M
        self.words = words

    def get_minimum_changes(self):
        total_changes = 0
        for i in range(self.M):
            freq = [0] * 26

            for word in self.words:
                char_index = ord(word[i]) - ord('a')
                freq[char_index] += 1

            max_freq = max(freq)

            changes_for_position = self.N - max_freq
            total_changes += changes_for_position

        return total_changes
    
if __name__ == "__main__":
    import sys
    input_data = sys.stdin.read().strip().split()
    N, M = map(int, input_data[:2])
    words = input_data[2:]

    uniform_maker = UniformMaker(N, M, words)
    print(uniform_maker.get_minimum_changes())