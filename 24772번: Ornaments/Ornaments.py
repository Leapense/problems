import math, sys

class Ornaments:
    def process(self):
        for line in sys.stdin:
            r, h, s = map(int, line.strip().split())
            if r == 0 and h == 0 and s == 0:
                break
            l = math.sqrt(h * h - r * r)
            theta = math.pi - math.acos(r / h)
            c = 2 * r * theta
            basic_length = 2 * l + c
            final_length = basic_length * (1 + s / 100)
            print("{0:.2f}".format(final_length))
if __name__ == "__main__":
    Ornaments().process()