import math

class Clock:
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c

    def count_overlaps(self):
        gcd_value = math.gcd(self.a - 1, self.a * self.b - 1)
        return max(gcd_value - 1, 0)
    
def main():
    a, b, c = map(int, input().split())
    clock = Clock(a, b, c)
    print(clock.count_overlaps())

if __name__ == "__main__":
    main()