#!/usr/bin/env python3
"""
순환 소수를 약분된 분수로 변환한다.

입력 : 여러 줄, 각 줄은 '정수부.비순환(순환)' 형태
출력 : '원본 = p / q'
"""

from __future__ import annotations

import sys
import math
import re
from typing import Tuple

# 상수
BASE : int = 10
PATTERN = re.compile(r"^(\d+)\.(\d*)\((\d+)\)$")

def parse_decimal(line : str) -> Tuple[str,str,str]:
    """
    'a.b(c)' 형태의 문자열을 정수부(a), 비순환(b), 순환(c) 세 부분으로 분리한다.

    :param line : 한 줄 입력(개행 제외)
    :return : (a, b, c)
    :raises ValueError : 형식이 맞지 않을 때
    """
    match = PATTERN.match(line)
    if not match:
        raise ValueError(f"잘못된 형식: {line}")
    return match.group(1), match.group(2), match.group(3)

def to_fraction(a : str, b : str, c : str) -> Tuple[int,int]:
    """
    공식에 따라 (A - B) / (10^(m+n) - 10^m) 을 계산하고 약분한다.

    :param a : 정수부
    :param b : 비순환부 (없으면 빈 문자열)
    :param c : 순환부 (길이 >= 1)
    :return : (약분된 분자, 분모)
    """
    m : int = len(b)
    n : int = len(c)

    digits_a_b_c : str = f"{a}{b}{c}"
    digits_a_b : str = f"{a}{b}" if b else a

    numerator : int = int(digits_a_b_c) - int(digits_a_b)
    denominator : int = BASE ** (m + n) - BASE ** m

    divisor : int = math.gcd(numerator, denominator)
    return numerator // divisor, denominator // divisor

def main() -> None:
    """
    EOF까지 한 줄씩 읽어 처리한다.
    """
    for raw in sys.stdin:
        line : str = raw.strip()
        if not line:
            continue
        a, b, c = parse_decimal(line)
        p, q = to_fraction(a, b, c)
        # 요구된 출력 형식
        print(f"{line} = {p} / {q}")

if __name__ == "__main__":
    main()