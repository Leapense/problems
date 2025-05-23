n, m, k, a, b, c = map(int, input().strip().split())

Joffery_Force = n * a
Robb_Force = m * b
Stannis_Force = k * c

max_Force = max(Joffery_Force, Robb_Force, Stannis_Force)

ans = []

if max_Force == Joffery_Force:
    ans.append("Joffrey")
if max_Force == Robb_Force:
    ans.append("Robb")
if max_Force == Stannis_Force:
    ans.append("Stannis")

print(" ".join(sorted(ans)))