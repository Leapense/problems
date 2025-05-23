import sys

class LightShow:
    def __init__(self):
        self.R = 0
        self.C = 0
        self.top = ''
        self.right = ''
        self.bottom = ''
        self.left = ''
        self.color_map = {'R' : 1, 'G' : 2, 'B' : 4}
        self.counts_rows = [0] * 8
        self.counts_columns = [0] * 8

    def read_input(self):
        input = sys.stdin.read().split()
        self.R = int(input[0])
        self.C = int(input[1])
        self.top = input[2]
        self.right = input[3]
        self.bottom = input[4]
        self.left = input[5]

    def count_masks(self):
        left_bits = [self.color_map[c] for c in self.left]
        right_bits = [self.color_map[c] for c in self.right]
        row_masks = [l | r for l, r in zip(left_bits, right_bits)]
        for mask in row_masks:
            self.counts_rows[mask] += 1

        top_bits = [self.color_map[c] for c in self.top]
        bottom_bits = [self.color_map[c] for c in self.bottom]
        column_masks = [t | b for t, b in zip(top_bits, bottom_bits)]
        for mask in column_masks:
            self.counts_columns[mask] += 1

    def count_white_cells(self):
        total_white = 0
        for r_mask in range(8):
            if self.counts_rows[r_mask] == 0:
                continue
            for c_mask in range(8):
                if self.counts_columns[c_mask] == 0:
                    continue
                if (r_mask | c_mask) == 7:
                    total_white += self.counts_rows[r_mask] * self.counts_columns[c_mask]
        return total_white
    
    def run(self):
        self.read_input()
        self.count_masks()
        result = self.count_white_cells()
        print(result)

if __name__ == "__main__":
    show = LightShow()
    show.run()