import sys
from decimal import Decimal, getcontext
from typing import List

# Decimal 연산 정밀도 설정
getcontext().prec = 50


def calculate_tetrahedron_volume_decimal(edges: List[str]) -> Decimal:
    """
    6개의 변 길이를 문자열로 받아 Decimal 연산으로 부피 계산.
    :param edges: ['AB', 'AC', 'AD', 'BC', 'BD', 'CD']
    :return: 부피 Decimal (정확히 4자리 반올림)
    """
    if len(edges) != 6:
        raise ValueError("6개의 변 길이를 입력해야 합니다.")
    # Decimal로 변환
    d = [Decimal(x) for x in edges]
    AB, AC, AD, BC, BD, CD = d
    # 제곱값 준비
    AB2, AC2, AD2, BC2, BD2, CD2 = [x * x for x in d]

    # Cayley-Menger 행렬 (5×5) 구성
    M = [
        [Decimal(0), Decimal(1),   Decimal(1),   Decimal(1),   Decimal(1)],
        [Decimal(1), Decimal(0),   AB2,          AC2,          AD2],
        [Decimal(1), AB2,          Decimal(0),   BC2,          BD2],
        [Decimal(1), AC2,          BC2,          Decimal(0),   CD2],
        [Decimal(1), AD2,          BD2,          CD2,          Decimal(0)],
    ]

    # 행렬식 계산 (Decimal 버전 가우스 소거)
    det = _determinant_decimal(M)
    if det < 0 and abs(det) < Decimal("1e-30"):
        det = Decimal(0)
    if det < 0:
        raise ValueError("유효한 테트라헤드론이 아닙니다.")

    # 부피 = sqrt(det / 288), 소수점 넷째 자리에서 반올림
    vol = (det / Decimal(288)).sqrt()
    return vol.quantize(Decimal("0.0001"))


def _determinant_decimal(A: List[List[Decimal]]) -> Decimal:
    """
    Decimal 가우스 소거로 행렬식 계산
    :param A: n×n Decimal 행렬
    :return: Decimal 행렬식
    """
    n = len(A)
    # 복사하여 원본 보호
    M = [row[:] for row in A]
    det = Decimal(1)
    for i in range(n):
        # 피벗 선택 (절댓값 최대)
        pivot = max(range(i, n), key=lambda r: abs(M[r][i]))
        if M[pivot][i] == 0:
            return Decimal(0)
        # 행 교환 시 부호 반전
        if pivot != i:
            M[i], M[pivot] = M[pivot], M[i]
            det = -det
        det *= M[i][i]
        # 전진 소거
        for j in range(i + 1, n):
            factor = M[j][i] / M[i][i]
            for k in range(i, n):
                M[j][k] -= factor * M[i][k]
    return det


def main():
    edges = sys.stdin.read().split()
    try:
        volume = calculate_tetrahedron_volume_decimal(edges)
        # 이미 4자리 반올림된 Decimal을 문자열로 출력
        print(volume)
    except Exception as ex:
        sys.stderr.write(f"Error: {ex}\n")
        sys.exit(1)


if __name__ == "__main__":
    main()