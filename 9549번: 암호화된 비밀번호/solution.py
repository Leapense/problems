#!/usr/bin/env python3

import sys
from typing import List

def is_encrypted_form(encrypted: str, original: str) -> bool:
    """
    encrypted 문자열이 original 문자열을 임의로 스왑한 후
    앞뒤에 임의의 문자를 붙여 만든 결과인지 판단합니다.
    """
    n, m = len(original), len(encrypted)
    if n > m:
        return False
    
    # 알파벳 빈도 배열 초기화
    target_count: List[int] = [0] * 26
    window_count: List[int] = [0] * 26

    # original 문자열 빈도 계산
    for ch in original:
        target_count[ord(ch) - ord('a')] += 1

    # 첫 윈도우(encrypted[0:n]) 빈도 계산
    for ch in encrypted[:n]:
        window_count[ord(ch) - ord('a')] += 1

    # 윈도우 슬라이딩
    if window_count == target_count:
        return True
    
    for i in range(m - n):
        left_idx = ord(encrypted[i]) - ord('a')
        right_idx = ord(encrypted[i + n]) - ord('a')
        window_count[left_idx] -= 1
        window_count[right_idx] += 1
        if window_count == target_count:
            return True
        
    return False

def main():
    t = int(sys.stdin.readline().strip())

    results: List[str] = []
    for _ in range(t):
        encrypted = sys.stdin.readline().rstrip()
        original = sys.stdin.readline().rstrip()
        result = "YES" if is_encrypted_form(encrypted, original) else "NO"
        results.append(result)

    # 한 번에 출력하여 I/O 횟수 절감
    print("\n".join(results))

if __name__ == "__main__":
    main()