import sys
import itertools

class Sport:
    def __init__(self):
        self.input = sys.stdin.read().strip()
        self.sorted_input = ''.join(sorted(self.input))
    def generate_permutations(self):
        return [''.join(p) for p in itertools.permutations(self.sorted_input)]
    
    def run(self):
        permutations = self.generate_permutations()
        for perm in permutations:
            print(perm)

if __name__ == "__main__":
    Sport().run()