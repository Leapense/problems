import sys

class ShuffleProcessor:
    def __init__(self):
        self.position = 1
        self.process_shuffles()
    def process_shuffles(self):
        input = sys.stdin.read().split()
        N = int(input[0])
        idx = 1
        for _ in range(N):
            A = []
            while idx < len(input) and len(A) < 27:
                A.append(int(input[idx]))
                idx += 1
                if sum(A) == 27:
                    break
            left_total = 13
            right_total = 14
            if self.position <= left_total:
                side = 'left'
                pos = self.position
            else:
                side = 'right'
                pos = self.position - left_total
            total_taken = 0
            for j, a in enumerate(A):
                if j % 2 == 0:
                    current_side = 'right'
                else:
                    current_side = 'left'
                if current_side == side:
                    if a >= pos:
                        self.position = total_taken + pos
                        break
                    else:
                        pos -= a
                total_taken += a
        print(self.position)
ShuffleProcessor()