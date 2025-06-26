import random
import time
import math
import matplotlib.pyplot as plt
from typing import List, Tuple

DAY = 24 * 60
QUOTA = 12 * 60

class Interval:
    __slots__ = ("s", "e", "owner")

    def __init__(self, s: int, e: int, owner: str) -> None:
        self.s = s
        self.e = e
        self.owner = owner
    
    @property
    def length(self) -> int:
        return self.e - self.s
    
def minimal_exchanges(fixed: List[Interval]) -> int:
    fixed.sort(key=lambda it : it.s)
    cam = jam = 0
    for it in fixed:
        if it.owner == "C":
            cam += it.length
        else:
            jam += it.length
    same_c: List[int] = []
    same_j: List[int] = []
    transitions = 0
    n = len(fixed)
    for idx in range(n):
        cur, nxt = fixed[idx], fixed[(idx + 1) % n]
        gap = (nxt.s - cur.e) % DAY
        if gap:
            if cur.owner == nxt.owner:
                if cur.owner == "C":
                    cam += gap
                    same_c.append(gap)
                else:
                    jam += gap
                    same_j.append(gap)
            else:
                transitions += 1
        if cur.owner != nxt.owner:
            transitions += 1
    transitions -= n
    if cam > QUOTA:
        transitions += _fix(cam - QUOTA, same_c)
    elif jam > QUOTA:
        transitions += _fix(jam - QUOTA, same_j)
    return transitions

def _fix(extra: int, gaps: List[int]) -> int:
    if extra <= 0:
        return 0
    gaps.sort(reverse=True)
    add = 0
    for g in gaps:
        if extra <= 0:
            break
        extra -= g
        add += 2
    if extra > 0:
        add += 2
    return add

def random_case(k: int) -> List[Interval]:
    points = sorted(random.sample(range(1, DAY), k * 2))
    intervals: List[Tuple[int, int]] = [(points[i], points[i + 1]) for i in range(0, 2 * k, 2)]
    fixed: List[Interval] = []
    for s, e in intervals:
        owner = random.choice(("C", "J"))
        fixed.append(Interval(s, e, owner))
    return fixed

def measure():
    ks, times = [], []
    for k in range(2, 31, 2):
        fixed = random_case(k)
        start = time.perf_counter()
        for _ in range(1_000):
            minimal_exchanges(fixed)
        elapsed = (time.perf_counter() - start) / 1_000
        ks.append(k)
        times.append(elapsed)

    theo = [ks[i] * math.log2(ks[i]) * times[0] / (ks[0] * math.log2(ks[0])) for i in range(len(ks))]
    plt.figure(figsize=(7, 4))
    plt.plot(ks, times, "o-", label="Time Elapsed (s)")
    plt.plot(ks, theo, "r--", label="c * k log k")
    plt.xlabel("Number of Activies (k)")
    plt.ylabel("Avg. Time Elapsed (s)")
    plt.title("Parenting Partnering Algorithm Time Complexity")
    plt.legend()
    plt.tight_layout()
    plt.show()

import matplotlib.pyplot as plt
from typing import List


def show_timeline(fixed: List[Interval]) -> None:
    """
    fixed  : 현재 구현처럼 'owner' 필드가 'C' 또는 'J' 인 Interval 리스트
             (즉, 이미 '아기를 봐야 하는 강제 구간'으로 변환된 형태)
    """
    # 알고리즘을 돌려서 최종 스케줄(분 단위 owner 배열)을 만든다.
    schedule = build_final_schedule(fixed)   # 아래에 정의

    fig, ax = plt.subplots(figsize=(10, 1.8))
    colors = {"C": "#4f81bd", "J": "#c0504d"}
    cur = schedule[0]
    start = 0
    for minute in range(1, 1441):
        if minute == 1440 or schedule[minute] != cur:
            ax.barh(0, minute - start, left=start,
                    height=0.5, color=colors[cur])
            start = minute
            if minute < 1440:
                cur = schedule[minute]
    ax.set_yticks([])
    ax.set_xlim(0, 1440)
    ax.set_xlabel("Minutes since midnight")
    ax.set_title("Baby-care timeline (C = blue, J = red)")
    plt.tight_layout()
    plt.show()


def build_final_schedule(fixed: List[Interval]) -> List[str]:
    """
    매우 단순한 구현:
       ① 서로 다른 owner 사이 gap 은 필요에 따라 Cameron 쪽으로 채움
       ② 부족하면 Jamie…
    시각화 목적이므로 최소 교대성을 따지기보다는 손쉽게 quota 를 맞춤
    (production 용은 DP 등을 이용해도 좋습니다)
    """
    timeline = ["?" for _ in range(1440)]
    for it in fixed:
        for m in range(it.s, it.e):
            timeline[m] = it.owner

    # 남은 칸 채우기 (alternate 방식)
    cur_owner = timeline[0] if timeline[0] != "?" else "C"
    for m in range(1440):
        if timeline[m] == "?":
            timeline[m] = cur_owner
        else:
            cur_owner = timeline[m]

    # Cameron quota 맞추기 (간단 조정)
    cam_minutes = sum(1 for x in timeline if x == "C")
    need = QUOTA - cam_minutes
    if need > 0:
        # Cameron 이 더 필요: 첫 need 만큼 J 를 C 로 바꾼다
        for m in range(1440):
            if timeline[m] == "J":
                timeline[m] = "C"
                need -= 1
                if need == 0:
                    break
    elif need < 0:
        need = -need
        for m in range(1440):
            if timeline[m] == "C":
                timeline[m] = "J"
                need -= 1
                if need == 0:
                    break
    return timeline + [timeline[0]]  # 1440 인덱스를 위해 wrap

if __name__ == "__main__":
    measure()
    fixed_intervals = [
        Interval(540, 600, "J"),
        Interval(840, 900, "C"),
    ]
    show_timeline(fixed_intervals)