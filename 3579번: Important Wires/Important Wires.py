import sys
lines = sys.stdin.read().splitlines()
if not lines:
    sys.exit(0)

n = int(lines[0].strip())
pins = []
for i in range(1, n+1):
    line = lines[i]
    left, _ = line.split(":=")
    pin = left.strip()
    pins.append(pin)

pins = sorted(set(pins))
formula_parts = []
for p in pins:
    formula_parts.append(f"{p}|~{p}")
formula = "&".join(formula_parts)
print("Yes")
print(formula)