import argparse
import random

BLOCK_TYPE = ['cube', 'cylinder']
N_MIN = 1
N_MAX = 100
A_MIN = 1
A_MAX = 1000


parser = argparse.ArgumentParser(description="BOJ 20901 Test Generator")

parser.add_argument("--n_max", type=int, default=100)
parser.add_argument("--a_max", type=int, default=1000)

args = parser.parse_args()

if args.n_max < N_MIN:
    print("n은 1보다 크거나 같아야 합니다. 다시 시도해주십시오.")
    exit(1)
if args.n_max > N_MAX:
    print("n은 100보다 작거나 같아야 합니다. 다시 시도해주십시오.")
    exit(1)

if args.a_max < A_MIN:
    print("블록 크기를 나타내는 a의 값은 1보다 크거나 같아야 합니다. 다시 시도해주십시오.")
    exit(1)
if args.a_max > A_MAX:
    print("블록 크기를 나타내는 a의 값은 1000보다 작거나 같아야 합니다. 다시 시도해주십시오.")
    exit(1)

n = random.randint(1, args.n_max)
a = []
for _ in range(n):
    blockType = random.choice(BLOCK_TYPE)
    a.append((blockType, random.randint(1, args.a_max)))

print(n)
for ba, bb in a:
    print(f"{ba} {bb}")

