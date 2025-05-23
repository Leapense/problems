n = int(input())
q, r = divmod(n,3)
if r == 0:
    print(7*q)
elif r == 1:
    print(7*(q-1)+4)
else:
    print(7*q+1)