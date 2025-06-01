#!/usr/bin/env python3

from __future__ import annotations
from dataclasses import dataclass
from typing import List, Tuple

@dataclass(frozen=True)
class Rect:
    x0: float
    y0: float
    x1: float
    y1: float

    def contains(self, x: float, y: float) -> bool:
        """점 (x, y)가 경계 안쪽에 있는가?"""
        return self.x0 < x < self.x1 and self.y0 < y < self.y1
    
VERTICAL_SIDES: str = "RLRRLLL"
HORIZONTAL_SIDES: str = "BBTTTBT"
CUT_COUNT: int = 14
ORIGIN_SIZE: float = 80.0

def build_partitions() -> List[Rect]:
    """15 개의 분할 영역을 계산하여 반환한다."""
    partitions: List[Rect] = []
    current: Rect = Rect(0.0, 0.0, ORIGIN_SIZE, ORIGIN_SIZE)
    vertical_idx: int = 0
    horizontal_idx: int = 0
    orientation: int = 0

    for _ in range(CUT_COUNT):
        if orientation % 2 == 0:
            side: str = VERTICAL_SIDES[vertical_idx]
            vertical_idx += 1
            width: float = (current.x1 - current.x0) / 4.0

            if side == "R":
                small = Rect(current.x1 - width, current.y0, current.x1, current.y1)
                large = Rect(current.x0, current.y0, current.x1 - width, current.y1)
            else:
                small = Rect(current.x0, current.y0, current.x0 + width, current.y1)
                large = Rect(current.x0 + width, current.y0, current.x1, current.y1)
        else:
            side = HORIZONTAL_SIDES[horizontal_idx]
            horizontal_idx += 1
            height: float = (current.y1 - current.y0) / 4.0

            if side == "B":
                small = Rect(current.x0, current.y0, current.x1, current.y0 + height)
                large = Rect(current.x0, current.y0 + height, current.x1, current.y1)
            else:
                small = Rect(current.x0, current.y1 - height, current.x1, current.y1)
                large = Rect(current.x0, current.y0, current.x1, current.y1 - height)

        
        partitions.append(small)
        current = large
        orientation = (orientation + 1) % 4

    partitions.append(current)
    return partitions

def locate_point(x: float, y: float, areas: List[Rect]) -> int:
    """점이 들어 있는 영역 번호(1-15)를 반환한다."""
    for idx, region in enumerate(areas, start=1):
        if region.contains(x, y):
            return idx
    raise ValueError("Point lies on a cutting line, contrary to problem guarantee.")

def main() -> None:
    import sys

    areas: List[Rect] = build_partitions()
    reader = sys.stdin.readline

    test_count: int = int(reader().strip())
    answers: List[str] = []
    for _ in range(test_count):
        px_str, py_str = reader().split()
        px, py = float(px_str), float(py_str)
        answers.append(str(locate_point(px, py, areas)))

    sys.stdout.write("\n".join(answers))

if __name__ == "__main__":
    main()