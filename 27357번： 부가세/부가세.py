class VATCalculator:
    def __init__(self):
        import sys
        input_data = sys.stdin.read().strip().split()
        self.T = int(input_data[0])
        self.data = input_data[1:]
        self.idx = 0

    def solve(self):
        results = []
        for _ in range(self.T):
            N = int(self.data[self.idx]); self.idx += 1
            X = int(self.data[self.idx]); self.idx += 1
            sum_c = 0
            for __ in range(N):
                price_str = self.data[self.idx]
                self.idx += 1
                d, c = price_str.split('.')
                sum_c += int(d) * 100 + int(c)

            possible_min = None
            possible_max = None

            for F in range(10001):
                r = F * sum_c
                tax_floor = r // 100
                if r % 100 == 0:
                    tax_ceil = tax_floor
                else:
                    tax_ceil = tax_floor + 1

                final_floor_dollars = (sum_c + tax_floor) // 100
                final_ceil_dollars = (sum_c + tax_ceil) // 100

                if final_floor_dollars == X or final_ceil_dollars == X:
                    if possible_min is None:
                        possible_min = F
                    possible_max = F

            results.append(f"{possible_min} {possible_max}")
        print("\n".join(results))


def main():
    calculator = VATCalculator()
    calculator.solve()

if __name__ == "__main__":
    main()