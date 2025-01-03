import math, sys
from math import isqrt

def get_coord(n):
    if n ==1:
        return (0,0)
    s = isqrt(n)
    if s*s <n:
        s +=1
    if s%2 ==1 and s*s >=n:
        k=(s -1)//2
    else:
        k=s//2
    max_num=(2*k +1)**2
    offset=max_num -n
    side_len=2*k
    side=offset // side_len
    pos=offset % side_len
    if side ==0:
        x=-k
        y=k - pos
    elif side ==1:
        x=-k + pos
        y=-k
    elif side ==2:
        x=k
        y=-k + pos
    elif side ==3:
        x=k - pos
        y=k
    return (x,y)

a, b = map(int, sys.stdin.read().split())
xa, ya = get_coord(a)
xb, yb = get_coord(b)
print(abs(xa - xb) + abs(ya - yb))
