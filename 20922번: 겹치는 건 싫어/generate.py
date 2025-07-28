import argparse
import random

parser = argparse.ArgumentParser(description="BOJ 20922 Test Data Generator")

parser.add_argument("--n", type=int, default=10)
parser.add_argument("--k", type=int, default=10)
parser.add_argument("--ai", type=int, default=10)

args = parser.parse_args()

if args.n < 1 or args.n > 200000:
    print("N의 범위는 [1, 200000] 이어야 합니다.")
    exit(1)

if args.k < 1 or args.k > 100:
    print("K의 범위는 [1, 100] 이어야 합니다.")
    exit(1)

if args.ai < 1 or args.ai > 100000:
    print("a[i] 의 범위는 [1, 100000] 이어야 합니다.")
    exit(1)

n = random.randint(1, args.n)
k = random.randint(1, args.k)

print(n, k)

a = []
for _ in range(n):
    a.append(random.randint(1, args.ai))

print(*a)