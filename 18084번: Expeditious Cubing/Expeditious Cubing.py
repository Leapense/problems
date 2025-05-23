def expeditious_cubing(t1, t2, t3, t4, target):
    times = [t1, t2, t3, t4]
    times.sort()

    current_best_score = sum(times[1:]) / 3
    if current_best_score <= target:
        return "infinite"
    
    lo, hi = 1, 20
    result = "impossible"

    while hi - lo > 1e-6:
        mid = (lo + hi) / 2
        new_times = sorted(times + [mid])
        new_score = sum(new_times[1:4]) / 3

        if new_score <= target:
            result = f"{mid:.2f}"
            lo = mid
        else:
            hi = mid

    return result

t1, t2, t3, t4 = map(float, input().strip().split())
target = float(input().strip())
print(expeditious_cubing(t1, t2, t3, t4, target))