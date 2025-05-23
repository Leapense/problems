t = int(input())

for _ in range(t):
    Yp, Lp, Ys, Ls = map(int, input().strip().split())

    ans = 0

    if Ys <= Ls:
        ans = Ys * Yp
    elif Yp <= Lp:
        ans = min(Ys * Yp, Ls * Lp)
    else:
        walk_lift = Ls * Lp + Ys * abs(Yp - Lp)
        lift_lift = Ls * (Yp + Yp - Lp);
        ans = min(walk_lift, lift_lift)
    print(ans)
