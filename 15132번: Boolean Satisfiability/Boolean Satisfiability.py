import sys
formula = sys.stdin.read().strip()
literals = formula.split('|')
positive_vars = set()
negative_vars = set()

for lit in literals:
    if lit.startswith('~'):
        negative_vars.add(lit[1])
    else:
        positive_vars.add(lit[0])

all_vars = positive_vars.union(negative_vars)
m = len(all_vars)
conflict = any(var in positive_vars and var in negative_vars for var in all_vars)
if conflict:
    result = 2 ** m
else:
    result = 2 ** m - 1

print(result)