import random
import argparse

parser = argparse.ArgumentParser(description="Get wise to this: the main contraption what churns out the goods.")

parser.add_argument('--n_max', type=int, default=20)
parser.add_argument('--ai_max', type=int, default=3000)

args = parser.parse_args()

if args.n_max < 3:
    print('Bro, N must be 3 up.')
    exit(1)
if args.n_max > 20:
    print('Yo, that is so many. Chillax.')
    exit(1)

if args.ai_max < 1:
    print('There is no way negative edition. what you expected.')
    exit(1)
if args.ai_max > 3000:
    print('Ya need to set BELOW 3000 plus 1.')
    exit(1)

n = random.randint(3, args.n_max)
ai = []

for i in range(n):
    ai.append(random.randint(1, args.ai_max))

print(n)
print(" ".join(map(str, ai)))