#!/usr/bin/env python3
import sys
from typing import List, Tuple

def read_file(path: str) -> str:
    with open(path, "r", encoding="utf-8") as f:
        return f.read()
    
def parse_input(inp: str) -> Tuple[int, List[int]]:
    lines = inp.strip().splitlines()
    if len(lines) < 2:
        raise ValueError("입력 형식 오류: 줄이 부족합니다.")
    try:
        N = int(lines[0].strip())
    except Exception:
        raise ValueError("입력 형식 오류: 첫 줄 N을 정수로 해석할 수 없습니다.")
    try:
        A = list(map(int, lines[1].split()))
    except Exception:
        raise ValueError("입력 형식 오류: 둘째 줄 A의 원소를 정수로 해석할 수 없습니다.")
    if len(A) != N:
        raise ValueError(f"입력 형식 오류: A의 길이 ({len(A)})가 N({N})과 다릅니다.")
    return N, A

def parse_output(out: str) -> Tuple[bool, int, List[int]]:
    tokens = out.split()
    if not tokens:
        raise ValueError("출력 형식 오류: 출력이 비어 있습니다.")
    if tokens[0] == "-1":
        return True, -1, []
    try:
        K = int(tokens[0])
    except Exception:
        raise ValueError("출력 형식 오류: 첫 토큰을 정수 K로 해석할 수 없습니다.")
    rest = tokens[1:]
    try:
        nums = list(map(int, rest))
    except Exception:
        raise ValueError("출력 형식 오류: 배열 원소를 정수로 해석할 수 없습니다.")
    return False, K, nums

def is_non_increasing(arr: List[int]) -> True:
    return all(arr[i] >= arr[i + 1] for i in range(len(arr) - 1))

def check_step(prev: List[int], curr: List[int], step_idx: int) -> Tuple[int, int, int]:
    if len(prev) != len(curr):
        raise ValueError(f"{step_idx}번째 단계 오류: 배열 길이가 일치하지 않습니다.")
    N = len(prev)
    changed = [p for p in range(N) if prev[p] != curr[p]]
    if len(changed) == 0:
        raise ValueError(f"{step_idx}번째 단계 오류: 변화가 없습니다. x > 0 이어야 합니다.")
    if len(changed) != 2:
        raise ValueError(f"{step_idx}번째 단계 오류: 한 단계에 정확히 두 위치만 변경되어야 합니다. (실제 {len(changed)}개)")
    a, b = changed
    da = curr[a] - prev[a]
    db = curr[b] - prev[b]
    if da + db != 0:
        raise ValueError(f"{step_idx}번째 단계 오류: 총합이 보존되지 않았습니다. (da+db={da+db})")
    if da == 0 or db == 0:
        raise ValueError(f"{step_idx}번째 단계 오류: 변화량이 0인 위치가 있습니다.")
    if abs(da) != abs(db):
        raise ValueError(f"{step_idx}번째 단계 오류: 두 변화량의 절댓값이 같아야 합니다. (|{da}| vs |{db}|)")
    x = abs(da)
    if not (1 <= x <= 10**6):
        raise ValueError(f"{step_idx}번째 단계 오류: x가 범위를 벗어났습니다. (x={x})")
    if da > 0 and db < 0:
        i, j = a, b
    elif db > 0 and da < 0:
        i, j = b, a
    else:
        raise ValueError(f"{step_idx}번째 단계 오류: 한쪽은 +x, 다른 한쪽은 -x 이어야 합니다.")
    return i, j, x

def chunk(lst: List[int], n: int) -> List[List[int]]:
    return [lst[i:i+n] for i in range(0, len(lst), n)]

def main():
    if len(sys.argv) != 3:
        print("사용법: python3 checker.py <input.txt> <output.txt>", file=sys.stderr)
        sys.exit(1)
    try:
        inp = read_file(sys.argv[1])
        out = read_file(sys.argv[2])
    except Exception as e:
        print(f"WA: 파일 읽기 실패 - {e}", file=sys.stderr)
        sys.exit(1)

    try:
        N, A0 = parse_input(inp)
    except Exception as e:
        print(f"WA: {e}", file=sys.stderr)
        sys.exit(1)

    try:
        is_minus_one, K, flat = parse_output(out)
    except Exception as e:
        print(f"WA: {e}", file=sys.stderr)
        sys.exit(1)

    if is_minus_one:
        print("WA: 이 문제는 ⌊N/2⌋번 이하로 항상 해결 가능합니다. -1 출력은 정답이 아닙니다.", file=sys.stderr)
        sys.exit(1)
    if K < 0:
        print("WA: K(연산 횟수)는 음수가 될 수 없습니다.", file=sys.stderr)
        sys.exit(1)
    if K > N // 2:
        print(f"WA: 연산 횟수 K가 제한을 초과했습니다. (K={K}, 허용={N//2})", file=sys.stderr)
        sys.exit(1)

    if len(flat) != K * N:
        print(f"WA: 출력 숫자 개수가 맞지 않습니다. (기대한 {K*N}개, 실제 {len(flat)}개)", file=sys.stderr)
        sys.exit(1)
    snaps = chunk(flat, N)
    prev = A0[:]
    for s, curr in enumerate(snaps, start=1):
        try:
            i, j, x = check_step(prev, curr, s)
        except Exception as e:
            print(f"WA: {e}", file=sys.stderr)
            sys.exit(1)
        prev = curr

    if not is_non_increasing(prev):
        print("WA: 최종 배열이 내림차순(비증가)이 아닙니다.", file=sys.stderr)
        sys.exit(1)

    print("OK")
    sys.exit(0)

if __name__ == "__main__":
    main()