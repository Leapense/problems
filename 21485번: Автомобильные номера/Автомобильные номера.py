import itertools
s = input().strip()

letters = [s[i] for i in [0,4,5]]
digits = [s[i] for i in [1,2,3]]
letter_perms = set(itertools.permutations(letters))
digit_perms = set(itertools.permutations(digits))
results = []

for lp in letter_perms:
    for dp in digit_perms:
        results.append(lp[0] + dp[0] + dp[1] + dp[2] + lp[1] + lp[2])

print(len(results))
for r in results:
    print(r)