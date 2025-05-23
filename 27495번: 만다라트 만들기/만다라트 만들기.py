class MandaratSolver:
    def __init__(self):
        self.board = [input().split() for _ in range(9)]
        self.mid_objs = []
        self.sub_objs_map = {}
        self.final_obj = self.board[4][4]
        self.find_mid_objs()
        self.find_sub_objs()

    def char_order(self, c):
        if c.isdigit():
            return (0, ord(c))
        if c.isalpha():
            if c.isupper():
                return (1, ord(c))
            return (2, ord(c))
        return (3, ord(c))
    
    def custom_sort_key(self, s):
        return tuple(self.char_order(c) for c in s), len(s)
    
    def find_mid_objs(self):
        for r in range(3, 6):
            for c in range(3, 6):
                if r == 4 and c == 4:
                    continue
                self.mid_objs.append(self.board[r][c])

    def find_second_occurrence(self, target):
        for r in range(9):
            for c in range(9):
                if 3 <= r <= 5 and 3 <= c <= 5:
                    continue
                if self.board[r][c] == target:
                    return (r, c)
                
    def find_sub_objs(self):
        for m in self.mid_objs:
            r, c = self.find_second_occurrence(m)
            subs = []
            for nr in range(r-1, r+2):
                for nc in range(c-1, c+2):
                    if not (nr == r and nc == c):
                        subs.append(self.board[nr][nc])
            self.sub_objs_map[m] = subs

    def solve(self):
        self.mid_objs.sort(key = self.custom_sort_key)
        for i, m in enumerate(self.mid_objs, start = 1):
            subs = self.sub_objs_map[m]
            subs.sort(key = self.custom_sort_key)
            print(f"#{i}. {m}")
            for j, s in enumerate(subs, start = 1):
                print(f"#{i}-{j}. {s}")
def main():
    solver = MandaratSolver()
    solver.solve()

if __name__ == "__main__":
    main()