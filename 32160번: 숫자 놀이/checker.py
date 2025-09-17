import argparse
import sys
from collections import Counter

def parse_int_line(s, where, allow_empty=False):
    s = s.strip()
    if allow_empty and s == "":
        return None
    try:
        return int(s)
    except Exception:
        raise ValueError(f"{where}: 정수 1개가 필요합니다. (문자열='{s}')")
    
def parse_pair_line(s, idx):
    parts = s.strip().split()
    if len(parts) != 2:
        raise ValueError(f"{idx}번째 연산 줄: 두 정수 'a b'가 필요합니다. (줄='{s.strip()}')")
    try:
        a = int(parts[0])
        b = int(parts[1])
    except Exception:
        raise ValueError(f"{idx}번째 연산 줄: 두 값은 정수여야 합니다. (줄='{s.strip()}')")
    return a, b

def read_input_file(path):
    with open(path, "r", encoding="utf-8") as f:
        lines = [line.rstrip('\n') for line in f]
    if not lines:
        raise ValueError("입력 파일이 비어 있습니다.")
    N = parse_int_line(lines[0], "입력 1행")
    if not (2 <= N <= 200_000):
        raise ValueError(f"입력 N이 범위를 벗어났습니다: {N}")
    return N

def read_output_file(path):
    with open(path, "r", encoding="utf-8") as f:
        raw = [line.rstrip("\n") for line in f]
    while raw and raw[-1].strip() == "":
        raw.pop()
    if not raw:
        raise ValueError("출력 파일이 비어 있습니다.")
    final_val = parse_int_line(raw[0], "출력 1행")
    ops_lines = raw[1:]
    return final_val, ops_lines

def simulate_and_check(N, final_val, ops_lines, check_optimal=False):
    if len(ops_lines) != N - 1:
        return f"WA: 연산 줄 개수가 틀렸습니다. 기대={N-1}, 실제={len(ops_lines)}"
    
    multiset = Counter(range(1, N + 1))
    for i, line in enumerate(ops_lines, start=1):
        a, b = parse_pair_line(line, i)
        if multiset[a] <= 0:
            return f"WA: {i}번째 연산에서 a={a} 가 현재 멀티셋에 존재하지 않습니다."
        multiset[a] -= 1
        if multiset[a] == 0:
            del multiset[a]

        if multiset[b] <= 0:
            return f"WA: {i}번째 연산에서 b={b} 가 현재 멀티셋에 존재하지 않습니다."
        multiset[b] -= 1
        if multiset[b] == 0:
            del multiset[b]
        c = a - b
        multiset[c] += 1

    total_cnt = sum(multiset.values())
    if total_cnt != 1:
        return f"WA: 모든 연산 후 멀티셋 원소 개수는 1이어야 합니다. 실제={total_cnt}"
    
    remaining_val = next(iter(multiset.keys()))
    if remaining_val != final_val:
        return f"WA: 출력 1행의 최종 값({final_val})과 실제 남은 값({remaining_val})이 다릅니다."
    
    if check_optimal:
        S = N * (N + 1) // 2
        best = S - 2
        if final_val != best:
            return f"WA (최적성): 최댓값은 {best} 이어야 합니다. 실제 출력={final_val}"
    return "OK"

def main():
    parser = argparse.ArgumentParser(description="숫자 놀이 출력 검증기 (checker)")
    parser.add_argument("input_file", help="입력 파일 경로 (N만 포함)")
    parser.add_argument("output_file", help="출력 파일 경로 (정답자가 출력한 결과)")
    parser.add_argument("--optimal", action="store_true", help="최적값(S-2)까지 함께 검증")
    args = parser.parse_args()

    try:
        N = read_input_file(args.input_file)
        final_val, ops_lines = read_output_file(args.output_file)
        verdict = simulate_and_check(N, final_val, ops_lines, check_optimal=args.optimal)
        if verdict == "OK":
            print("OK")
            sys.exit(0)
        else:
            print(verdict)
            sys.exit(1)
    except Exception as e:
        print(f"Checker Error: {e}")
        sys.exit(1)

if __name__ == "__main__":
    main()