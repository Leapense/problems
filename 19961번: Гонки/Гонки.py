def calc(t, v, x):
    r = x // (v * t)
    q = x % (v * t)

    if r != 0:
        if q != 0:
            return 2.0 * r * t + q // v
        else:
            return (2.0 * r - 1) * t
    else:
        return q / v


t1, v1, t2, v2 = map(int, input().split())
x = int(input())

if calc(t1, v1, x) < calc(t2, v2, x):
    print("First")
elif calc(t1, v1, x) > calc(t2, v2, x):
    print("Second")
else:
    print("Draw")
