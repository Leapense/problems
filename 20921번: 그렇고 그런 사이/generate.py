import argparse
import random

parser = argparse.ArgumentParser(description="BOJ 20921 Test Data Generator")

parser.add_argument("--n_max", type=int, default=10)
parser.add_argument("--k_max", type=int, default=(10 * 9) // 2)

args = parser.parse_args()

if args.n_max < 2:
    print("N은 2보다 크거나 같아야 합니다.")
    exit(1)
if args.n_max > 4242:
    print("N은 4,242 보다 작거나 같아야 합니다.")
    exit(1)

if args.k_max < 0:
    print("K는 0보다 크거나 같아야 합니다.")
    exit(1)
if args.k_max > (args.n_max * (args.n_max - 1)) // 2:
    print("K는 N(N-1)/2 보다 작거나 같아야 합니다.")
    exit(1)

n = random.randint(2, args.n_max)
k = random.randint(0, args.k_max)

print(n, k)