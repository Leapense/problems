import math

def lcm(x, y):
    return abs(x * y) // math.gcd(x, y)

n, a, b = map(int, input().split())
if a != b:
    Fizz = math.floor(n / a)
    Buzz = math.floor(n / b)
    FizzBuzz = math.floor(n / lcm(a, b))
    Fizz -= FizzBuzz
    Buzz -= FizzBuzz
    print(Fizz, Buzz, FizzBuzz)
else:
    print(0, 0, math.floor(n / a))