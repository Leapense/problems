#!/usr/bin/env python3
import argparse
import math
import random
import sys

def compute_ice_degrees(temps):
    """
    자바 코드의 로직과 동일:
    current -= t; current < 0 이면 0으로 보정.
    """
    current = 0
    out = []
    for t in temps:
        current -= t
        if current < 0:
            current = 0
        out.append(current)
    return out

def gen_segments(n, k):
    if k <= 0:
        return []
    lens = [n // k] * k
    for i in range(n % k):
        lens[i] += 1
    random.shuffle(lens)
    return lens

def gen_temps(n, tmin, tmax, pattern):
    if pattern == 'uniform':
        return [random.randint(tmin, tmax) for _ in range(n)]

    # mix 패턴: cold/warm/swing/mild 구간을 섞어 생성
    k = 1 if n < 3 else random.randint(3, 7)
    lens = gen_segments(n, k)
    temps = []
    for seg_len in lens:
        if seg_len == 0:
            continue
        mode = random.choices(['cold', 'warm', 'swing', 'mild'],
                              weights=[3, 2, 2, 1])[0]

        if mode == 'cold' and tmin < 0:
            lo = tmin
            hi = min(-1, tmax)
            if lo <= hi:
                temps.extend(random.randint(lo, hi) for _ in range(seg_len))
                continue

        if mode == 'warm' and tmax > 0:
            lo = max(1, tmin)
            hi = tmax
            if lo <= hi:
                temps.extend(random.randint(lo, hi) for _ in range(seg_len))
                continue

        if mode == 'mild':
            lo = max(tmin, -2)
            hi = min(tmax, 2)
            if lo <= hi:
                temps.extend(random.randint(lo, hi) for _ in range(seg_len))
                continue

        # swing 또는 fallback: 음/양을 절반씩 섞되 범위를 보장
        for _ in range(seg_len):
            if random.random() < 0.5 and tmin < 0:
                lo = tmin
                hi = min(-1, tmax)
                if lo <= hi:
                    temps.append(random.randint(lo, hi))
                    continue
            lo = max(0, tmin)
            hi = tmax
            temps.append(random.randint(lo, hi))

    # 길이 보정
    temps = temps[:n]
    if len(temps) < n:
        temps += [random.randint(tmin, tmax) for _ in range(n - len(temps))]
    return temps

def choose_thresholds(p, ice_degrees, ensure_extremes=False, maxcm=None):
    max_ice = max(ice_degrees) if ice_degrees else 0
    base_max_cm = math.ceil(max_ice / 5) if max_ice > 0 else 0
    upper = max(0, maxcm) if maxcm is not None else max(20, base_max_cm * 3 + 15)

    res = []
    if p <= 0:
        return res

    if ensure_extremes:
        candidates = [0]
        if base_max_cm > 0:
            candidates.append(base_max_cm)  # 경계선 부근
        candidates.append(base_max_cm + random.randint(1, 10))  # 확실히 어려운 값
        # 음수 제거, 중복 제거
        seen = set()
        clean = []
        for c in candidates:
            if c >= 0 and c not in seen:
                seen.add(c)
                clean.append(c)
        random.shuffle(clean)
        for c in clean[:min(len(clean), p)]:
            res.append(c)

    while len(res) < p:
        r = random.random()
        if r < 0.5:
            val = random.randint(0, upper)
        elif r < 0.8:
            spread = max(5, base_max_cm * 2 + 5)
            val = base_max_cm + random.randint(-spread, spread)
            if val < 0:
                val = 0
        else:
            val = random.randint(0, min(upper, 10))
        res.append(val)

    random.shuffle(res)
    return res[:p]

def main():
    parser = argparse.ArgumentParser(description="자바 코드용 랜덤 테스트 입력 생성기")
    parser.add_argument('--days', '-d', type=int, default=None,
                        help='일수 days (미지정 시 무작위 1..200)')
    parser.add_argument('--people', '-p', type=int, default=None,
                        help='사람 수 people (미지정 시 무작위 1..200)')
    parser.add_argument('--tmin', type=int, default=-30, help='온도 최소값')
    parser.add_argument('--tmax', type=int, default=20, help='온도 최대값')
    parser.add_argument('--pattern', choices=['mix', 'uniform'], default='mix',
                        help='온도 생성 패턴')
    parser.add_argument('--seed', type=int, default=None, help='난수 시드')
    parser.add_argument('--ensure-extremes', action='store_true',
                        help='임계치에 극단값(항상 가능/거의 불가능) 일부 포함')
    parser.add_argument('--maxcm', type=int, default=None,
                        help='임계치(cm) 최대 상한 직접 지정')
    args = parser.parse_args()

    if args.seed is not None:
        random.seed(args.seed)

    if args.tmin > args.tmax:
        args.tmin, args.tmax = args.tmax, args.tmin

    n = args.days if args.days is not None else random.randint(1, 200)
    m = args.people if args.people is not None else random.randint(1, 200)

    # 자바 코드가 각 줄을 읽기 때문에 n, m은 1 이상을 권장
    n = max(1, n)
    m = max(1, m)

    temps = gen_temps(n, args.tmin, args.tmax, args.pattern)
    ice = compute_ice_degrees(temps)
    thresholds = choose_thresholds(m, ice,
                                   ensure_extremes=args.ensure_extremes,
                                   maxcm=args.maxcm)

    # 출력 포맷: 3줄
    # 1) days people
    # 2) temperatures (days개)
    # 3) thresholdsCm (people개)
    print(f"{n} {m}")
    print(" ".join(str(x) for x in temps))
    print(" ".join(str(x) for x in thresholds))

if __name__ == "__main__":
    main()